#include <iostream>
#include <string>
#include <chrono>
#include <iomanip>
#include "University.hpp"
#include "Utilities.hpp"
#include "Shared_Variables.hpp"
#include "Customer.hpp"

using namespace std;
using namespace chrono;


UniversityList::UniversityList()
{
}

UniversityList::~UniversityList()
{
}

UniversityNode* UniversityList::createUniversityNode(string rank, string arScore, string erScore, string fsrScore, string cpfScore, string ifrScore,
    string isrScore, string irnScore, string gerScore, string scoreScaled, string institutionName, string locationCode, string location,
    string arRank, string erRank, string fsrRank, string cpfRank, string ifrRank, string isrRank, string irnRank, string gerRank)
{
    UniversityNode * newNode = new UniversityNode;

    newNode->rank = stoi(rank);
    newNode->institutionName = institutionName;
    newNode->locationCode = locationCode;
    newNode->location = location;
    newNode->arScore = stod(arScore);
    newNode->arRank = arRank;
    newNode->erScore = stod(erScore);
    newNode->erRank = erRank;
    newNode->fsrScore = stod(fsrScore);
    newNode->fsrRank = fsrRank;
    newNode->cpfScore = stod(cpfScore);
    newNode->cpfRank = cpfRank;
    newNode->ifrScore = stod(ifrScore);
    newNode->ifrRank = ifrRank;
    newNode->isrScore = stod(isrScore);
    newNode->isrRank = isrRank;
    newNode->irnScore = stod(irnScore);
    newNode->irnRank = irnRank;
    newNode->gerScore = stod(gerScore);
    newNode->gerRank = gerRank;
    newNode->scoreScaled = stod(scoreScaled);
    newNode->nextUniversity = nullptr;

    return newNode;
}

void UniversityList::insertEnd(string rank, string arScore, string erScore, string fsrScore, string cpfScore, string ifrScore,
    string isrScore, string irnScore, string gerScore, string scoreScaled, string institutionName, string locationCode, string location,
    string arRank, string erRank, string fsrRank, string cpfRank, string ifrRank, string isrRank, string irnRank, string gerRank)
{
    UniversityNode* newNode = createUniversityNode(rank, arScore, erScore, fsrScore, cpfScore, ifrScore,
        isrScore, irnScore, gerScore, scoreScaled, institutionName, locationCode, location,
        arRank, erRank, fsrRank, cpfRank, ifrRank, isrRank, irnRank, gerRank);

    if (head == nullptr)
    {
        head = tail = newNode;
    }
    else 
    {
        UniversityNode* current = head; 
        
        while (current->nextUniversity != nullptr) 
        {
            current = current->nextUniversity;
        }
        
        current->nextUniversity = newNode;
        tail = newNode;
    }
    size++;
}

void UniversityList::sortByName()
{
    cout << "Sorting in..." << endl;
    cout << "1. Ascending order" << endl;
    cout << "2. Descending order" << endl;
    cout << "Enter your choice: ";

    int order = readInteger(1, 2);
    bool isAscending = order == 1 ? true : false;

    cout << "Sorting with..." << endl;
    cout << "1. Merge sort" << endl;
    cout << "2. Quick sort" << endl;
    cout << "Enter your choice: ";

    int sort = readInteger(1, 2);

    if (sort == 1)
    {
        auto start = high_resolution_clock::now();
        MergeSort<FieldName::INSTITUTION_NAME>(&head, isAscending);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "Time taken by MERGE SORT algorithm: " << duration.count() << " microseconds." << endl;
    }
    else if (sort == 2)
    {
        auto start = high_resolution_clock::now();
        // QuickSort<FieldName::INSTITUTION_NAME>(&head, isAscending);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "Time taken by QUICK SORT algorithm: " << duration.count() << " microseconds." << endl;
    }
}

void UniversityList::sortUniversities(FieldName field)
{
    cout << "Sorting in..." << endl;
    cout << "1. Ascending order" << endl;
    cout << "2. Descending order" << endl;
    cout << "Enter your choice: ";

    int order = readInteger(1, 2);
    bool isAscending = order == 1 ? true : false;

    callMergeSort(field, isAscending);

}

void UniversityList::searchUniversities(FieldName field, string user)
{
    int choice = 1;
    if (field != FieldName::INSTITUTION_NAME && field != FieldName::LOCATION) {
        cout << endl;
        cout << "Search using..." << endl;
        cout << "1. Linear Search" << endl;
        cout << "2. Exponential Search" << endl;
        cout << "Enter your choice: ";
        choice = readInteger(1, 2);
        cin.ignore();
    }

    string searchValue = "";
    cout << endl << "Please enter search value: ";
    getline(cin, searchValue);
    while (!inputValidation(searchValue, field)) {
        cout << endl << "Please enter a valid search value: ";
        getline(cin, searchValue);
    }

    if (choice == 1) {
        LinearSearch(searchValue, field, user);
    }
    else {
        ExponentialSearch(searchValue, field, user);
    } 
}

bool UniversityList::searchElement(int rankArr[], int size, int value) {
    for (int i = 0; i < size; i++) {
        if (rankArr[i] == value) {
            return true;
        }
    }
    return false;
}

void UniversityList::displayList(UniversityNode* firstNode, int viewMode, string user)
{
    int selectedViewMode = viewMode;
    if (selectedViewMode == -1) {
        cout << endl;
        cout << "Do you want to view in RANK mode or SCORE mode?" << endl;
        cout << "Press 1 for RANK mode, press 2 for SCORE mode: ";
        selectedViewMode = readInteger(1, 2);
    }

    system("cls");

    UniversityNode* temp = firstNode;
    int maxNameLength = 18;
    int maxLocationLength = 10;

    for (int i = 0; i < 25; i++) {
        if (temp != nullptr) {

            if (temp->institutionName.length() > maxNameLength) {
                maxNameLength = temp->institutionName.length();
            }

            if (temp->location.length() > maxLocationLength) {
                maxLocationLength = temp->location.length();
            }
            temp = temp->nextUniversity;
        }
        else {
            break;
        }
    }

    maxNameLength += 2;
    maxLocationLength += 2;
    temp = firstNode;

    cout << string(maxNameLength + maxLocationLength + 98, '-') << endl;

    if (selectedViewMode == 1) {
        cout << left << setw(6) << "Rank" << setw(maxNameLength) << "Institution Name" << setw(maxLocationLength) << "Location" <<
            setw(10) << "ArRank" << setw(10) << "ErRank" << setw(10) << "FsrRank" << setw(10) << "CpfRank" << setw(10) << "IfrRank" << setw(10) << "IsrRank" <<
            setw(10) << "IrnRank" << setw(10) << "GerRank" << setw(13) << "ScoreScaled" << endl;
    }
    else {
        cout << left << setw(6) << "Rank" << setw(maxNameLength) << "Institution Name" << setw(maxLocationLength) << "Location" <<
            setw(10) << "ArScore" << setw(10) << "ErScore" << setw(10) << "FsrScore" << setw(10) << "CpfScore" << setw(10) << "IfrScore" << setw(10) << "IsrScore" <<
            setw(10) << "IrnScore" << setw(10) << "GerScore" << setw(13) << "ScoreScaled" << endl;
    }

    cout << string(maxNameLength + maxLocationLength + 98, '-') << endl;

    int index = 0;
    int lastRank = 0;
    int rankArr[25];

    if (selectedViewMode == 1) {
        while (index < 25 && temp != nullptr)
        {
            cout << left << setw(6) << temp->rank << setw(maxNameLength + setWidth(temp->institutionName)) << temp->institutionName << setw(maxLocationLength) << temp->location <<
                setw(10) << checkAndDisplay(temp->arRank) << setw(10) << checkAndDisplay(temp->erRank) << setw(10) << checkAndDisplay(temp->fsrRank) <<
                setw(10) << checkAndDisplay(temp->cpfRank) << setw(10) << checkAndDisplay(temp->ifrRank) << setw(10) << checkAndDisplay(temp->isrRank) <<
                setw(10) << checkAndDisplay(temp->irnRank) << setw(10) << checkAndDisplay(temp->gerRank) << setw(13) << checkAndDisplay(to_string(temp->scoreScaled)) << endl;
            lastRank = temp->rank;
            rankArr[index] = lastRank;
            temp = temp->nextUniversity;
            index++;
        }
    }
    else {
        while (index < 25 && temp != nullptr)
        {
            cout << left << setw(6) << temp->rank << setw(maxNameLength + setWidth(temp->institutionName)) << temp->institutionName << setw(maxLocationLength) << temp->location <<
                setw(10) << checkAndDisplay(to_string(temp->arScore)) << setw(10) << checkAndDisplay(to_string(temp->erScore)) << setw(10) << checkAndDisplay(to_string(temp->fsrScore)) <<
                setw(10) << checkAndDisplay(to_string(temp->cpfScore)) << setw(10) << checkAndDisplay(to_string(temp->ifrScore)) << setw(10) << checkAndDisplay(to_string(temp->isrScore)) <<
                setw(10) << checkAndDisplay(to_string(temp->irnScore)) << setw(10) << checkAndDisplay(to_string(temp->gerScore)) << setw(13) << checkAndDisplay(to_string(temp->scoreScaled)) << endl;
            lastRank = temp->rank;
            rankArr[index] = lastRank;
            temp = temp->nextUniversity;
            index++;
        }
    }

    cout << string(maxNameLength + maxLocationLength + 98, '-') << endl;

    int option;
    int selectedUniversity = -1;

    if (temp == nullptr) {
        cout << endl << "List ends here!" << endl << endl;
        cout << "1. Select University" << endl;
        cout << "2. Exit" << endl;
        cout << "Please select an option: ";
        option = readInteger(1, 2);
        switch (option)
        {
        case 1:
            cout << "Enter University Rank: ";
            cin >> selectedUniversity;
            while (!searchElement(rankArr, sizeof(rankArr) / sizeof(rankArr[0]), selectedUniversity)) {
                cout << "Please select a valid option: ";
                cin >> selectedUniversity;
            }
            displayUniversity(uniList.getUniversity(selectedUniversity), user);
            break;
        case 2:
            return;
        default:
            break;
        }
    }
    else {
        cout << endl;
        cout << "1. Select University" << endl;
        cout << "2. Next Page" << endl;
        cout << "3. Exit" << endl;
        cout << "Please select an option: ";
        option = readInteger(1, 3);
        switch (option)
        {
        case 1:
            cout << "Enter University Rank: ";
            selectedUniversity = readInteger(firstNode->rank, lastRank);
            displayUniversity(uniList.getUniversity(selectedUniversity), user);
            break;
        case 2:
            system("cls");
            displayList(temp, selectedViewMode, user);
            break;
        case 3:
            return;
        default:
            break;
        }
    }
}

void UniversityList::displayUniversity(UniversityNode* university, string user) {
    system("cls");

    int maxLength = university->institutionName.length() + 50;

    string line(maxLength, '=');

    cout << line << endl;
    cout << string((maxLength / 2) + 1 - (11 / 2), ' ') << "University" << string((maxLength / 2) - (11 / 2), ' ') << endl;
    cout << line << endl;
    cout << " Rank:               |   " << university->rank << endl;
    cout << " Institution Name:   |   " << university->institutionName << endl;
    cout << " Location:           |   " << university->location << endl;
    cout << line << endl;
    cout << "   - AR Rank:        |   " << setw(6) << university->arRank << setw(6) << "   - AR Score:       |   " << university->arScore << endl;
    cout << "   - ER Rank:        |   " << setw(6) << university->erRank << setw(6) << "   - ER Score:       |   " << university->erScore << endl;
    cout << "   - FSR Rank:       |   " << setw(6) << university->fsrRank << setw(6) << "   - FSR Score:      |   " << university->fsrScore << endl;
    cout << "   - CPF Rank:       |   " << setw(6) << university->cpfRank << setw(6) << "   - CPF Score:      |   " << university->cpfScore << endl;
    cout << "   - IFR Rank:       |   " << setw(6) << university->ifrRank << setw(6) << "   - IFR Score:      |   " << university->ifrScore << endl;
    cout << "   - ISR Rank:       |   " << setw(6) << university->isrRank << setw(6) << "   - ISR Score:      |   " << university->isrScore << endl;
    cout << "   - IRN Rank:       |   " << setw(6) << university->irnRank << setw(6) << "   - IRN Score:      |   " << university->irnScore << endl;
    cout << "   - GER Rank:       |   " << setw(6) << university->gerRank << setw(6) << "   - GER Score:      |   " << university->gerScore << endl;
    cout << "   - FSR Score:      |   " << university->fsrScore << endl;
    cout << line << endl;

    int option;
    if (user == "Customer" || user == "Favourite") {
        if (user == "Customer" && !checkFavouriteExist(university->rank)) {
            cout << "1. Save as Favourite" << endl;
        }
        else {
            cout << "1. Delete from Favourite" << endl;
        }
        cout << "2. Write Feedback" << endl;
        cout << "3. Exit" << endl;
        cout << "Please select an option: ";
        option = readInteger(1, 3);
        switch (option)
        {
        case 1:
            if (user == "Customer" && !checkFavouriteExist(university->rank)) {
                customerList.saveFavouriteUniversity(university->rank, customerList.getCustomer(loginCustomer.getCustomerID()));
            }
            else {
                customerList.deleteFavouriteUniversity(university->rank);
            } 
            break;
        case 2:
            customerList.sendFeedback(loginCustomer, university, &feedbackList, &uniList);
            break;
        case 3:
            break;
        default:
            break;
        }
    }
}

bool UniversityList::inputValidation(string value, FieldName field) {
    try {
        if (field == FieldName::RANK || field == FieldName::AR_RANK || field == FieldName::ER_RANK || field == FieldName::FSR_RANK || field == FieldName::CPF_RANK ||
            field == FieldName::IFR_RANK || field == FieldName::ISR_RANK || field == FieldName::IRN_RANK || field == FieldName::GER_RANK) {
            int buffer;
            buffer = stoi(value);
            return true;
        }
        else {
            double buffer;
            buffer = stod(value);
            return true;
        }
    }
    catch (...) {
        return false;
    }
}

string UniversityList::checkAndDisplay(string value) {
    if (value == "-1" || value == "-1.000000") {
        return "N/A";
    }

    // Remove additional 
    int decimalPos = value.find('.');
    int index = decimalPos;
    if (index != string::npos) {
        index++;
        while (index < value.length()) {
            if (value[index] == '0') {
                value = value.erase(index, 1);
                index--;
            }
            index++;
        }

        if (value.length() == decimalPos + 1) {
            value = value.erase(value.length() - 1, 1);
        }
    }

    return value;
}

bool UniversityList::checkFavouriteExist(int universityRank) {
    CustomerNode* customer = customerList.getCustomer(loginCustomer.getCustomerID());
    FavouriteNode* current = customer->favourites;
    while (current != nullptr) {
        if (current->universityRank == universityRank) {
            return true;
        }
        current = current->nextFavourite;
    }
    return false;
}

void UniversityList::clearTempUniversityList() {
    UniversityNode* currentDelete = tempUniversityList.getHead();
    UniversityNode* nextNode;

    while (currentDelete != nullptr) {
        nextNode = currentDelete->nextUniversity;
        delete currentDelete;
        currentDelete = nextNode;
    }

    tempUniversityList.setHeadNull();
}

int UniversityList::getSize() {
    return size;
}

UniversityNode* UniversityList::getHead() {
    return head;
}

UniversityNode* UniversityList::getTail() {
    return tail;
}

UniversityNode* UniversityList::getUniversity(int index) {
    UniversityNode* current = head;
    for (int i = 1; i < index; i++) {
        current = current->nextUniversity;
    }
    return current;
}

void UniversityList::setHeadNull() {
    head = tail = nullptr;
}

void UniversityList::setHead(UniversityNode* university) {
    head = university;
}

int UniversityList::setWidth(string value) {
    int additionalLength = 0;
    for (int i = 0; i < value.length(); i++) {
        if ((unsigned int) value[i] > 127) {
            additionalLength++;
            i++;
        }
    }
    return additionalLength;
}