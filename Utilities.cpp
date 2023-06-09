#include <iostream>
#include <string>
#include <limits>
#include <regex>
#include <chrono>
#include <cmath>
#include "Utilities.hpp"
#include "Admin.hpp"
#include "Customer.hpp"
#include "Guest.hpp"
#include "University.hpp"
#include "Feedback.hpp"
#include "FileIO.hpp"
#include "Shared_Variables.hpp"

using namespace std;
using namespace std::chrono;

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
        
        cout << "1. Display All Universities" << endl;
        cout << "2. Sort Universities" << endl;
        cout << "3. Search Universities" << endl;
        cout << "4. Display Customer Details" << endl;
        cout << "5. Modify Customer Details" << endl;
        cout << "6. Delete Customer Account" << endl;
        cout << "7. View Customer Feedback" << endl;
        cout << "8. Generate Report" << endl;
        cout << "9. Logout" << endl;
        cout << "Please select an option: ";

        int option = readInteger(1, 9);

        if (option == 1)
        {
            callMergeSort(FieldName::RANK, true);
            admin.displayUniversity();
            system("pause");
        }
        else if (option == 2)
        {
            admin.sortUniversities();
            system("pause");
        }
        else if (option == 3)
        {
            admin.searchUniversities();
            system("pause");
        }
        else if (option == 4)
        {
            admin.displayCustomerDetails();
            system("pause");
        }
        else if (option == 5)
        {
            admin.modifyCustomerDetails();
            system("pause");
        }
        else if (option == 6)
        {
            admin.deleteCustomerAccount();
            system("pause");
        }
        else if (option == 7)
        {
            admin.displayAllFeedbacks();
        }
        else if (option == 8)
        {
            admin.generateReport();
        }
        else if (option == 9)
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
        cout << "4. Display Favourite Universities" << endl;
        cout << "5. Display Feedbacks and Replies" << endl;
        cout << "6. Logout" << endl;
        cout << "Please select an option: ";

        int option = readInteger(1, 10);

        if (option == 1)
        {
            callMergeSort(FieldName::RANK, true);
            customerList.displayUniversity();
        }
        else if (option == 2)
        {
            customerList.sortUniversities();
            system("pause");
        }
        else if (option == 3)
        {
            customerList.searchUniversities();
            system("pause");
        }
        else if (option == 4)
        {
            customerList.displayFavouriteUniversities();
        }
        else if (option == 5)
        {
            customerList.displayAllFeedbacks(loginCustomer);
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
            callMergeSort(FieldName::RANK, true);
            guest.displayUniversity();
            system("pause");
        }
        else if (option == 2)
        {
            guest.sortUniversityByName();
            system("pause");
        }
        else if (option == 3)
        {
            guest.searchUniversityByName();
            system("pause");
        }
        else if (option == 4)
        {
            guest.searchUniversityByLocation();
            system("pause");
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
    time_t rawTime = time(nullptr);
    struct tm* lastLoginTime = localtime(&rawTime);
    time_t lastLoginTimeValue = mktime(lastLoginTime);


    readUsernameAndPassword(&username, &password, "Unique Customer");
    readEmail(&email);

    if (guest.registerAccount(username, email, password, lastLoginTimeValue))
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
        cout << "Please select a valid option: ";
        cin >> input;
    }

    return input;
}

void readUsernameAndPassword(string* username, string* password, string message)
{
    cout << message << " Username: ";
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
    cout << "1.  AR FSR ER Score" << endl;
    cout << "2.  Rank" << endl;
    cout << "3.  Institution Name" << endl;
    cout << "4.  Location" << endl;
    cout << "5.  AR Rank" << endl;
    cout << "6.  ER Rank" << endl;
    cout << "7.  FSR Rank" << endl;
    cout << "8.  CPF Rank" << endl;
    cout << "9.  IFR Rank" << endl;
    cout << "10. ISR Rank" << endl;
    cout << "11. IRN Rank" << endl;
    cout << "12. GER Rank" << endl;
    cout << "13. AR Score" << endl;
    cout << "14. ER Score" << endl;
    cout << "15. FSR Score" << endl;
    cout << "16. CPF Score" << endl;
    cout << "17. IFR Score" << endl;
    cout << "18. ISR Score" << endl;
    cout << "19. IRN Score" << endl;
    cout << "20. GER Score" << endl;
    cout << "21. Score Scaled" << endl;
    cout << "Please select sorting field: ";

    return static_cast<FieldName>(readInteger(1, 21) - 1);
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
        if (a->arRank == "-1") return false;
        else if (b->arRank == "-1") return true;
        else return stod(a->arRank) <= stod(b->arRank);
    }
    else if constexpr (Field == FieldName::ER_RANK)
    {
        if (a->erRank == "-1") return false;
        else if (b->erRank == "-1") return true;
        else return stod(a->erRank) <= stod(b->erRank);
    }
    else if constexpr (Field == FieldName::FSR_RANK)
    {
        if (a->fsrRank == "-1") return false;
        else if (b->fsrRank == "-1") return true;
        else return stod(a->fsrRank) <= stod(b->fsrRank);
    }
    else if constexpr (Field == FieldName::CPF_RANK)
    {
        if (a->cpfRank == "-1") return false;
        else if (b->cpfRank == "-1") return true;
        else return stod(a->cpfRank) <= stod(b->cpfRank);
    }
    else if constexpr (Field == FieldName::IFR_RANK)
    {
        if (a->ifrRank == "-1") return false;
        else if (b->ifrRank == "-1") return true;
        else return stod(a->ifrRank) <= stod(b->ifrRank);
    }
    else if constexpr (Field == FieldName::ISR_RANK)
    {
        if (a->isrRank == "-1") return false;
        else if (b->isrRank == "-1") return true;
        else return stod(a->isrRank) <= stod(b->isrRank);
    }
    else if constexpr (Field == FieldName::IRN_RANK)
    {
        if (a->irnRank == "-1") return false;
        else if (b->irnRank == "-1") return true;
        else return stod(a->irnRank) <= stod(b->irnRank);
    }
    else if constexpr (Field == FieldName::GER_RANK)
    {
        if (a->gerRank == "-1") return false;
        else if (b->gerRank == "-1") return true;
        else return stod(a->gerRank) <= stod(b->gerRank);
    }
    else if constexpr (Field == FieldName::AR_SCORE)
    {
        if (a->arScore == -1) return false;
        else if (b->arScore == -1) return true;
        else return a->arScore <= b->arScore;
    }
    else if constexpr (Field == FieldName::ER_SCORE)
    {
        if (a->erScore == -1) return false;
        else if (b->erScore == -1) return true;
        else return a->erScore <= b->erScore;
    }
    else if constexpr (Field == FieldName::FSR_SCORE)
    {
        if (a->fsrScore == -1) return false;
        else if (b->fsrScore == -1) return true;
        else return a->fsrScore <= b->fsrScore;
    }
    else if constexpr (Field == FieldName::CPF_SCORE)
    {
        if (a->cpfScore == -1) return false;
        else if (b->cpfScore == -1) return true;
        else return a->cpfScore <= b->cpfScore;
    }
    else if constexpr (Field == FieldName::IFR_SCORE)
    {
        if (a->ifrScore == -1) return false;
        else if (b->ifrScore == -1) return true;
        else return a->ifrScore <= b->ifrScore;
    }
    else if constexpr (Field == FieldName::ISR_SCORE)
    {
        if (a->isrScore == -1) return false;
        else if (b->isrScore == -1) return true;
        else return a->isrScore <= b->isrScore;
    }
    else if constexpr (Field == FieldName::IRN_SCORE)
    {
        if (a->irnScore == -1) return false;
        else if (b->irnScore == -1) return true;
        else return a->irnScore <= b->irnScore;
    }
    else if constexpr (Field == FieldName::GER_SCORE)
    {
        if (a->gerScore == -1) return false;
        else if (b->gerScore == -1) return true;
        else return a->gerScore <= b->gerScore;
    }
    else if constexpr (Field == FieldName::SCORE_SCALED)
    {
        if (a->scoreScaled == -1) return false;
        else if (b->scoreScaled == -1) return true;
        else return a->scoreScaled <= b->scoreScaled;
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
        return stod(a->arRank) >= stod(b->arRank);
    }
    else if constexpr (Field == FieldName::ER_RANK)
    {
        return stod(a->erRank) >= stod(b->erRank);
    }
    else if constexpr (Field == FieldName::FSR_RANK)
    {
        return stod(a->fsrRank) >= stod(b->fsrRank);
    }
    else if constexpr (Field == FieldName::CPF_RANK)
    {
        return stod(a->cpfRank) >= stod(b->cpfRank);
    }
    else if constexpr (Field == FieldName::IFR_RANK)
    {
        return stod(a->ifrRank) >= stod(b->ifrRank);
    }
    else if constexpr (Field == FieldName::ISR_RANK)
    {
        return stod(a->isrRank) >= stod(b->isrRank);
    }
    else if constexpr (Field == FieldName::IRN_RANK)
    {
        return stod(a->irnRank) >= stod(b->irnRank);
    }
    else if constexpr (Field == FieldName::GER_RANK)
    {
        return stod(a->gerRank) >= stod(b->gerRank);
    }
    else if constexpr (Field == FieldName::AR_SCORE)
    {
        return a->arScore >= b->arScore;
    }
    else if constexpr (Field == FieldName::ER_SCORE)
    {
        return a->erScore >= b->erScore;
    }
    else if constexpr (Field == FieldName::FSR_SCORE)
    {
        return a->fsrScore >= b->fsrScore;
    }
    else if constexpr (Field == FieldName::CPF_SCORE)
    {
        return a->cpfScore >= b->cpfScore;
    }
    else if constexpr (Field == FieldName::IFR_SCORE)
    {
        return a->ifrScore >= b->ifrScore;
    }
    else if constexpr (Field == FieldName::ISR_SCORE)
    {
        return a->isrScore >= b->isrScore;
    }
    else if constexpr (Field == FieldName::IRN_SCORE)
    {
        return a->irnScore >= b->irnScore;
    }
    else if constexpr (Field == FieldName::GER_SCORE)
    {
        return a->gerScore >= b->gerScore;
    }
    else if constexpr (Field == FieldName::SCORE_SCALED)
    {
        return a->scoreScaled >= b->scoreScaled;
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

void callMergeSort(FieldName field, bool isAscending)
{
    switch (field)
    {
        case FieldName::RANK:
            MergeSort<FieldName::RANK>(&uniList.head, isAscending);
            break;
        case FieldName::INSTITUTION_NAME:
            MergeSort<FieldName::INSTITUTION_NAME>(&uniList.head, isAscending);
            break;
        case FieldName::LOCATION:
            MergeSort<FieldName::LOCATION>(&uniList.head, isAscending);
            break;
        case FieldName::AR_FSR_ER_SCORE:
            MergeSort<FieldName::AR_FSR_ER_SCORE>(&uniList.head, isAscending);
            break;
        case FieldName::AR_RANK:
            MergeSort<FieldName::AR_RANK>(&uniList.head, isAscending);
            break;
        case FieldName::ER_RANK:
            MergeSort<FieldName::ER_RANK>(&uniList.head, isAscending);
            break;
        case FieldName::FSR_RANK:
            MergeSort<FieldName::FSR_RANK>(&uniList.head, isAscending);
            break;
        case FieldName::CPF_RANK:
            MergeSort<FieldName::CPF_RANK>(&uniList.head, isAscending);
            break;  
        case FieldName::IFR_RANK:
            MergeSort<FieldName::IFR_RANK>(&uniList.head, isAscending);
            break;
        case FieldName::ISR_RANK:
            MergeSort<FieldName::ISR_RANK>(&uniList.head, isAscending);
            break;
        case FieldName::IRN_RANK:
            MergeSort<FieldName::IRN_RANK>(&uniList.head, isAscending);
            break;
        case FieldName::GER_RANK:
            MergeSort<FieldName::GER_RANK>(&uniList.head, isAscending);
            break;
        case FieldName::AR_SCORE:
            MergeSort<FieldName::AR_SCORE>(&uniList.head, isAscending);
            break;
        case FieldName::ER_SCORE:
            MergeSort<FieldName::ER_SCORE>(&uniList.head, isAscending);
            break;
        case FieldName::FSR_SCORE:
            MergeSort<FieldName::FSR_SCORE>(&uniList.head, isAscending);
            break;
        case FieldName::CPF_SCORE:
            MergeSort<FieldName::CPF_SCORE>(&uniList.head, isAscending);
            break;
        case FieldName::IFR_SCORE:
            MergeSort<FieldName::IFR_SCORE>(&uniList.head, isAscending);
            break;
        case FieldName::ISR_SCORE:
            MergeSort<FieldName::ISR_SCORE>(&uniList.head, isAscending);
            break;
        case FieldName::IRN_SCORE:
            MergeSort<FieldName::IRN_SCORE>(&uniList.head, isAscending);
            break;
        case FieldName::GER_SCORE:
            MergeSort<FieldName::GER_SCORE>(&uniList.head, isAscending);
            break;
        case FieldName::SCORE_SCALED:
            MergeSort<FieldName::SCORE_SCALED>(&uniList.head, isAscending);
            break;
        default:
            break;
    }
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
template void MergeSort<FieldName::AR_SCORE>(UniversityNode** headRef, bool isAscending);
template void MergeSort<FieldName::ER_SCORE>(UniversityNode** headRef, bool isAscending);
template void MergeSort<FieldName::FSR_SCORE>(UniversityNode** headRef, bool isAscending);
template void MergeSort<FieldName::CPF_SCORE>(UniversityNode** headRef, bool isAscending);
template void MergeSort<FieldName::IFR_SCORE>(UniversityNode** headRef, bool isAscending);
template void MergeSort<FieldName::ISR_SCORE>(UniversityNode** headRef, bool isAscending);
template void MergeSort<FieldName::IRN_SCORE>(UniversityNode** headRef, bool isAscending);
template void MergeSort<FieldName::GER_SCORE>(UniversityNode** headRef, bool isAscending);
template void MergeSort<FieldName::SCORE_SCALED>(UniversityNode** headRef, bool isAscending);

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
template UniversityNode* SortedMerge<FieldName::AR_SCORE>(UniversityNode* a, UniversityNode* b, bool isAscending);
template UniversityNode* SortedMerge<FieldName::ER_SCORE>(UniversityNode* a, UniversityNode* b, bool isAscending);
template UniversityNode* SortedMerge<FieldName::FSR_SCORE>(UniversityNode* a, UniversityNode* b, bool isAscending);
template UniversityNode* SortedMerge<FieldName::CPF_SCORE>(UniversityNode* a, UniversityNode* b, bool isAscending);
template UniversityNode* SortedMerge<FieldName::IFR_SCORE>(UniversityNode* a, UniversityNode* b, bool isAscending);
template UniversityNode* SortedMerge<FieldName::ISR_SCORE>(UniversityNode* a, UniversityNode* b, bool isAscending);
template UniversityNode* SortedMerge<FieldName::IRN_SCORE>(UniversityNode* a, UniversityNode* b, bool isAscending);
template UniversityNode* SortedMerge<FieldName::GER_SCORE>(UniversityNode* a, UniversityNode* b, bool isAscending);
template UniversityNode* SortedMerge<FieldName::SCORE_SCALED>(UniversityNode* a, UniversityNode* b, bool isAscending);

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
template bool compareFieldAsc<FieldName::AR_SCORE>(UniversityNode* a, UniversityNode* b);
template bool compareFieldAsc<FieldName::ER_SCORE>(UniversityNode* a, UniversityNode* b);
template bool compareFieldAsc<FieldName::FSR_SCORE>(UniversityNode* a, UniversityNode* b);
template bool compareFieldAsc<FieldName::CPF_SCORE>(UniversityNode* a, UniversityNode* b);
template bool compareFieldAsc<FieldName::IFR_SCORE>(UniversityNode* a, UniversityNode* b);
template bool compareFieldAsc<FieldName::ISR_SCORE>(UniversityNode* a, UniversityNode* b);
template bool compareFieldAsc<FieldName::IRN_SCORE>(UniversityNode* a, UniversityNode* b);
template bool compareFieldAsc<FieldName::GER_SCORE>(UniversityNode* a, UniversityNode* b);
template bool compareFieldAsc<FieldName::SCORE_SCALED>(UniversityNode* a, UniversityNode* b);

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
template bool compareFieldDesc<FieldName::AR_SCORE>(UniversityNode* a, UniversityNode* b);
template bool compareFieldDesc<FieldName::ER_SCORE>(UniversityNode* a, UniversityNode* b);
template bool compareFieldDesc<FieldName::FSR_SCORE>(UniversityNode* a, UniversityNode* b);
template bool compareFieldDesc<FieldName::CPF_SCORE>(UniversityNode* a, UniversityNode* b);
template bool compareFieldDesc<FieldName::IFR_SCORE>(UniversityNode* a, UniversityNode* b);
template bool compareFieldDesc<FieldName::ISR_SCORE>(UniversityNode* a, UniversityNode* b);
template bool compareFieldDesc<FieldName::IRN_SCORE>(UniversityNode* a, UniversityNode* b);
template bool compareFieldDesc<FieldName::GER_SCORE>(UniversityNode* a, UniversityNode* b);
template bool compareFieldDesc<FieldName::SCORE_SCALED>(UniversityNode* a, UniversityNode* b);


/* QUICK SORT */
template <FieldName Field>
UniversityNode* Partition(UniversityNode* head, UniversityNode* end, UniversityNode** newHead, UniversityNode** newEnd, bool isAscending)
{
    UniversityNode* pivot = end;
    UniversityNode* prev = nullptr;
    UniversityNode* curr = head;
    UniversityNode* tail = pivot;
    while (curr != pivot)
    {
        if (isAscending)
        {
            if (compareFieldAsc<Field>(curr, pivot))
            {
                if (*newHead == nullptr)
                    *newHead = curr;
                prev = curr;
                curr = curr->nextUniversity;
            }
            else
            {
                if (prev)
                    prev->nextUniversity = curr->nextUniversity;
                UniversityNode* temp = curr->nextUniversity;
                curr->nextUniversity = nullptr;
                tail->nextUniversity = curr;
                tail = curr;
                curr = temp;
            }
        }
        else
        {
            if (compareFieldDesc<Field>(curr, pivot))
            {
                if (*newHead == nullptr)
                    *newHead = curr;
                prev = curr;
                curr = curr->nextUniversity;
            }
            else
            {
                if (prev)
                    prev->nextUniversity = curr->nextUniversity;
                UniversityNode* temp = curr->nextUniversity;
                curr->nextUniversity = nullptr;
                tail->nextUniversity = curr;
                tail = curr;
                curr = temp;
            }
        }
    }
    if (*newHead == nullptr)
        *newHead = pivot;
    *newEnd = tail;
    return pivot;
}

template <FieldName Field>
UniversityNode* SortQuick(UniversityNode* head, UniversityNode* end, bool isAscending)
{
    if (!head || head == end)
        return head;
    UniversityNode* newHead = nullptr;
    UniversityNode* newEnd = nullptr;
    UniversityNode* pivot = Partition<Field>(head, end, &newHead, &newEnd, isAscending);
    if (newHead != pivot)
    {
        UniversityNode* temp = newHead;
        while (temp->nextUniversity != pivot)
            temp = temp->nextUniversity;
        temp->nextUniversity = nullptr;
        newHead = SortQuick<Field>(newHead, temp, isAscending);
        temp = uniList.getTail(newHead);
        temp->nextUniversity = pivot;
    }
    pivot->nextUniversity = SortQuick<Field>(pivot->nextUniversity, newEnd, isAscending);
    return newHead;
}

template <FieldName Field>
void QuickSort(UniversityNode** headRef, bool isAscending)
{
    *headRef = SortQuick<Field>(*headRef, uniList.getTail(*headRef), isAscending);
}

template UniversityNode* Partition<FieldName::RANK>(UniversityNode* head, UniversityNode* end, UniversityNode** newHead, UniversityNode** newEnd, bool isAscending);
template UniversityNode* Partition<FieldName::INSTITUTION_NAME>(UniversityNode* head, UniversityNode* end, UniversityNode** newHead, UniversityNode** newEnd, bool isAscending);
template UniversityNode* Partition<FieldName::LOCATION>(UniversityNode* head, UniversityNode* end, UniversityNode** newHead, UniversityNode** newEnd, bool isAscending);
template UniversityNode* Partition<FieldName::AR_FSR_ER_SCORE>(UniversityNode* head, UniversityNode* end, UniversityNode** newHead, UniversityNode** newEnd, bool isAscending);
template UniversityNode* Partition<FieldName::AR_RANK>(UniversityNode* head, UniversityNode* end, UniversityNode** newHead, UniversityNode** newEnd, bool isAscending);
template UniversityNode* Partition<FieldName::ER_RANK>(UniversityNode* head, UniversityNode* end, UniversityNode** newHead, UniversityNode** newEnd, bool isAscending);
template UniversityNode* Partition<FieldName::FSR_RANK>(UniversityNode* head, UniversityNode* end, UniversityNode** newHead, UniversityNode** newEnd, bool isAscending);
template UniversityNode* Partition<FieldName::CPF_RANK>(UniversityNode* head, UniversityNode* end, UniversityNode** newHead, UniversityNode** newEnd, bool isAscending);
template UniversityNode* Partition<FieldName::IFR_RANK>(UniversityNode* head, UniversityNode* end, UniversityNode** newHead, UniversityNode** newEnd, bool isAscending);
template UniversityNode* Partition<FieldName::ISR_RANK>(UniversityNode* head, UniversityNode* end, UniversityNode** newHead, UniversityNode** newEnd, bool isAscending);
template UniversityNode* Partition<FieldName::IRN_RANK>(UniversityNode* head, UniversityNode* end, UniversityNode** newHead, UniversityNode** newEnd, bool isAscending);
template UniversityNode* Partition<FieldName::GER_RANK>(UniversityNode* head, UniversityNode* end, UniversityNode** newHead, UniversityNode** newEnd, bool isAscending);
template UniversityNode* Partition<FieldName::AR_SCORE>(UniversityNode* head, UniversityNode* end, UniversityNode** newHead, UniversityNode** newEnd, bool isAscending);
template UniversityNode* Partition<FieldName::ER_SCORE>(UniversityNode* head, UniversityNode* end, UniversityNode** newHead, UniversityNode** newEnd, bool isAscending);
template UniversityNode* Partition<FieldName::FSR_SCORE>(UniversityNode* head, UniversityNode* end, UniversityNode** newHead, UniversityNode** newEnd, bool isAscending);
template UniversityNode* Partition<FieldName::CPF_SCORE>(UniversityNode* head, UniversityNode* end, UniversityNode** newHead, UniversityNode** newEnd, bool isAscending);
template UniversityNode* Partition<FieldName::IFR_SCORE>(UniversityNode* head, UniversityNode* end, UniversityNode** newHead, UniversityNode** newEnd, bool isAscending);
template UniversityNode* Partition<FieldName::ISR_SCORE>(UniversityNode* head, UniversityNode* end, UniversityNode** newHead, UniversityNode** newEnd, bool isAscending);
template UniversityNode* Partition<FieldName::IRN_SCORE>(UniversityNode* head, UniversityNode* end, UniversityNode** newHead, UniversityNode** newEnd, bool isAscending);
template UniversityNode* Partition<FieldName::GER_SCORE>(UniversityNode* head, UniversityNode* end, UniversityNode** newHead, UniversityNode** newEnd, bool isAscending);
template UniversityNode* Partition<FieldName::SCORE_SCALED>(UniversityNode* head, UniversityNode* end, UniversityNode** newHead, UniversityNode** newEnd, bool isAscending);

template UniversityNode* SortQuick<FieldName::RANK>(UniversityNode* head, UniversityNode* end, bool isAscending);
template UniversityNode* SortQuick<FieldName::INSTITUTION_NAME>(UniversityNode* head, UniversityNode* end, bool isAscending);
template UniversityNode* SortQuick<FieldName::LOCATION>(UniversityNode* head, UniversityNode* end, bool isAscending);
template UniversityNode* SortQuick<FieldName::AR_FSR_ER_SCORE>(UniversityNode* head, UniversityNode* end, bool isAscending);
template UniversityNode* SortQuick<FieldName::AR_RANK>(UniversityNode* head, UniversityNode* end, bool isAscending);
template UniversityNode* SortQuick<FieldName::ER_RANK>(UniversityNode* head, UniversityNode* end, bool isAscending);
template UniversityNode* SortQuick<FieldName::FSR_RANK>(UniversityNode* head, UniversityNode* end, bool isAscending);
template UniversityNode* SortQuick<FieldName::CPF_RANK>(UniversityNode* head, UniversityNode* end, bool isAscending);
template UniversityNode* SortQuick<FieldName::IFR_RANK>(UniversityNode* head, UniversityNode* end, bool isAscending);
template UniversityNode* SortQuick<FieldName::ISR_RANK>(UniversityNode* head, UniversityNode* end, bool isAscending);
template UniversityNode* SortQuick<FieldName::IRN_RANK>(UniversityNode* head, UniversityNode* end, bool isAscending);
template UniversityNode* SortQuick<FieldName::GER_RANK>(UniversityNode* head, UniversityNode* end, bool isAscending);
template UniversityNode* SortQuick<FieldName::AR_SCORE>(UniversityNode* head, UniversityNode* end, bool isAscending);
template UniversityNode* SortQuick<FieldName::ER_SCORE>(UniversityNode* head, UniversityNode* end, bool isAscending);
template UniversityNode* SortQuick<FieldName::FSR_SCORE>(UniversityNode* head, UniversityNode* end, bool isAscending);
template UniversityNode* SortQuick<FieldName::CPF_SCORE>(UniversityNode* head, UniversityNode* end, bool isAscending);
template UniversityNode* SortQuick<FieldName::IFR_SCORE>(UniversityNode* head, UniversityNode* end, bool isAscending);
template UniversityNode* SortQuick<FieldName::ISR_SCORE>(UniversityNode* head, UniversityNode* end, bool isAscending);
template UniversityNode* SortQuick<FieldName::IRN_SCORE>(UniversityNode* head, UniversityNode* end, bool isAscending);
template UniversityNode* SortQuick<FieldName::GER_SCORE>(UniversityNode* head, UniversityNode* end, bool isAscending);
template UniversityNode* SortQuick<FieldName::SCORE_SCALED>(UniversityNode* head, UniversityNode* end, bool isAscending);

template void QuickSort<FieldName::RANK>(UniversityNode** headRef, bool isAscending);
template void QuickSort<FieldName::INSTITUTION_NAME>(UniversityNode** headRef, bool isAscending);
template void QuickSort<FieldName::LOCATION>(UniversityNode** headRef, bool isAscending);
template void QuickSort<FieldName::AR_FSR_ER_SCORE>(UniversityNode** headRef, bool isAscending);
template void QuickSort<FieldName::AR_RANK>(UniversityNode** headRef, bool isAscending);
template void QuickSort<FieldName::ER_RANK>(UniversityNode** headRef, bool isAscending);
template void QuickSort<FieldName::FSR_RANK>(UniversityNode** headRef, bool isAscending);
template void QuickSort<FieldName::CPF_RANK>(UniversityNode** headRef, bool isAscending);
template void QuickSort<FieldName::IFR_RANK>(UniversityNode** headRef, bool isAscending);
template void QuickSort<FieldName::ISR_RANK>(UniversityNode** headRef, bool isAscending);
template void QuickSort<FieldName::IRN_RANK>(UniversityNode** headRef, bool isAscending);
template void QuickSort<FieldName::GER_RANK>(UniversityNode** headRef, bool isAscending);
template void QuickSort<FieldName::AR_SCORE>(UniversityNode** headRef, bool isAscending);
template void QuickSort<FieldName::ER_SCORE>(UniversityNode** headRef, bool isAscending);
template void QuickSort<FieldName::FSR_SCORE>(UniversityNode** headRef, bool isAscending);
template void QuickSort<FieldName::CPF_SCORE>(UniversityNode** headRef, bool isAscending);
template void QuickSort<FieldName::IFR_SCORE>(UniversityNode** headRef, bool isAscending);
template void QuickSort<FieldName::ISR_SCORE>(UniversityNode** headRef, bool isAscending);
template void QuickSort<FieldName::IRN_SCORE>(UniversityNode** headRef, bool isAscending);
template void QuickSort<FieldName::GER_SCORE>(UniversityNode** headRef, bool isAscending);
template void QuickSort<FieldName::SCORE_SCALED>(UniversityNode** headRef, bool isAscending);


void callQuickSort(FieldName field, bool isAscending)
{
    switch (field)
    {
        case FieldName::RANK:
            QuickSort<FieldName::RANK>(&uniList.head, isAscending);
            break;
        case FieldName::INSTITUTION_NAME:
            QuickSort<FieldName::INSTITUTION_NAME>(&uniList.head, isAscending);
            break;
        case FieldName::LOCATION:
            QuickSort<FieldName::LOCATION>(&uniList.head, isAscending);
            break;
        case FieldName::AR_FSR_ER_SCORE:
            QuickSort<FieldName::AR_FSR_ER_SCORE>(&uniList.head, isAscending);
            break;
        case FieldName::AR_RANK:
            QuickSort<FieldName::AR_RANK>(&uniList.head, isAscending);
            break;
        case FieldName::ER_RANK:
            QuickSort<FieldName::ER_RANK>(&uniList.head, isAscending);
            break;
        case FieldName::FSR_RANK:
            QuickSort<FieldName::FSR_RANK>(&uniList.head, isAscending);
            break;
        case FieldName::CPF_RANK:
            QuickSort<FieldName::CPF_RANK>(&uniList.head, isAscending);
            break;  
        case FieldName::IFR_RANK:
            QuickSort<FieldName::IFR_RANK>(&uniList.head, isAscending);
            break;
        case FieldName::ISR_RANK:
            QuickSort<FieldName::ISR_RANK>(&uniList.head, isAscending);
            break;
        case FieldName::IRN_RANK:
            QuickSort<FieldName::IRN_RANK>(&uniList.head, isAscending);
            break;
        case FieldName::GER_RANK:
            QuickSort<FieldName::GER_RANK>(&uniList.head, isAscending);
            break;
        case FieldName::AR_SCORE:
            QuickSort<FieldName::AR_SCORE>(&uniList.head, isAscending);
            break;
        case FieldName::ER_SCORE:
            QuickSort<FieldName::ER_SCORE>(&uniList.head, isAscending);
            break;
        case FieldName::FSR_SCORE:
            QuickSort<FieldName::FSR_SCORE>(&uniList.head, isAscending);
            break;
        case FieldName::CPF_SCORE:
            QuickSort<FieldName::CPF_SCORE>(&uniList.head, isAscending);
            break;
        case FieldName::IFR_SCORE:
            QuickSort<FieldName::IFR_SCORE>(&uniList.head, isAscending);
            break;
        case FieldName::ISR_SCORE:
            QuickSort<FieldName::ISR_SCORE>(&uniList.head, isAscending);
            break;
        case FieldName::IRN_SCORE:
            QuickSort<FieldName::IRN_SCORE>(&uniList.head, isAscending);
            break;
        case FieldName::GER_SCORE:
            QuickSort<FieldName::GER_SCORE>(&uniList.head, isAscending);
            break;
        case FieldName::SCORE_SCALED:
            QuickSort<FieldName::SCORE_SCALED>(&uniList.head, isAscending);
            break;
        default:
            break;
    }
}

/* SEARCHING ALGORITHMS */
/* LINEAR SEARCH */
FieldName getSearchField() {

    // Get the field to be searched
    int fieldNum;
    cout << endl;
    cout << "1.  Rank" << endl;
    cout << "2.  Institution Name" << endl;
    cout << "3.  Location" << endl;
    cout << "4.  AR Rank" << endl;
    cout << "5.  ER Rank" << endl;
    cout << "6.  FSR Rank" << endl;
    cout << "7.  CPF Rank" << endl;
    cout << "8.  IFR Rank" << endl;
    cout << "9.  ISR Rank" << endl;
    cout << "10. IRN Rank" << endl;
    cout << "11. GER Rank" << endl;
    cout << "12. AR Score" << endl;
    cout << "13. ER Score" << endl;
    cout << "14. FSR Score" << endl;
    cout << "15. CPF Score" << endl;
    cout << "16. IFR Score" << endl;
    cout << "17. ISR Score" << endl;
    cout << "18. IRN Score" << endl;
    cout << "19. GER Score" << endl;
    cout << "20. Score Scaled" << endl;
    cout << "Please select searching field: ";

    return static_cast<FieldName>(readInteger(1, 20));
}

string getFieldValue(UniversityNode* node, FieldName field) {

    // Read the value of the search field of a specific university
    switch (field) {
    case FieldName::INSTITUTION_NAME: return node->institutionName; break;
    case FieldName::LOCATION: return node->location; break;
    case FieldName::RANK: return to_string(node->rank); break;
    case FieldName::AR_RANK: return node->arRank; break;
    case FieldName::AR_SCORE: return to_string(node->arScore); break;
    case FieldName::ER_RANK: return node->erRank; break;
    case FieldName::ER_SCORE: return to_string(node->erScore); break;
    case FieldName::FSR_RANK: return node->fsrRank; break;
    case FieldName::FSR_SCORE: return to_string(node->fsrScore); break;
    case FieldName::CPF_RANK: return node->cpfRank; break;
    case FieldName::CPF_SCORE: return to_string(node->cpfScore); break;
    case FieldName::IFR_RANK: return node->ifrRank; break;
    case FieldName::IFR_SCORE: return to_string(node->ifrScore); break;
    case FieldName::ISR_RANK: return node->isrRank; break;
    case FieldName::ISR_SCORE: return to_string(node->isrScore); break;
    case FieldName::IRN_RANK: return node->irnRank; break;
    case FieldName::IRN_SCORE: return to_string(node->irnScore); break;
    case FieldName::GER_RANK: return node->gerRank; break;
    case FieldName::GER_SCORE: return to_string(node->gerScore); break;
    case FieldName::SCORE_SCALED: return to_string(node->scoreScaled); break;
    default: break;
    }
}

void LinearSearch(string searchValue, FieldName field, string user)
{
    system("cls");

    if (field == FieldName::INSTITUTION_NAME || field == FieldName::LOCATION) {
        callMergeSort(FieldName::RANK, true);
    }
    else {
        callMergeSort(field, true);
    }

    auto start = high_resolution_clock::now();

    UniversityNode* current = uniList.getHead();
    UniversityNode* result = nullptr;

    while (current != NULL) {

        // Searching string value
        if (field == FieldName::INSTITUTION_NAME || field == FieldName::LOCATION) {
            if (getFieldValue(current, field).find(searchValue) != string::npos) {
                tempUniversityList.insertEnd(to_string(current->rank), to_string(current->arScore), to_string(current->erScore), 
                    to_string(current->fsrScore), to_string(current->cpfScore), to_string(current->ifrScore), to_string(current->isrScore), 
                    to_string(current->irnScore), to_string(current->gerScore), to_string(current->scoreScaled), current->institutionName, 
                    current->locationCode, current->location, current->arRank, current->erRank, current->fsrRank, current->cpfRank, current->ifrRank, 
                    current->isrRank, current->irnRank, current->gerRank);
            }
        }
        // Searching integer value
        else if (field == FieldName::RANK || field == FieldName::AR_RANK || field == FieldName::ER_RANK || field == FieldName::FSR_RANK || field == FieldName::CPF_RANK || 
            field == FieldName::IFR_RANK || field == FieldName::ISR_RANK || field == FieldName::IRN_RANK || field == FieldName::GER_RANK){
            if(stoi(getFieldValue(current, field)) >= stoi(searchValue)){
                result = current;
                break;
            }
        }
        // Searching double value
        else {
            if (stod(getFieldValue(current, field)) >= stod(searchValue)) {
                result = current;
                break;
            }
        }

        current = current->nextUniversity;
    }

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by linear search algorithm: ";
    cout << duration.count() << " microseconds." << endl;

    if (tempUniversityList.getSize() == 0 && result == nullptr) {
        cout << endl << "No match found!" << endl << endl;
        if (user == "Guest") {
            system("pause");
        }
        return;
    }

    cout << endl;
    cout << "Result(s) Found!" << endl;
    cout << "Continue to View Search Result for \"" << searchValue << "\"..." << endl;

    if (field == FieldName::INSTITUTION_NAME || field == FieldName::LOCATION) {
        tempUniversityList.displayList(tempUniversityList.getHead(), -1, user);
    }
    else {
        uniList.displayList(current, -1, user);
    }

    uniList.clearTempUniversityList();
}

/* EXPONENTIAL SEARCH */
void ExponentialSearch(string searchValue, FieldName field, string user) {

    system("cls");

    callMergeSort(field, true);

    auto start = high_resolution_clock::now();

    UniversityNode* result;

    // Check if the result is the first node, returns if yes
    if (field == FieldName::RANK || field == FieldName::AR_RANK || field == FieldName::ER_RANK || field == FieldName::FSR_RANK || field == FieldName::CPF_RANK ||
        field == FieldName::IFR_RANK || field == FieldName::ISR_RANK || field == FieldName::IRN_RANK || field == FieldName::GER_RANK) {
        if (stoi(getFieldValue(uniList.getHead(), field)) == stoi(searchValue)) {
            result = uniList.getHead();
        }
    }
    else {
        if (stod(getFieldValue(uniList.getHead(), field)) == stod(searchValue)) {
            result = uniList.getHead();
        }
    }
    
    // If the result is not at the first node, search other nodes
    UniversityNode* upper = uniList.getHead()->nextUniversity;
    UniversityNode* lower = uniList.getHead()->nextUniversity;
    int bound = 1;

    // Searching integer value
    if (field == FieldName::RANK || field == FieldName::AR_RANK || field == FieldName::ER_RANK || field == FieldName::FSR_RANK || field == FieldName::CPF_RANK ||
        field == FieldName::IFR_RANK || field == FieldName::ISR_RANK || field == FieldName::IRN_RANK || field == FieldName::GER_RANK) {
        while (bound < uniList.getSize() && stoi(getFieldValue(upper, field)) <= stoi(searchValue)) {
            lower = upper;
            for (int k = bound; k < bound * 2; k++) {
                if (upper->nextUniversity != nullptr) {
                    upper = upper->nextUniversity;
                }
                else {
                    break;
                }
            }
            bound = bound * 2;
        }
    }
    // Searching double value
    else {
        while (bound < uniList.getSize() && stod(getFieldValue(upper, field)) <= stod(searchValue)) {
            lower = upper;
            for (int k = bound; k < bound * 2; k++) {
                if (upper->nextUniversity != nullptr) {
                    upper = upper->nextUniversity;
                }
                else {
                    break;
                }
            }
            bound = bound * 2;
        }
    }

    // Call binary search to continue the search
    result = BinarySearch(lower, upper, field, searchValue);

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by exponential search algorithm: ";
    cout << duration.count() << " microseconds." << endl;

    if (result == nullptr) {
        cout << endl << "No match found!" << endl << endl;
        system("pause");
        return;
    }

    cout << endl;
    cout << "Result(s) Found!" << endl;
    cout << "Continue to View Search Result for \"" << searchValue << "\"..." << endl;

    uniList.displayList(result, -1, user);
}

UniversityNode* BinarySearch(UniversityNode* lowerNode, UniversityNode* upperNode, FieldName field, string searchValue)
{

    UniversityNode* middleNode;
    UniversityNode* temp = uniList.getHead();

    if (lowerNode != nullptr && upperNode != nullptr) {

        // Find the indeces of the lower, middle, and upper nodes
        int upperIndex = 1;

        while (temp != upperNode) {
            temp = temp->nextUniversity;
            upperIndex++;
        }

        temp = uniList.getHead();

        int lowerIndex = 1;

        while (temp != lowerNode) {
            temp = temp->nextUniversity;
            lowerIndex++;
        }

        middleNode = uniList.getUniversity((lowerIndex + upperIndex) / 2);

        temp = uniList.getHead();

        int middleIndex = 1;
        
        while (temp != middleNode) {
            temp = temp->nextUniversity;
            middleIndex++;
        }
        
        // Searching interger value
        if (field == FieldName::RANK || field == FieldName::AR_RANK || field == FieldName::ER_RANK || field == FieldName::FSR_RANK || field == FieldName::CPF_RANK ||
            field == FieldName::IFR_RANK || field == FieldName::ISR_RANK || field == FieldName::IRN_RANK || field == FieldName::GER_RANK) {

            // Return if the middle node is the result
            if (stoi(getFieldValue(middleNode, field)) == stoi(searchValue)) {
                return middleNode;
            }

            // If the value of the search value is smaller than the middle node, move the upper to the previous node of middle,
            // then call binary search again to search the lower part of the list
            if (stoi(getFieldValue(middleNode, field)) > stoi(searchValue)) {
                return BinarySearch(lowerNode, uniList.getUniversity(middleIndex - 1), field, searchValue);
            }

            // If the search value is already greater than the value of the upper node, return the result from there
            if (stoi(getFieldValue(upperNode, field)) < stoi(searchValue)) {
                return uniList.getUniversity(upperIndex + 1);
            }

            // If the search value is already smaller than the value of the lower node, return the result from there
            if (stoi(getFieldValue(lowerNode, field)) > stoi(searchValue)) {
                return uniList.getUniversity(lowerIndex - 2);
            }
        }
        // Searching double value
        else {          
            if (stod(getFieldValue(middleNode, field)) == stod(searchValue)) {
                return middleNode;
            }

            // If the value of the search value is smaller than the middle node, move the upper to the previous node of middle,
            // then call binary search again to search the lower part of the list
            if (stod(getFieldValue(middleNode, field)) > stod(searchValue)) {
                return BinarySearch(lowerNode, uniList.getUniversity(middleIndex - 1), field, searchValue);
            }

            // If the search value is already greater than the value of the upper node, return the result from there
            if (stod(getFieldValue(upperNode, field)) < stod(searchValue)) {
                return uniList.getUniversity(upperIndex + 1);
            }

            // If the search value is already smaller than the value of the lower node, return the result from there
            if (stod(getFieldValue(lowerNode, field)) > stod(searchValue)) {
                return uniList.getUniversity(lowerIndex - 2);
            }
        }

        // If the value of the search value is greater than the middle node, move the lower to the next node of middle,
        // then call binary search again to search the upper part of the list
        return BinarySearch(middleNode->nextUniversity, upperNode, field, searchValue);
    }

    return nullptr;
}