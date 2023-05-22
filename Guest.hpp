#ifndef Guest_
#define Guest_

/* GUEST */
class Guest
{
public:
    Guest();
    ~Guest();
    bool registerAccount(std::string memberID, std::string email, std::string password);
    void displayUniversity();
    void sortUniversityByName();
    void searchUniversityByName();
    void searchUniversityByLocation();
};

#endif