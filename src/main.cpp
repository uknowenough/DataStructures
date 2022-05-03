#include <memory>
#include <iostream>
#include <random>
#include <ctime>

#include "Data.h"
#include "BinaryTree.h"

int main()
{
  using ds::BinaryTree;
  using ds::Data;

  std::unique_ptr<BinaryTree<Data>> binary_tree = std::make_unique<BinaryTree<Data>>();

  std::srand(std::time(nullptr));
  const int size = std::rand()/((RAND_MAX + 1u)/2048);

  for (int i = 0; i < size; ++i) {
    int random_value = std::rand()/((RAND_MAX + 1u)/2048);
    std::cout << i << ' ' << random_value << '\n';
    binary_tree->insert(Data(random_value));
  }

  return 0;
}
