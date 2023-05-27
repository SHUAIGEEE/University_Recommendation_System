#include <iostream>
#include <string>
#include <limits>
#include <regex>
#include "Utilities.hpp"
#include "Admin.hpp"
#include "Customer.hpp"
#include "Guest.hpp"
#include "University.hpp"
#include "Feedback.hpp"
#include "FileIO.hpp"
#include "Shared_Variables.hpp"

using namespace std;

const int MAIN_MENU_LENGTH = 166;
const int LOGIN_MENU_TITLE_LENGTH = 54;
const int ADMIN_MENU_TITLE_LENGTH = 58;
const int CUSTOMER_MENU_TITLE_LENGTH = 73;
const int GUEST_MENU_TITLE_LENGTH = 54;
const int THANK_YOU_LENGTH = 49;

Admin admin;
Guest guest;
Customer loginCustomer;

void mainMenu()
{
    while (true)
    {
        // system("cls");

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
        system("cls");

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


/* ADMIN */
void adminLogin()
{
    string adminName;
    string password;

    readUsernameAndPassword(&adminName, &password, "Admin");

    if (admin.login(adminName, password))
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
        system("cls");

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
            admin.viewAllFeedbacks();
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


/* CUSTOMER */
void customerLogin()
{
    string username;
    string password;

    readUsernameAndPassword(&username, &password, "Customer");

    if (customerList.login(username, password))
    {
        cout << "Login successful!" << endl;
        system("pause");
        customerMenu();
    }
    else
    {
        cout << "Login failed!" << endl;
        system("pause");
    }
}

void customerMenu()
{
    while (true)
    {
        system("cls");

        cout << string(CUSTOMER_MENU_TITLE_LENGTH, '-') << endl;
        cout << " _____           _                             ___  ___                 " << endl;
        cout << "/  __ \\         | |                            |  \\/  |                 " << endl;
        cout << "| /  \\/_   _ ___| |_ ___  _ __ ___   ___ _ __  | .  . | ___ _ __  _   _ " << endl;
        cout << "| |   | | | / __| __/ _ \\| '_ ` _ \\ / _ \\ '__| | |\\/| |/ _ \\ '_ \\| | | |" << endl;
        cout << "| \\__/\\ |_| \\__ \\ || (_) | | | | | |  __/ |    | |  | |  __/ | | | |_| |" << endl;
        cout << " \\____/\\__,_|___/\\__\\___/|_| |_| |_|\\___|_|    \\_|  |_/\\___|_| |_|\\__,_|" << endl;
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
            uniList.displayList();

            //如果要换成一个一个uni view的话，可以直接pass currentUni 进去write feedback
            int selectedUni = -1;
            while (selectedUni < 1 || selectedUni > uniList.getSize()) {
                cout << "Select University to Write a Feedback (1 - " << uniList.getSize() << "): ";
                selectedUni = readInteger(1, uniList.getSize());
            }
            UniversityNode* selectedUniversity = uniList.getUniversity(selectedUni);
            //

            customerList.sendFeedback(loginCustomer, selectedUniversity, &feedbackList, &uniList); 
        }
        else if (option == 2)
        {
            cout << "Sort Universities" << endl;
            customerList.sortUniversities();
            system("pause"); // can change to something like display n times then stop
        }
        else if (option == 3)
        {
            cout << "Search Universities" << endl;
            FieldName searchField = getSearchField();
            string searchValue = "";
            cout << endl << "Please enter search value: ";
            getline(cin, searchValue);
            linearSearch(searchValue, searchField);
            system("pause");
        }
        else if (option == 4)
        {
            cout << "View Favourite Universities" << endl;
            // favourite也要可以send feedback
            // customerList.showFavouriteUniversities();
        }
        else if (option == 5)
        {
            cout << "View Feedbacks and Replies" << endl;
            customerList.viewAllFeedbacks(loginCustomer);
        }
        else if (option == 6)
        {
            customerList.logout();
            break;
        }
    }
}


/* GUEST */
void guestMenu()
{
    while (true)
    {
        system("cls");

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
            // guest.displayUniversity();
        }
        else if (option == 2)
        {
            cout << "Sort Universities" << endl;
            // guest.sortUniversityByName();
        }
        else if (option == 3)
        {
            cout << "Search Name" << endl;
            // guest.searchUniversityByName();
        }
        else if (option == 4)
        {
            cout << "Search Location" << endl;
            // guest.searchUniversityByLocation();
        }
        else if (option == 5)
        {
            guestRegister();
        }
        else if (option == 6)
        {
            break;
        }
    }
}

void guestRegister()
{
    string username;
    string email;
    string password;

    readUsernameAndPassword(&username, &password, "Unique Customer");
    readEmail(&email);

    if (guest.registerAccount(username, email, password))
    {
        cout << "Registration successful!" << endl;
        cout << "You can login your account from main menu now!" << endl;
    }
    else
    {
        cout << "Registration failed!" << endl;
    }
    system("pause");
}


void exitPage()
{
    system("cls");
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

void readUsernameAndPassword(string* username, string* password, string message)
{
    cout << message << " Usernanme: ";
    cin >> *username;
    cout << "Password: ";
    cin >> *password;
}

void readEmail(string* email)
{
    cout << "Email: ";
    cin >> *email;
    regex rgx("\\w{6,30}@gmail.com");

    while (cin.fail() || !regex_match(*email, rgx))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid email! Email should contain 6-30 alphanumeric characters followed by @gmail.com" << endl;
        system("pause");
        cout << "Email: ";
        cin >> *email;
    }
}

/* Sorting Algorithms */
/* MERGE SORT */
FieldName getSortField()
{
    cout << endl;
    cout << "1.  RANK" << endl;
    cout << "2.  INSTITUTION_NAME" << endl;
    cout << "3.  LOCATION" << endl;
    cout << "4.  AR_FSR_ER_SCORE" << endl;
    cout << "5.  AR_RANK" << endl;
    cout << "6.  ER_RANK" << endl;
    cout << "7.  FSR_RANK" << endl;
    cout << "8.  CPF_RANK" << endl;
    cout << "9.  IFR_RANK" << endl;
    cout << "10. ISR_RANK" << endl;
    cout << "11. IRN_RANK" << endl;
    cout << "12. GER_RANK" << endl;
    cout << "Please select sorting field: ";

    return static_cast<FieldName>(readInteger(1, 12) - 1);
}

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
    if constexpr (Field == FieldName::INSTITUTION_NAME)
    {
        return a->institutionName <= b->institutionName;
    }
    else if constexpr (Field == FieldName::AR_FSR_ER_SCORE)
    {
        if (a->arScore != b->arScore) return a->arScore < b->arScore;
        else if (a->fsrScore != b->fsrScore) return a->fsrScore < b->fsrScore;
        else if (a->erScore != b->erScore) return a->erScore < b->erScore;
        else return a->rank <= b->rank;
    }
    else if constexpr (Field == FieldName::RANK)
    {
        return a->rank <= b->rank;
    }
    else if constexpr (Field == FieldName::LOCATION)
    {
        return a->location <= b->location;
    }
    else if constexpr (Field == FieldName::AR_RANK)
    {
        return a->arRank <= b->arRank;
    }
    else if constexpr (Field == FieldName::ER_RANK)
    {
        return a->erRank <= b->erRank;
    }
    else if constexpr (Field == FieldName::FSR_RANK)
    {
        return a->fsrRank <= b->fsrRank;
    }
    else if constexpr (Field == FieldName::CPF_RANK)
    {
        return a->cpfRank <= b->cpfRank;
    }
    else if constexpr (Field == FieldName::IFR_RANK)
    {
        return a->ifrRank <= b->ifrRank;
    }
    else if constexpr (Field == FieldName::ISR_RANK)
    {
        return a->isrRank <= b->isrRank;
    }
    else if constexpr (Field == FieldName::IRN_RANK)
    {
        return a->irnRank <= b->irnRank;
    }
    else if constexpr (Field == FieldName::GER_RANK)
    {
        return a->gerRank <= b->gerRank;
    }
}

template <FieldName Field>
bool compareFieldDesc(UniversityNode* a, UniversityNode* b)
{
    if constexpr (Field == FieldName::INSTITUTION_NAME)
    {
        return a->institutionName >= b->institutionName;
    }
    else if constexpr (Field == FieldName::AR_FSR_ER_SCORE)
    {
        if (a->arScore != b->arScore) return a->arScore > b->arScore;
        else if (a->fsrScore != b->fsrScore) return a->fsrScore > b->fsrScore;
        else if (a->erScore != b->erScore) return a->erScore > b->erScore;
        else return a->rank >= b->rank;
    }
    else if constexpr (Field == FieldName::RANK)
    {
        return a->rank >= b->rank;
    }
    else if constexpr (Field == FieldName::LOCATION)
    {
        return a->location >= b->location;
    }
    else if constexpr (Field == FieldName::AR_RANK)
    {
        return a->arRank >= b->arRank;
    }
    else if constexpr (Field == FieldName::ER_RANK)
    {
        return a->erRank >= b->erRank;
    }
    else if constexpr (Field == FieldName::FSR_RANK)
    {
        return a->fsrRank >= b->fsrRank;
    }
    else if constexpr (Field == FieldName::CPF_RANK)
    {
        return a->cpfRank >= b->cpfRank;
    }
    else if constexpr (Field == FieldName::IFR_RANK)
    {
        return a->ifrRank >= b->ifrRank;
    }
    else if constexpr (Field == FieldName::ISR_RANK)
    {
        return a->isrRank >= b->isrRank;
    }
    else if constexpr (Field == FieldName::IRN_RANK)
    {
        return a->irnRank >= b->irnRank;
    }
    else if constexpr (Field == FieldName::GER_RANK)
    {
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

template void MergeSort<FieldName::RANK>(UniversityNode** headRef, bool isAscending);
template void MergeSort<FieldName::INSTITUTION_NAME>(UniversityNode** headRef, bool isAscending);
template void MergeSort<FieldName::LOCATION>(UniversityNode** headRef, bool isAscending);
template void MergeSort<FieldName::AR_FSR_ER_SCORE>(UniversityNode** headRef, bool isAscending);
template void MergeSort<FieldName::AR_RANK>(UniversityNode** headRef, bool isAscending);
template void MergeSort<FieldName::ER_RANK>(UniversityNode** headRef, bool isAscending);
template void MergeSort<FieldName::FSR_RANK>(UniversityNode** headRef, bool isAscending);
template void MergeSort<FieldName::CPF_RANK>(UniversityNode** headRef, bool isAscending);
template void MergeSort<FieldName::IFR_RANK>(UniversityNode** headRef, bool isAscending);
template void MergeSort<FieldName::ISR_RANK>(UniversityNode** headRef, bool isAscending);
template void MergeSort<FieldName::IRN_RANK>(UniversityNode** headRef, bool isAscending);
template void MergeSort<FieldName::GER_RANK>(UniversityNode** headRef, bool isAscending);

template UniversityNode* SortedMerge<FieldName::RANK>(UniversityNode* a, UniversityNode* b, bool isAscending);
template UniversityNode* SortedMerge<FieldName::INSTITUTION_NAME>(UniversityNode* a, UniversityNode* b, bool isAscending);
template UniversityNode* SortedMerge<FieldName::LOCATION>(UniversityNode* a, UniversityNode* b, bool isAscending);
template UniversityNode* SortedMerge<FieldName::AR_FSR_ER_SCORE>(UniversityNode* a, UniversityNode* b, bool isAscending);
template UniversityNode* SortedMerge<FieldName::AR_RANK>(UniversityNode* a, UniversityNode* b, bool isAscending);
template UniversityNode* SortedMerge<FieldName::ER_RANK>(UniversityNode* a, UniversityNode* b, bool isAscending);
template UniversityNode* SortedMerge<FieldName::FSR_RANK>(UniversityNode* a, UniversityNode* b, bool isAscending);
template UniversityNode* SortedMerge<FieldName::CPF_RANK>(UniversityNode* a, UniversityNode* b, bool isAscending);
template UniversityNode* SortedMerge<FieldName::IFR_RANK>(UniversityNode* a, UniversityNode* b, bool isAscending);
template UniversityNode* SortedMerge<FieldName::ISR_RANK>(UniversityNode* a, UniversityNode* b, bool isAscending);
template UniversityNode* SortedMerge<FieldName::IRN_RANK>(UniversityNode* a, UniversityNode* b, bool isAscending);
template UniversityNode* SortedMerge<FieldName::GER_RANK>(UniversityNode* a, UniversityNode* b, bool isAscending);

template bool compareFieldAsc<FieldName::RANK>(UniversityNode* a, UniversityNode* b);
template bool compareFieldAsc<FieldName::INSTITUTION_NAME>(UniversityNode* a, UniversityNode* b);
template bool compareFieldAsc<FieldName::LOCATION>(UniversityNode* a, UniversityNode* b);
template bool compareFieldAsc<FieldName::AR_FSR_ER_SCORE>(UniversityNode* a, UniversityNode* b);
template bool compareFieldAsc<FieldName::AR_RANK>(UniversityNode* a, UniversityNode* b);
template bool compareFieldAsc<FieldName::ER_RANK>(UniversityNode* a, UniversityNode* b);
template bool compareFieldAsc<FieldName::FSR_RANK>(UniversityNode* a, UniversityNode* b);
template bool compareFieldAsc<FieldName::CPF_RANK>(UniversityNode* a, UniversityNode* b);
template bool compareFieldAsc<FieldName::IFR_RANK>(UniversityNode* a, UniversityNode* b);
template bool compareFieldAsc<FieldName::ISR_RANK>(UniversityNode* a, UniversityNode* b);
template bool compareFieldAsc<FieldName::IRN_RANK>(UniversityNode* a, UniversityNode* b);
template bool compareFieldAsc<FieldName::GER_RANK>(UniversityNode* a, UniversityNode* b);

template bool compareFieldDesc<FieldName::RANK>(UniversityNode* a, UniversityNode* b);
template bool compareFieldDesc<FieldName::INSTITUTION_NAME>(UniversityNode* a, UniversityNode* b);
template bool compareFieldDesc<FieldName::LOCATION>(UniversityNode* a, UniversityNode* b);
template bool compareFieldDesc<FieldName::AR_FSR_ER_SCORE>(UniversityNode* a, UniversityNode* b);
template bool compareFieldDesc<FieldName::AR_RANK>(UniversityNode* a, UniversityNode* b);
template bool compareFieldDesc<FieldName::ER_RANK>(UniversityNode* a, UniversityNode* b);
template bool compareFieldDesc<FieldName::FSR_RANK>(UniversityNode* a, UniversityNode* b);
template bool compareFieldDesc<FieldName::CPF_RANK>(UniversityNode* a, UniversityNode* b);
template bool compareFieldDesc<FieldName::IFR_RANK>(UniversityNode* a, UniversityNode* b);
template bool compareFieldDesc<FieldName::ISR_RANK>(UniversityNode* a, UniversityNode* b);
template bool compareFieldDesc<FieldName::IRN_RANK>(UniversityNode* a, UniversityNode* b);
template bool compareFieldDesc<FieldName::GER_RANK>(UniversityNode* a, UniversityNode* b);

/* QUICK SORT */



/* SEARCHING ALGORITHMS */
/* LINEAR SEARCH */
FieldName getSearchField() {
    int fieldNum = -1;
    while (fieldNum < 1 || fieldNum > 11) {
        cout << endl;
        cout << "1.  Institution Name" << endl;
        cout << "2.  Location" << endl;
        cout << "3.  Rank" << endl;
        cout << "4.  AR Rank" << endl;
        cout << "5.  ER Rank" << endl;
        cout << "6.  FSR Rank" << endl;
        cout << "7.  CPF Rank" << endl;
        cout << "8.  IFR Rank" << endl;
        cout << "9.  ISR Rank" << endl;
        cout << "10. IRN Rank" << endl;
        cout << "11. GER Rank" << endl;
        cout << "Please select searching field: ";
        cin >> fieldNum;
        cin.ignore();
    }

    switch (fieldNum) {
    case 1: return FieldName::INSTITUTION_NAME; break;
    case 2: return FieldName::LOCATION; break;
    case 3: return FieldName::RANK; break;
    case 4: return FieldName::AR_RANK; break;
    case 5: return FieldName::ER_RANK; break;
    case 6: return FieldName::FSR_RANK; break;
    case 7: return FieldName::CPF_RANK; break;
    case 8: return FieldName::IFR_RANK; break;
    case 9: return FieldName::ISR_RANK; break;
    case 10: return FieldName::IRN_RANK; break;
    case 11: return FieldName::GER_RANK; break;
    }
}

void linearSearch(string searchValue, FieldName field)
{
    UniversityNode* current = uniList.getHead();
    bool matchFound = false;
    while (current != NULL) {
        if (field == FieldName::INSTITUTION_NAME && current->institutionName.find(searchValue) != string::npos) {
            //cout 过后可以换format，看要怎样，不过我觉得是跟着displayList()一样的好
            cout << current->rank << ". " << current->institutionName << endl;
            matchFound = true;
        }
        else if (field == FieldName::LOCATION && current->location.find(searchValue) != string::npos) {
            cout << current->rank << ". " << current->institutionName << endl;
            matchFound = true;
        }
        else if (field == FieldName::RANK && std::to_string(current->rank) >= searchValue) {
            cout << current->rank << ". " << current->institutionName << endl;
            matchFound = true;
        }
        else if (field == FieldName::AR_RANK && current->arRank >= searchValue) {
            cout << current->rank << ". " << current->institutionName << endl;
            matchFound = true;
        }
        else if (field == FieldName::ER_RANK && current->erRank >= searchValue) {
            cout << current->rank << ". " << current->institutionName << endl;
            matchFound = true;
        }
        else if (field == FieldName::FSR_RANK && current->fsrRank >= searchValue) {
            cout << current->rank << ". " << current->institutionName << endl;
            matchFound = true;
        }
        else if (field == FieldName::CPF_RANK && current->cpfRank >= searchValue) {
            cout << current->rank << ". " << current->institutionName << endl;
            matchFound = true;
        }
        else if (field == FieldName::IFR_RANK && current->ifrRank >= searchValue) {
            cout << current->rank << ". " << current->institutionName << endl;
            matchFound = true;
        }
        else if (field == FieldName::ISR_RANK && current->isrRank >= searchValue) {
            cout << current->rank << ". " << current->institutionName << endl;
            matchFound = true;
        }
        else if (field == FieldName::IRN_RANK && current->irnRank >= searchValue) {
            cout << current->rank << ". " << current->institutionName << endl;
            matchFound = true;
        }
        else if (field == FieldName::GER_RANK && current->gerRank >= searchValue) {
            cout << current->rank << ". " << current->institutionName << endl;
            matchFound = true;
        }

        current = current->nextUniversity;
    }

    if (!matchFound) {
        cout << endl << "No match found!" << endl;
    }
}

/* EXPONENTIAL SEARCH */