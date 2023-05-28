#include <iostream>
#include <string>
#include <chrono>
#include <iomanip>
#include "University.hpp"
#include "Utilities.hpp"
#include "Shared_Variables.hpp"

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

    switch (field)
    {
        case FieldName::RANK:
            MergeSort<FieldName::RANK>(&head, isAscending);
            // QuickSort<FieldName::RANK>(&head, isAscending);
            break;
        case FieldName::INSTITUTION_NAME:
            MergeSort<FieldName::INSTITUTION_NAME>(&head, isAscending);
            // QuickSort<FieldName::INSTITUTION_NAME>(&head, isAscending);
            break;
        case FieldName::LOCATION:
            MergeSort<FieldName::LOCATION>(&head, isAscending);
            // QuickSort<FieldName::LOCATION>(&head, isAscending);
            break;
        case FieldName::AR_FSR_ER_SCORE:
            MergeSort<FieldName::AR_FSR_ER_SCORE>(&head, isAscending);
            // QuickSort<FieldName::AR_FSR_ER_SCORE>(&head, isAscending);
            break;
        case FieldName::AR_RANK:
            MergeSort<FieldName::AR_RANK>(&head, isAscending);
            // QuickSort<FieldName::AR_RANK>(&head, isAscending);
            break;
        case FieldName::ER_RANK:
            MergeSort<FieldName::ER_RANK>(&head, isAscending);
            // QuickSort<FieldName::ER_RANK>(&head, isAscending);
            break;
        case FieldName::FSR_RANK:
            MergeSort<FieldName::FSR_RANK>(&head, isAscending);
            // QuickSort<FieldName::FSR_RANK>(&head, isAscending);
            break;
        case FieldName::CPF_RANK:
            MergeSort<FieldName::CPF_RANK>(&head, isAscending);
            // QuickSort<FieldName::CPF_RANK>(&head, isAscending);
            break;  
        case FieldName::IFR_RANK:
            MergeSort<FieldName::IFR_RANK>(&head, isAscending);
            // QuickSort<FieldName::IFR_RANK>(&head, isAscending);
            break;
        case FieldName::ISR_RANK:
            MergeSort<FieldName::ISR_RANK>(&head, isAscending);
            // QuickSort<FieldName::ISR_RANK>(&head, isAscending);
            break;
        case FieldName::IRN_RANK:
            MergeSort<FieldName::IRN_RANK>(&head, isAscending);
            // QuickSort<FieldName::IRN_RANK>(&head, isAscending);
            break;
        case FieldName::GER_RANK:
            MergeSort<FieldName::GER_RANK>(&head, isAscending);
            // QuickSort<FieldName::GER_RANK>(&head, isAscending);
            break;
    }
}

void UniversityList::searchUniversities(FieldName field)
{
    string searchValue = "";
    cout << endl << "Please enter search value: ";
    getline(cin, searchValue);
    linearSearch(searchValue, field);
}

void UniversityList::displayUniversity(UniversityNode* university) {
    system("cls");
    cout << setw(18) << "Rank: " << university->rank << endl;
    cout << setw(18) << "Institution Name: " << university->institutionName << endl;
    cout << setw(18) << "Location Code: " << university->locationCode << endl;
    cout << setw(18) << "Location: " << university->location << endl;
    cout << setw(18) << "erRank: " << university->erRank << endl;
    cout << setw(18) << "erScore: " << university->erScore << endl;
    cout << setw(18) << "fsrRank: " << university->fsrRank << endl;
    cout << setw(18) << "fsrScore: " << university->fsrScore << endl;
    cout << setw(18) << "cpfRank: " << university->cpfRank << endl;
    cout << setw(18) << "cpfScore: " << university->cpfScore << endl;
    cout << setw(18) << "ifrRank: " << university->ifrRank << endl;
    cout << setw(18) << "ifrScore: " << university->ifrScore << endl;
    cout << setw(18) << "isrRank: " << university->isrRank << endl;
    cout << setw(18) << "isrScore: " << university->isrScore << endl;
    cout << setw(18) << "irnRank: " << university->irnRank << endl;
    cout << setw(18) << "irnScore: " << university->irnScore << endl;
    cout << setw(18) << "gerRank: " << university->gerRank << endl;
    cout << setw(18) << "gerScore: " << university->gerScore << endl;
    cout << setw(18) << "scoreScaled: " << university->scoreScaled << endl;

    int option;
    cout << "1. Write Feedback" << endl;
    cout << "2. Exit" << endl;
    option = readInteger(1, 2);
    switch (option)
    {
    case 1:
        //customerList.sendFeedback(loginCustomer, university, &feedbackList, &uniList);
        break;
    case 2:
        break;
    default:
        break;
    }
}

void UniversityList::displayList(UniversityNode* firstNode, int viewMode)
{
    int selectedViewMode = viewMode;
    if (selectedViewMode == -1) {
        cout << "Do you want to view in RANK mode or SCORE mode?" << endl;
        cout << "Press 1 for RANK mode, press 2 for SCORE mode: ";
        selectedViewMode = readInteger(1, 2);
    }

    cout << "List of universities is having " << size << " of items!" << endl;

	UniversityNode* temp = firstNode;
    int maxNameLength = 0;
    int maxLocationLength = 0;

    for (int i = 0; i < 25; i++ ) {
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

    if (selectedViewMode == 1) {
        cout << std::left << setw(6) << "Rank" << setw(maxNameLength) << "Institution Name" << setw(maxLocationLength) << "Location" <<
            setw(10) << "ArRank" << setw(10) << "ErRank" << setw(10) << "FsrRank" << setw(10) << "CpfRank" << setw(10) << "IfrRank" << setw(10) << "IsrRank" << 
            setw(10) << "IrnRank" << setw(10) << "GerRank" << setw(13) << "ScoreScaled" << endl;
    }
    else {
        cout << std::left << setw(6) << "Rank" << setw(maxNameLength) << "Institution Name" << setw(maxLocationLength) << "Location" <<
            setw(10) << "ArScore" << setw(10) << "ErScore" << setw(10) << "FsrScore" << setw(10) << "CpfScore" << setw(10) << "IfrScore" << setw(10) << "IsrScore" <<
            setw(10) << "IrnScore" << setw(10) << "GerScore" << setw(13) << "ScoreScaled" << endl;
    }

    cout << string(maxNameLength + maxLocationLength + 99, '-') << endl;

    int index = 0;

    if (selectedViewMode == 1) {
        while (index < 25 && temp != nullptr)
        {
            cout << std::left << setw(6) << temp->rank << setw(maxNameLength) << temp->institutionName << setw(maxLocationLength) << temp->location << 
                setw(10) << temp->arRank << setw(10) << temp->erRank << setw(10) << temp->fsrRank << setw(10) << temp->cpfRank << setw(10) << temp->ifrRank << 
                setw(10) << temp->isrRank << setw(10) << temp->irnRank << setw(10) << temp->gerRank << setw(13) << temp->scoreScaled << endl;
            temp = temp->nextUniversity;
            index++;
        }
    }
    else {
        while (index < 25 && temp != nullptr)
        {
            cout << std::left << setw(6) << temp->rank << setw(maxNameLength) << temp->institutionName << setw(maxLocationLength) << temp->location << 
                setw(10) << temp->arScore << setw(10) << temp->erScore << setw(10) << temp->fsrScore << setw(10) << temp->cpfScore << setw(10) << temp->ifrScore << 
                setw(10) << temp->isrScore << setw(10) << temp->irnScore << setw(10) << temp->gerScore << setw(13) << temp->scoreScaled << endl;
            temp = temp->nextUniversity;
            index++;
        }
    }

    int option;

    if (temp == nullptr) {
        cout << endl << "List is ended here!" << endl << endl;
    }
    else {
        cout << endl;
        cout << "1. Next Page" << endl;
        cout << "2. Select University" << endl;
        cout << "3. Exit" << endl;
        cout << "Please select an option: ";
        option = readInteger(1, 3);
        switch (option)
        {
        case 1:
            system("cls");
            displayList(temp, selectedViewMode);
            break;
        case 2:
            int selectedUniversity;
            cout << "Enter University Rank: ";
            selectedUniversity = readInteger(firstNode->rank, temp->rank - 1);
            displayUniversity(uniList.getUniversity(selectedUniversity));
            break;
        case 3:
            return;
        default:
            break;
        }
    }
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

int UniversityList::getSize() {
    return size;
}

