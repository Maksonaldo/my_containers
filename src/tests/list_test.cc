#include <gtest/gtest.h>

TEST(test_list_constructor, default_constructor) {
  my::list<int> list;
  std::list<int> stdList;

  EXPECT_EQ(list.size(), stdList.size());
  EXPECT_EQ(list.empty(), stdList.empty());
}

TEST(test_list_constructor, pametrized_constructor) {
  my::list<int> list(4);
  std::list<int> stdList(4);
  EXPECT_EQ(list.size(), stdList.size());
}

TEST(test_list_constructor, initializer_list_constructor) {
  my::list<int> list({21, 42, 9999});
  std::list<int> stdList({21, 42, 9999});

  compare_list_data(list, stdList);
}

TEST(test_list_constructor, copy_list_constructor) {
  my::list<int> list1({21, 42, 9999});
  my::list<int> list(list1);

  std::list<int> stdList1({21, 42, 9999});
  std::list<int> stdList(stdList1);

  compare_list_data(list, stdList);
}

TEST(test_list_constructor, move_list_constructor) {
  my::list<int> list1({21, 42, 9999});
  my::list<int> list(std::move(list1));

  std::list<int> stdList1({21, 42, 9999});
  std::list<int> stdList(std::move(stdList1));

  compare_list_data(list, stdList);
}

TEST(test_list_operator, eq_operator) {
  my::list<int> list1({21, 42, 9999});
  my::list<int> list;
  list = list1;
  auto iter = list.begin();
  auto jter = list1.begin();

  for (; iter != list.end(); ++iter, ++jter) {
    EXPECT_EQ(*jter, *iter);
  }
}

TEST(test_list_methods, element_access) {
  my::list<int> list({21, 42, 9999});
  std::list<int> stdList({21, 42, 9999});

  EXPECT_EQ(list.front(), stdList.front());
  EXPECT_EQ(list.back(), stdList.back());
}

TEST(test_list_methods, iterators) {
  my::list<int> list({21, 42, 9999});
  std::list<int> stdList({21, 42, 9999});

  auto iter = list.begin();
  auto jter = stdList.begin();

  EXPECT_EQ(*iter, *jter);

  iter = list.end();
  jter = stdList.end();
  --iter;
  --jter;

  EXPECT_EQ(*iter, *jter);
}

TEST(test_list_methods, capacity) {
  my::list<int> list({21, 42, 9999});
  my::list<int> list1;
  std::list<int> stdList({21, 42, 9999});
  std::list<int> stdList1;

  EXPECT_EQ(list.empty(), stdList.empty());
  EXPECT_EQ(list1.empty(), stdList1.empty());
  EXPECT_EQ(list.size(), stdList.size());
  EXPECT_EQ(list1.size(), stdList1.size());
  EXPECT_EQ(list.max_size(), stdList.max_size());
  EXPECT_EQ(list1.max_size(), stdList1.max_size());
}

TEST(test_list_methods, modifiers_clear) {
  my::list<int> list({21, 42, 9999});
  std::list<int> stdList({21, 42, 9999});

  compare_list_data(list, stdList);
  list.clear();
  stdList.clear();
  compare_list_data(list, stdList);
}

TEST(test_list_methods, modifiers_insert) {
  my::list<int> list({21, 42, 9999});
  std::list<int> stdList({21, 42, 9999});

  auto iter = list.begin();
  auto jter = stdList.begin();

  list.insert(iter, 890);
  stdList.insert(jter, 890);

  compare_list_data(list, stdList);
  EXPECT_EQ(list.size(), stdList.size());
}

TEST(test_list_methods, modifiers_erase) {
  my::list<int> list({21, 42, 9999});
  std::list<int> stdList({21, 42, 9999});

  auto iter = list.begin();
  auto jter = stdList.begin();

  list.erase(iter);
  stdList.erase(jter);

  compare_list_data(list, stdList);
  EXPECT_EQ(list.size(), stdList.size());
}

TEST(test_list_methods, modifiers_push_back) {
  my::list<int> list({21, 42, 9999});
  std::list<int> stdList({21, 42, 9999});

  list.push_back(670);
  stdList.push_back(670);

  compare_list_data(list, stdList);
  EXPECT_EQ(list.size(), stdList.size());
}

TEST(test_list_methods, modifiers_pop_back) {
  my::list<int> list({21, 42, 9999});
  std::list<int> stdList({21, 42, 9999});

  list.pop_back();
  stdList.pop_back();

  compare_list_data(list, stdList);
  EXPECT_EQ(list.size(), stdList.size());
}

TEST(test_list_methods, modifiers_push_front) {
  my::list<int> list({21, 42, 9999});
  std::list<int> stdList({21, 42, 9999});

  list.push_front(345);
  stdList.push_front(345);

  compare_list_data(list, stdList);
  EXPECT_EQ(list.size(), stdList.size());
}

TEST(test_list_methods, modifiers_pop_front) {
  my::list<int> list({21, 42, 9999});
  std::list<int> stdList({21, 42, 9999});

  list.pop_front();
  stdList.pop_front();

  compare_list_data(list, stdList);
  EXPECT_EQ(list.size(), stdList.size());
}

TEST(test_list_methods, modifiers_swap) {
  my::list<int> list({21, 42, 9999});
  my::list<int> list1({300, 3000});
  std::list<int> stdList({21, 42, 9999});
  std::list<int> stdList1({300, 3000});

  list.swap(list1);
  stdList.swap(stdList1);

  compare_list_data(list, stdList);
  compare_list_data(list1, stdList1);
  EXPECT_EQ(list.size(), stdList.size());
  EXPECT_EQ(list1.size(), stdList1.size());
}

TEST(test_list_methods, modifiers_merge) {
  my::list<int> list({21, 42, 9999});
  my::list<int> list1({300, 3000});
  std::list<int> stdList({21, 42, 9999});
  std::list<int> stdList1({300, 3000});

  list.merge(list1);
  stdList.merge(stdList1);

  compare_list_data(list, stdList);
  EXPECT_EQ(list.size(), stdList.size());
}

TEST(test_list_methods, modifiers_splice) {
  my::list<int> list({21, 42, 9999});
  my::list<int> list1({300, 3000});
  std::list<int> stdList({21, 42, 9999});
  std::list<int> stdList1({300, 3000});

  auto iter = list.begin();
  auto jter = stdList.begin();

  ++iter;
  ++jter;
  list.splice(iter, list1);
  stdList.splice(jter, stdList1);

  compare_list_data(list, stdList);
  EXPECT_EQ(list.size(), stdList.size());
}

TEST(test_list_methods, modifiers_reverse) {
  my::list<int> list({21, 42, 9999});
  std::list<int> stdList({21, 42, 9999});

  list.reverse();
  stdList.reverse();

  compare_list_data(list, stdList);
  EXPECT_EQ(list.size(), stdList.size());
}

TEST(test_list_methods, modifiers_unique) {
  my::list<int> list({21, 42, 42, 9999, 42});
  std::list<int> stdList({21, 42, 42, 9999, 42});

  list.unique();
  stdList.unique();

  compare_list_data(list, stdList);
  EXPECT_EQ(list.size(), stdList.size());
}

TEST(test_list_methods, modifiers_sort) {
  my::list<int> list({21, 1, 9999, 42, 42});
  std::list<int> stdList({21, 1, 9999, 42, 42});

  list.sort();
  stdList.sort();

  compare_list_data(list, stdList);
  EXPECT_EQ(list.size(), stdList.size());
}

TEST(test_list_methods, modifiers_emplaces) {
  my::list<int> list({3000});
  std::list<int> stdList({3000});

  auto iter = list.begin();
  auto jter = stdList.begin();

  list.emplace(iter, 33);
  stdList.emplace(jter, 33);

  list.emplace_back(359);
  stdList.emplace_back(359);

  list.emplace_front(1703);
  stdList.emplace_front(1703);

  compare_list_data(list, stdList);
  EXPECT_EQ(list.size(), stdList.size());
}
