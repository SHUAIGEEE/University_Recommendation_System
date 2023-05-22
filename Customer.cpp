#include <iostream>
#include <string>
#include "Customer.hpp"
#include "Shared_Variables.hpp"

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

void CustomerList::viewFeedbackReply(Customer customer)
{
    FeedbackList customerFeedbacks;
    FeedbackNode* current = feedbackList.getHead();
    while (current != nullptr) {
        if (current->customerID == customer.getCustomerID()) {
            customerFeedbacks.insertIntoSortedList(current->customerID, current->university, current->feedbackContent, current->timePosted);
        }
        current = current->nextFeedback;
    }

    current = customerFeedbacks.getHead();
    while (current != nullptr) {
        cout << current->university->institutionName << endl;
        cout << current->customerID << endl;
        cout << current->feedbackContent << endl;
        current = current->nextFeedback;
        //ReplyNode* current = current->replies;
    }
    /*while (current != nullptr) {
        cout << current->content << endl;
    }*/
}

void CustomerList::sendFeedbackReply()
{
}
