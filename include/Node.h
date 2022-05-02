#ifndef NODE_H
#define NODE_H

namespace ds {

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

}

#endif // NODE_H
