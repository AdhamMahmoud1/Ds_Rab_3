#include "../includes/AVL.hpp"


template<typename T>
AVL<T>::AVL(){
  BST<T>();
}

// The function calculates the height of a current node = the number of edges
template<typename T>
int AVL<T>::height(Bnode<T> * node){

  if(node != NULL){
    
    int leftSubtreeHeight = height(node->left);
    int rightSubtreeHeight = height(node->right);
    int maxHeight = max(leftSubtreeHeight, rightSubtreeHeight);
    return maxHeight + 1;
  }else{
    return 0;
  }
}

// The function calculates the height of the leftSubtree - right one
template<typename T>
int AVL<T>::balanceFactor(Bnode<T> * node){
  return height(node->left) - height(node->right);
}

// left left rotation 
template<typename T>
Bnode<T> * AVL<T>::ll_rotation(Bnode<T> * node){
  Bnode<T> * temp = node->left;
  node->left = temp->right;
  temp->right = node;
  return temp;
}

// left right rotation
template<typename T>
Bnode<T> * AVL<T>::lr_rotation(Bnode<T> * node){
  Bnode<T> * temp = node->left;
  node->left = rr_rotation(temp);
  return ll_rotation(node);

}
// right right rotation
template<typename T>
Bnode<T> * AVL<T>::rr_rotation(Bnode<T> * node){
  Bnode<T> * temp = node->right;
  node->right = temp->left;
  temp->left = node;
  return temp;
}
// right left
template<typename T>
Bnode<T> * AVL<T>::rl_rotation(Bnode<T> * node){
  Bnode<T> * temp = node->right;
  node->right = ll_rotation(temp);
  return rr_rotation(node);
}

template<typename T>
Bnode<T> * AVL<T>::balance(Bnode<T> * node){
  int balance_Factor = balanceFactor(node);
  // height of left > right
  if(balance_Factor > 1){
    if(balanceFactor(node->left) > 0){
      node = ll_rotation(node);
    }else{
      node = lr_rotation(node);
    }
  }else if(balance_Factor < -1){
    if(balanceFactor(node->right) > 0){
      node = rl_rotation(node);
    }else{
      node = rr_rotation(node);
    }
  }
  return node;
}

template<typename T>
Bnode<T> * AVL<T>::insert(Bnode<T> *r, T element){
  if(r == nullptr){
    r = new Bnode<T>(element);
    return r;
  }else if(element < r->data){
    r->left = insert(r->left, element);
    r = balance(r);
  }else if(element >= r->data){
    r->right = insert(r->right , element);
    r = balance(r);
  }
  return r;
}

template<typename T>
void AVL<T>::insert(T element){
  BST<T>::root  = insert(BST<T>::root, element);
}





template<typename T>
Bnode<T> *AVL<T>::Delete(Bnode<T> *r, T element) {
  if (!r) {
    // element not found
    cout << "NOT FOUND\n";
    return r; 
  }
  if (element < r->data) {
    r->left = Delete(r->left, element);
  } else if (element > r->data) {
    r->right = Delete(r->right, element);
  } else { 
    // element == r->data, found the node to delete
    if (!r->left || !r->right) { 
      // node has one child or no child
      Bnode<T> *temp = r->left ? r->left : r->right;
      if (!temp) {
        // node has no child
        temp = r;
        r = nullptr;
      } else { 
        // node has one child
        *r = *temp;
      }
      delete temp;
    } else { 
      Bnode<T> *temp = r->right;
      while (temp->left) { 
        temp = temp->left;
      }
      r->data = temp->data; 
      r->right = Delete( r->right, temp->data ); 
    }
  }
  if (!r) { // node was deleted
    return r;
  }
  return balance(r);
}

template<typename T>
void AVL<T>::Delete(T element){
  BST<T>::root  = Delete(BST<T>::root, element);
}
