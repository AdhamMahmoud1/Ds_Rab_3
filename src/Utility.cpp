
#include "..\includes\Utility.hpp"

map<string, string> Utility::PROMPTS = {
    {"Main", "1- BST\n2- AVL\n3- Min Heap\n4- Max Heap\n5- Exit\n\nData Structure to store data: "},
    {"StudentCrudOptions", "1- Add Student\n2- Remove Student\n3- Search Student\n4- print All(sorted by id)\n5- Back to previous menu\n\nwhat do you want to do: "},
  
};

/**/
std::string Utility::s_ClassDescription = "";


/**/
bool Utility::checkCinFaliure()
{
    if (cin.fail())
    {
        cout << "##########################" << "\n";
        cout << "ERROR -- You did not enter an integer\n";

        // get rid of failure state
        cin.clear();

        // discard 'bad' character(s) 
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        return true;
    }
    else
    {
        return false;
    }
}

void Utility::printFromatedMesage(const string& message, bool forInput)
{
    // print sep anyway
    cout << sep << endl;

    // check if for input or regular message
    if (forInput)
    {
        cout << message;
    }
    else
    {
        cout << message << endl;
    }
}

void Utility::printHeader(const string& title)
{
    // sep the prefvious
    cout << sep << endl;
    cout << headerSep << " " <<  title << " " << headerSep << endl;

}


bool Utility::isValidName(string name)
{
    regex pattern("^[a-zA-Z]{2,}(?: [a-zA-Z]+){0,3}$");
    
    return regex_match(name, pattern);
}

bool Utility::isValidPhoneNumber(string phoneNumber)
{
    regex pattern("^(010|011|012|015)\\d{8}$");
    return regex_match(phoneNumber, pattern);
}

bool Utility::isValidAddress(string address)
{
    regex pattern("");
    return regex_match(address, pattern);
}

/**/
bool Utility::isValidAmountOfMoney(double amountOfMoney)
{
    // amount of money is a nonnegative value
    return (amountOfMoney >= 0);
}

bool Utility::isValidAccountID(string accountID)
{
    regex pattern("^FCAI\\-\\d+$");
    return regex_match(accountID, pattern);
}

bool Utility::isValidGpa(string gpa)
{
    regex pattern("^[0]|[0-3](\\.(\\d?\\d?)|[4].[0])?$");
    return regex_match(gpa, pattern);
}

bool Utility::isValidId(string id)
{
    regex pattern("^\\d+$");
    return regex_match(id, pattern);
}

bool Utility::isValidDepartment(string dep)
{
    regex pattern("/^(is|ds|cs|ai|it)$/i");
    return true;
}

string Utility::getValidNameFromUser()
{
    // name to store user input
    string name;

    // take input from user
    cout << "Name: ";
    getline(cin >> ws, name);

    while (!isValidName(name))
    {
        cout << "###########################" << "\n";
        cout << "!! Invalid Name !!" << "\n";
        cout << "###########################" << "\n";

        cout << "Please Enter A Valid Name  (e.g., Fady Kamal) : ";
        getline(cin >> ws, name);
    }

    return name;

}

string Utility::getValidIdFromUser()
{
    // id to store user input
    string id;

    // take input from user
    cout << "Id: ";
    getline(cin >> ws, id);

    while (!isValidId(id))
    {
        cout << "###########################" << "\n";
        cout << "!! Invalid Id !!" << "\n";
        cout << "###########################" << "\n";

        cout << "Please Enter A Valid Id  (e.g., 1) : ";
        getline(cin >> ws, id);
    }

    return id;

}


string Utility::getValidPhoneNumberFromUser()
{
    // phoneNumber to store user input
    string phoneNumber;

    // take input from user
    cout << "Phone Number: ";
    getline(cin >> ws, phoneNumber);

    while (!isValidPhoneNumber(phoneNumber))
    {
        cout << "###########################" << "\n";
        cout << "!! Invalid Phone Number !!" << "\n";
        cout << "###########################" << "\n";
        cout << "Please Enter A Valid Phone Number (e.g., 01212345678) : ";
        getline(cin >> ws, phoneNumber);
    }

    return phoneNumber;
}

string Utility::getValidAddressFromuser()
{
    // address to store user input
    string address;

    // take input from user
    cout << "Address: ";
    getline(cin >> ws, address);

    while (!isValidName(address))
    {
        cout << "###########################" << "\n";
        cout << "!! Invalid Address !!" << "\n";
        cout << "###########################" << "\n";

        cout << "Please Enter A Valid Address: ";
        getline(cin >> ws, address);
    }
    return address;
}

double Utility::getValidAmountOfMoneyFromUser(bool isFirstTime)
{
    double amount;

    if (isFirstTime)
    {
        // inittial balance
        cout << "Please Enter the Starting Balance: ";
    }
    else
    {
        cout << "Amount Of Money: ";
    }

    // variable to store user input
    cin >> amount;

    while(!isValidAmountOfMoney(amount) || Utility::checkCinFaliure())
    {
        cout << "###########################" << "\n";
        cout << "!! Invalid Amount Of Money !!" << "\n";
        cout << "###########################" << "\n";

        cout << "Please Enter A Valid Amount Of Money (e.g., 100.15) : ";
        cin >> amount;
    }
    return amount;
    
}

string Utility::getValidAccountID()
{
    // variable to store user input
    string accoutID;

    cout << "AccountID: ";
    getline(cin >> ws, accoutID);

    while (!isValidAccountID(accoutID))
    {
        cout << "###########################" << "\n";
        cout << "!! Invalid AccountID !!" << "\n";
        cout << "###########################" << "\n";

        cout << "Please Enter A Valid AccountID (e.g., FCAI-1)  : ";
        getline(cin >> ws, accoutID);
    }
    return accoutID;
}


string Utility::getValidGpaFromUser()
{
    // name to store user input
    string gpa;

    // take input from user
    cout << "gpa: ";
    getline(cin >> ws, gpa);

    while (!isValidGpa(gpa))
    {
        cout << "###########################" << "\n";
        cout << "!! Invalid GPA !!" << "\n";
        cout << "###########################" << "\n";

        cout << "Please Enter A Valid Gpa  (e.g., 3.56) : ";
        getline(cin >> ws, gpa);
    }

    return gpa;
}

//
void convertIntoUpperCase(string& s)
{
    for(auto& c: s) c = toupper(c);
}

string Utility::getValidDeparmentFromUser()
{
    // dep to store user input
    string dep;

    // take input from user
    cout << "Deparment: ";
    getline(cin >> ws, dep);

    while (!isValidDepartment(dep))
    {
        cout << "###########################" << "\n";
        cout << "!! Invalid Deparment !!" << "\n";
        cout << "###########################" << "\n";

        cout << "Please Enter A Valid Department  (e.g., Is, Cs, Ds) : ";
        getline(cin >> ws, dep);
    }
    
    // convert dep into upper case
    convertIntoUpperCase(dep);

    return dep;
}

