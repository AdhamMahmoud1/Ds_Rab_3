#pragma once
#include <iostream>
#include <string>
#include <regex>
#include <limits>
#include <map>
#include <algorithm>
#define endl "\n"
#define sep "#########################################"
#define minSep "###########################"
#define headerSep "*****************"
using namespace std;

class Utility
{
public:
    /* Static Attriubtes */
    static std::string s_ClassDescription;
    static map<string, string> PROMPTS;


public:
    /* Static Methods*/

    static bool isValidName(string name);    
    static bool isValidPhoneNumber(string phoneNumber);
    static bool isValidAddress(string  address);
    static bool isValidAmountOfMoney(double amountOfMoney);
    static bool isValidAccountID(string accountID);
    static bool isValidGpa(string gpa);
    static bool isValidId(string id);
    static bool isValidDepartment(string dep);

    static string getValidNameFromUser();
    static string getValidPhoneNumberFromUser();
    static string getValidAddressFromuser();
    static double getValidAmountOfMoneyFromUser(bool isFirstTime);
    static string getValidAccountID();
    static string getValidGpaFromUser();
    static string getValidIdFromUser();
    static string getValidDeparmentFromUser();

    bool static checkCinFaliure();
    void static printFromatedMesage(const string& message, bool forInput=false);
    void static printHeader(const string& title);

};
