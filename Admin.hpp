#ifndef Admin_
#define Admin_
#include "Feedback.hpp";

/* ADMIN */
class Admin
{
private:
    std::string adminID;
    std::string password;

public:
    Admin();
    ~Admin();
    bool login(std::string adminID, std::string password);
    void logout();
    void displayCustomerDetails();
    void modifyCustomerDetails(std::string customerID);
    void deleteCustomerAccount(std::string customerID);
    void viewAllFeedbacks();
    void viewSelectedFeedback(FeedbackNode* feedback);
    void replyToFeedback(FeedbackNode* feedback);
    void generateReport();
};


#endif