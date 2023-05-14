
#include <bits/stdc++.h>
#include "./src/AVL.cpp"
#include "./src/Student.cpp"
using namespace std;


BST<Student> b_students;
AVL<Student> students;

void getFileData();

int main()
{

  getFileData();



  cout << "Choose the Data Structure : \n";

  cout << " 1- BST\n 2-AVL \n";

  int choice;
  cin >> choice;

  cout << "Choose one of the following options: \n";
  if(choice == 1){
    
  }else if(choice == 2){
    while (true)
    {
      /* code */
      cout << " 1- Add Student \n 2- Remove Student \n 3- Search Student \n 4- print All(sorted by id) \n";
      int option;
      cin >> option;

      int id;
      string name ; string dep;
      double GPA;
      Student newStud = Student();
      switch (option)
      {
      case 1:
        cout << "Enter the id : ";
        cin >> id;
        cout << "\nEnter the name : ";
        cin.ignore();
        getline (cin , name);
        cout << "\nEnter the GPA : ";
        cin >> GPA;
        cout << "\nEnter the Department : ";
        cin >> dep;
        newStud.setID(id); newStud.setName(name); newStud.setGPA(GPA);
        newStud.setDepartment(dep);

        students.insert(newStud);

        break;

      

      case 3:
        cout << "Enter the student ID: ";
        int ID; 
        cin >> ID;
        if(students.search(Student(ID))){
          cout << "Student is found \n";
        }else{
          cout << "Student is NOT found \n";
        }
        break;
      case 4:
        // لسا معملتهاش تجربة بس
        students.preOrder();
      
        break;
      default:
        break;
    }
    }
  }
/*     BST<int> b;
    b.insert(45);
    b.insert(15);
    b.insert(79);
    b.insert(90);
    b.insert(10);
    b.insert(55);
    b.insert(12);
    b.insert(50);

    cout << "Display the Tree Contenet: \n";
    b.preOrder();

    cout << "\nenter item to search for : ";
    int key;
    cin >> key;
    if (b.search(key))
    {
        cout << "Item Found \n";
    }
    else
    {
        cout << "Item Not Found\n";
    }

    b.Delete(10);
    b.preOrder();
 */
}

void getFileData(){
  fstream my_file;
	my_file.open("input_files/file1.txt", ios::in);
  string numberOfStud;
  getline(my_file, numberOfStud);
  int no_studs = stoi(numberOfStud);
  
  cout << "Reading from the file \n";

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
    
    students.insert(st);
    cout << id << " " << dep << " " << name << " " << gpa << endl;
    // b_students.insert(st);
  }
  cout << "finished reading from the file \n";
  my_file.close();
}