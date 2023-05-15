
#include <bits/stdc++.h>
#include "./src/AVL.cpp"
#include "./src/Student.cpp"
#include "./src/minHeap.cpp"
#include "./src/maxHeap.cpp"

using namespace std;


BST<Student> bst_students;
AVL<Student> avl_students;
minHeap<Student> mh_students;
Heap<Student> mx_students;

int no_studs;

void getFileData();


int main()
{
  getFileData();



  cout << "Choose the Data Structure : \n";

  cout << " 1- BST\n 2-AVL \n 3- min Heap \n 4- max Heap\n";

  int choice;
  cin >> choice;

  cout << "Choose one of the following options: \n";
  if(choice == 1){
      while(true){
        cout << " 1- Add Student \n 2- Remove Student \n 3- Search Student \n 4- print All(sorted by id) \n 5- Exit \n";
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

            bst_students.insert(newStud);

            break;

          case 2:
            cout << "Enter the Student's ID to be removed : ";
            cin >> id;
            bst_students.Delete(id);
            break;

          case 3:
            cout << "Enter the student ID: ";
            int ID; 
            cin >> ID;
            if(bst_students.search(Student(ID))){
              cout << "Student is found \n";
            }else{
              cout << "Student is NOT found \n";
            }
            break;
          case 4:
            cout << "\n\t";
            bst_students.inOrder();
            cout << endl;
            bst_students.countStudentsByDepartment();
          
            break;

          default:
            return 0;
        }
      }
    
  }else if(choice == 2){
    while (true)
    {
      
      cout << " 1- Add Student \n 2- Remove Student \n 3- Search Student \n 4- print All(sorted by id) \n 5- Exit \n";
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

          avl_students.insert(newStud);

          break;

        case 2:
          cout << "Enter the Student's ID to be removed : ";
          cin >> id;
          avl_students.Delete(id);
          break;

        case 3:
          cout << "Enter the student ID: ";
          int ID; 
          cin >> ID;
          if(avl_students.search(Student(ID))){
            cout << "Student is found \n";
          }else{
            cout << "Student is NOT found \n";
          }
          break;
        case 4:
            cout << "\n\t";
            bst_students.inOrder();
            cout << endl;
            bst_students.countStudentsByDepartment();
        
          break;
        default:
          return 0;
      }
    }
  }else if(choice == 3){
    while (true)
    {
      cout << " 1- Add Student \n 2- Remove Student \n 3- Search Student \n 4- print All(sorted by id) \n 5- Exit \n";
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

          mh_students.insert(newStud);

          break;

        case 2:
          cout << "Enter the Student's ID to be removed : ";
          cin >> id;
          mh_students.remove(id);
          break;

        case 3:
          cout << "Enter the student ID: ";
          int ID; 
          cin >> ID;
          if(mh_students.search(Student(ID))){
            cout << "Student is found \n";
          }else{
            cout << "Student is NOT found \n";
          }
          break;
        case 4:
          cout << " ";
          mh_students.printHeap();
          
        
          break;
        
        default:
          return 0;
      }
      
    }
    
  }else if(choice == 4){
    while (true)
    {
      cout << " 1- Add Student \n 2- Remove Student \n 3- Search Student \n 4- print All(sorted by id) \n 5- Exit \n";
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

          mx_students.insert(newStud);

          break;

        case 2:
          cout << "Enter the Student's ID to be removed : ";
          cin >> id;
          mx_students.remove(id);
          break;

        case 3:
          cout << "Enter the student ID: ";
          int ID; 
          cin >> ID;
          if(mx_students.search(Student(ID))){
            cout << "Student is found \n";
          }else{
            cout << "Student is NOT found \n";
          }
          break;
        case 4:
          cout << " ";
          mx_students.printHeap();
          
        
          break;
        
        default:
          return 0;
      }
      
    }
  }
}

void getFileData(){
  fstream my_file;
	my_file.open("input_files/file1.txt", ios::in);
  if(my_file.is_open()){
    string numberOfStud;
    getline(my_file, numberOfStud);
    no_studs = stoi(numberOfStud);
    
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
      
      avl_students.insert(st);
      bst_students.insert(st);
      mh_students.insert(st);
      mx_students.insert(st);


      cout << st;
      // b_students.insert(st);
    }
    cout << "finished reading from the file \n";

    my_file.close();
  }else{
    cout << "File is does'nt Exist\n";
  }
}
