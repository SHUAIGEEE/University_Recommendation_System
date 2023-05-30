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

bool Guest::registerAccount(string username, string email, string password, time_t lastLoginTime)
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
    time_t rawTime = time(nullptr);
    struct tm* loginTime = localtime(&rawTime);
    customerList.insertEnd(customerID, username, email, password, *loginTime);
    return true;
}

void Guest::displayUniversity()
{
    uniList.displayList();
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

