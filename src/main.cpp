#include <iostream>
#include <random>
#include <ctime>

#include "BinaryTree.h"

class A {
 public:
  explicit A (int id) : id_(id) {}

  friend bool operator<(const A& l, const A& r){
    return l.id_ < r.id_;
  }

  friend bool operator>(const A& l, const A& r){
    return !(l < r);
  }

  friend bool operator==(const A& l, const A& r){
    return l.id_ == r.id_;
  }

  friend bool operator!=(const A& l, const A& r){
    return !(l == r);
  }

 private:
  int id_;
};

int main()
{
  BinaryTree<A>* binary_tree = new BinaryTree<A>();

  std::srand(std::time(nullptr));
  const int size = std::rand()/((RAND_MAX + 1u)/2048);

  for (int i = 0; i < size; ++i) {
    int random_value = std::rand()/((RAND_MAX + 1u)/2048);
    std::cout << i << ' ' << random_value << '\n';
    binary_tree->insert(A(random_value));
  }

  delete binary_tree;
  return 0;
}
