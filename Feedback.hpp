#ifndef Feedback
#define Feedback
#include "University.hpp";

/* REPLY */
struct ReplyNode
{
    std::string content;
    bool isAdmin;
    struct tm timePosted;
    ReplyNode* nextReply;
};


/* FEEDBACK */
struct FeedbackNode
{
    std::string customerID;
    UniversityNode* university;
    bool isNew;
    std::string feedbackContent;
    struct tm timePosted;
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
    FeedbackNode* createFeedbackNode(std::string customerID, UniversityNode* university, std::string feedbackContent, struct tm timePosted);
    void insertIntoSortedList(std::string customerID, UniversityNode* university, std::string feedbackContent, struct tm timePosted);
    void sortFeedback();
    void displayList();
    ReplyNode* createReplyNode(std::string content, bool isAdmin, struct tm timePosted);
    void addReply(std::string content, bool isAdmin, struct tm timePosted, FeedbackNode* feedback, bool readFromFile);
    FeedbackNode* getHead();
    FeedbackNode* getTail();
    void setHead(FeedbackNode* feedback);
    void setTail(FeedbackNode* feedback);
    FeedbackNode* getFeedbackNode(int index, FeedbackList* feedbackList);
    int getSize();
};

#endif