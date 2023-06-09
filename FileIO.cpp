#include <iostream>
#include <fstream>
#include <string>
#include "Shared_Variables.hpp"
#include "Customer.hpp"
#include "University.hpp"
#include "Feedback.hpp"
#include "Admin.hpp"
#include "Guest.hpp"
#include "FileIO.hpp"
#include <ctime>
#include <iomanip>
#include <sstream>

using namespace std;

UniversityList uniList;
CustomerList customerList;
FeedbackList feedbackList;
UniversityList tempUniversityList;

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

		if (rank == "")
		{
			break;
		}

		getline(iss, institutionName, ',');
		while (institutionName.front() == '"' && institutionName.back() != '"') {
			getline(iss, buffer, ',');
			institutionName = institutionName + buffer;
		}

		if (institutionName[0] == ' ') {
			institutionName = institutionName.erase(0, 1);
		}

		if (institutionName[institutionName.length() - 1] == ' ') {
			institutionName = institutionName.erase(institutionName.length() - 1, 1);
		}

		if (institutionName[0] == '"' && institutionName[institutionName.length() - 1] == '"') {
			institutionName = institutionName.erase(institutionName.length() - 1, 1);
			institutionName = institutionName.erase(0, 1);
		}

		int i = 0;
		while (i < institutionName.length() - 1) {
			if (institutionName[i] == '"' && institutionName[i + 1] == '"') {
				institutionName = institutionName.erase(i, 1);
				i--;
			}
			i++;
		}

		getline(iss, locationCode, ',');
		getline(iss, location, ',');
		while (location.front() == '"' && location.back() != '"') {
			getline(iss, buffer, ',');
			location = location + buffer;
		}

		if (location[0] == ' ') {
			location = location.erase(0, 1);
		}

		if (location[location.length() - 1] == ' ') {
			location = location.erase(location.length() - 1, 1);
		}

		if (location[0] == '"' && location[location.length() - 1] == '"') {
			location = location.erase(location.length() - 1, 1);
			location = location.erase(0, 1);
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

		uniList.insertEnd(rank, arScore, erScore, fsrScore, cpfScore, ifrScore,
			isrScore, irnScore, gerScore, scoreScaled, institutionName, locationCode, location,
			arRank, erRank, fsrRank, cpfRank, ifrRank, isrRank, irnRank, gerRank);
	}
    file.close();

    /* Customer */
    file.open("Customer.txt");
	string customerLine;
    string customerID, username, email, password, lastLoginTime, favouriteUni;
    while (getline(file, customerLine))
    {
		istringstream customeriss(customerLine);
        getline(customeriss, customerID, ';');
        getline(customeriss, username, ';');
        getline(customeriss, email, ';');
        getline(customeriss, password, ';');
		getline(customeriss, lastLoginTime, ';');

		std::string format = "%d-%m-%Y";
		std::tm timeStruct = {};
		std::istringstream timeiss(lastLoginTime);
		timeiss >> std::get_time(&timeStruct, format.c_str());
        customerList.insertEnd(customerID, username, email, password, timeStruct);

		while (getline(customeriss, favouriteUni, ';')) {
			customerList.insertFavouriteEnd(stoi(favouriteUni), customerList.getCustomer(customerID));
		}
    }
    file.close();


    /* Feedback */
    file.open("Feedback.txt");
    string feedbackLine;
    string feedbackCustomerID, feedbackUniRank, feedbackContent, timePosted, reply;
    string replyContent, isAdmin, replyTimePosted;

    while (getline(file, feedbackLine))
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

    file.close();
}

void writeFile()
{
    /* Customer */
    ofstream file("Customer.txt");
    CustomerNode* customerTemp = customerList.getHead();

    while (customerTemp != nullptr)
    {
        struct tm loginTime = customerTemp->customer.getLastLoginTime();
		char formattedTime[50];
		strftime(formattedTime, sizeof(formattedTime), "%d-%m-%Y", &loginTime);
        file << customerTemp->customer.getCustomerID() << ";" << customerTemp->customer.getUsername() << ";"
			<< customerTemp->customer.getEmail() << ";" << customerTemp->customer.getPassword() << ";" 
			<< formattedTime;
		FavouriteNode* favouriteTemp = customerTemp->favourites;
		while (favouriteTemp != nullptr) {
			file << ";" << favouriteTemp->universityRank;
			favouriteTemp = favouriteTemp->nextFavourite;
		}
		file << endl;
		customerTemp = customerTemp->nextCustomer;
    }

    file.close();

	system("pause");

    /* Feedback */
    file.open("Feedback.txt");
    FeedbackNode* feedbackTemp = feedbackList.getHead();

    while (feedbackTemp != nullptr)
    {
        char formattedTime[50];
        strftime(formattedTime, sizeof(formattedTime), "%d-%m-%Y %a %H:%M:%S", &feedbackTemp->timePosted);
        file << feedbackTemp->customerID << ";" << feedbackTemp->university->rank << ";" << feedbackTemp->feedbackContent << ";" << formattedTime;
        ReplyNode* reply = feedbackTemp->replies;
        while (reply != nullptr) {
            strftime(formattedTime, sizeof(formattedTime), "%d-%m-%Y %a %H:%M:%S", &reply->timePosted);
            file << ";" << reply->content << "," << reply->isAdmin << "," << formattedTime;
            reply = reply->nextReply;
        }
        file << endl;
        feedbackTemp = feedbackTemp->nextFeedback;
    }

    file.close();
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