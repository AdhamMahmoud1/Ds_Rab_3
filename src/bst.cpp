#include "../includes/bst.hpp"

template <typename T>
BST<T>::BST() : root(nullptr) {}

template <typename T>
Bnode<T> *BST<T>::insert(Bnode<T> *r, T element) {
    if (r == nullptr)
    {
        Bnode<T> *newNode = new Bnode(element);
        r = newNode;
    }
    else if (element < r->data)
    {
        r->left = insert(r->left, element);
    }
    else
    {
        r->right = insert(r->right, element);
    }
    return r;
}

template <typename T>
void BST<T>:: insert(T element){
    root = insert(root, element);
}

template <typename T>
Bnode<T> *BST<T>::get_root() { return root; }

template <typename T>
Bnode<T> *BST<T>::search(Bnode<T> *r, T element)
{
    if (r == nullptr)
    {
        return nullptr;
    }
    else if (r->data == element)
    {
        return r;
    }
    else if (element < r->data)
    {
        return search(r->left, element);
    }
    else
    {
        return search(r->right, element);
    }
}

template <typename T>
bool BST<T>::search(T element)
{
    Bnode<T> *result = search(root, element);
    return (result == nullptr) ? false : true;
}

template <typename T>
Bnode<T> *BST<T>::findMinimum(Bnode<T> *r)
{
    if (r == nullptr)
    {
        return nullptr;
    }
    else if (r->left == nullptr)
    {
        return r;
    }
    else
    {
        return findMinimum(r->left);
    }
}

template <typename T>
Bnode<T> *BST<T>::findMaxmum(Bnode<T> *r)
{
    if (r == nullptr)
    {
        return nullptr;
    }
    if (r->right == nullptr)
    {
        return r;
    }
    else
    {
        return findMaxmum(r->right);
    }
}
template <typename T>
Bnode<T> *BST<T>::Delete(Bnode<T> *r, T element)
{
    if (r == nullptr)
    {
        return nullptr;
    }
    if (element < r->data)
    {
        r->left = Delete(r->left, element);
    }
    else if (element > r->data)
    {
        r->right = Delete(r->right, element);
    }
    else
    {
        if (r->left == nullptr && r->right == nullptr)
        {
            r = nullptr;
        }
        else if (r->left != nullptr && r->right == nullptr)
        {
            r->data = r->left->data;
            delete r->left;
            r->left = nullptr;
        }
        else if (r->left == nullptr && r->right != nullptr)
        {
            r->data = r->right->data;
            delete r->right;
            r->right = nullptr;
        }
        else
        {
            Bnode<T> *max = findMaxmum(r->left);
            r->data = max->data;
            r->left = Delete(r->left, max->data);
        }
    }
    return r;
}
template <typename T>
void BST<T>::Delete(T element)
{
    root = Delete(root, element);
}
template <typename T>
void BST<T>::preOrder(Bnode<T> *r)
{
    if (r == nullptr)
    {
        return;
    }
    std::cout << r->data << " ";
    preOrder(r->left);
    preOrder(r->right);
}

template <typename T>
void BST<T>::inOrder(Bnode<T> *r)
{
    if (r == nullptr)
    {
        return;
    }
    inOrder(r->left);
    std::cout << r->data << " ";
    inOrder(r->right);
}

template <typename T>
void BST<T>::postOrder(Bnode<T> *r)
{
    if (r == nullptr)
    {
        return;
    }
    inOrder(r->left);
    inOrder(r->right);
    std::cout << r->data << " ";
}