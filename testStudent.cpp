/**
 * @file main.cpp
 * @author Adham Mahmoud (20210055)
 * @author Fady Kamal (20210282)
 * @author Mohamed Hesham (20210543)
 * @brief Contains the entry point of programming (program starts and ends here)
 * @version 0.1
 * @date 2023-05-15
 * 
 *  * 
 */

#include <bits/stdc++.h>
#include "./src/AVL.cpp"
#include "./src/Student.cpp"
#include "./src/minHeap.cpp"
#include "./src/maxHeap.cpp"
#include "./src/Utility.cpp"
using namespace std;


void displayMenu(const string& prompt, string& choice);
template<class T>
void ModifyTree(T& tree, const string& treeType);
void getUserCredentials(string& id, string& name, string& gpa, string& dep);
void removeStudent(const string& dataStructureToRemoveFrom="BST");
void searchAStudent(const string& dataStructureToRemoveFrom="BST");
void printTree(const string& dataStructureToRemoveFrom="BST");
void getFileData();


BST<Student> bst_students;
AVL<Student> avl_students;
minHeap<Student> mh_students;
Heap<Student> mx_students;
int no_studs;
string choice;




int main()
{
  // program credentials
  bool ProgramRunning = true, IsFirstTime = true;

  // user choice
  string choice;

  // reading data from file
  getFileData();

  // print header
  Utility::printHeader("Main");
  
  // display menu
  displayMenu(Utility::PROMPTS["Main"], choice);

  // main program
  while (ProgramRunning)
  {
    if (choice == "1")
    {
      ModifyTree(::bst_students, "BST");
    }
    else if (choice == "2")
    {
      ModifyTree(::avl_students, "AVL");
    }
    else if (choice == "3")
    { 
      ModifyTree(::mh_students, "MIN_HEAP");

    }
    else if (choice == "4")
    {
      ModifyTree(::mx_students, "MAX_HEAP");

    }
    else if (choice == "5")
    {
      // finish the program
      ProgramRunning = false;
      break;
    }
    else
    {
      // invalid choice
      Utility::printFromatedMesage("!! Invalid !!");
    }

    // print header
    Utility::printHeader("Main");

    // menus
    displayMenu(Utility::PROMPTS["Main"], choice);
  }
}




/**
 * @author Fady Kamal (20210282)
 * @brief Take input from user and insrted in choice
 * @param prompt Menus prompt and fetched from utilities
 * @param choice Var by reference to recive user input
 */
void displayMenu(const string& prompt, string& choice)
{
  // print prompt
  cout << prompt;

  // take user choice
  getline(cin >> ws, choice);
}


/**
 * @author Fady Kamal (20210282)
 * @brief A template function that modifes all types of trees depening on parameter
 * @tparam T Type of tree that will be managed
 * @param tree Tree that will be managed
 * @param treeType Tree type, for instance (BST, AVL)
 */
template<class T>
void ModifyTree(T& tree, const string& treeType)
{
  // credentials
  string id, name, gpa, deparment;

  // header
  Utility::printHeader(treeType);

  // diplay option prompt to user
  displayMenu(Utility::PROMPTS["StudentCrudOptions"], ::choice);

  // menu with options
  while (true)
  {
    if (::choice == "1")
    {
      // add student
      getUserCredentials(id, name, gpa, deparment);

      // new student
      Student s(stoi(id), name, stod(gpa), deparment);

      // add to tree
      tree.insert(s);

      // print success message
      Utility::printFromatedMesage("!! Added Successfully !!");
      cin.get();
    }
    else if (::choice == "2")
    {
      // delete
      removeStudent(treeType);
    }
    else if (::choice == "3")
    {
      // search a student
      searchAStudent(treeType);
    }
    else if (::choice == "4")
    {
      // print students based on tree name
      printTree(treeType);
    }
    else if (::choice == "5")
    {
        break;
    }
    else
    {
      Utility::printFromatedMesage("!! Invalid !!");
    }

    // header
    Utility::printHeader(treeType);

    // diplay option prompt to user
    displayMenu(Utility::PROMPTS["StudentCrudOptions"], ::choice);
  }
    
}


/**
 * @author Fady kamal (20210282)
 * @brief Get the User Credentials 
 * @param id Var called by refernce to recive user input
 * @param name Var called by refernce to recive user input
 * @param gpa Var called by refernce to recive user input
 * @param dep Var called by refernce to recive user input
 */
void getUserCredentials(string& id, string& name, string& gpa, string& dep)
{
  // sep
  cout << minSep << endl;

  // get valid id from user
  id = Utility::getValidIdFromUser();

  // sep
  cout << minSep << endl;

  // get vaild name 
  name = Utility::getValidNameFromUser();

  // sep
  cout << minSep << endl;

  // get valid gpa
  gpa = Utility::getValidGpaFromUser();

  // sep
  cout << minSep << endl;

  // get valid dep 
  dep = Utility::getValidDeparmentFromUser();

}


/**
 * @author Fady kamal (20210282)
 * @brief Take type of tree from which student will be removed
 * @param dataStructureToRemoveFrom Tree type
 */
void removeStudent(const string& dataStructureToRemoveFrom)
{
  // print sep
  cout << minSep << endl;

  // student id to be removed
  string ID = Utility::getValidIdFromUser();

  // id to int
  int id = stoi(ID);

  // flag with init false to reduce statment
  bool deleted = false;

  if (dataStructureToRemoveFrom == "BST")
  {
    if (bst_students.search(Student(id)))
    {
      // remove
      ::bst_students.Delete(id);
      deleted = true;
    }
  }
  else if (dataStructureToRemoveFrom == "AVL")
  {
    if (::avl_students.search(Student(id)))
    {
      // remove
      ::avl_students.Delete(Student(id));
      deleted = true;
    }
  }
  else if (dataStructureToRemoveFrom == "MIN_HEAP")
  {
    if (::mh_students.search(Student(id)))
    {
      // remove
      ::mh_students.remove(id);
      deleted = true;
    }
  }
  else
  {
    if (::mx_students.search(Student(id)))
    {
      // remove
      ::mh_students.remove(id);
      deleted = true;
    } 
  }

  // converming message
  if (deleted)
  { Utility::printFromatedMesage("!! Student With Id: " + ID + " Deleted Successfully From " + dataStructureToRemoveFrom + " !!"); }

  else
  { Utility::printFromatedMesage("!! Id: " + ID + " Doesn't Exist In " + dataStructureToRemoveFrom + " !!"); }
}


/**
 * @author Fady Kamal (20210282) 
 * @brief Take id from user and check whether exists in given tree or not
 * @param dataStructureToRemoveFrom Tree Type
 */
void searchAStudent(const string& dataStructureToRemoveFrom)
{
  // sep
  cout << minSep << endl;

  // student id to be removed
  string ID = Utility::getValidIdFromUser();

  // id to int
  int id = stoi(ID);

  // flag 
  bool exists = false;

  if (dataStructureToRemoveFrom == "BST")
  {
    exists = bst_students.search(Student(id));
  }
  else if (dataStructureToRemoveFrom == "AVL")
  {
    exists = avl_students.search(Student(id));
  }
  else if (dataStructureToRemoveFrom == "MIN_HEAP")
  {
    exists = mh_students.search(Student(id));
  }
  else
  {
    exists = mx_students.search(Student(id));
  }

  // print message to user
  if(exists)
  {
   Utility::printFromatedMesage("!! Student With Id: " + ID + " Exists In " + dataStructureToRemoveFrom + " !!");
  }
  else
  {
    Utility::printFromatedMesage("!! Student With Id: " + ID + " Not Found In " + dataStructureToRemoveFrom + " !!");
  }

}


/**
 * @author Fady Kamal (20210282)
 * @brief Print all studens existing in the tree
 * @param dataStructureToRemoveFrom Type of tree
 */
void printTree(const string& dataStructureToPrintAllStudents)
{
  // sep
  Utility::printFromatedMesage("Students In Tree: ");

  if (dataStructureToPrintAllStudents == "BST")
  {
    ::bst_students.inOrder();
  }
  else if (dataStructureToPrintAllStudents == "AVL")
  {
    ::avl_students.inOrder();
  }
  else if (dataStructureToPrintAllStudents == "MIN_HEAP")
  {
    ::mh_students.printHeap();
  }
  else
  {
    ::mx_students.printHeap();
  }

}


/**
 * @author Mohamed Hesham (20210543)
 * @brief Reads data from input file to trees
 * 
 */
void getFileData()
{
  fstream my_file;
	my_file.open("input_files/file1.txt", ios::in);
  string numberOfStud;
  getline(my_file, numberOfStud);
  no_studs = stoi(numberOfStud);
  
  Utility::printFromatedMesage(" !! Reading from the file !!");

  while (no_studs--)
  {
    
    string id_str, gpa_str;
    Student st;
    getline(my_file, id_str);
    int id = stoi(id_str);
    st.setID(id);



    string name;
    getline(my_file, name);
    st.setName(name);

    
    getline(my_file, gpa_str);
    double gpa = stod(gpa_str);
    st.setGPA(gpa);


    string dep; 
    getline(my_file, dep);
    st.setDepartment(dep);
    
    avl_students.insert(st);
    bst_students.insert(st);
    mh_students.insert(st);
    mx_students.insert(st);

    cout << st;
  }
  Utility::printFromatedMesage(" !! Finished reading from the file !!");
  my_file.close();
}
