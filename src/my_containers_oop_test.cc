#include <gtest/gtest.h>

#include <array>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>

#include "my_containers.h"
#include "my_containersplus.h"
using my::array;
using my::list;
using my::map;
using my::multiset;
using my::queue;
using my::set;
using my::stack;
using my::vector;

template <class T>
void compare_list_data(my::list<T> list, std::list<T> stdList) {
  auto iter = list.begin();
  auto stdIter = stdList.begin();

  for (; iter != list.end(); ++iter, ++stdIter) {
    EXPECT_EQ(*iter, *stdIter);
  }
}

template <class T>
void compare_vector_data(my::vector<T> vec, std::vector<T> stdVec) {
  auto iter = vec.begin();
  auto stdIter = stdVec.begin();

  for (; iter != vec.end(); ++iter, ++stdIter) {
    EXPECT_EQ(*iter, *stdIter);
  }
}

template <class T>
void compare_stack_data(my::stack<T> st, std::stack<T> stdSt) {
  while (!st.empty()) {
    EXPECT_EQ(st.top(), stdSt.top());
    st.pop();
    stdSt.pop();
  }
}

template <class T>
void compare_queue_data(my::queue<T> qe, std::queue<T> stdQe) {
  while (!qe.empty()) {
    EXPECT_EQ(qe.front(), stdQe.front());
    qe.pop();
    stdQe.pop();
  }
}

#include "tests/array_test.cc"
#include "tests/list_test.cc"
#include "tests/map_test.cc"
#include "tests/multiset_test.cc"
#include "tests/queue_test.cc"
#include "tests/set_test.cc"
#include "tests/stack_test.cc"
#include "tests/vector_test.cc"

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
