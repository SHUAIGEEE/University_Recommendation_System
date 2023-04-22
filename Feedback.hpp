#ifndef Feedback
#define Feedback

/* REPLY */
struct ReplyNode
{
    std::string content;
    bool isAdmin;
    struct tm* timePosted;
    ReplyNode* nextReply;
};


/* FEEDBACK */
struct FeedbackNode
{
    std::string customerID;
    int universityRank;
    bool isNew;
    std::string feedbackContent;
    struct tm* timePosted;
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
    FeedbackNode* createFeedbackNode(std::string customerID, int universityRank, std::string feedbackContent, tm* timePosted);
    void insertIntoSortedList(std::string customerID, int universityRank, std::string feedbackContent, tm* timePosted);
    void sortFeedback();
    void displayList();
    FeedbackNode* moveFoward();
    FeedbackNode* moveBackward();
    ReplyNode createReplyNode(std::string content, bool isAdmin, tm* timePosted);
    void addReply(std::string content, bool isAdmin, tm* timePosted);
};

#endif