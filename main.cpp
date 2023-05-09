
#include <bits/stdc++.h>
#include "./src/bst.cpp"
using namespace std;


int main()
{
    BST<int> b;
    b.insert(45);
    b.insert(15);
    b.insert(79);
    b.insert(90);
    b.insert(10);
    b.insert(55);
    b.insert(12);
    b.insert(50);

    cout << "Display the Tree Contenet: \n";
    b.preOrder(b.get_root());

    cout << "\nenter item to search for : ";
    int key;
    cin >> key;
    if (b.search(key))
    {
        cout << "Item Found \n";
    }
    else
    {
        cout << "Item Not Found\n";
    }

    b.Delete(10);
    b.preOrder(b.get_root());
}