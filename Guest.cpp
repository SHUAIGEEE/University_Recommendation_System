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
    uniList.displayList(uniList.getHead(), -1, "Guest");
}

void Guest::sortUniversityByName()
{
    uniList.sortByName();
    uniList.displayList(uniList.getHead(), -1, "Guest");
}

void Guest::searchUniversityByName()
{
    cin.ignore();
    uniList.searchUniversities(FieldName::INSTITUTION_NAME, "Guest");
}

void Guest::searchUniversityByLocation()
{
    cin.ignore();
    uniList.searchUniversities(FieldName::LOCATION, "Guest");
}

