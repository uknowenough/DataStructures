#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

#include <iostream>

#include "Node.h"

namespace ds {

template<typename T>
class SinglyLinkedList {
 public:
  SinglyLinkedList()
      : head_(nullptr),
        tail_(nullptr) {}

  T get(int index) {
    if (index < 0
        || index >= length_)
      return -1;

    if (index == 0) {
      return head_->value();
    } else if (index == (length_-1)) {
      return tail_->value();
    } else {
      int counter = index;
      auto node = head_;
      while (counter != 0) {
        node = node->next();
        --counter;
      }

      return node->value();
    }

    return -1;
  }

  void addAtHead(const T& val) {
    auto new_head = new SingleNode<T>(val);
    new_head->setNext(head_);

    head_ = new_head;
    if (!tail_)
      tail_ = head_;

    ++length_;
  }

  void addAtTail(T val) {
    auto new_tail = new SingleNode<T>(val);

    if (tail_)
      tail_->setNext(new_tail);
    else
      head_ = new_tail;

    tail_ = new_tail;

    ++length_;
  }

  void addAtIndex(int index, T val) {
    if (index < 0
        || index > length_)
      return;

    if (index == 0) {
      addAtHead(val);
    } else if (index == length_) {
      addAtTail(val);
    } else {
      int counter = 0;
      auto node = head_;
      while (counter != (index-1)) {
        node = node->next();
        ++counter;
      }

      auto new_node = new SingleNode<T>(val);
      new_node->setNext(node->next());
      node->setNext(new_node);

      ++length_;
    }
  }

  void deleteAtIndex(int index) {
    if (index < 0
        || index >= length_)
      return;

    if (index == 0) {
      auto ptr = head_;
      head_ = ptr->next();
      delete ptr;
    } else {
      int counter = index;
      auto node = head_;
      while ((--counter) != 0) {
        node = node->next();
      }

      auto next_node = node->next();
      auto ptr = next_node->next();
      node->setNext(ptr);

      if (next_node) {
        delete next_node;

        if (ptr == nullptr) {
          node->setNext(nullptr);
          tail_ = node;
        }
      } else {
        tail_ = node;
      }
    }

    --length_;
  }

  friend std::ostream& operator<<(std::ostream& out, const SinglyLinkedList<T>& list) {
    auto ptr = list.head_;
    while (ptr != nullptr) {
      out << ptr->value() << "->";
      ptr = ptr->next();
    }
    out << "null\n";

    return out;
  }

  int length() const { return length_; }

 private:
  //! Linked List Head
  SingleNode<T>* head_;
  //! Linked List Tail
  SingleNode<T>* tail_;
  //! Lenght
  int length_ = 0;
};

}

#endif // SINGLYLINKEDLIST_H
