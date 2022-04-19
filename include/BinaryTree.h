#ifndef BINARYTREE_H
#define BINARYTREE_H

template<typename T>
class Node {
 public:
  explicit Node(const T& value)
      : value_(value),
        l_(nullptr),
        r_(nullptr) {}

  /**
   * @brief Деструктор
   */
  ~Node() {
    if (l_) {
      delete l_;
      l_ = nullptr;
    }

    if (r_) {
      delete r_;
      r_ = nullptr;
    }
  }

  void insert(T value)
  {
    if (value > value_) {
      if (!r_) {
        r_ = new Node(value);
      } else {
        r_->insert(value);
      }
    } else if (value < value_) {
      if (!l_) {
        l_ = new Node(value);
      } else {
        l_->insert(value);
      }
    }
  }

 private:
  //! Данные
  T value_;

  Node* l_;
  Node* r_;
};

template<typename T>
class BinaryTree
{
 public:
  /**
   * @brief Конструктор по умолчанию
   */
  BinaryTree() : root_node_(nullptr) {}

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
      root_node_ = new Node<T>(value);

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

 private:
  //! Root node
  Node<T>* root_node_;

};

#endif // BINARYTREE_H
