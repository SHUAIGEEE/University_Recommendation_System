#ifndef Admin_
#define Admin_

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
    void displayCustomerDetails();
    void modifyCustomerDetails(std::string customerID);
    void deleteCustomerAccount(std::string customerID);
    void viewCustomerFeedback();
    void viewNextFeedback();
    void viewPreviousFeedback();
    void replyToFeedback();
    void generateReport();
    //TODO: Add search and sort and display university
};


#endif