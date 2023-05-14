#ifndef AVL_H
#define AVL_H
#include "../src/bst.cpp"





template<typename T>
class AVL : public BST<T>{
private:
  Bnode<T> *insert(Bnode<T> *r, T element);
  Bnode<T> *Delete(Bnode<T> *, T element);

public:

  AVL();

  int height(Bnode<T> *);
  int balanceFactor(Bnode<T> *);
  Bnode<T> * ll_rotation(Bnode<T> *);
  Bnode<T> * lr_rotation(Bnode<T> *);
  Bnode<T> * rr_rotation(Bnode<T> *);
  Bnode<T> * rl_rotation(Bnode<T> *);
  Bnode<T> * balance(Bnode<T> *);
  void insert(T element);
  void Delete(T element);

/* 
  // functions for the Student class specificaly
  void addStudent(Student);
  void searchStudent(int);
  void printSorted(); */
};










#endif