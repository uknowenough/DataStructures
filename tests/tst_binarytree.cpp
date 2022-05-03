
#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

using namespace testing;

#include <memory>
#include <iostream>
#include <random>
#include <ctime>

#include "Data.h"
#include "BinaryTree.h"

TEST(EmptyInputData, BinaryTree)
{
  using ds::BinaryTree;
  using ds::Data;

  std::unique_ptr<BinaryTree<Data>> binary_tree = std::make_unique<BinaryTree<Data>>();

  EXPECT_EQ(binary_tree->countNode(), 0);
//  ASSERT_THAT(0, Eq(0));
}

TEST(RandomInputData, BinaryTree)
{
  using ds::BinaryTree;
  using ds::Data;

  std::unique_ptr<BinaryTree<Data>> binary_tree = std::make_unique<BinaryTree<Data>>();

  std::srand(std::time(nullptr));
  const int size = std::rand()/((RAND_MAX + 1u)/2048);

  for (int i = 0; i < size; ++i) {
    int random_value = std::rand()/((RAND_MAX + 1u)/2048);
    binary_tree->insert(Data(random_value));
  }

  std::cout << "Exprected Binary Tree Size: " << size << std::endl;
  std::cout << "Binary Tree Size: " << binary_tree->countNode() << std::endl;

  EXPECT_EQ(binary_tree->countNode(), size);
  //  ASSERT_THAT(0, Eq(0));
}

