#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "Node.h"

namespace ds {

template<typename T>
class BinaryTree
{
 public:
  /**
   * @brief Конструктор по умолчанию
   */
  BinaryTree()
      : root_node_(nullptr) {}

  /**
   * @brief Деструктор бинарного дерева
   */
  ~BinaryTree() {
    if (root_node_) {
      delete root_node_;
      root_node_ = nullptr;
    }
  }

  /**
   * @brief Метод вставки нового значения в дерево
   *
   * @param Новое значение
   */
  void insert(T value)
  {
    if (!root_node_)
      root_node_ = new DoubleNode<T>(value);

    root_node_->insert(value);
  }

  /**
   * @brief Метод поиска значения в дереве
   *
   * @param Значение, которое необходимо найти
   */
  bool find(T value)
  {
    return false;
  }

  int countNode() const
  {
    return (root_node_) ? root_node_->countChildren() : 0;
  }

 private:
  //! Root node
  DoubleNode<T>* root_node_;

};

}

#endif // BINARYTREE_H
