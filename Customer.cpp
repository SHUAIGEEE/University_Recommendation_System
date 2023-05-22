#include <iostream>
#include <string>
#include "Customer.hpp"
#include "Shared_Variables.hpp"

using namespace std;

Customer::Customer()
{
}

Customer::Customer(string customerID, string username, string email, string password)
{
    this->customerID = customerID;
    this->username = username;
    this->email = email;
    this->password = password;
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

CustomerNode* CustomerList::createCustomerNode(string customerID, string username, string email, string password)
{
    CustomerNode * newNode = new CustomerNode;

    newNode->customer = Customer(customerID, username, email, password);
    newNode->favourites = nullptr;
    newNode->nextCustomer = nullptr;

    return newNode;
}

void CustomerList::insertEnd(string customerID, string username, string email, string password)
{
    CustomerNode* newNode = createCustomerNode(customerID, username, email, password);

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

	while (temp != nullptr)
	{
		cout << temp->customer.getCustomerID() << " - " << temp->customer.getUsername()
        << " - " << temp->customer.getEmail() << " - " << temp->customer.getPassword() << endl;
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

void CustomerList::sendFeedback()
{
}

void CustomerList::viewFeedbackReply()
{
}

void CustomerList::sendFeedbackReply()
{
}
