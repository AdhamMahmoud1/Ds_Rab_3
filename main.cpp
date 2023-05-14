
#include <bits/stdc++.h>
#include "./src/AVL.cpp"
#include "./src/heap.cpp"
using namespace std;

int main() {


        Heap<int> h;
        h.insert(3);
        h.insert(2);
        h.insert(1);
        h.insert(5);
        h.insert(4);
        h.printHeap(); // Output: 5 4 1 3 2
        h.heapSort();
        h.printHeap(); // Output: 1 2 3 4 5
        h.remove(2);
        h.printHeap(); // Output: 5 4 1 3
        cout << h.search(4) << endl;

//
// BST<int> b;
//b.insert(45);
//b.insert(15);
//b.insert(79);
//b.insert(90);
//b.insert(10);
//b.insert(55);
//b.insert(12);
//b.insert(50);
//
//cout << "Display the Tree Contenet: \n";
//b.preOrder();
//
//cout << "\nenter item to search for : ";
//int key;
//cin >> key;
//if (b.search(key))
//{
//    cout << "Item Found \n";
//}
//else
//{
//    cout << "Item Not Found\n";
//}
//
//b.Delete(10);
//b.preOrder();
//
}
