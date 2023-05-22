#ifndef University
#define University

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
    void sortDescendingByArFsrErScore();
    void sortByRank(std::string rank); // not sure if is sort or search
    void searchByName(std::string institutionName);
    void searchByLocation(std::string location);
    void searchByArRank(std::string arRank);
    void searchByErRank(std::string erRank);
    void searchByFsrRank(std::string fsrRank);
    void searchByCpfRank(std::string cpfRank);
    void searchByIfrRank(std::string ifrRank);
    void searchByIsrRank(std::string isrRank);
    void searchByIrnRank(std::string irnRank);
    void searchByGerRank(std::string gerRank);
    void displayList();
};


#endif