
#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

using namespace testing;

#include <memory>
#include <iostream>
#include <random>
#include <ctime>

#include <list>
#include <string>
#include <tuple>

#include "Data.h"
#include "SinglyLinkedList.h"

TEST(LeetCodeImput, SinglyLinkedList)
{
  using ds::Data;
  using ds::SinglyLinkedList;

  std::unique_ptr<SinglyLinkedList<int>> list = std::make_unique<SinglyLinkedList<int>>();

  std::list<std::string> command_list {
      "addAtHead","addAtTail","addAtTail","addAtTail","addAtTail","addAtTail","addAtTail","deleteAtIndex",
      "addAtHead","addAtHead","get","addAtTail","addAtHead","get","addAtTail","addAtIndex","addAtTail","addAtHead",
      "addAtHead","addAtHead","get","addAtIndex","addAtHead","get","addAtHead","deleteAtIndex","addAtHead","addAtTail",
      "addAtTail","addAtIndex","addAtTail","addAtHead","get","addAtTail","deleteAtIndex","addAtIndex","deleteAtIndex",
      "addAtHead","addAtTail","addAtHead","addAtHead","addAtTail","addAtTail","get","get","addAtHead","addAtTail",
      "addAtTail","addAtTail","addAtIndex","get","addAtHead","addAtIndex","addAtHead","addAtTail","addAtTail",
      "addAtIndex","deleteAtIndex","addAtIndex","addAtHead","addAtHead","deleteAtIndex","addAtTail","deleteAtIndex",
      "addAtIndex","addAtTail","addAtHead","get","addAtIndex","addAtTail","addAtHead","addAtHead","addAtHead","addAtHead",
      "addAtHead","addAtHead","deleteAtIndex","get","get","addAtHead","get","addAtTail","addAtTail","addAtIndex","addAtIndex",
      "addAtHead","addAtTail","addAtTail","get","addAtIndex","addAtHead","deleteAtIndex","addAtTail","get","addAtHead","get",
      "addAtHead","deleteAtIndex","get","addAtTail","addAtTail"
  };

  std::pair<int, int> sd[] {
    {38,0},{66,0},{61,0},{76,0},{26,0},{37,0},{8,0},{5,0},{4,0},{45,0},{4,0},{85,0},{37,0},{5,0},{93,0},{10,23},
      {21,0},{52,0},{15,0},{47,0},{12,0},{6,24},{64,0},{4,0},{31,0},{6,0},{40,0},{17,0},{15,0},{19,2},
      {11,0},{86,0},{17,0},{55,0},{15,0},{14,95},{22,0},{66,0},{95,0},{8,0},{47,0},{23,0},{39,0},{30,0},
      {27,0},{0,0},{99,0},{45,0},{4,0},{9,11},{6,0},{81,0},{18,32},{20,0},{13,0},{42,0},{37,91},
      {36,0},{10,37},{96,0},{57,0},{20,0},{89,0},{18,0},{41,5},{23,0},{75,0},{7,0},{25,51},{48,0},
      {46,0},{29,0},{85,0},{82,0},{6,0},{38,0},{14,0},{1,0},{12,0},{42,0},{42,0},{83,0},{13,0},{14,20},{17,34},
      {36,0},{58,0},{2,0},{38,0},{33,59},{37,0},{15,0},{64,0},{56,0},{0,0},{40,0},{92,0},{63,0},{35,0},{62,0},{32,0}
      };

  int i = 0;
  for (const auto& command : command_list) {
    std::cout << i << ' ' << command << ' ' << sd[i].first << ' ' << sd[i].second << '\n';
    if (command == "addAtHead") {
      list->addAtHead(sd[i].first);
    } else if (command == "addAtTail") {
      list->addAtTail(sd[i].first);
    } else if (command == "addAtIndex") {
      list->addAtIndex(sd[i].first, sd[i].second);
    } else if (command == "deleteAtIndex") {
      list->deleteAtIndex(sd[i].first);
    } else if (command == "get") {
      std::cout << list->get(sd[i].first) << '\n';
    }

    std::cout << *list;

    ++i;
  }
}
