#include <iostream>
#include <string>
#include "Admin.hpp"

using namespace std;

Admin::Admin()
{
    this->adminName = "cxk";
    this->password = "a";
}

Admin::~Admin()
{
}

bool Admin::login(string adminName, string password)
{
    if (adminName == this->adminName && password == this->password) return true;
    else return false;
}

void Admin::logout()
{
    cout << "Logout successful!" << endl;
}

void Admin::displayCustomerDetails()
{
}

void Admin::modifyCustomerDetails(string customerID)
{
}

void Admin::deleteCustomerAccount(string customerID)
{
}

void Admin::viewCustomerFeedback()
{
}

void Admin::viewNextFeedback()
{
}

void Admin::viewPreviousFeedback()
{
}

void Admin::replyToFeedback()
{
}

void Admin::generateReport()
{

}
