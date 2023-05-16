#include <iostream>
#include "Guest.hpp"
#include "Customer.hpp"
#include "Shared_Variables.hpp"

using namespace std;

Guest::Guest()
{

}

Guest::~Guest()
{

}

bool Guest::registerAccount(string memberID, string password)
{
    //Check if memberID already exists
	CustomerNode* temp = customerList.getHead();

	while (temp != nullptr)
	{
		if (temp->customer.getCustomerID() == memberID)
        {
            cout << "Member ID already exists!" << endl;
            return false;
        }
        else
        {
            temp = temp->nextCustomer;
        }
	}
    customerList.insertEnd(memberID, password);
    return true;
}

void Guest::displayUniversity()
{

}

void Guest::sortUniversityByName()
{

}

void Guest::searchUniversityByName()
{

}

void Guest::searchUniversityByLocation()
{

}

