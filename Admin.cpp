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
    uniList.displayList();
}

void Admin::sortUniversities()
{
    uniList.sortUniversities(getSortField());
    uniList.displayList(); // can change to display sorted list
}

void Admin::searchUniversities()
{
    uniList.searchUniversities(getSearchField());
}

void Admin::displayCustomerDetails()
{
    customerList.displayList();
}

void Admin::modifyCustomerDetails()
{
    CustomerNode* temp = customerList.getHead();
    string customerID;
    string newUsername;
    string newPassword;
    string newEmail;
    cout << endl << "Please enter customerID : ";
    cin >> customerID;

    cout << "1. Modify username" << endl;
    cout << "2. Modify password" << endl;
    cout << "3. Modify email" << endl;
    cout << "4. Back" << endl;
    int modifyCustomerOption = readInteger(1,4);
    if (modifyCustomerOption == 1)
    {
        cout << "Please enter the new username: " << endl;
        cin >> newUsername;
        while (temp != NULL)
        {
            if (temp->customer.getCustomerID() == customerID)
            {
                temp->customer.setUsername(newUsername);
                cout << "Username modified successfully!" << endl;
                break;
            }
            temp = temp->nextCustomer;
        }
        if (temp == NULL)
        {
            cout << "Customer ID not found!" << endl;
        }
        
    }
    else if (modifyCustomerOption == 2)
    {
        cout << "Please enter the new password: " << endl;
        cin >> newPassword;
        while (temp != NULL)
        {
            if (temp->customer.getCustomerID() == customerID)
            {
                temp->customer.setPassword(newPassword);
                cout << "Password modified successfully!" << endl;
                break;
            }
            temp = temp->nextCustomer;
        }
        if (temp == NULL)
        {
            cout << "Customer ID not found!" << endl;
        }
    }
    else if (modifyCustomerOption == 3)
    {
        cout << "Please enter the new email: " << endl;
        cin >> newEmail;
        while (temp != NULL)
        {
            if (temp->customer.getCustomerID() == customerID)
            {
                temp->customer.setEmail(newEmail);
                cout << "Email modified successfully!" << endl;
                break;
            }
            temp = temp->nextCustomer;
        }
        if (temp == NULL)
        {
            cout << "Customer ID not found!" << endl;
        }
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
        strftime(formattedTime, sizeof(formattedTime), "%d-%m-%Y", &current->customer.getLastLoginTime());

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

void Admin::viewAllFeedbacks()
{
    feedbackList.displayList();
    FeedbackNode* current = feedbackList.getHead();
    cout << "Please select a feedback to view (Press 0 to go back): ";
    int viewFeedbackOption = readInteger(0, feedbackList.getSize());
    if (viewFeedbackOption == 0) {
        return;
    }
    viewSelectedFeedback(feedbackList.getFeedbackNode(viewFeedbackOption, &feedbackList));
}

void Admin::viewSelectedFeedback(FeedbackNode* feedback)
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
        viewSelectedFeedback(feedback);
        break;
    case 2:
        if (feedback->prevFeedback != NULL) {
            viewSelectedFeedback(feedback->prevFeedback);
            break;
        }
        else {
            cout << endl << "This is already the first feedback!" << endl;
            system("pause");
            viewSelectedFeedback(feedback);
            break;
        }
    case 3:
        if (feedback->nextFeedback != NULL) {
            viewSelectedFeedback(feedback->nextFeedback);
            break;
        }
        else {
            cout << endl << "This is already the last feedback!" << endl;
            system("pause");
            viewSelectedFeedback(feedback);
            break;
        }
    case 4:
        viewAllFeedbacks();
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

}
