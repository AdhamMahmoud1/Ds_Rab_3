/**
 * @file Bnode.hpp
 * @author Fady kamal (20210282)
 * @brief  Bnode Header file
 * @version 0.1
 * @date 2023-05-13
 * 
 */
///////////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma once


template<class T>
class Bnode
{
public:
    /* Instance Attributes */
    T data;
    Bnode* left;
    Bnode* right;
    Bnode<T>* node;

    
    /* Constructors And Destructor*/
    Bnode(): left(NULL), right(NULL){};                             // Default
    Bnode(T item): data(item), left(NULL), right(NULL){};           // Parametrized
    ~Bnode(){};                                                     // Destructor
};
