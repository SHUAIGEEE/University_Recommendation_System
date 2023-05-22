#ifndef Feedback
#define Feedback
#include "University.hpp";

/* REPLY */
struct ReplyNode
{
    std::string content;
    bool isAdmin;
    time_t timePosted;
    ReplyNode* nextReply;
};


/* FEEDBACK */
struct FeedbackNode
{
    std::string customerID;
    UniversityNode* university;
    bool isNew;
    std::string feedbackContent;
    time_t timePosted;
    ReplyNode* replies;
    FeedbackNode* nextFeedback;
    FeedbackNode* prevFeedback;
};

class FeedbackList
{
private:
    FeedbackNode* head = nullptr;
    FeedbackNode* tail = nullptr;
    int size = 0;

public:
    FeedbackList();
    ~FeedbackList();
    FeedbackNode* createFeedbackNode(std::string customerID, UniversityNode* university, std::string feedbackContent, time_t timePosted);
    void insertIntoSortedList(std::string customerID, UniversityNode* university, std::string feedbackContent, time_t timePosted);
    void sortFeedback();
    void displayList();
    void displayFeedback(FeedbackNode* feedback);
    void moveFoward(FeedbackNode* current);
    void moveBackward(FeedbackNode* current);
    ReplyNode* createReplyNode(std::string content, bool isAdmin, time_t timePosted);
    void addReply(std::string content, bool isAdmin, time_t timePosted, FeedbackNode* feedback);
    FeedbackNode* getHead();
};

#endif