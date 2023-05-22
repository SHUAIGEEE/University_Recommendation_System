#ifndef Utilities
#define Utilities

#include "Shared_Variables.hpp"

void mainMenu();
void loginMenu();
void adminLogin();
void adminMenu();
void customerLogin();
void customerMenu();
void guestMenu();
void guestRegister();
void exitPage();
int readInteger(int min, int max);
void readUsernameAndPassword(std::string* username, std::string* password, std::string message);
void readEmail(std::string* email);

/* MERGE SORT */
void FrontBackSplit(UniversityNode* source, UniversityNode** frontRef, UniversityNode** backRef);
template <FieldName Field>
bool compareFieldAsc(UniversityNode* a, UniversityNode* b);
template <FieldName Field>
bool compareFieldDesc(UniversityNode* a, UniversityNode* b);
template <FieldName Field>
UniversityNode* SortedMerge(UniversityNode* a, UniversityNode* b, bool isAscending);
template <FieldName Field>
void MergeSort(UniversityNode** headRef, bool isAscending);

/* QUICK SORT */

/* LINEAR SEARCH */

/* EXPONENTIAL SEARCH */


#endif