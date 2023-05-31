#include <iostream>
#include <string>
#include <iomanip>
#include "Admin.hpp"
#include "Customer.hpp"
#include "Feedback.hpp"
#include "Shared_Variables.hpp"
#include "Utilities.hpp"
#include <ctime>

using namespace std;

Admin::Admin()
{
    this->adminName = "cxk";
    this->password = "a";
}

Admin::~Admin()
{
}

bool Admin::login(string adminName, string password)
{
    if (adminName == this->adminName && password == this->password) return true;
    else return false;
}

void Admin::logout()
{
    cout << "Logout successful!" << endl;
}

void Admin::displayUniversity()
{
    uniList.displayList(uniList.getHead(), -1, "Admin");
}

void Admin::sortUniversities()
{
    uniList.sortUniversities(getSortField());
    uniList.displayList(uniList.getHead(), -1, "Admin"); // can change to display sorted list
}

void Admin::searchUniversities()
{
    uniList.searchUniversities(getSearchField(), "Admin");
}

void Admin::displayCustomerDetails()
{
    customerList.displayList();
}

void Admin::modifyCustomerDetails()
{
    cin.ignore();
    string customerID;
    string newUsername;
    string newPassword;
    string newEmail;
    cout << endl << "Please enter Customer ID : ";
    getline(cin, customerID);

    CustomerNode* temp = customerList.getCustomer(customerID);
    while (temp == nullptr) {
        cout << "Invalid Customer ID." << endl;
        cout << "Please enter a valid Customer ID : ";
        getline(cin, customerID);
        temp = customerList.getCustomer(customerID);
    }

    cout << "1. Modify username" << endl;
    cout << "2. Modify password" << endl;
    cout << "3. Modify email" << endl;
    cout << "4. Back" << endl;
    int modifyCustomerOption = readInteger(1,4);
    if (modifyCustomerOption == 1)
    {
        cout << "Please enter the new username: " << endl;
        cin >> newUsername;
        temp->customer.setUsername(newUsername);
        cout << "Username modified successfully!" << endl;
    }
    else if (modifyCustomerOption == 2)
    {
        cout << "Please enter the new password: " << endl;
        cin >> newPassword;
        temp->customer.setPassword(newPassword);
        cout << "Password modified successfully!" << endl;
    }
    else if (modifyCustomerOption == 3)
    {
        cout << "Please enter the new email: " << endl;
        cin >> newEmail;
        temp->customer.setEmail(newEmail);
        cout << "Email modified successfully!" << endl;
    }
    else if (modifyCustomerOption == 4)
    {
        return;
    }
}

void Admin::deleteCustomerAccount()
{
    string customerID;
    cout << endl << "Customer that login 180 days ago: " << endl;
    time_t currentTime = time(nullptr);
    CustomerNode* current = customerList.getHead();
    CustomerNode* previous = nullptr;

	cout << string(105, '-') << endl;

	cout << std::left << setw(18) << "Customer ID" << setw(20) << "Username"
		<< setw(30) << "Email" << setw(20) << "Password" << setw(15) << "Last Logged in" << endl;

    cout << string(105, '-') << endl;
    
    while (current != nullptr)
    {
        struct tm loginTime = current->customer.getLastLoginTime();
        time_t loginTimeT = mktime(&loginTime);

        char formattedTime[50];
        strftime(formattedTime, sizeof(formattedTime), "%d-%m-%Y", &loginTime);

        int elapsedDays = static_cast<int>((currentTime - loginTimeT) / (24 * 60 * 60));
        if (elapsedDays >= 180)
        {
            cout << std::left << setw(18) << current->customer.getCustomerID() << setw(20) << current->customer.getUsername()
                << setw(30) << current->customer.getEmail() << setw(20) << current->customer.getPassword() << setw(15) << formattedTime << endl;
        }
        current = current->nextCustomer;
    }

    cout << string(105, '-') << endl;

    cout << endl << "List ends here!" << endl << endl;

    current = customerList.getHead();
    previous = nullptr;

    cout << "Please enter customer ID to delete: ";
    cin >> customerID;
    while (current != nullptr)
    {
        if (current->customer.getCustomerID() == customerID)
        {
            if (previous == nullptr)
            {
                customerList.setHead(current->nextCustomer);
            }
            else
            {
                previous->nextCustomer = current->nextCustomer;
            }
            delete current;
            cout << "User with customerID " << customerID << " has been deleted." << endl;
            return;
        }
        previous = current;
        current = current->nextCustomer;
    }
    cout << "User with customerID " << customerID << " not found." << endl;
}

void Admin::displayAllFeedbacks()
{
    system("cls");
    feedbackList.displayList();
    FeedbackNode* current = feedbackList.getHead();
    cout << "Please select a feedback to view (Press 0 to go back): ";
    int viewFeedbackOption = readInteger(0, feedbackList.getSize());
    if (viewFeedbackOption == 0) {
        return;
    }
    displaySelectedFeedback(feedbackList.getFeedbackNode(viewFeedbackOption, &feedbackList));
}

void Admin::displaySelectedFeedback(FeedbackNode* feedback)
{
    cout << "University Name: " << feedback->university->institutionName << endl;
    cout << "Customer ID: " << feedback->customerID << endl;
    char formattedTime[50];
    strftime(formattedTime, sizeof(formattedTime), "%d-%m-%Y %a %H:%M:%S", &feedback->timePosted);
    cout << "Last Updated: " << formattedTime << endl;
    cout << "Feedback: " << feedback->feedbackContent << endl;
    if (feedback->replies != nullptr) {
        cout << "Replies: " << endl;
        ReplyNode* currentReplies = feedback->replies;
        while (currentReplies != nullptr) {
            if (currentReplies->isAdmin) {
                cout << "Admin: " << currentReplies->content << endl;
            }
            else {
                cout << feedback->customerID << ": " << currentReplies->content << endl;
            }

            currentReplies = currentReplies->nextReply;
        }
    }

    cout << endl;
    cout << "1. Write a Reply" << endl;
    cout << "2. View Previous Feedback" << endl;
    cout << "3. View Next Feedback" << endl;
    cout << "4. Back" << endl;
    cout << "Please select an option: ";
    int viewFeedbackOption = readInteger(1, 4);
    switch (viewFeedbackOption)
    {
    case 1:
        replyToFeedback(feedback);
        displaySelectedFeedback(feedback);
        break;
    case 2:
        if (feedback->prevFeedback != NULL) {
            displaySelectedFeedback(feedback->prevFeedback);
            break;
        }
        else {
            cout << endl << "This is already the first feedback!" << endl;
            system("pause");
            displaySelectedFeedback(feedback);
            break;
        }
    case 3:
        if (feedback->nextFeedback != NULL) {
            displaySelectedFeedback(feedback->nextFeedback);
            break;
        }
        else {
            cout << endl << "This is already the last feedback!" << endl;
            system("pause");
            displaySelectedFeedback(feedback);
            break;
        }
    case 4:
        displayAllFeedbacks();
    default:
        break;
    }
}

void Admin::replyToFeedback(FeedbackNode* feedback)
{
    string replyContent = "";
    cin.ignore();
    cout << "Please enter your reply: ";
    getline(cin, replyContent);

    time_t rawTime = time(nullptr);
    struct tm* timeInfo = localtime(&rawTime);
    feedbackList.addReply(replyContent, true, *timeInfo, feedback, false);
    cout << "Your reply has been sent!" << endl;
    system("pause");
}

void Admin::generateReport()
{
    uniList.clearTempUniversityList();
    UniversityNode* currentUniversity = tempUniversityList.getHead();
    UniversityNode* insertUni;
    FavouriteNode* currentFavourite;
    bool alreadyExist = false;
    int* favouriteUniIndex = new int[customerList.getSize() * 20];
    int loopIndex = 0;
    CustomerNode* currentCustomer = customerList.getHead();
    if (currentCustomer == nullptr) {
        cout << "No favourite university is saved by customers." << endl;
        system("pause");
        return;
    }

    while (currentCustomer != nullptr) {

        currentFavourite = currentCustomer->favourites;

        while (currentFavourite != nullptr) {

            loopIndex = 0;
            alreadyExist = false;
            currentUniversity = tempUniversityList.getHead();

            while (currentUniversity != nullptr) {

                if (currentFavourite->universityRank == currentUniversity->rank) {
                    favouriteUniIndex[loopIndex]++;
                    alreadyExist = true;
                    break;
                }

                currentUniversity = currentUniversity->nextUniversity;
                loopIndex++;
            }

            if (!alreadyExist) {
                insertUni = uniList.getUniversity(currentFavourite->universityRank);
                tempUniversityList.insertEnd(to_string(insertUni->rank), to_string(insertUni->arScore), to_string(insertUni->erScore),
                    to_string(insertUni->fsrScore), to_string(insertUni->cpfScore), to_string(insertUni->ifrScore), to_string(insertUni->isrScore),
                    to_string(insertUni->irnScore), to_string(insertUni->gerScore), to_string(insertUni->scoreScaled), insertUni->institutionName,
                    insertUni->locationCode, insertUni->location, insertUni->arRank, insertUni->erRank, insertUni->fsrRank, insertUni->cpfRank, insertUni->ifrRank,
                    insertUni->isrRank, insertUni->irnRank, insertUni->gerRank);
                favouriteUniIndex[loopIndex] = 1;
            }

            currentFavourite = currentFavourite->nextFavourite;
        }

        currentCustomer = currentCustomer->nextCustomer;
    };

    int temp;
    bool swapResult = false;
    UniversityNode* prev;
    UniversityNode* current = tempUniversityList.getHead();
    UniversityNode* next = current->nextUniversity;


    for (int i = 0; i < tempUniversityList.getSize() - 1; i++) {
        for (int j = 0; j < tempUniversityList.getSize() - 1; j++) {
            if (favouriteUniIndex[j] < favouriteUniIndex[j + 1]) {
                temp = favouriteUniIndex[j];
                favouriteUniIndex[j] = favouriteUniIndex[j + 1];
                favouriteUniIndex[j + 1] = temp;

                current = tempUniversityList.getHead();
                next = current->nextUniversity;

                for (int k = 0; k < j; k++) {
                    prev = current;
                    current = next;
                    next = next->nextUniversity;
                }

                current->nextUniversity = next->nextUniversity;
                next->nextUniversity = current;

                if (j == 0) {
                    tempUniversityList.setHead(next);
                }
                else {
                    prev->nextUniversity = next;
                }

                swapResult = true;
            }
        }
        if (!swapResult) {
            break;
        }
        swapResult = false;
    }

    currentUniversity = tempUniversityList.getHead();
    loopIndex = 0;
    int maxNameLength = 18;

    while (currentUniversity != nullptr) {
        if (currentUniversity->institutionName.length() > maxNameLength) {
            maxNameLength = currentUniversity->institutionName.length();
        }

        currentUniversity = currentUniversity->nextUniversity;
    }

    maxNameLength += 6;
    currentUniversity = tempUniversityList.getHead();

    system("cls");

    cout << "Top 10 Favourite University Report" << endl << endl;

    cout << string(maxNameLength + 50, '-') << endl;

    cout << left << setw(6) << "Rank" << setw(maxNameLength) << "Institution Name" << setw(26) 
        << "University Ranking" << setw(28) << "Number of Favourites" << endl;

    cout << string(maxNameLength + 50, '-') << endl;

    while (currentUniversity != nullptr) {
        cout << left << setw(6) << loopIndex + 1 << setw(maxNameLength) << currentUniversity->institutionName 
            << setw(26) << currentUniversity->rank << setw(28) << favouriteUniIndex[loopIndex] << endl;
        loopIndex++;
        currentUniversity = currentUniversity->nextUniversity;
    }

    cout << string(maxNameLength + 50, '-') << endl << endl;

    system("pause");

    uniList.clearTempUniversityList();
    delete[] favouriteUniIndex;
}
