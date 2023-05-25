#include <iostream>
#include <string>
#include <chrono>
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

    cout << "Sorting with..." << endl;
    cout << "1. Merge sort" << endl;
    cout << "2. Quick sort" << endl;
    cout << "Enter your choice: ";

    int sort = readInteger(1, 2);

    if (order == 1)
    {
        cout << "Sorting in ascending order..." << endl;

        if (sort == 1)
        {
            auto start = high_resolution_clock::now();
            MergeSort<FieldName::INSTITUTION_NAME>(&head, true);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            cout << "Time taken by MERGE SORT algorithm: " << duration.count() << " microseconds." << endl;
        }
        else if (sort == 2)
        {
            auto start = high_resolution_clock::now();
            // QuickSort<FieldName::INSTITUTION_NAME>(&head, true);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            cout << "Time taken by QUICK SORT algorithm: " << duration.count() << " microseconds." << endl;
        }
    }
    else
    {
        cout << "Sorting in descending order..." << endl;

        if (sort == 1)
        {
            auto start = high_resolution_clock::now();
            MergeSort<FieldName::INSTITUTION_NAME>(&head, false);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            cout << "Time taken by MERGE SORT algorithm: " << duration.count() << " microseconds." << endl;
        }
        else if (sort == 2)
        {
            auto start = high_resolution_clock::now();
            // QuickSort<FieldName::INSTITUTION_NAME>(&head, false);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            cout << "Time taken by QUICK SORT algorithm: " << duration.count() << " microseconds." << endl;
        }
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

void UniversityList::displayList()
{
    cout << "List of universities is having " << size << " of items!" << endl;

	UniversityNode* temp = head;

	while (temp != NULL)
	{
		cout << temp->institutionName << " - " << temp->rank << endl;
		temp = temp->nextUniversity;
	}

	cout << endl << "List is ended here!" << endl << endl;
}

void UniversityList::searchByName(string institutionName)
{

}

void UniversityList::searchByLocation(string location)
{

}

void UniversityList::searchByArRank(string arRank)
{

}

void UniversityList::searchByErRank(string erRank)
{

}

void UniversityList::searchByFsrRank(string fsrRank)
{

}

void UniversityList::searchByCpfRank(string cpfRank)
{

}

void UniversityList::searchByIfrRank(string ifrRank)
{

}

void UniversityList::searchByIsrRank(string isrRank)
{

}

void UniversityList::searchByIrnRank(string irnRank)
{

}

void UniversityList::searchByGerRank(string gerRank)
{

}

