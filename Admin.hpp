#ifndef Admin_
#define Admin_

/* ADMIN */
class Admin
{
private:
    std::string adminID;
    std::string password;

public:
    Admin();
    ~Admin();
    void login(std::string adminID, std::string password);
    void logout();
    void displayCustomerDetails();
    void modifyCustomerDetails(std::string customerID);
    void deleteCustomerAccount(std::string customerID);
    void viewCustomerFeedback();
    void viewNextFeedback();
    void viewPreviousFeedback();
    void replyToFeedback();
    void generateReport();
};


#endif