#ifndef Admin_
#define Admin_
#include "Feedback.hpp"

/* ADMIN */
class Admin
{
private:
    std::string adminName;
    std::string password;

public:
    Admin();
    ~Admin();
    bool login(std::string adminName, std::string password);
    void logout();
    void displayUniversity();
    void sortUniversities();
    void searchUniversities();
    void displayCustomerDetails();
    void modifyCustomerDetails();
    void deleteCustomerAccount();
    void displayAllFeedbacks();
    void displaySelectedFeedback(FeedbackNode* feedback);
    void replyToFeedback(FeedbackNode* feedback);
    void generateReport();
};


#endif