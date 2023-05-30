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

Customer::Customer(string customerID, string username, string email, string password, struct tm lastLoginTime)
{
    this->customerID = customerID;
    this->username = username;
    this->email = email;
    this->password = password;
    this->lastLoginTime = lastLoginTime;
}

Customer::~Customer()
{
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

CustomerList::CustomerList()
{
}

CustomerList::~CustomerList()
{
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

string CustomerList::generateCustomerID()
{
    int size = customerList.getSize();
    if (size < 1000) return "C00" + to_string(size + 1);
    else if (size < 100) return "C0" + to_string(size + 1);
    else return "C" + to_string(size + 1);
}

void CustomerList::deleteCustomer()
{
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

CustomerNode* CustomerList::getHead()
{
    return head;
}

CustomerNode* CustomerList::getTail()
{
    return tail;
}

int CustomerList::getSize()
{
    return size;
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

void CustomerList::displayUniversity()
{
    uniList.displayList(uniList.getHead(), -1, "Customer");
}

void CustomerList::sortUniversities()
{
    uniList.sortUniversities(getSortField());
    uniList.displayList(uniList.getHead(), -1, "Customer"); // can change to display sorted list
}

void CustomerList::searchUniversities()
{
    uniList.searchUniversities(getSearchField(), "Customer");

}

FavouriteNode *CustomerList::createFavouriteNode(int universityRank)
{
    return nullptr;
}

void CustomerList::saveFavouriteUniversity(int universityRank)
{
}

void CustomerList::deleteFavouriteUniversity(int universityRank)
{
}

void CustomerList::showFavouriteUniversities()
{
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

void CustomerList::viewAllFeedbacks(Customer customer) {
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
    viewFeedbackReply(customer, feedbackList.getFeedbackNode(feedbackIndeces[viewFeedbackOption - 1], &feedbackList));
}

void CustomerList::viewFeedbackReply(Customer customer, FeedbackNode* feedback)
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
        viewFeedbackReply(customer, feedback);
        break;
    case 2:
        if (feedback->prevFeedback != NULL) {
            viewFeedbackReply(customer, feedback->prevFeedback);
            break;
        }
        else {
            cout << endl << "This is already the first feedback!" << endl;
            system("pause");
            viewFeedbackReply(customer, feedback);
            break;
        }
    case 3:
        if (feedback->nextFeedback != NULL) {
            viewFeedbackReply(customer, feedback->nextFeedback);
            break;
        }
        else {
            cout << endl << "This is already the last feedback!" << endl;
            system("pause");
            viewFeedbackReply(customer, feedback);
            break;
        }
    case 4:
        viewAllFeedbacks(customer);
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

void CustomerList::setHead(CustomerNode* customer)
{
    if (customer == nullptr) {
        return;
    }

    head = customer;
}

