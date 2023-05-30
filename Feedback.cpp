#include <iostream>
#include <ctime>
#include "Feedback.hpp"
#include <string>
#include "Shared_Variables.hpp"

using namespace std;

FeedbackList::FeedbackList()
{
}

FeedbackList::~FeedbackList()
{
}

FeedbackNode *FeedbackList::createFeedbackNode(std::string customerID, UniversityNode* university, std::string feedbackContent, struct tm timePosted)
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

void FeedbackList::insertIntoSortedList(std::string customerID, UniversityNode* university, std::string feedbackContent, struct tm timePosted)
{
    FeedbackNode* newNode = createFeedbackNode(customerID, university, feedbackContent, timePosted);

    if (head == nullptr)
    {
        head = tail = newNode;
    }
    else if(mktime(&timePosted) >= mktime(&head->timePosted))
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
            if (mktime(&timePosted) >= mktime(&head->timePosted)) {
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
        cout << index << ". " << temp->university->institutionName << " - " << temp->customerID << " - " << temp->feedbackContent << endl;
        char formattedTime[50];
        strftime(formattedTime, sizeof(formattedTime), "%d-%m-%Y %a %H:%M:%S", &temp->timePosted);
        cout << "   Last Updated: " << formattedTime << endl;
        temp = temp->nextFeedback;
        index++;
    }

    cout << endl << "List is ended here!" << endl << endl;
}

ReplyNode* FeedbackList::createReplyNode(std::string content, bool isAdmin, struct tm timePosted)
{
    ReplyNode* newNode = new ReplyNode;

    newNode->content = content;
    newNode->isAdmin = isAdmin;
    newNode->timePosted = timePosted;
    newNode->nextReply = nullptr;
    return newNode;
}

void FeedbackList::addReply(std::string content, bool isAdmin, struct tm timePosted, FeedbackNode* feedback, bool readFromFile)
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

    if (!readFromFile) {
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
        if (feedback != feedbackList.getHead()) {
            temp->nextFeedback = feedbackList.getHead();
            feedbackList.getHead()->prevFeedback = temp;
            feedbackList.setHead(temp);
        }
    }
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

FeedbackNode* FeedbackList::getFeedbackNode(int index, FeedbackList* feedbackList) {
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