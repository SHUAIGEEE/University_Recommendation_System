#ifndef Shared_Variables
#define Shared_Variables

class Admin;
class Guest;
class Customer;
class UniversityList;
class CustomerList;
class FeedbackList;

struct UniversityNode;
struct CustomerNode;
struct FeedbackNode;

extern Admin admin;
extern Guest guest;
extern Customer loginCustomer;
extern UniversityList uniList;
extern CustomerList customerList;
extern FeedbackList feedbackList;
extern UniversityList searchResult;

enum class FieldName
{
    RANK,
    INSTITUTION_NAME,
    LOCATION,
    AR_FSR_ER_SCORE,
    AR_RANK,
    ER_RANK,
    FSR_RANK,
    CPF_RANK,
    IFR_RANK,
    ISR_RANK,
    IRN_RANK,
    GER_RANK
};

#endif