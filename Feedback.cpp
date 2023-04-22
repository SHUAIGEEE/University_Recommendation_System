#include <iostream>
#include <ctime>
#include "Feedback.hpp"

using namespace std;

FeedbackList::FeedbackList()
{
}

FeedbackList::~FeedbackList()
{
}

FeedbackNode *FeedbackList::createFeedbackNode(std::string customerID, int universityRank, std::string feedbackContent, tm *timePosted)
{
    return nullptr;
}

void FeedbackList::insertIntoSortedList(std::string customerID, int universityRank, std::string feedbackContent, tm *timePosted)
{
}

void FeedbackList::sortFeedback()
{
}

void FeedbackList::displayList()
{
}

FeedbackNode* FeedbackList::moveFoward()
{
}

FeedbackNode* FeedbackList::moveBackward()
{
}

ReplyNode FeedbackList::createReplyNode(std::string content, bool isAdmin, tm *timePosted)
{
    return ReplyNode();
}

void FeedbackList::addReply(std::string content, bool isAdmin, tm *timePosted)
{
}
