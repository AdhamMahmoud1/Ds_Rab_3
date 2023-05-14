<<<<<<< HEAD
//
// Created by mahmo on 5/14/2023.
//

#ifndef DS_RAB_3_MINHEAP_H
#define DS_RAB_3_MINHEAP_H

#endif //DS_RAB_3_MINHEAP_H
=======
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
>>>>>>> 6f13064a36c36ca7a34fe93ecaf951163b2cd099
