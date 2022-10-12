#include <gtest/gtest.h>

TEST(test_queue_constructor, default_constructor) {
  my::queue<int> qe;
  std::queue<int> stdQe;

  EXPECT_EQ(qe.size(), stdQe.size());
  EXPECT_EQ(qe.empty(), stdQe.empty());
}

TEST(test_queue_constructor, initializer_list_constructor) {
  my::queue<int> qe({45, 68, 22, 44, 9009});
  std::queue<int> stdQe({45, 68, 22, 44, 9009});

  compare_queue_data(qe, stdQe);

  EXPECT_EQ(qe.size(), stdQe.size());
  EXPECT_EQ(qe.empty(), stdQe.empty());
}

TEST(test_queue_constructor, copy_queue_constructor) {
  my::queue<int> qe1({45, 68, 22, 44, 9009});
  std::queue<int> stdQe1({45, 68, 22, 44, 9009});
  my::queue<int> qe(qe1);
  std::queue<int> stdQe(stdQe1);

  compare_queue_data(qe, stdQe);

  EXPECT_EQ(qe.size(), stdQe.size());
  EXPECT_EQ(qe.empty(), stdQe.empty());
}

TEST(test_queue_constructor, move_queue_constructor) {
  my::queue<int> qe1({45, 68, 22, 44, 9009});
  std::queue<int> stdQe1({45, 68, 22, 44, 9009});
  my::queue<int> qe(std::move(qe1));
  std::queue<int> stdQe(std::move(stdQe1));

  compare_queue_data(qe, stdQe);

  EXPECT_EQ(qe.size(), stdQe.size());
  EXPECT_EQ(qe.empty(), stdQe.empty());
}

TEST(test_queue_operator, eq_operator) {
  my::queue<int> qe1({45, 68, 22, 44, 9009});
  std::queue<int> stdQe1({45, 68, 22, 44, 9009});
  my::queue<int> qe;
  std::queue<int> stdQe;

  qe = qe1;
  stdQe = stdQe1;

  compare_queue_data(qe, stdQe);

  EXPECT_EQ(qe.size(), stdQe.size());
  EXPECT_EQ(qe.empty(), stdQe.empty());
}

TEST(test_queue_methods, element_access) {
  my::queue<int> qe({45, 68, 22, 44, 9009});
  std::queue<int> stdQe({45, 68, 22, 44, 9009});

  EXPECT_EQ(qe.front(), stdQe.front());
  EXPECT_EQ(qe.back(), stdQe.back());
  EXPECT_EQ(qe.empty(), stdQe.empty());
  EXPECT_EQ(qe.size(), stdQe.size());
}

TEST(test_queue_methods, modifiers_push) {
  my::queue<int> qe({45, 68, 22, 44, 9009});
  std::queue<int> stdQe({45, 68, 22, 44, 9009});

  qe.push(359);
  stdQe.push(359);

  compare_queue_data(qe, stdQe);

  EXPECT_EQ(qe.front(), stdQe.front());
  EXPECT_EQ(qe.back(), stdQe.back());
  EXPECT_EQ(qe.empty(), stdQe.empty());
  EXPECT_EQ(qe.size(), stdQe.size());
}

TEST(test_queue_methods, modifiers_pop) {
  my::queue<int> qe({45, 68, 22, 44, 9009});
  std::queue<int> stdQe({45, 68, 22, 44, 9009});

  qe.pop();
  stdQe.pop();

  compare_queue_data(qe, stdQe);

  EXPECT_EQ(qe.front(), stdQe.front());
  EXPECT_EQ(qe.back(), stdQe.back());
  EXPECT_EQ(qe.empty(), stdQe.empty());
  EXPECT_EQ(qe.size(), stdQe.size());
}

TEST(test_queue_methods, modifiers_swap) {
  my::queue<int> qe1({45, 68, 22, 44, 9009});
  std::queue<int> stdQe1({45, 68, 22, 44, 9009});
  my::queue<int> qe({789, 111});
  std::queue<int> stdQe({789, 111});

  qe.swap(qe1);
  stdQe.swap(stdQe1);

  compare_queue_data(qe, stdQe);
  compare_queue_data(qe1, stdQe1);

  EXPECT_EQ(qe.front(), stdQe.front());
  EXPECT_EQ(qe.back(), stdQe.back());
  EXPECT_EQ(qe.empty(), stdQe.empty());
  EXPECT_EQ(qe.size(), stdQe.size());
  EXPECT_EQ(qe1.front(), stdQe1.front());
  EXPECT_EQ(qe1.back(), stdQe1.back());
  EXPECT_EQ(qe1.empty(), stdQe1.empty());
  EXPECT_EQ(qe1.size(), stdQe1.size());
}

TEST(test_queue_methods, modifiers_emplace_back) {
  my::queue<int> qe({45, 68, 22, 44, 9009});
  std::queue<int> stdQe({45, 68, 22, 44, 9009});

  qe.emplace_back(359);
  stdQe.emplace(359);

  compare_queue_data(qe, stdQe);

  EXPECT_EQ(qe.front(), stdQe.front());
  EXPECT_EQ(qe.back(), stdQe.back());
  EXPECT_EQ(qe.empty(), stdQe.empty());
  EXPECT_EQ(qe.size(), stdQe.size());
}
