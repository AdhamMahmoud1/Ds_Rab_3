#include "../includes/Student.hpp"

// constructors
Student::Student() : id(0), name(""), GPA(0), department(" ") {};
Student::Student(int ID) : id(ID), name(""), GPA(0), department(" ") {};

Student::Student(int id, std::string name, double GPA, std::string department)
    : id(id), name(name), GPA(GPA), department(department){}



// getters

int Student::getID(){
  return id;
}

string Student::getName(){
  return name;
}

string Student::getDepartment(){
  return department;
}

double Student::getGPA(){
  return GPA;
}


// setters

void Student::setName(string nm) {name = nm;};
void Student::setDepartment(string dp) {department = dp;};
void Student::setGPA(double gpa) {GPA = gpa;};
void Student::setID(int ID) {id = ID;};



bool operator== (const Student& s1, const Student& s2){
  return s1.id == s2.id;
}
bool operator!= (const Student& s1, const Student& s2){
  return s1.id != s2.id;
}
bool operator< (const Student& s1, const Student& s2){
  return s1.id < s2.id;
}
bool operator> (const Student& s1, const Student& s2){
  return s1.id > s2.id;
}
bool operator>= (const Student& s1, const Student& s2){
  return s1.id >= s2.id;
}
bool operator<= (const Student& s1, const Student& s2){
  return s1.id <= s2.id;
}

ostream& operator<<(ostream& os, const Student& s){
  os << s.id;
  return os;
}


