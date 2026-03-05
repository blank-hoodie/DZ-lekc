#include <iostream>

template<class T>
struct BiList {
  T val;
  BiList<T>* next;
  BiList<T>* prev;
};

namespace danila {
  template<class T>
  BiList<T>* create(T value) {
    BiList<T>* newNode = new BiList<T>;
    newNode->val = value;
    newNode->next = newNode;
    newNode->prev = newNode;
    return newNode;
  }
  template<class T>
  void New(BiList<T>** head, T value) {
    if (*head == nullptr) {
      *head = create(value);
      return;
    }
    
    BiList<T>* newNode = create(value);
    BiList<T>* last = (*head)->prev;
    
    newNode->next = *head;
    newNode->prev = last;
    last->next = newNode;
    (*head)->prev = newNode;
  }

  template<class T>
  void clear(BiList<T>** head) {
    if (*head == nullptr) return;
    
    BiList<T>* last = (*head)->prev;
    last->next = nullptr;
    
    while (*head != nullptr) {
      BiList<T>* temp = *head;
      *head = (*head)->next;
      delete temp;
    }
    *head = nullptr;
  }
}

template<typename T>
void arrayToList(const T* arr, int size, BiList<T>** list) {
    danila::clear(list);
  
  for (int i = 0; i < size; ++i) {
      danila::New(list, arr[i]);
  }
}
