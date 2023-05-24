#ifndef Customer_
#define Customer_
#include "University.hpp"
#include "Feedback.hpp"
#include "Customer.hpp"

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
    std::string password;
public:
    Customer();
    Customer(std::string customerID, std::string password);
    ~Customer();
    std::string getCustomerID();
    std::string getPassword();
    void setCustomerID(std::string customerID);
    void setPassword(std::string password);
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
    CustomerNode* createCustomerNode(std::string customerID, std::string password);
    void insertEnd(std::string customerID, std::string password);
    void deleteCustomer();
    void displayList();
    CustomerNode* getHead();
    CustomerNode* getTail();
    bool login(std::string customerID, std::string password);
    void logout();
    void displayUniversity();
    void sortUniversityDescending();
    void sortUniversityByRank();
    void searchUniversity();
    FavouriteNode* createFavouriteNode(int universityRank);
    void saveFavouriteUniversity(int universityRank);
    void deleteFavouriteUniversity(int universityRank);
    void showFavouriteUniversities();
    void sendFeedback(Customer customer, UniversityNode* university, FeedbackList* feedbackList, UniversityList* universityList);
    void viewAllFeedbacks(Customer customer);
    void viewFeedbackReply(Customer customer, FeedbackNode* feedback);
    void sendFeedbackReply(FeedbackNode* feedback);
};

#endif