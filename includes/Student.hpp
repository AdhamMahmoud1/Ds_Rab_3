#ifndef Student_H
#define Student_H
#include "bits/stdc++.h"
using namespace std;



class Student {
public:
  int id;
  string name;
  double GPA;
  string department;
// public:
  Student();
  Student(int);
  Student(int id, string name, double GPA, string department);
  
  // getters
  int getID();
  string getName();
  double getGPA();
  string getDepartment();


  //setters

  void setID(int);
  void setName(string);
  void setGPA(double);
  void setDepartment(string);



  // 
/* 
  friend bool operator== (const Student& c1, const Student& c2);
  friend bool operator!= (const Student& c1, const Student& c2);
  friend bool operator< (const Student& c1, const Student& c2);
  friend bool operator> (const Student& c1, const Student& c2);
  friend bool operator>= (const Student& c1, const Student& c2);
  friend bool operator<= (const Student& c1, const Student& c2);
  friend ostream& operator<<(ostream& os, const Student& s); */

};











#endif