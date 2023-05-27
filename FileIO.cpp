#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include "FileIO.hpp"
#include "Customer.hpp"
#include "University.hpp"
#include "Feedback.hpp"
#include "Admin.hpp"
#include "Guest.hpp"
#include "Shared_Variables.hpp"
#include <iomanip>
#include <sstream>

using namespace std;

UniversityList uniList;
CustomerList customerList;
FeedbackList feedbackList;

void readFile()
{

	/* Universities */
	ifstream file("2023 QS World University Rankings.csv");
	if (!file)
	{
		cout << "Error opening file!" << endl;
		return;
	}
	string universityLine, buffer;
	string rank; // int
	string arScore, erScore, fsrScore, cpfScore, ifrScore, isrScore, irnScore, gerScore, scoreScaled; // double
	string institutionName, locationCode, location, arRank, erRank, fsrRank, cpfRank, ifrRank, isrRank, irnRank, gerRank; // string

	getline(file, universityLine); // Skip headers

	while (getline(file, universityLine)) {
		stringstream iss(universityLine);
		getline(iss, rank, ',');


		/*if (rank == "Rank")
		{
			continue;
		}*/
		if (rank == "")
		{
			break;
		}

		cout << rank << endl;

		getline(iss, institutionName, ',');
		while (institutionName.front() == '"' && institutionName.back() != '"') {
			getline(iss, buffer, ',');
			institutionName = institutionName + buffer;
		}
		getline(iss, locationCode, ',');
		/*while (institutionName.front() == '"' && institutionName.back() != '"') {
			getline(iss, buffer, ',');
			institutionName = institutionName + buffer;
		}*/
		getline(iss, location, ',');
		while (location.front() == '"' && location.back() != '"') {
			getline(iss, buffer, ',');
			location = location + buffer;
		}
		getline(iss, arScore, ',');
		getline(iss, arRank, ',');
		getline(iss, erScore, ',');
		getline(iss, erRank, ',');
		getline(iss, fsrScore, ',');
		getline(iss, fsrRank, ',');
		getline(iss, cpfScore, ',');
		getline(iss, cpfRank, ',');
		getline(iss, ifrScore, ',');
		getline(iss, ifrRank, ',');
		getline(iss, isrScore, ',');
		getline(iss, isrRank, ',');
		getline(iss, irnScore, ',');
		getline(iss, irnRank, ',');
		getline(iss, gerScore, ',');
		getline(iss, gerRank, ',');
		getline(iss, scoreScaled, ',');

		arScore = checkNull(arScore);
		arRank = checkNull(arRank);
		erScore = checkNull(erScore);
		erRank = checkNull(erRank);
		fsrScore = checkNull(fsrScore);
		fsrRank = checkNull(fsrRank);
		cpfScore = checkNull(cpfScore);
		cpfRank = checkNull(cpfRank);
		ifrScore = checkNull(ifrScore);
		ifrRank = checkNull(ifrRank);
		isrScore = checkNull(isrScore);
		isrRank = checkNull(isrRank);
		irnScore = checkNull(irnScore);
		irnRank = checkNull(irnRank);
		gerScore = checkNull(gerScore);
		gerRank = checkNull(gerRank);
		scoreScaled = checkNull(scoreScaled);

		cout << institutionName << ":" << location << ":" << arScore << ":" << fsrRank << endl;

		uniList.insertEnd(rank, arScore, erScore, fsrScore, cpfScore, ifrScore,
			isrScore, irnScore, gerScore, scoreScaled, institutionName, locationCode, location,
			arRank, erRank, fsrRank, cpfRank, ifrRank, isrRank, irnRank, gerRank);
	}


    /* Customer */;
    ifstream customerFile("Customer.txt");
    string memberID, password;

    while (customerFile.good())
    {
        getline(customerFile, memberID, ';');
        getline(customerFile, password);

        if (memberID == "")
        {
            break;
        }
        
        customerList.insertEnd(memberID, password);
    }

    customerFile.close();

    /* Feedback */
    ifstream feedbackFile("Feedback.txt");
    string feedbackLine;
    string feedbackCustomerID, feedbackUniRank, feedbackContent, timePosted, reply;
    string replyContent, isAdmin, replyTimePosted;

    while (getline(feedbackFile, feedbackLine))
    {
        istringstream feedbackiss(feedbackLine);
        getline(feedbackiss, feedbackCustomerID, ';');
        getline(feedbackiss, feedbackUniRank, ';');
        getline(feedbackiss, feedbackContent, ';');
        getline(feedbackiss, timePosted, ';');

        std::string format = "%d-%m-%Y %a %H:%M:%S";
        std::tm timeStruct = {};
        std::istringstream timeiss(timePosted);
        timeiss >> std::get_time(&timeStruct, format.c_str());
        feedbackList.insertIntoSortedList(feedbackCustomerID, uniList.getUniversity(stoi(feedbackUniRank)), feedbackContent, timeStruct);

        while (getline(feedbackiss, reply, ';')) {
            istringstream replyiss(reply);
            getline(replyiss, replyContent, ',');
            getline(replyiss, isAdmin, ',');
            getline(replyiss, replyTimePosted, ',');
            std::istringstream iss(replyTimePosted);
            iss >> std::get_time(&timeStruct, format.c_str());
            feedbackList.addReply(replyContent, isAdmin == "1", timeStruct, feedbackList.getTail(), true);
        }
    }

    feedbackFile.close();
}

void writeFile()
{
    /* Customer */
    ofstream file("Customer.txt");
    CustomerNode* temp = customerList.getHead();

    while (temp != nullptr)
    {
        file << temp->customer.getCustomerID() << ";" << temp->customer.getPassword() << endl;
        temp = temp->nextCustomer;
    }

    file.close();

    /* Feedback */
    ofstream feedbackFile("Feedback.txt");
    FeedbackNode* feedbackTemp = feedbackList.getHead();

    while (feedbackTemp != nullptr)
    {
        char formattedTime[50];
        strftime(formattedTime, sizeof(formattedTime), "%d-%m-%Y %a %H:%M:%S", &feedbackTemp->timePosted);
        feedbackFile << feedbackTemp->customerID << ";" << feedbackTemp->university->rank << ";" << feedbackTemp->feedbackContent << ";" << formattedTime;
        ReplyNode* reply = feedbackTemp->replies;
        while (reply != nullptr) {
            strftime(formattedTime, sizeof(formattedTime), "%d-%m-%Y %a %H:%M:%S", &reply->timePosted);
            feedbackFile << ";" << reply->content << "," << reply->isAdmin << "," << formattedTime;
            reply = reply->nextReply;
        }
        feedbackFile << endl;
        feedbackTemp = feedbackTemp->nextFeedback;
    }

    feedbackFile.close();
}

string checkNull(string value) {
	if (value == "" || value == "-") {
		return "-1";
	}
	return value;
}

string checkFullString(string value, stringstream ss) {
	string buffer;
	while (value.front() == '"' && value.back() != '"') {
		getline(ss, buffer, ',');
		value = value + buffer;
	}
	return value;
}