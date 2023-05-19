#include <iostream>
#include <string>
#include "University.hpp"

using namespace std;


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

void UniversityList::sortAscendingByName()
{

}

void UniversityList::sortDescendingByArFsrErScore()
{

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

void UniversityList::searchByName(std::string institutionName)
{

}

void UniversityList::searchByLocation(std::string location)
{

}

void UniversityList::searchByArRank(std::string arRank)
{

}

void UniversityList::searchByErRank(std::string erRank)
{

}

void UniversityList::searchByFsrRank(std::string fsrRank)
{

}

void UniversityList::searchByCpfRank(std::string cpfRank)
{

}

void UniversityList::searchByIfrRank(std::string ifrRank)
{

}

void UniversityList::searchByIsrRank(std::string isrRank)
{

}

void UniversityList::searchByIrnRank(std::string irnRank)
{

}

void UniversityList::searchByGerRank(std::string gerRank)
{

}

