/**
 * @file BST.hpp
 * @author Fady Kamal (20210282)
 * @brief Binary Search Tree Header file
 * @version 0.1
 * @date 2023-05-13
 * 
 */
///////////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma once
#include <iostream>
#include <string>
#include "Bnode.hpp"
using namespace std;


template<class T>
class BST
{
protected:
    /* Instance Attributes */
    Bnode<T>* root;
    

public:
    /* Constructors And Destructor */
    BST();                                  // Default constructor
    ~BST();                                 // Destructor



    /* Setters & Getters */
    Bnode<T> *get_root() const;


    /* Instance Methodss  */
    Bnode<T>* insert(Bnode<T>* subTreeRoot, T item);
    void insert(T item);

    Bnode<T>* search(Bnode<T>* subTreeRoot, T key);
    bool search(T key);

    Bnode<T>* Delete(Bnode<T>* subTreeRoot, T item);
    void Delete(T item);

    Bnode<T>* findMaxmum(Bnode<T>* subTreeRoot);
    Bnode<T>* findMinimum(Bnode<T>* subTreeRoot);

    void preOrder(Bnode<T>* subTreeRoot);
    void preOrder();
    
    void inOrder(Bnode<T>* subTreeRoot);
    void inOrder();

    void postOrder(Bnode<T>* subTreeRoot);
    void postOrder();


};
