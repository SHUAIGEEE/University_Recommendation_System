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
    UniversityNode* newNode = createUniversityNode(rank, institutionName, locationCode, location, arScore, arRank, erScore, erRank,
    fsrScore, fsrRank, cpfScore, cpfRank, ifrScore, ifrRank, isrScore, isrRank, irnScore, irnRank, gerScore, gerRank, scoreScaled);

    if (head == nullptr)
    {
        head = newNode;
    }
    else 
    {
        UniversityNode* current = head; 
        
        while (current->nextUniversity != nullptr) 
        {
            current = current->nextUniversity;
        }
        
        current->nextUniversity = newNode;
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

void UniversityList::sortDescendingByArFsrErScore()
{
    cout << "Sorting in..." << endl;
    cout << "1. Ascending order" << endl;
    cout << "2. Descending order" << endl;
    cout << "Enter your choice: ";

    int order = readInteger(1, 2);

    if (order == 1)
    {
        cout << "Sorting in ascending order..." << endl;
        MergeSort<FieldName::INSTITUTION_NAME>(&head, true);
        // QuickSort<FieldName::INSTITUTION_NAME>(&head, true);
    }
    else
    {
        cout << "Sorting in descending order..." << endl;
        MergeSort<FieldName::INSTITUTION_NAME>(&head, false);
        // QuickSort<FieldName::INSTITUTION_NAME>(&head, false);
    }
}

void UniversityList::sortByRank(string rank)
{
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

