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
    ifstream feedbackFile("Feedback.txt");
    string rank; // int
    string arScore, erScore, fsrScore, cpfScore, ifrScore, isrScore, irnScore, gerScore, scoreScaled; // double
    string institutionName, locationCode, location, arRank, erRank, fsrRank, cpfRank, ifrRank, isrRank, irnRank, gerRank; // string

    // while (file.good())
    // {
    //     getline(file, rank, ',');
    //     getline(file, institutionName, ',');
    //     getline(file, locationCode, ',');
    //     getline(file, location, ',');
    //     getline(file, arScore, ',');
    //     getline(file, arRank, ',');
    //     getline(file, erScore, ',');
    //     getline(file, erRank, ',');
    //     getline(file, fsrScore, ',');
    //     getline(file, fsrRank, ',');
    //     getline(file, cpfScore, ',');
    //     getline(file, cpfRank, ',');
    //     getline(file, ifrScore, ',');
    //     getline(file, ifrRank, ',');
    //     getline(file, isrScore, ',');
    //     getline(file, isrRank, ',');
    //     getline(file, irnScore, ',');
    //     getline(file, irnRank, ',');
    //     getline(file, gerScore, ',');
    //     getline(file, gerRank, ',');
    //     getline(file, scoreScaled, ',');

    //     if (rank == "Rank")
    //     {
    //         continue;
    //     }
    //     else if (rank == "")
    //     {
    //         break;
    //     }
        
    //     uniList.insertEnd(rank, institutionName, locationCode, location, arScore, arRank, erScore, erRank,
    //     fsrScore, fsrRank, cpfScore, cpfRank, ifrScore, ifrRank, isrScore, isrRank, irnScore, irnRank, gerScore, gerRank, scoreScaled);

    // }
    // uniList.displayList();
    

    /* Customer */
    file.close();
    file.open("Customer.txt");
    string memberID, password;

    while (file.good())
    {
        getline(file, memberID, ';');
        getline(file, password);

        if (memberID == "")
        {
            break;
        }
        
        customerList.insertEnd(memberID, password);
    }

    file.close();

    /* Feedback */
    string line;
    string feedbackCustomerID, feedbackUniRank, feedbackContent, timePosted, reply;
    string replyContent, isAdmin, replyTimePosted;

    while (getline(feedbackFile, line))
    {
        istringstream feedbackiss(line);
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