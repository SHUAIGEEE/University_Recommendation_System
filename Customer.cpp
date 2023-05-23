#include <iostream>
#include <string>
#include "Customer.hpp"
#include "Shared_Variables.hpp"
#include "Utilities.hpp";

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
    feedbackList->insertIntoSortedList(customer.getCustomerID(), university, feedbackContent, rawTime);
    cout << "Thank you for your feedback!" << endl;
    system("pause");
}

void CustomerList::viewFeedback(Customer customer) {
    FeedbackList customerFeedbacks;
    FeedbackNode* current = feedbackList.getHead();
    while (current != nullptr) {
        if (current->customerID == customer.getCustomerID()) {
            customerFeedbacks.insertIntoSortedList(current->customerID, current->university, current->feedbackContent, current->timePosted);
            cout << customerFeedbacks.getSize() << ". " << current->university->institutionName << " - " << current->feedbackContent << endl;
        }
        current = current->nextFeedback;
    }
    cout << "Please select a feedback to view (Press 0 to go back): ";
    int viewFeedbackOption = readInteger(0, customerFeedbacks.getSize());
    cout << "option is : " << viewFeedbackOption << endl;
    if (viewFeedbackOption == 0) {
        return;
    }
    viewFeedbackReply(customer, customerFeedbacks.getFeedbackNode(viewFeedbackOption, &feedbackList));
}

void CustomerList::viewFeedbackReply(Customer customer, FeedbackNode* feedback)
{
    cout << feedback->university->institutionName << endl;
    cout << feedback->customerID << endl;
    cout << feedback->feedbackContent << endl;
    ReplyNode* currentReplies = feedback->replies;
    while (currentReplies != nullptr) {
        cout << endl << currentReplies->content << endl;
        currentReplies = currentReplies->nextReply;
    }

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
        break;
    case 2:
        if (feedback->prevFeedback != NULL) {
            viewFeedbackReply(customer, feedback->prevFeedback);
            break;
        }
        else {
            cout << "This is already the first feedback!" << endl;
            viewFeedbackReply(customer, feedback);
            break;
        }
    case 3:
        if (feedback->nextFeedback != NULL) {
            viewFeedbackReply(customer, feedback->nextFeedback);
            break;
        }
        else {
            cout << "This is already the last feedback!" << endl;
            viewFeedbackReply(customer, feedback);
            break;
        }
    case 4:
        viewFeedback(customer);
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
    feedbackList.addReply(replyContent, false, rawTime, feedback);
    cout << "Your reply has been sent!" << endl;
}
