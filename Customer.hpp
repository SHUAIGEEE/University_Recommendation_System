#ifndef Customer_
#define Customer_
#include "University.hpp"
#include "Feedback.hpp"
#include "Customer.hpp"
#include <ctime>

/* FAVOURITE */
struct FavouriteNode
{
    int universityRank;
    FavouriteNode* nextFavourite;
};


/* CUSTOMER */
class Customer
{
private:
    std::string customerID;
    std::string username;
    std::string email;
    std::string password;
    struct tm lastLoginTime;
public:
    Customer();
    Customer(std::string customerID, std::string username, std::string email , std::string password, struct tm lastLoginTime);
    ~Customer();
    std::string getCustomerID();
    std::string getUsername();
    std::string getEmail();
    std::string getPassword();
    struct tm getLastLoginTime();
    void setCustomerID(std::string customerID);
    void setUsername(std::string username);
    void setEmail(std::string email);
    void setPassword(std::string password);
    void setLoginTime(struct tm* timeInfo);
};

struct CustomerNode
{
    Customer customer;
    FavouriteNode* favourites;
    CustomerNode* nextCustomer;
};

class CustomerList
{
private:
    CustomerNode* head = nullptr;
    CustomerNode* tail = nullptr;
    int size = 0;

public:
    CustomerList();
    ~CustomerList();
    CustomerNode* createCustomerNode(std::string customerID, std::string username, std::string email, std::string password, struct tm lastLoginTime);
    void insertEnd(std::string customerID, std::string username, std::string email, std::string password, struct tm lastLoginTime);
    std::string generateCustomerID();
    void deleteCustomer();
    void displayList();
    CustomerNode* getHead();
    CustomerNode* getTail();
    int getSize();
    bool login(std::string username, std::string password);
    void logout();
    void displayUniversity();
    void sortUniversities();
    void searchUniversities();
    FavouriteNode* createFavouriteNode(int universityRank);
    void insertFavouriteEnd(int universityRank, CustomerNode* customer);
    void saveFavouriteUniversity(int universityRank, CustomerNode* customerNode);
    void deleteFavouriteUniversity(int universityRank);
    void showFavouriteUniversities();
    void sendFeedback(Customer customer, UniversityNode* university, FeedbackList* feedbackList, UniversityList* universityList);
    void viewAllFeedbacks(Customer customer);
    void viewFeedbackReply(Customer customer, FeedbackNode* feedback);
    void sendFeedbackReply(FeedbackNode* feedback);
    void updateLastLoginTime();
    void setHead(CustomerNode* customer);
    CustomerNode* getCustomer(std::string customerID);
};

#endif