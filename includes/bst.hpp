#pragma once
#include<bits/stdc++.h>
#include "Bnode.hpp"
using namespace std;
template <typename T>
class BST {
protected:
    Bnode<T>  * root;

    Bnode<T> *insert(Bnode<T> *r, T element);
    Bnode<T> *search(Bnode<T> *r, T element);
    Bnode<T> *Delete(Bnode<T> *, T element);
    void preOrder(Bnode<T> *r);
    void inOrder(Bnode<T> *r);
    void postOrder(Bnode<T> *r);

public:
    BST();
    Bnode<T> *get_root();
    void insert(T element);
    bool search(T element);
    Bnode<T> *findMaxmum(Bnode<T> *r);
    Bnode<T> *findMinimum(Bnode<T> *r);
    void Delete(T element);
    
    void preOrder();
    void inOrder();
    void postOrder();
};
