#ifndef Customer_
#define Customer_

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
public:
    Customer();
    Customer(std::string customerID, std::string username, std::string email , std::string password);
    ~Customer();
    std::string getCustomerID();
    std::string getUsername();
    std::string getEmail();
    std::string getPassword();
    void setCustomerID(std::string customerID);
    void setUsername(std::string username);
    void setEmail(std::string email);
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
    CustomerNode* createCustomerNode(std::string customerID, std::string username, std::string email, std::string password);
    void insertEnd(std::string customerID, std::string username, std::string email, std::string password);
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
    void searchUniversity();
    FavouriteNode* createFavouriteNode(int universityRank);
    void saveFavouriteUniversity(int universityRank);
    void deleteFavouriteUniversity(int universityRank);
    void showFavouriteUniversities();
    void sendFeedback();
    void viewFeedbackReply();
    void sendFeedbackReply();
};

#endif