#include <iostream>
#include <Windows.h>
#include "Shared_Variables.hpp"
#include "FileIO.hpp"
#include "Guest.hpp"
#include "Customer.hpp"
#include "Admin.hpp"
#include "University.hpp"
#include "Feedback.hpp"
#include "Utilities.hpp"

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