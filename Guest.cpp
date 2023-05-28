#include <iostream>
#include "Guest.hpp"
#include "Customer.hpp"
#include "Shared_Variables.hpp"
#include "University.hpp"

using namespace std;

Guest::Guest()
{

}

Guest::~Guest()
{

}

bool Guest::registerAccount(string username, string email, string password)
{
    //Check if username already exists
	CustomerNode* temp = customerList.getHead();

	while (temp != nullptr)
	{
		if (temp->customer.getUsername() == username)
        {
            cout << "Username already exists!" << endl;
            return false;
        }
        else
        {
            temp = temp->nextCustomer;
        }
	}
    string customerID = customerList.generateCustomerID();

    customerList.insertEnd(customerID, username, email, password);
    return true;
}

void Guest::displayUniversity()
{
    uniList.displayList(uniList.getHead(), -1);
}

void Guest::sortUniversityByName()
{
    uniList.sortByName();
}

void Guest::searchUniversityByName()
{
    //TODO: Read university name from user
}

void Guest::searchUniversityByLocation()
{
    //TODO: Read location from user
}

