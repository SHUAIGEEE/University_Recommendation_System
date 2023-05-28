#include <iostream>
#include "FileIO.hpp"
#include "Guest.hpp"
#include "Customer.hpp"
#include "Admin.hpp"
#include "University.hpp"
#include "Feedback.hpp"
#include "Utilities.hpp"
#include "Shared_Variables.hpp"
#include <Windows.h>

using namespace std;

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    readFile();

    mainMenu();
    exitPage();

    writeFile();
    return 0;
}