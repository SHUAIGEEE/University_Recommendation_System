#include <iostream>
#include <ctime>
#include "Feedback.hpp"
#include <time.h>
#include <string>

using namespace std;

FeedbackList::FeedbackList()
{
}

FeedbackList::~FeedbackList()
{
}

FeedbackNode *FeedbackList::createFeedbackNode(std::string customerID, UniversityNode* university, std::string feedbackContent, time_t timePosted)
{
    FeedbackNode* newNode = new FeedbackNode;

    newNode->customerID = customerID;
    newNode->university = university;
    newNode->feedbackContent = feedbackContent;
    newNode->timePosted = timePosted;
    newNode->replies = nullptr;
    newNode->nextFeedback = nullptr;
    newNode->prevFeedback = nullptr;

    return newNode;
}

//TODO: Sort
void FeedbackList::insertIntoSortedList(std::string customerID, UniversityNode* university, std::string feedbackContent, time_t timePosted)
{
    FeedbackNode* newNode = createFeedbackNode(customerID, university, feedbackContent, timePosted);

    if (head == nullptr)
    {
        head = tail = newNode;
    }
    else if (difftime(timePosted, head->timePosted) <= 0)
    {
        newNode->nextFeedback = head;
        head->prevFeedback = newNode;
        head = newNode;
    }
    else {
        FeedbackNode* current = head->nextFeedback;
        FeedbackNode* prev = head;

        while (current != nullptr)
        {
            if (difftime(timePosted, current->timePosted) <= 0) {
                break;
            }
            prev = current;
            current = current->nextFeedback;
        }
        prev->nextFeedback = newNode;
        newNode->prevFeedback = prev;

        if (current != nullptr) {
            newNode->nextFeedback = current;
            current->prevFeedback = newNode;
        }
        else {
            tail = newNode;
        }

    }
    size++;
}

void FeedbackList::sortFeedback()
{
}

void FeedbackList::displayList()
{
    FeedbackNode* temp = head;

    while (temp != NULL)
    {
        //cout << temp->customerID << " : " << temp->universityRank << " : " << temp->feedbackContent << " :" << temp->timePosted << endl;
        cout << temp->customerID << " : " << temp->university->institutionName << " : " << temp->feedbackContent << " :" << asctime(localtime(&temp->timePosted)) << endl;
        temp = temp->nextFeedback;
    }

    cout << endl << "List is ended here!" << endl << endl;
}

void FeedbackList::displayFeedback(FeedbackNode* feedback)
{
    cout << feedback->university->institutionName << endl;
    cout << feedback->customerID << endl;
    cout << feedback->feedbackContent << endl;
    ReplyNode* current = feedback->replies;
    while (current != nullptr) {
        cout << current->content << endl;
    }
}

void FeedbackList::moveFoward(FeedbackNode* current)
{
    if (current->nextFeedback != nullptr) {
        current = current->nextFeedback;
        //displayFeedback(currentFeedback);
    }
    else {
        cout << "This is the last feedback." << endl;
    }
}

void FeedbackList::moveBackward(FeedbackNode* current)
{
    if (current->prevFeedback != nullptr) {
        current = current->prevFeedback;
        //displayFeedback(currentFeedback);
    }
    else {
        cout << "This is the first feedback." << endl;
    }
}

ReplyNode* FeedbackList::createReplyNode(std::string content, bool isAdmin, time_t timePosted)
{
    ReplyNode* newNode = new ReplyNode;

    newNode->content = content;
    newNode->isAdmin = isAdmin;
    newNode->timePosted = timePosted;
    newNode->nextReply = nullptr;
    return newNode;
}

void FeedbackList::addReply(std::string content, bool isAdmin, time_t timePosted, FeedbackNode* feedback)
{
    ReplyNode* newNode = createReplyNode(content, isAdmin, timePosted);

    if (feedback->replies == nullptr) {
        feedback->replies = newNode;
    }
    else {
        ReplyNode* current = feedback->replies;
        while (current->nextReply != nullptr) {
            current = current->nextReply;
        }
        current->nextReply = newNode;
    }
}

FeedbackNode* FeedbackList::getHead() {
    return head;
}
