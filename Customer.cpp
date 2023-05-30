#include <iostream>
#include <string>
#include "Customer.hpp"
#include "Utilities.hpp"
#include "Shared_Variables.hpp"
#include "University.hpp"
#include "Utilities.hpp"
#include <sstream>
#include <ctime>

using namespace std;

Customer::Customer()
{
}

Customer::Customer(string customerID, string username, string email, string password)
{
    this->customerID = customerID;
    this->username = username;
    this->email = email;
    this->password = password;
}

Customer::~Customer()
{
}

string Customer::getCustomerID()
{
    return this->customerID;
}

string Customer::getUsername()
{
    return this->username;
}

string Customer::getEmail()
{
    return this->email;
}

string Customer::getPassword()
{
    return this->password;
}

void Customer::setCustomerID(string customerID)
{
    this->customerID = customerID;
}

void Customer::setUsername(string username)
{
    this->username = username;
}

void Customer::setEmail(string email)
{
    this->email = email;
}

void Customer::setPassword(string password)
{
    this->password = password;
}

CustomerList::CustomerList()
{
}

CustomerList::~CustomerList()
{
}

CustomerNode* CustomerList::createCustomerNode(string customerID, string username, string email, string password)
{
    CustomerNode * newNode = new CustomerNode;

    newNode->customer = Customer(customerID, username, email, password);
    newNode->favourites = nullptr;
    newNode->nextCustomer = nullptr;

    return newNode;
}

void CustomerList::insertEnd(string customerID, string username, string email, string password)
{
    CustomerNode* newNode = createCustomerNode(customerID, username, email, password);

    if (head == nullptr)
    {
        head = newNode;
    }
    else 
    {
        CustomerNode* current = head; 
        
        while (current->nextCustomer != nullptr) 
        {
            current = current->nextCustomer;
        }
        
        current->nextCustomer = newNode;
    }
    size++;
}

string CustomerList::generateCustomerID()
{
    int size = customerList.getSize();
    if (size < 1000) return "C00" + to_string(size + 1);
    else if (size < 100) return "C0" + to_string(size + 1);
    else return "C" + to_string(size + 1);
}

void CustomerList::deleteCustomer()
{
}

void CustomerList::displayList()
{
	CustomerNode* temp = head;

	while (temp != nullptr)
	{
		cout << temp->customer.getCustomerID() << " - " << temp->customer.getUsername()
        << " - " << temp->customer.getEmail() << " - " << temp->customer.getPassword() << endl;
		temp = temp->nextCustomer;
	}

	cout << endl << "List is ended here!" << endl << endl;
}

CustomerNode* CustomerList::getHead()
{
    return head;
}

CustomerNode* CustomerList::getTail()
{
    return tail;
}

int CustomerList::getSize()
{
    return size;
}

bool CustomerList::login(string username, string password)
{
    CustomerNode* temp = head;

    while (temp != nullptr)
    {
        if (temp->customer.getUsername() == username && temp->customer.getPassword() == password)
        {
            loginCustomer.setUsername(username);
            loginCustomer.setPassword(password);
            loginCustomer.setCustomerID(temp->customer.getCustomerID());
            loginCustomer.setEmail(temp->customer.getEmail());
            return true;
        }
        else
        {
            temp = temp->nextCustomer;
        }
    }
    return false;
}

void CustomerList::logout()
{
    loginCustomer.setCustomerID("");
    loginCustomer.setUsername("");
    loginCustomer.setEmail("");
    loginCustomer.setPassword("");
    cout << "Logout successful!" << endl;
}

void CustomerList::displayUniversity()
{
    uniList.displayList();

    //TODO save as favourite

    //如果要换成一个一个uni view的话，可以直接pass currentUni 进去write feedback
    int selectedUni = -1;
    while (selectedUni < 1 || selectedUni > uniList.getSize()) {
        cout << "Select University to Write a Feedback (1 - " << uniList.getSize() << "): ";
        selectedUni = readInteger(1, uniList.getSize());
    }
    UniversityNode* selectedUniversity = uniList.getUniversity(selectedUni);

    customerList.sendFeedback(loginCustomer, selectedUniversity, &feedbackList, &uniList); 
}

void CustomerList::sortUniversities()
{
    uniList.sortUniversities(getSortField());
    uniList.displayList(); // can change to display sorted list
}

void CustomerList::searchUniversities()
{
    uniList.searchUniversities(getSearchField());
}

FavouriteNode *CustomerList::createFavouriteNode(int universityRank)
{
    FavouriteNode* newNode = new FavouriteNode;
    newNode->universityRank = universityRank;
    newNode->nextFavourite = nullptr;
    return newNode;
}

void CustomerList::saveFavouriteUniversity(int universityRank)
{
    FavouriteNode* newNode = createFavouriteNode(universityRank);
    if (loginCustomer.getCustomerID().empty()) {
        cout << "Please log in to save a favourite university." << endl;
        return;
    } 
    if (head == nullptr) {
        head = createCustomerNode("", "", "", "");
        head->favourites = newNode;
        tail = head;
    }
    else {
        tail->nextCustomer = createCustomerNode("", "", "", "");
        tail->nextCustomer->favourites = newNode;
        tail = tail->nextCustomer;
    }
    cout << "University has successfully saved as favourite!" << endl;
}
 
void CustomerList::deleteFavouriteUniversity(int universityRank)
{
    if (head == nullptr) {
        cout << "List of favourite universities is empty." << endl;
        return;
    }
    CustomerNode* current = head;
    CustomerNode* previous = nullptr;

    while (current != nullptr) {
        FavouriteNode* favCurrent = current->favourites;
        FavouriteNode* favPrevious = nullptr;

        while (favCurrent != nullptr) {
            if (favCurrent->universityRank == universityRank) {
                if (favPrevious == nullptr) {
                    //Removing head node
                    current->favourites = favCurrent->nextFavourite;
                }
                else {
                    favPrevious->nextFavourite = favCurrent->nextFavourite;
                }
                delete favCurrent;
                cout << "University has been removed from favourites." << endl;
                return;
            }
            favPrevious = favCurrent;
            favCurrent = favCurrent->nextFavourite;
        }
        previous = current;
        current = current->nextCustomer;
    }
    cout << "University not found in favourites!" << endl;
}

void CustomerList::showFavouriteUniversities()
{
    if (head == nullptr) {
        cout << "List of favourite universities is empty." << endl;
        return;
    }
    CustomerNode* current = head;
    while (current != nullptr) {
        FavouriteNode* favCurrent = current->favourites;
        while (favCurrent != nullptr) {
            cout << "University Rank: " << favCurrent->universityRank << endl;
            //Display the details of the university based on the rank
            UniversityNode* university = uniList.getUniversity(favCurrent->universityRank);
            if (university != nullptr) {
                cout << "University Name: " << university->institutionName << endl;
                cout << "Location: " << university->location << endl;
                cout << "Ar Score: " << university->arScore << endl;
                cout << "Ar Rank: " << university->arRank << endl;
                cout << "Er Score: " << university->erScore << endl;
                cout << "Er Rank: " << university->erRank << endl;
                cout << "Fsr Score: " << university->fsrScore << endl;
                cout << "Fsr Rank: " << university->fsrRank << endl;
                cout << "Cpf Score: " << university->cpfScore << endl;
                cout << "Cpf Rank " << university->cpfRank << endl;
                cout << "Ifr Score: " << university->ifrScore << endl;
                cout << "Ifr Rank: " << university->ifrRank << endl;
                cout << "Isr Score: " << university->isrScore << endl;
                cout << "Isr Rank: " << university->isrRank << endl;
                cout << "Irn Score: " << university->irnScore << endl;
                cout << "Irn Rank: " << university->irnRank << endl;
                cout << "Ger Score: " << university->gerScore << endl;
                cout << "Ger Rank: " << university->gerRank << endl;
                cout << "Score Scaled: " << university->scoreScaled << endl;
            }
            else {
                cout << "University details not found: " << favCurrent->universityRank << endl;
            }
            favCurrent = favCurrent->nextFavourite;
        }
        current = current->nextCustomer;
    }
    cout << endl;
    cout << "1. Save a new university as favourite" << endl;
    cout << "2. Removed a university from favourites" << endl;
    cout << "3. Show all saved university" << endl;
    cout << "4. Back" << endl;
    cout << "Please select an option: ";
    int viewSaveOption = readInteger(1, 4);
    switch (viewSaveOption)
    {
    case 1: {
        int universityRank;
        cout << "Enter the university rank to save as favourites: ";
        cin >> universityRank;
        saveFavouriteUniversity(universityRank);
        break;
    }
    case 2: {
        int universityRank;
        cout << "Enter the university rank to remove from favourites: ";
        cin >> universityRank;
        deleteFavouriteUniversity(universityRank);
        break;
    }
    case 3:
        showFavouriteUniversities();
        break;
    case 4:
        return;
    default:
        break;
    }
}

void CustomerList::sendFeedback(Customer customer, UniversityNode* university, FeedbackList* feedbackList, UniversityList* universityList)
{
    string feedbackContent = "";
    cin.ignore();
    cout << "Please enter your feedback: ";
    getline(cin, feedbackContent);

    time_t rawTime = time(nullptr);
    struct tm* timeInfo = localtime(&rawTime);
    feedbackList->insertIntoSortedList(customer.getCustomerID(), university, feedbackContent, *timeInfo);
    cout << "Thank you for your feedback!" << endl;
    system("pause");
}

void CustomerList::viewAllFeedbacks(Customer customer) {
    FeedbackNode* current = feedbackList.getHead();
    int* feedbackIndeces = new int(feedbackList.getSize());
    int index = 0;
    int loopIndex = 0;
    while (current != nullptr) {
        if (current->customerID == customer.getCustomerID()) {
            feedbackIndeces[index] = loopIndex;
            cout << index + 1 << ". " << current->university->institutionName << " - " << current->feedbackContent << endl;
            index++;
            char formattedTime[50];
            strftime(formattedTime, sizeof(formattedTime), "%d-%m-%Y %a %H:%M:%S", &current->timePosted);
            cout << "   Last Updated: " << formattedTime << endl;
        }
        current = current->nextFeedback;
        loopIndex++;
    }
    cout << "Please select a feedback to view (Press 0 to go back): ";
    int viewFeedbackOption = readInteger(0, index);
    if (viewFeedbackOption == 0) {
        return;
    }
    viewFeedbackReply(customer, feedbackList.getFeedbackNode(feedbackIndeces[viewFeedbackOption - 1], &feedbackList));
}

void CustomerList::viewFeedbackReply(Customer customer, FeedbackNode* feedback)
{
    cout << "University Name: " << feedback->university->institutionName << endl;
    char formattedTime[50];
    strftime(formattedTime, sizeof(formattedTime), "%d-%m-%Y %a %H:%M:%S", &feedback->timePosted);
    cout << "Last Updated: " << formattedTime << endl;
    cout << "Feedback: " << feedback->feedbackContent << endl;
    if (feedback->replies != nullptr) {
        cout << "Replies: " << endl;
        ReplyNode* currentReplies = feedback->replies;
        while (currentReplies != nullptr) {
            if (currentReplies->isAdmin) {
                cout << "Admin: " << currentReplies->content << endl;
            }
            else {
                cout << feedback->customerID << ": " << currentReplies->content << endl;
            }
            currentReplies = currentReplies->nextReply;
        }
    }

    cout << endl;
    cout << "1. Write a Reply" << endl;
    cout << "2. View Previous Feedback" << endl;
    cout << "3. View Next Feedback" << endl;
    cout << "4. Back" << endl;
    cout << "Please select an option: ";
    int viewFeedbackOption = readInteger(1, 4);
    switch (viewFeedbackOption)
    {
    case 1:
        sendFeedbackReply(feedback);
        viewFeedbackReply(customer, feedback);
        break;
    case 2:
        if (feedback->prevFeedback != NULL) {
            viewFeedbackReply(customer, feedback->prevFeedback);
            break;
        }
        else {
            cout << endl << "This is already the first feedback!" << endl;
            system("pause");
            viewFeedbackReply(customer, feedback);
            break;
        }
    case 3:
        if (feedback->nextFeedback != NULL) {
            viewFeedbackReply(customer, feedback->nextFeedback);
            break;
        }
        else {
            cout << endl << "This is already the last feedback!" << endl;
            system("pause");
            viewFeedbackReply(customer, feedback);
            break;
        }
    case 4:
        viewAllFeedbacks(customer);
    default:
        break;
    }
}

void CustomerList::sendFeedbackReply(FeedbackNode* feedback)
{
    string replyContent = "";
    cin.ignore();
    cout << "Please enter your reply: ";
    getline(cin, replyContent);

    time_t rawTime = time(nullptr);
    struct tm* timeInfo = localtime(&rawTime);
    feedbackList.addReply(replyContent, false, *timeInfo, feedback, false);
    cout << "Your reply has been sent!" << endl;
    system("pause");
}
