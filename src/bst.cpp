/**
 * @file BST.cpp
 * @author Fady Kamal (20210282)
 * @brief BinarySearchTree implementation file
 * @version 0.1
 * @date 2023-05-13
 * 
 * 
 */
#include "../includes/bst.hpp"


////////////////////////////////////////////////// Constructors And Destructor ////////////////////////////////////
/**
 * @brief Construct a new BST<T>::BST object
 * @details Default constructor
 * @tparam T Type of contained data
 */
template<class T>
BST<T>::BST(): root(NULL){}


/**
 * @brief Destroy the BST<T>::BST object
 * 
 * @tparam T Type of contained data
 */
template<class T>
BST<T>::~BST(){}



////////////////////////////////////////////////// Setters  & Getters  ////////////////////////////////////
/**
 * @brief Return tree's root
 * 
 * @tparam T Type of contained data
 * @return Bnode<T>* Root of tree
 */
template<class T>
Bnode<T>* BST<T>::get_root() const
{
    return this->root;
}



////////////////////////////////////////////////// Instance Methods  ////////////////////////////////////
/**
 * @brief Take item and insert it into the tree
 * 
 * @tparam T Type of contained data
 * @param subTreeRoot Root of subTree that insertion will start at
 * @param item Item to insrt
 * @return Bnode<T>* Inserted root
 */
template<class T>
Bnode<T>* BST<T>::insert(Bnode<T>* subTreeRoot, T item)
{
        if ( subTreeRoot == NULL)
        {
            /**
             *  if tree is empty, 
             *  create a new node with new item, 
             *  set its left and right childs to null (thanks to constructor),
             *  update root
             */

            // create a new node 
            Bnode<T>* newNode = new Bnode<T>();
            newNode->data = item;

            // set newNode as root 
            subTreeRoot = newNode;
        }
        else if (item < subTreeRoot->data)
        {
            /**
             *  if item < data of subtree's root 
             *  insert data in left child of current root
             */
            subTreeRoot->left = insert(subTreeRoot->left, item);
        }
        else
        {
            /**
             *  if item >= data of subtree's root 
             *  insert data in right child of current root
             */
            subTreeRoot->right = insert(subTreeRoot->right, item);
        }

        // return subTreeRoot to update tree's root
        return subTreeRoot;
}


/**
 * @brief Overloading with tree's main root
 * 
 * @tparam T Type of contained data
 * @param item Item to insert
 */
template<class T>
void BST<T>::insert(T item)
{
    // insert item in tree 
    root = insert(this->root, item);
}


/**
 * @brief Takes key and checks if in tree or not
 * 
 * @tparam T 
 * @param subTreeRoot 
 * @param key 
 * @return Bnode<T>* 
 */
template<class T>
Bnode<T>* BST<T>::search(Bnode<T>* subTreeRoot, T key)
{
    if (subTreeRoot == NULL)
    {
        // return wihtout doing any thing
        return NULL;
    }
    else if (key < subTreeRoot->data)
    {
        // keep searching
        return search(subTreeRoot->left, key);
    }
    else if (key > subTreeRoot->data)
    {
        // keep searching till be found and return
        return search(subTreeRoot->right, key);
    }
    else
    {
        // found, return this node
        return subTreeRoot;
    }
}


/**
 * @brief 
 * 
 * @tparam T 
 * @param key 
 * @return true 
 * @return false 
 */
template <class T>
bool BST<T>::search(T key)
{
    // search for item starting from root
    Bnode<T>* result = search(root, key);

    // if found return true else return false
    return (result == NULL)? false: true;
}


/**
 * @brief 
 * 
 * @tparam T 
 * @param subTreeRoot 
 * @param key 
 * @return Bnode<T>* 
 */
template<class T>
Bnode<T>* BST<T>::Delete(Bnode<T>* subTreeRoot, T key)
{
    if (subTreeRoot == NULL)
    {
        // empty, return null
        return NULL;
    }
    if (key < subTreeRoot->data)
    {
        // delete from left branch
        subTreeRoot->left = Delete(subTreeRoot->left, key);
    }
    else if (key > subTreeRoot->data)
    {
        // delete from right branch
        subTreeRoot->right = Delete(subTreeRoot->right, key);
    }
    else
    {
        if  (subTreeRoot->left == NULL && subTreeRoot->right == NULL)       // leave node
        {
            // remove any way
            subTreeRoot = NULL;
        }
        else if (subTreeRoot->left != NULL && subTreeRoot->right == NULL)   // left exists and there is no right
        {
            subTreeRoot->data = subTreeRoot->left->data;
            delete subTreeRoot->left;
            subTreeRoot->left = NULL;
        }
        else if (subTreeRoot->left == NULL && subTreeRoot->right != NULL)   // right exists and there is no left
        {
            // store in child and remove that child
            subTreeRoot->data = subTreeRoot->right->data;
            delete subTreeRoot->right;
            subTreeRoot->right = NULL;
        }
        else
        {
            // if node has two children
            Bnode<T>* max = findMaxmum(subTreeRoot->left);
            subTreeRoot->data =  max->data;

            // delete max
            subTreeRoot->left = Delete(subTreeRoot->left, max->data);
        }

    }

    return subTreeRoot;
}


/**
 * @brief 
 * 
 * @tparam T 
 * @param item 
 */
template <class T>
void BST<T>::Delete(T item)
{
    // delete item based on root
    root = Delete(root, item);
}


/**
 * @brief 
 * 
 * @tparam T 
 * @param subTreeRoot 
 * @return Bnode<T>* 
 */
template <class T>
Bnode<T>* BST<T>::findMaxmum(Bnode<T>* subTreeRoot)
{
    /**
     * note: max item in tree exists only in right branch
     *
     * if tree is empty, return
     * else if left branch is empty, then root is the minimum
     * else findmin in rest subTrees
     */
    if (subTreeRoot == NULL)
    {
        return NULL;
    }
    else if (subTreeRoot->right == NULL)
    {
        return subTreeRoot;
    }
    else 
    {
        return findMaxmum(subTreeRoot->right);
    }
}


/**
 * @brief 
 * 
 * @tparam T 
 * @param subTreeRoot 
 * @return Bnode<T>* 
 */
template <class T>
Bnode<T>* BST<T>::findMinimum(Bnode<T>* subTreeRoot)
{
    /**
     * if tree is empty, return
     * else if left branch is empty, then root is the minimum
     * else findmin in rest subTrees
     */
    if (subTreeRoot == NULL)
    {
        return NULL;
    }
    else if (subTreeRoot->left == NULL)
    {
        return subTreeRoot;
    }
    else
    {
        return findMinimum(subTreeRoot->left);
    }
}


/**
 * @brief 
 * 
 * @tparam T 
 * @param subTreeRoot 
 */
template <class T>
void BST<T>::preOrder(Bnode<T>* subTreeRoot)
{
    // if tree empty return without doing any things
    if (subTreeRoot == NULL)
    {
        return; 
    }
    else
    {
        // root left right
        cout << subTreeRoot->data;
        preOrder(subTreeRoot->left);
        preOrder(subTreeRoot->right);
    }
}


/**
 * @brief 
 * 
 * @tparam T 
 */
template <class T>
void BST<T>::preOrder()
{
    preOrder(root);
}

template <class T>
void BST<T>::inOrder(Bnode<T>* subTreeRoot)
{
    // if tree empty return without doing any things
    if (subTreeRoot == NULL)
    {
        return; 
    }
    else
    {
        // left root right
        inOrder(subTreeRoot->left);
        cout << subTreeRoot->data;
        inOrder(subTreeRoot->right);
    }
}


/**
 * @brief 
 * 
 * @tparam T 
 */
template <class T>
void BST<T>::inOrder()
{
    inOrder(root);
}


/**
 * @brief 
 * 
 * @tparam T 
 * @param subTreeRoot 
 */
template <class T>
void BST<T>::postOrder(Bnode<T>* subTreeRoot)
{
    // if tree empty return without doing any things
    if (subTreeRoot == NULL)
    {
        return; 
    }
    else
    {
        // left right root
        postOrder(subTreeRoot->left);
        postOrder(subTreeRoot->right);
        cout << subTreeRoot->data;
    }
}


/**
 * @brief 
 * 
 * @tparam T 
 */
template <class T>
void BST<T>::postOrder()
{
    postOrder(root);
}
