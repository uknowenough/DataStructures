#ifndef NODE_H
#define NODE_H

namespace ds {

template<typename T>
class SingleNode {
 public:
  explicit SingleNode(const T& value)
      : value_(value),
        next_node_(nullptr) {}

  ~SingleNode() {}

  void setNext(SingleNode<T>* next) { next_node_ = next; }
  SingleNode<T>* next() { return next_node_; }

  void insert(T value) {
    if (!next_node_) next_node_ = new SingleNode(value);
  }

  const T& value() const { return value_; }

 private:
  //! Данные
  T value_;

  SingleNode* next_node_;
};

template<typename T>
class DoubleNode {
 public:
  explicit DoubleNode(const T& value)
      : value_(value),
        l_(nullptr),
        r_(nullptr) {}

  /**
   * @brief Деструктор
   */
  ~DoubleNode() {
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
        r_ = new DoubleNode(value);
      } else {
        r_->insert(value);
      }
    } else if (value < value_) {
      if (!l_) {
        l_ = new DoubleNode(value);
      } else {
        l_->insert(value);
      }
    }
  }

  int countChildren() const {
    int count = 0;
    if (l_) count += l_->countChildren() + 1;
    if (r_) count += r_->countChildren() + 1;
    return count;
  }

 private:
  //! Данные
  T value_;

  DoubleNode* l_;
  DoubleNode* r_;
};

}

#endif // NODE_H
