#include <iostream>
#include <string>
#include "Customer.hpp"
#include "Utilities.hpp"
#include "Shared_Variables.hpp"
#include "University.hpp"
#include "Utilities.hpp"
#include <sstream>
#include <ctime>
#include <iomanip>


using namespace std;

Customer::Customer()
{
}

Customer::~Customer()
{
}

Customer::Customer(string customerID, string username, string email, string password, struct tm lastLoginTime)
{
    this->customerID = customerID;
    this->username = username;
    this->email = email;
    this->password = password;
    this->lastLoginTime = lastLoginTime;
}

string Customer::getCustomerID()
{
    return this->customerID;
}

string Customer::getUsername()
{
    return this->username;
}

string Customer::getEmail()
{
    return this->email;
}

string Customer::getPassword()
{
    return this->password;
}

struct tm Customer::getLastLoginTime()
{
    return this->lastLoginTime;
}

void Customer::setCustomerID(string customerID)
{
    this->customerID = customerID;
}

void Customer::setUsername(string username)
{
    this->username = username;
}

void Customer::setEmail(string email)
{
    this->email = email;
}

void Customer::setPassword(string password)
{
    this->password = password;
}

void Customer::setLoginTime(struct tm* timeInfo) 
{
    this->lastLoginTime = *timeInfo;
}

CustomerList::CustomerList()
{
}

CustomerList::~CustomerList()
{
}

string CustomerList::generateCustomerID()
{
    int size = customerList.getSize();
    if (size < 1000) return "C00" + to_string(size + 1);
    else if (size < 100) return "C0" + to_string(size + 1);
    else return "C" + to_string(size + 1);
}

CustomerNode* CustomerList::createCustomerNode(string customerID, string username, string email, string password, struct tm lastLoginTime)
{
    CustomerNode * newNode = new CustomerNode;

    newNode->customer = Customer(customerID, username, email, password, lastLoginTime);
    newNode->favourites = nullptr;
    newNode->nextCustomer = nullptr;

    return newNode;
}

void CustomerList::insertEnd(string customerID, string username, string email, string password, struct tm lastLoginTime)
{
    CustomerNode* newNode = createCustomerNode(customerID, username, email, password, lastLoginTime);

    if (head == nullptr)
    {
        head = newNode;
    }
    else 
    {
        CustomerNode* current = head; 
        
        while (current->nextCustomer != nullptr) 
        {
            current = current->nextCustomer;
        }
        
        current->nextCustomer = newNode;
    }
    size++;
}

bool CustomerList::login(string username, string password)
{
    CustomerNode* temp = head;

    while (temp != nullptr)
    {
        if (temp->customer.getUsername() == username && temp->customer.getPassword() == password)
        {
            loginCustomer.setUsername(username);
            loginCustomer.setPassword(password);
            loginCustomer.setCustomerID(temp->customer.getCustomerID());
            loginCustomer.setEmail(temp->customer.getEmail());

            time_t rawTime = time(nullptr);
            struct tm* timeInfo = localtime(&rawTime);
            loginCustomer.setLoginTime(timeInfo);
            temp->customer.setLoginTime(timeInfo);

            return true;
        }
        else
        {
            temp = temp->nextCustomer;
        }
    }
    return false;
}

void CustomerList::logout()
{
    loginCustomer.setCustomerID("");
    loginCustomer.setUsername("");
    loginCustomer.setEmail("");
    loginCustomer.setPassword("");
    cout << "Logout successful!" << endl;
}

void CustomerList::displayList()
{
    CustomerNode* temp = head;
    cout << string(105, '-') << endl;

    cout << std::left << setw(18) << "Customer ID" << setw(20) << "Username"
        << setw(30) << "Email" << setw(20) << "Password" << setw(15) << "Last Logged in" << endl;

    cout << string(105, '-') << endl;

    while (temp != nullptr)
    {
        struct tm loginTime = temp->customer.getLastLoginTime();
        char formattedTime[50];
        strftime(formattedTime, sizeof(formattedTime), "%d-%m-%Y", &loginTime);
        cout << std::left << setw(18) << temp->customer.getCustomerID() << setw(20) << temp->customer.getUsername()
            << setw(30) << temp->customer.getEmail() << setw(20) << temp->customer.getPassword() << setw(15) << formattedTime << endl;
        temp = temp->nextCustomer;
    }

    cout << endl << "List ends here!" << endl << endl;
}

void CustomerList::displayUniversity()
{
    uniList.displayList(uniList.getHead(), -1, "Customer");
}

void CustomerList::sortUniversities()
{
    uniList.sortUniversities(getSortField());
    uniList.displayList(uniList.getHead(), -1, "Customer");
}

void CustomerList::searchUniversities()
{
    uniList.searchUniversities(getSearchField(), "Customer");
}

FavouriteNode *CustomerList::createFavouriteNode(int universityRank)
{
    FavouriteNode* newNode = new FavouriteNode;

    newNode->universityRank = universityRank;
    newNode->nextFavourite = nullptr;

    return newNode;
}

void CustomerList::insertFavouriteEnd(int universityRank, CustomerNode* customer) {
    FavouriteNode* newNode = createFavouriteNode(universityRank);

    if (customer->favourites == nullptr)
    {
        customer->favourites = newNode;
    }
    else {
        FavouriteNode* current = customer->favourites->nextFavourite;
        FavouriteNode* prev = customer->favourites;

        while (current != nullptr)
        {
            prev = current;
            current = current->nextFavourite;
        }
        prev->nextFavourite = newNode;
    }
}

void CustomerList::saveFavouriteUniversity(int universityRank, CustomerNode* customer)
{
    customerList.insertFavouriteEnd(universityRank, customer);

    cout << endl  << uniList.getUniversity(universityRank)->institutionName << " saved as favourite!" << endl << endl;
    system("pause");
}

void CustomerList::deleteFavouriteUniversity(int universityRank)
{
    CustomerNode* customer = customerList.getCustomer(loginCustomer.getCustomerID());
    FavouriteNode* current = customer->favourites;
    FavouriteNode* prev = nullptr;
    if (current == nullptr) {
        cout << "No university to delete!" << endl;
        system("pause");
        return;
    }

    if (current->universityRank == universityRank) {
        customer->favourites = current->nextFavourite;
        cout << endl << "Removed " << uniList.getUniversity(current->universityRank)->institutionName << " from favourite list!" << endl << endl;
        delete current;
        system("pause");
        return;
    }
    else {
        while (current->nextFavourite != nullptr) {
            prev = current;
            current = current->nextFavourite;
            if (current->universityRank == universityRank) {
                prev->nextFavourite = current->nextFavourite;
                cout << endl << "Removed " << uniList.getUniversity(current->universityRank)->institutionName << " from favourite list!" << endl << endl;
                delete current;
                system("pause");
                return;
            }
        }
    }
    cout << "Cannot find university to delete!" << endl;
    system("pause");
}

void CustomerList::displayFavouriteUniversities()
{
    CustomerNode* customer = customerList.getCustomer(loginCustomer.getCustomerID());
    FavouriteNode* current = customer->favourites;
    UniversityNode* university;

    if (current == nullptr) {
        cout << endl << "No favourite universities!" << endl << endl;
        system("pause");
        return;
    }

    while (current != nullptr) {
        university = uniList.getUniversity(current->universityRank);
        tempUniversityList.insertEnd(to_string(university->rank), to_string(university->arScore), to_string(university->erScore),
            to_string(university->fsrScore), to_string(university->cpfScore), to_string(university->ifrScore), to_string(university->isrScore),
            to_string(university->irnScore), to_string(university->gerScore), to_string(university->scoreScaled), university->institutionName,
            university->locationCode, university->location, university->arRank, university->erRank, university->fsrRank, university->cpfRank, 
            university->ifrRank, university->isrRank, university->irnRank, university->gerRank);
        current = current->nextFavourite;
    }

    tempUniversityList.displayList(tempUniversityList.getHead(), -1, "Favourite");
    uniList.clearTempUniversityList();
}

void CustomerList::sendFeedback(Customer customer, UniversityNode* university, FeedbackList* feedbackList, UniversityList* universityList)
{
    string feedbackContent = "";
    cin.ignore();
    cout << endl;
    cout << "Please enter your feedback: ";
    getline(cin, feedbackContent);

    time_t rawTime = time(nullptr);
    struct tm* timeInfo = localtime(&rawTime);
    feedbackList->insertIntoSortedList(customer.getCustomerID(), university, feedbackContent, *timeInfo);
    cout << "Thank you for your feedback!" << endl;
    system("pause");
}

void CustomerList::displayAllFeedbacks(Customer customer) {
    system("cls");
    cout << "View Feedbacks and Replies" << endl << endl;
    FeedbackNode* current = feedbackList.getHead();
    int* feedbackIndeces = new int(feedbackList.getSize());
    int index = 0;
    int loopIndex = 1;
    while (current != nullptr) {
        if (current->customerID == customer.getCustomerID()) {
            feedbackIndeces[index] = loopIndex;
            cout << index + 1 << ". " << current->university->institutionName << " - " << current->feedbackContent << endl;
            index++;
            char formattedTime[50];
            strftime(formattedTime, sizeof(formattedTime), "%d-%m-%Y %a %H:%M:%S", &current->timePosted);
            cout << "   Last Updated: " << formattedTime << endl;
        }
        current = current->nextFeedback;
        loopIndex++;
    }
    cout << endl;
    cout << "Please select a feedback to view (Press 0 to go back): ";
    int viewFeedbackOption = readInteger(0, index);
    if (viewFeedbackOption == 0) {
        return;
    }
    displayFeedbackReply(customer, feedbackList.getFeedbackNode(feedbackIndeces[viewFeedbackOption - 1], &feedbackList));
}

void CustomerList::displayFeedbackReply(Customer customer, FeedbackNode* feedback)
{
    system("cls");
    cout << "University Name: " << feedback->university->institutionName << endl;
    char formattedTime[50];
    strftime(formattedTime, sizeof(formattedTime), "%d-%m-%Y %a %H:%M:%S", &feedback->timePosted);
    cout << "Last Updated: " << formattedTime << endl;
    cout << "Feedback: " << feedback->feedbackContent << endl;
    if (feedback->replies != nullptr) {
        cout << "Replies: " << endl;
        ReplyNode* currentReplies = feedback->replies;
        while (currentReplies != nullptr) {
            if (currentReplies->isAdmin) {
                cout << "Admin: " << currentReplies->content << endl;
            }
            else {
                cout << feedback->customerID << ": " << currentReplies->content << endl;
            }
            currentReplies = currentReplies->nextReply;
        }
    }

    cout << endl;
    cout << "1. Write a Reply" << endl;
    cout << "2. View Previous Feedback" << endl;
    cout << "3. View Next Feedback" << endl;
    cout << "4. Back" << endl;
    cout << "Please select an option: ";
    int viewFeedbackOption = readInteger(1, 4);
    switch (viewFeedbackOption)
    {
    case 1:
        sendFeedbackReply(feedback);
        displayFeedbackReply(customer, feedback);
        break;
    case 2:
        if (feedback->prevFeedback != NULL) {
            displayFeedbackReply(customer, feedback->prevFeedback);
            break;
        }
        else {
            cout << endl << "This is already the first feedback!" << endl;
            system("pause");
            displayFeedbackReply(customer, feedback);
            break;
        }
    case 3:
        if (feedback->nextFeedback != NULL) {
            displayFeedbackReply(customer, feedback->nextFeedback);
            break;
        }
        else {
            cout << endl << "This is already the last feedback!" << endl;
            system("pause");
            displayFeedbackReply(customer, feedback);
            break;
        }
    case 4:
        displayAllFeedbacks(customer);
    default:
        break;
    }
}

void CustomerList::sendFeedbackReply(FeedbackNode* feedback)
{
    string replyContent = "";
    cin.ignore();
    cout << "Please enter your reply: ";
    getline(cin, replyContent);

    time_t rawTime = time(nullptr);
    struct tm* timeInfo = localtime(&rawTime);
    feedbackList.addReply(replyContent, false, *timeInfo, feedback, false);
    cout << "Your reply has been sent!" << endl;
    system("pause");
}

void CustomerList::updateLastLoginTime()
{
    time_t lastLoginTime = time(nullptr);
}

int CustomerList::getSize()
{
    return size;
}

CustomerNode* CustomerList::getHead()
{
    return head;
}

CustomerNode* CustomerList::getTail()
{
    return tail;
}

CustomerNode* CustomerList::getCustomer(string customerID) {
    CustomerNode* current = customerList.getHead();
    while (current != nullptr) {
        if (current->customer.getCustomerID() == customerID) {
            return current;
        }
        current = current->nextCustomer;
    }
    return nullptr;
}

void CustomerList::setHead(CustomerNode* customer)
{
    if (customer == nullptr) {
        return;
    }

    head = customer;
}

