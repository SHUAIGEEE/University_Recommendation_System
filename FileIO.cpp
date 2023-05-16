#include <iostream>
#include <fstream>
#include <string>
#include "FileIO.hpp"
#include "Customer.hpp"
#include "University.hpp"
#include "Feedback.hpp"
#include "Admin.hpp"
#include "Guest.hpp"
#include "Shared_Variables.hpp"

using namespace std;

UniversityList uniList;
CustomerList customerList;
FeedbackList feedbackList;

void readFile()
{

    /* Universities */
    ifstream file("2023 QS World University Rankings.csv");
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

    customerList.displayList();
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
}