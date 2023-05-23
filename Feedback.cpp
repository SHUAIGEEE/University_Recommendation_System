#include <iostream>
#include <ctime>
#include "Feedback.hpp"
#include <time.h>
#include <string>
#include "Shared_Variables.hpp";

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

void FeedbackList::insertIntoSortedList(std::string customerID, UniversityNode* university, std::string feedbackContent, time_t timePosted)
{
    FeedbackNode* newNode = createFeedbackNode(customerID, university, feedbackContent, timePosted);

    if (head == nullptr)
    {
        head = tail = newNode;
    }
    else if (difftime(timePosted, head->timePosted) >= 0)
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
            if (difftime(timePosted, current->timePosted) >= 0) {
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
    int index = 1;

    while (temp != NULL)
    {
        //cout 可以换format
        cout << index << ". " << temp->university->institutionName << " - " << temp->customerID << " - " << temp->feedbackContent << endl;
        struct tm* timeInfo = localtime(&temp->timePosted);
        char formattedTime[50];
        strftime(formattedTime, sizeof(formattedTime), "%d-%m-%Y %a %H:%M%p", timeInfo);
        cout << "   Last Updated: " << formattedTime << endl;
        temp = temp->nextFeedback;
        index++;
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
    feedback->timePosted = newNode->timePosted;
    FeedbackNode* temp = feedback;
    if (feedbackList.getSize() > 1 && feedback == feedbackList.getTail()) {
        temp->prevFeedback->nextFeedback = nullptr;
        feedbackList.setTail(temp->prevFeedback);
    }
    else if (feedbackList.getSize() > 1 && feedback != feedbackList.getHead()) {
        temp->prevFeedback->nextFeedback = temp->nextFeedback;
        temp->nextFeedback->prevFeedback = temp->prevFeedback;
    }
    temp->nextFeedback = feedbackList.getHead();
    feedbackList.getHead()->prevFeedback = temp;
    feedbackList.setHead(temp);
}

FeedbackNode* FeedbackList::getHead() {
    return head;
}

FeedbackNode* FeedbackList::getTail() {
    return tail;
}

void FeedbackList::setHead(FeedbackNode* feedback) {
    head = feedback;
}

void FeedbackList::setTail(FeedbackNode* feedback) {
    tail = feedback;
}

FeedbackNode*FeedbackList::getFeedbackNode(int index, FeedbackList* feedbackList) {
    int i = 1;
    FeedbackNode* current = feedbackList->getHead();
    while (i < index) {
        current = current->nextFeedback;
        i++;
    }
    return current;
}

int FeedbackList::getSize() {
    return size;
}
