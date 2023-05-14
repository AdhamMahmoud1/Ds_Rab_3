//
// Created by Adham on 5/13/2023.
//

#pragma once

#include <vector>

template <typename T>
class minHeap {
private:
    std::vector<T> heap;
    void heapify(int i, int n);
    void buildHeap();
public:
    void insert(T elemetn);
    void heapSort();
    void printHeap();

    bool search(T element);

    void remove(T element);
};
