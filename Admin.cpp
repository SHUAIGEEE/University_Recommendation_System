#include <iostream>
#include <string>
#include "Admin.hpp"
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
}

void Admin::modifyCustomerDetails(string customerID)
{
}

void Admin::deleteCustomerAccount(string customerID)
{
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
