#ifndef Shared_Variables
#define Shared_Variables

#include "Admin.hpp"
#include "Customer.hpp"
#include "Guest.hpp"
#include "University.hpp"
#include "Feedback.hpp"

extern Admin admin;
extern Guest guest;
extern Customer loginCustomer;
extern UniversityList uniList;
extern CustomerList customerList;
extern FeedbackList feedbackList;

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