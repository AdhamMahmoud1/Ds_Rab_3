#pragma once
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
