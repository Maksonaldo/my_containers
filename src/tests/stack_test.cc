#include <gtest/gtest.h>

TEST(test_stack_constructor, default_constructor) {
  my::stack<int> st;
  std::stack<int> stdSt;

  EXPECT_EQ(st.size(), stdSt.size());
  EXPECT_EQ(st.empty(), stdSt.empty());
}

TEST(test_stack_constructor, initializer_list_constructor) {
  my::stack<int> st({34, 56, 789, 11, 3});
  std::stack<int> stdSt({34, 56, 789, 11, 3});

  while (!st.empty()) {
    EXPECT_EQ(st.top(), stdSt.top());
    st.pop();
    stdSt.pop();
  }

  EXPECT_EQ(st.size(), stdSt.size());
  EXPECT_EQ(st.empty(), stdSt.empty());
}

TEST(test_stack_constructor, copy_stack_constructor) {
  my::stack<int> st1({34, 56, 789, 11, 3});
  std::stack<int> stdSt1({34, 56, 789, 11, 3});
  my::stack<int> st(st1);
  std::stack<int> stdSt(stdSt1);

  compare_stack_data(st, stdSt);

  EXPECT_EQ(st.size(), stdSt.size());
  EXPECT_EQ(st.empty(), stdSt.empty());
}

TEST(test_stack_constructor, move_stack_constructor) {
  my::stack<int> st1({34, 56, 789, 11, 3});
  std::stack<int> stdSt1({34, 56, 789, 11, 3});
  my::stack<int> st(std::move(st1));
  std::stack<int> stdSt(std::move(stdSt));

  EXPECT_EQ(st.top(), 34);
  st.pop();
  EXPECT_EQ(st.top(), 56);
  st.pop();
  EXPECT_EQ(st.top(), 789);
  st.pop();
  EXPECT_EQ(st.top(), 11);
  st.pop();
  EXPECT_EQ(st.top(), 3);
  st.pop();

  EXPECT_EQ(st.size(), 0);
  EXPECT_EQ(st.empty(), true);
}

TEST(test_stack_operator, eq_operator) {
  my::stack<int> st1({34, 56, 789, 11, 3});
  std::stack<int> stdSt1({34, 56, 789, 11, 3});
  my::stack<int> st;
  std::stack<int> stdSt;

  st = st1;

  EXPECT_EQ(st.top(), 34);
  st.pop();
  EXPECT_EQ(st.top(), 56);
  st.pop();
  EXPECT_EQ(st.top(), 789);
  st.pop();
  EXPECT_EQ(st.top(), 11);
  st.pop();
  EXPECT_EQ(st.top(), 3);
  st.pop();

  EXPECT_EQ(st.size(), 0);
  EXPECT_EQ(st.empty(), true);
}

TEST(test_stack_methods, element_access) {
  my::stack<int> st({34, 56, 789, 11, 3});
  std::stack<int> stdSt({34, 56, 789, 11, 3});

  EXPECT_EQ(st.top(), stdSt.top());
  EXPECT_EQ(st.empty(), stdSt.empty());
  EXPECT_EQ(st.size(), stdSt.size());
}

TEST(test_stack_methods, modifiers_push) {
  my::stack<int> st({34, 56, 789, 11, 3});
  std::stack<int> stdSt({34, 56, 789, 11, 3});

  st.push(9999);
  stdSt.push(9999);

  while (!st.empty()) {
    EXPECT_EQ(st.top(), stdSt.top());
    st.pop();
    stdSt.pop();
  }
}

TEST(test_stack_methods, modifiers_pop) {
  my::stack<int> st({34, 56, 789, 11, 3});
  std::stack<int> stdSt({34, 56, 789, 11, 3});

  st.pop();
  stdSt.pop();

  while (!st.empty()) {
    EXPECT_EQ(st.top(), stdSt.top());
    st.pop();
    stdSt.pop();
  }
}

TEST(test_stack_methods, modifiers_swap) {
  my::stack<int> st({34, 56, 789, 11, 3});
  std::stack<int> stdSt({34, 56, 789, 11, 3});
  my::stack<int> st1({25, 57, 99});
  std::stack<int> stdSt1({25, 57, 99});

  st.swap(st1);
  stdSt.swap(stdSt1);

  while (!st.empty()) {
    EXPECT_EQ(st.top(), stdSt.top());
    EXPECT_EQ(st1.top(), stdSt1.top());
    st.pop();
    stdSt.pop();
  }
}

TEST(test_stack_methods, modifiers_emplace_front) {
  my::stack<int> st({34, 56, 789, 11, 3});
  std::stack<int> stdSt({34, 56, 789, 11, 3});

  st.emplace_front(777);
  stdSt.emplace(777);

  while (!st.empty()) {
    EXPECT_EQ(st.top(), stdSt.top());
    st.pop();
    stdSt.pop();
  }
}
