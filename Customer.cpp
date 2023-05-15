#include <iostream>
#include <string>
#include "Customer.hpp"

using namespace std;

// Customer::Customer(std::string customerID, std::string password)
// {
//     this->customerID = customerID;
//     this->password = password;
// }

// Customer::~Customer()
// {
// }

CustomerList::CustomerList()
{
}

CustomerList::~CustomerList()
{
}

CustomerNode* CustomerList::createCustomerNode(string customerID, string password)
{
    CustomerNode * newNode = new CustomerNode;

    newNode->customerID = customerID;
    newNode->password = password;
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

	while (temp != NULL)
	{
		cout << temp->customerID << " - " << temp->password << endl;
		temp = temp->nextCustomer;
	}

	cout << endl << "List is ended here!" << endl << endl;
}

void CustomerList::login(string customerID, string password)
{
}

void CustomerList::logout()
{
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
