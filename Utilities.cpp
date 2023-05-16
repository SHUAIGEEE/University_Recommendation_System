#include <iostream>
#include <string>
#include <limits>
#include "Utilities.hpp"
#include "Admin.hpp"
#include "Customer.hpp"
#include "Guest.hpp"
#include "University.hpp"
#include "Feedback.hpp"
#include "FileIO.hpp"
#include "Shared_Variables.hpp"
// #include <iomanip>

using namespace std;

const int MAIN_MENU_LENGTH = 166;
const int LOGIN_MENU_TITLE_LENGTH = 54;
const int ADMIN_MENU_TITLE_LENGTH = 58;
const int CUSTOMER_MENU_TITLE_LENGTH = 73;
const int GUEST_MENU_TITLE_LENGTH = 54;
const int THANK_YOU_LENGTH = 49;

Admin admin;
Guest guest;

void mainMenu()
{
    while (true)
    {
        system("cls");

        cout << string(MAIN_MENU_LENGTH, '-') << endl;
        cout << " _   _       _                    _ _          ______                                                  _       _   _               _____           _                 " << endl;
        cout << "| | | |     (_)                  (_) |         | ___ \\                                                | |     | | (_)             /  ___|         | |                " << endl;
        cout << "| | | |_ __  ___   _____ _ __ ___ _| |_ _   _  | |_/ /___  ___ ___  _ __ ___  _ __ ___   ___ _ __   __| | __ _| |_ _  ___  _ __   \\ `--. _   _ ___| |_ ___ _ __ ___  " << endl;
        cout << "| | | | '_ \\| \\ \\ / / _ \\ '__/ __| | __| | | | |    // _ \\/ __/ _ \\| '_ ` _ \\| '_ ` _ \\ / _ \\ '_ \\ / _` |/ _` | __| |/ _ \\| '_ \\   `--. \\ | | / __| __/ _ \\ '_ ` _ \\ " << endl;
        cout << "| |_| | | | | |\\ V /  __/ |  \\__ \\ | |_| |_| | | |\\ \\  __/ (_| (_) | | | | | | | | | | |  __/ | | | (_| | (_| | |_| | (_) | | | | /\\__/ / |_| \\__ \\ ||  __/ | | | | |" << endl;
        cout << " \\___/|_| |_|_| \\_/ \\___|_|  |___/_|\\__|\\__, | \\_| \\_\\___|\\___\\___/|_| |_| |_|_| |_| |_|\\___|_| |_|\\__,_|\\__,_|\\__|_|\\___/|_| |_| \\____/ \\__, |___/\\__\\___|_| |_| |_|" << endl;
        cout << "                                         __/ |                                                                                            __/ |                      " << endl;
        cout << "                                        |___/                                                                                            |___/                       " << endl;
        cout << string(MAIN_MENU_LENGTH, '-') << endl;

        system("pause");

        cout << "1. Login" << endl;
        cout << "2. Continue as Guest" << endl;
        cout << "3. Exit" << endl;
        cout << "Please select an option: ";

        int option = readInteger(1, 3);

        if (option == 1)
        {
            loginMenu();
        }
        else if (option == 2)
        {
            guestMenu();
        }
        else if (option == 3)
        {
            break;
        }
    }
}

void loginMenu()
{
    while (true)
    {
        cout << endl << endl;
        cout << string(LOGIN_MENU_TITLE_LENGTH, '-') << endl;
        cout << " _                 _        ___  ___                 " << endl;
        cout << "| |               (_)       |  \\/  |                 " << endl;
        cout << "| |     ___   __ _ _ _ __   | .  . | ___ _ __  _   _ " << endl;
        cout << "| |    / _ \\ / _` | | '_ \\  | |\\/| |/ _ \\ '_ \\| | | |" << endl;
        cout << "| |___| (_) | (_| | | | | | | |  | |  __/ | | | |_| |" << endl;
        cout << "\\_____/\\___/ \\__, |_|_| |_| \\_|  |_/\\___|_| |_|\\__,_|" << endl;
        cout << "              __/ |                                  " << endl;
        cout << "             |___/                                   " << endl;
        cout << string(LOGIN_MENU_TITLE_LENGTH, '-') << endl;

        cout << "1. Login as Admin" << endl;
        cout << "2. Login as Customer" << endl;
        cout << "3. Back" << endl;
        cout << "Please select an option: ";

        int option = readInteger(1, 3);

        if (option == 1)
        {
            adminLogin();
        }
        else if (option == 2)
        {
            customerLogin();
        }
        else if (option == 3)
        {
            break;
        }
    }
}

void adminLogin()
{
    string adminID;
    string password;

    cout << "Admin ID: ";
    cin >> adminID;
    cout << "Password: ";
    cin >> password;

    if (admin.login(adminID, password))
    {
        cout << "Login successful!" << endl;
        system("pause");
        adminMenu();
    }
    else
    {
        cout << "Login failed!" << endl;
        system("pause");
    }
}

void adminMenu()
{
    while (true)
    {
        cout << endl << endl;
        cout << string(ADMIN_MENU_TITLE_LENGTH, '-') << endl;
        cout << "  ___      _           _        ___  ___                 " << endl;
        cout << " / _ \\    | |         (_)       |  \\/  |                 " << endl;
        cout << "/ /_\\ \\ __| |_ __ ___  _ _ __   | .  . | ___ _ __  _   _ " << endl;
        cout << "|  _  |/ _` | '_ ` _ \\| | '_ \\  | |\\/| |/ _ \\ '_ \\| | | |" << endl;
        cout << "| | | | (_| | | | | | | | | | | | |  | |  __/ | | | |_| |" << endl;
        cout << "\\_| |_/\\__,_|_| |_| |_|_|_| |_| \\_|  |_/\\___|_| |_|\\__,_|" << endl;
        cout << string(ADMIN_MENU_TITLE_LENGTH, '-') << endl;
        
        cout << "1. Display Customer Details" << endl;
        cout << "2. Modify Customer Details" << endl;
        cout << "3. Delete Customer Account" << endl;
        cout << "4. View Customer Feedback" << endl;
        cout << "5. Generate Report" << endl;
        cout << "6. Logout" << endl;
        cout << "Please select an option: ";

        int option = readInteger(1, 6);

        if (option == 1)
        {
            cout << "Display Customer Details" << endl;
            // admin.displayCustomerDetails();
        }
        else if (option == 2)
        {
            cout << "Modify Customer Details" << endl;
            // admin.modifyCustomerDetails();
        }
        else if (option == 3)
        {
            cout << "Delete Customer Account" << endl;
            // admin.deleteCustomerAccount();
        }
        else if (option == 4)
        {
            cout << "View Customer Feedback" << endl;
            // admin.viewCustomerFeedback();
        }
        else if (option == 5)
        {
            cout << "Generate Report" << endl;
            // admin.generateReport();
        }
        else if (option == 6)
        {
            admin.logout();
            system("pause");
            break;
        }
    }
}

void customerLogin()
{
    cout << "Customer Login" << endl;
    //TODO: Customer authentication
    customerMenu();
}

void customerMenu()
{
    while (true)
    {
        cout << endl << endl;
        cout << string(CUSTOMER_MENU_TITLE_LENGTH, '-') << endl;
        cout << " _____           _                             ___  ___                 " << endl;
        cout << "/  __ \\         | |                            |  \\/  |                 " << endl;
        cout << "| /  \\/_   _ ___| |_ ___  _ __ ___   ___ _ __  | .  . | ___ _ __  _   _ " << endl;
        cout << "| |   | | | / __| __/ _ \\| '_ ` _ \\ / _ \\ '__| | |\\/| |/ _ \\ '_ \\| | | |" << endl;
        cout << "| \\__/\\ |_| \\__ \\ || (_) | | | | | |  __/ |    | |  | |  __/ | | | |_| |" << endl;
        cout << "\\____/\\__,_|___/\\__\\___/|_| |_| |_|\\___|_|    \\_|  |_/\\___|_| |_|\\__,_|" << endl;
        cout << string(CUSTOMER_MENU_TITLE_LENGTH, '-') << endl;

        cout << "1. Display All Universities" << endl;
        cout << "2. Sort Universities" << endl;
        cout << "3. Search Universities" << endl;
        cout << "4. View Favourite Universities" << endl;
        cout << "5. View Feedbacks and Replies" << endl;
        cout << "6. Logout" << endl;
        cout << "Please select an option: ";

        int option = readInteger(1, 10);

        if (option == 1)
        {
            cout << "All universities" << endl;
            // uniList.displayList();
        }
        else if (option == 2)
        {
            cout << "Sort Universities" << endl;
            // uniList.sortAscendingByName();
        }
        else if (option == 3)
        {
            cout << "Search Universities" << endl;
            // uniList.searchByName();
        }
        else if (option == 4)
        {
            cout << "View Favourite Universities" << endl;
            // favourite也要可以send feedback
            // customer.showFavouriteUniversities();
        }
        else if (option == 5)
        {
            cout << "View Feedbacks and Replies" << endl;
            // customer.viewFeedbackReply();
        }
        else if (option == 6)
        {
            break;
        }
    }
}

void guestMenu()
{
    while (true)
    {
        cout << endl << endl;
        cout << string(GUEST_MENU_TITLE_LENGTH, '-') << endl;
        cout << " _____                 _    ___  ___                 " << endl;
        cout << "|  __ \\               | |   |  \\/  |                 " << endl;
        cout << "| |  \\/_   _  ___  ___| |_  | .  . | ___ _ __  _   _ " << endl;
        cout << "| | __| | | |/ _ \\/ __| __| | |\\/| |/ _ \\ '_ \\| | | |" << endl;
        cout << "| |_\\ \\ |_| |  __/\\__ \\ |_  | |  | |  __/ | | | |_| |" << endl;
        cout << " \\____/\\__,_|\\___||___/\\__| \\_|  |_/\\___|_| |_|\\__,_|" << endl;
        cout << string(GUEST_MENU_TITLE_LENGTH, '-') << endl;

        cout << "1. Display All Universities" << endl;
        cout << "2. Sort Universities by Name" << endl;
        cout << "3. Search Universities by Name" << endl;
        cout << "4. Search Universities by Location" << endl;
        cout << "5. Register as Customer" << endl;
        cout << "6. Back" << endl;
        cout << "Please select an option: ";

        int option = readInteger(1, 6);

        if (option == 1)
        {
            cout << "All universities" << endl;
            // uniList.displayList();
        }
        else if (option == 2)
        {
            cout << "Sort Universities" << endl;
            // uniList.sortAscendingByName();
        }
        else if (option == 3)
        {
            cout << "Search Name" << endl;
            // uniList.searchByName();
        }
        else if (option == 4)
        {
            cout << "Search Location" << endl;
            // uniList.searchByLocation();
        }
        else if (option == 5)
        {
            cout << "Register" << endl;
            // guest.registerAccount();
            
        }
        else if (option == 6)
        {
            break;
        }
    }
}

void exitPage()
{
    cout << string(THANK_YOU_LENGTH, '-') << endl;
    cout << " _____ _                 _     __   __          " << endl;
    cout << "|_   _| |               | |    \\ \\ / /          " << endl;
    cout << "  | | | |__   __ _ _ __ | | __  \\ V /___  _   _ " << endl;
    cout << "  | | | '_ \\ / _` | '_ \\| |/ /   \\ // _ \\| | | |" << endl;
    cout << "  | | | | | | (_| | | | |   <    | | (_) | |_| |" << endl;
    cout << "  \\_/ |_| |_|\\__,_|_| |_|_|\\_\\   \\_/\\___/ \\__,_|" << endl;
    cout << string(THANK_YOU_LENGTH, '-') << endl;
}

int readInteger(int min, int max)
{
    int input;
    cin >> input;

    while (cin.fail() || input < min || input > max)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input!" << endl;
        system("pause");
        cout << "Please select an option: " << endl;
        cin >> input;
    }

    return input;
}


/* MERGE SORT */
void FrontBackSplit(UniversityNode* source, UniversityNode** frontRef, UniversityNode** backRef)
{
    UniversityNode* fast;
    UniversityNode* slow;
    slow = source;
    fast = source->nextUniversity;

    // Advance 'fast' two nodes, and advance 'slow' one node
    while (fast != nullptr) 
    {
        fast = fast->nextUniversity;
        if (fast != nullptr) 
        {
            slow = slow->nextUniversity;
            fast = fast->nextUniversity;
        }
    }

    // Split it at 'slow' (before the midpoint)
    *frontRef = source;
    *backRef = slow->nextUniversity;
    slow->nextUniversity = nullptr;
}

template <FieldName Field>
bool compareFieldAsc(UniversityNode* a, UniversityNode* b)
{
    switch (Field)
    {
    case FieldName::INSTITUTION_NAME:
        return a->institutionName <= b->institutionName;
    case FieldName::AR_FSR_ER_SCORE:
        //TODO three scores
    case FieldName::RANK:
        return a->rank <= b->rank;
    case FieldName::LOCATION:
        return a->location <= b->location;
    case FieldName::AR_RANK:
        return a->arRank <= b->arRank;
    case FieldName::ER_RANK:
        return a->erRank <= b->erRank;
    case FieldName::FSR_RANK:
        return a->fsrRank <= b->fsrRank;
    case FieldName::CPF_RANK:
        return a->cpfRank <= b->cpfRank;
    case FieldName::IFR_RANK:
        return a->ifrRank <= b->ifrRank;
    case FieldName::ISR_RANK:
        return a->isrRank <= b->isrRank;
    case FieldName::IRN_RANK:
        return a->irnRank <= b->irnRank;
    case FieldName::GER_RANK:
        return a->gerRank <= b->gerRank;
    }
}

template <FieldName Field>
bool compareFieldDesc(UniversityNode* a, UniversityNode* b)
{
    switch (Field)
    {
    case FieldName::INSTITUTION_NAME:
        return a->institutionName >= b->institutionName;
    case FieldName::AR_FSR_ER_SCORE:
        //TODO three scores
    case FieldName::RANK:
        return a->rank >= b->rank;
    case FieldName::LOCATION:
        return a->location >= b->location;
    case FieldName::AR_RANK:
        return a->arRank >= b->arRank;
    case FieldName::ER_RANK:
        return a->erRank >= b->erRank;
    case FieldName::FSR_RANK:
        return a->fsrRank >= b->fsrRank;
    case FieldName::CPF_RANK:
        return a->cpfRank >= b->cpfRank;
    case FieldName::IFR_RANK:
        return a->ifrRank >= b->ifrRank;
    case FieldName::ISR_RANK:
        return a->isrRank >= b->isrRank;
    case FieldName::IRN_RANK:
        return a->irnRank >= b->irnRank;
    case FieldName::GER_RANK:
        return a->gerRank >= b->gerRank;
    }
}

template <FieldName Field>
UniversityNode* SortedMerge(UniversityNode* a, UniversityNode* b, bool isAscending)
{
    UniversityNode* result = nullptr;

    // Base cases 
    if (a == nullptr)
        return (b);
    else if (b == nullptr)
        return (a);

    // Pick a or b, and recur
    if (isAscending)
    {
        if (compareFieldAsc<Field>(a, b))
        {
            result = a;
            result->nextUniversity = SortedMerge<Field>(a->nextUniversity, b, isAscending);
        }
        else
        {
            result = b;
            result->nextUniversity = SortedMerge<Field>(a, b->nextUniversity, isAscending);
        }
    }
    else
    {
        if (compareFieldDesc<Field>(a, b))
        {
            result = a;
            result->nextUniversity = SortedMerge<Field>(a->nextUniversity, b, isAscending);
        }
        else
        {
            result = b;
            result->nextUniversity = SortedMerge<Field>(a, b->nextUniversity, isAscending);
        }
    }
    return (result);
}

template <FieldName Field>
void MergeSort(UniversityNode** headRef, bool isAscending)
{
    UniversityNode* head = *headRef;
    UniversityNode* a;
    UniversityNode* b;
  
    // Base case -- length 0 or 1 
    if ((head == nullptr) || (head->nextUniversity == nullptr)) 
    {
        return;
    }
  
    // Split the list in two halves
    FrontBackSplit(head, &a, &b);
  
    // Recursively sort the sublists 
    MergeSort<Field>(&a, isAscending);
    MergeSort<Field>(&b, isAscending);
  
    // Merge the two sorted halves
    *headRef = SortedMerge<Field>(a, b, isAscending);
}