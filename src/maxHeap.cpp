//
// Created by Adham on 5/13/2023.
//

#include "../includes/maxHeap.h"
#include <iostream>



template <typename T>
void Heap<T>::heapify(int i, int n) {
    int l = (2 * i) + 1;
    int r = (2 * i) + 2;
    int maxNo = i;
    if (l < n && heap[l] > heap[maxNo]) {
        maxNo = l;
    }
    if (r < n && heap[r] > heap[maxNo]) {
        maxNo = r;
    }
    if (maxNo != i) {
        swap(heap[i], heap[maxNo]);
        heapify(maxNo, n);
    }
}

template <typename T>
void Heap<T>::buildHeap() {
    for (int i = heap.size() / 2 - 1; i >= 0; i--){
        heapify(i, heap.size());
    }
}


template <typename T>
void Heap<T>::heapSort() {
    buildHeap();
    for (int i = heap.size() - 1; i >= 1; i--) {
        swap(heap[0], heap[i]);
        heapify(0, i);
    }
}

template <typename T>
void Heap<T>::insert(T element) {
    heap.push_back(element);
    int i = heap.size() - 1;
    while (i > 0 && heap[i] > heap[(i - 1) / 2]) {
        swap(heap[i], heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}


template <typename T>
bool Heap<T>::search(T element) {
    for (int i = 0; i < heap.size(); i++) {
        if (heap[i] == element) {
            return true;
        }
    }
    return false;
}

template <typename T>
void Heap<T>::remove(T element) {
    int i = 0;
    for (; i < heap.size(); i++) {
        if (heap[i] == element) {
            break;
        }
    }
    if (i == heap.size()) {
        return;
    }
    heap[i] = heap.back();
    heap.pop_back();
    while (i > 0 && heap[i] > heap[(i - 1) / 2]) {
        swap(heap[i], heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
    heapify(0, heap.size());
}


template <typename T>
void Heap<T>::printHeap() {
    for (int i = 0; i < heap.size(); i++){
        std::cout << heap[i] << " ";
    }
    std::cout << std::endl;
}
