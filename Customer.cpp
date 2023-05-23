#include <iostream>
#include <string>
#include "Customer.hpp"
#include "Shared_Variables.hpp"
#include "Utilities.hpp";
#include <sstream>

using namespace std;

Customer::Customer()
{
}

Customer::Customer(string customerID, string password)
{
    this->customerID = customerID;
    this->password = password;
}

Customer::~Customer()
{
}

string Customer::getCustomerID()
{
    return this->customerID;
}

string Customer::getPassword()
{
    return this->password;
}

void Customer::setCustomerID(string customerID)
{
    this->customerID = customerID;
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

CustomerNode* CustomerList::createCustomerNode(string customerID, string password)
{
    CustomerNode * newNode = new CustomerNode;

    newNode->customer = Customer(customerID, password);
    newNode->favourites = nullptr;
    newNode->nextCustomer = nullptr;

    return newNode;
}

void CustomerList::insertEnd(string customerID, string password)
{
    CustomerNode* newNode = createCustomerNode(customerID, password);

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

void CustomerList::deleteCustomer()
{
}

void CustomerList::displayList()
{
	CustomerNode* temp = head;

	while (temp != nullptr)
	{
		cout << temp->customer.getCustomerID() << " - " << temp->customer.getPassword() << endl;
		temp = temp->nextCustomer;
	}

	cout << endl << "List is ended here!" << endl << endl;
}

CustomerNode* CustomerList::getHead()
{
    return head;
}

CustomerNode* CustomerList::getTail()
{
    return tail;
}

bool CustomerList::login(string customerID, string password)
{
    CustomerNode* temp = head;

    while (temp != nullptr)
    {
        if (temp->customer.getCustomerID() == customerID && temp->customer.getPassword() == password)
        {
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
    loginCustomer.setPassword("");
    cout << "Logout successful!" << endl;
}

void CustomerList::displayUniversity()
{
}

void CustomerList::sortUniversityDescending()
{
}

void CustomerList::sortUniversityByRank()
{
}

void CustomerList::searchUniversity()
{
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

// void addUniversity(CustomerNode* customer, string universityName) {
//     UniversityNode* newUniversity = new UniversityNode;
//     newUniversity->name = universityName;
//     newUniversity->next = nullptr;
//     if (customer->universities == nullptr) {
//         customer->universities = newUniversity;
//     } else {
//         UniversityNode* curr = customer->universities;
//         while (curr->next != nullptr) {
//             curr = curr->next;
//         }
//         curr->next = newUniversity;
//     }
// }

void CustomerList::showFavouriteUniversities()
{
}

void CustomerList::sendFeedback(Customer customer, UniversityNode* university, FeedbackList* feedbackList, UniversityList* universityList)
{
    string feedbackContent = "";
    cin.ignore();
    cout << "Please enter your feedback: ";
    getline(cin, feedbackContent);

    time_t rawTime = time(nullptr);
    struct tm* timeInfo = localtime(&rawTime);
    feedbackList->insertIntoSortedList(customer.getCustomerID(), university, feedbackContent, *timeInfo);
    cout << "Thank you for your feedback!" << endl;
    system("pause");
}

void CustomerList::viewAllFeedbacks(Customer customer) {
    FeedbackList customerFeedbackList;
    FeedbackNode* current = feedbackList.getHead();
    while (current != nullptr) {
        if (current->customerID == customer.getCustomerID()) {
            customerFeedbackList.insertIntoSortedList(current->customerID, current->university, current->feedbackContent, current->timePosted);
            cout << customerFeedbackList.getSize() << ". " << current->university->institutionName << " - " << current->feedbackContent << endl;
            
            char formattedTime[50];
            strftime(formattedTime, sizeof(formattedTime), "%d-%m-%Y %a %H:%M:%S", &current->timePosted);
            cout << "   Last Updated: " << formattedTime << endl;
        }
        current = current->nextFeedback;
    }
    cout << "Please select a feedback to view (Press 0 to go back): ";
    int viewFeedbackOption = readInteger(0, customerFeedbackList.getSize());
    if (viewFeedbackOption == 0) {
        return;
    }
    viewFeedbackReply(customer, customerFeedbackList.getFeedbackNode(viewFeedbackOption, &customerFeedbackList));
}

void CustomerList::viewFeedbackReply(Customer customer, FeedbackNode* feedback)
{
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
    feedbackList.addReply(replyContent, false, *timeInfo, feedback);
    cout << "Your reply has been sent!" << endl;
    system("pause");
}
