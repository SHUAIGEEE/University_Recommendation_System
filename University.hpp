#ifndef University
#define University

#include "Shared_Variables.hpp"

/* UNIVERSITY */
struct UniversityNode
{
    int rank;
    double arScore, erScore, fsrScore, cpfScore, ifrScore, isrScore, irnScore, gerScore, scoreScaled;
    std::string institutionName, locationCode, location, arRank, erRank, fsrRank, cpfRank, ifrRank, isrRank, irnRank, gerRank;
    UniversityNode* nextUniversity;
};

class UniversityList
{
private:
    UniversityNode* head = nullptr;
    UniversityNode* tail = nullptr;
    int size = 0;

public:
    UniversityList();
    ~UniversityList();
    UniversityNode * createUniversityNode(std::string rank, std::string arScore, std::string erScore, std::string fsrScore, std::string cpfScore, std::string ifrScore,
        std::string isrScore, std::string irnScore, std::string gerScore, std::string scoreScaled, std::string institutionName, std::string locationCode,
        std::string location, std::string arRank, std::string erRank, std::string fsrRank, std::string cpfRank, std::string ifrRank, std::string isrRank,
        std::string irnRank, std::string gerRank);
    void insertEnd(std::string rank, std::string arScore, std::string erScore, std::string fsrScore, std::string cpfScore, std::string ifrScore,
        std::string isrScore, std::string irnScore, std::string gerScore, std::string scoreScaled, std::string institutionName, std::string locationCode,
        std::string location, std::string arRank, std::string erRank, std::string fsrRank, std::string cpfRank, std::string ifrRank, std::string isrRank,
        std::string irnRank, std::string gerRank);
    void sortByName();
    void sortUniversities(FieldName field);
    void searchUniversities(FieldName field);
    void displayList();
    UniversityNode* getHead();
    UniversityNode* getTail();
    UniversityNode* getUniversity(int index);
    int getSize();
};


#endif