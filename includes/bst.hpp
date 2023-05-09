#pragma once
#include <bits/stdc++.h>

template <typename T>
struct Bnode
{
    T data;
    Bnode<T> *left;
    Bnode<T> *right;
    Bnode(T d)
    {
        data = d;
        left = nullptr;
        right = nullptr;
    }
};

template <typename T>
class BST {
private:
    Bnode<T> *root;

    Bnode<T> *insert(Bnode<T> *r, T element);
    Bnode<T> *search(Bnode<T> *r, T element);
    Bnode<T> *Delete(Bnode<T> *, T element);

public:
    BST();
    Bnode<T> *get_root();
    void insert(T element);
    bool search(T element);
    Bnode<T> *findMaxmum(Bnode<T> *r);
    Bnode<T> *findMinimum(Bnode<T> *r);
    void Delete(T element);
    void preOrder(Bnode<T> *r);
    void inOrder(Bnode<T> *r);
    void postOrder(Bnode<T> *r);
};