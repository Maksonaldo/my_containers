#include <gtest/gtest.h>

TEST(Set_Test_begin, Test_1) {
  my::set<int> my_set({1, 2, 3});
  std::set<int> set({1, 2, 3});
  my::set<int>::iterator my_it = my_set.begin();
  std::set<int>::iterator it = set.begin();
  ASSERT_EQ(*my_it, *it);
}

TEST(Set_Test_begin, Test_2) {
  my::set<int> my_set({44, 423, 3242, 4234234, 12, 111});
  std::set<int> set({12, 44, 66, 32});
  my::set<int>::iterator my_it = my_set.begin();
  std::set<int>::iterator it = set.begin();
  ASSERT_EQ(*my_it, *it);
}

TEST(Set_Test_empty, Test_1) {
  my::set<int> my_set({44, 423, 3242, 4234234, 12, 111});
  std::set<int> set({12, 44, 66, 32});
  auto my_count = my_set.empty();
  auto count = set.empty();
  ASSERT_EQ(my_count, count);
}

TEST(Set_Test_empty, Test_2) {
  my::set<int> my_set;
  std::set<int> set;
  auto my_count = my_set.empty();
  auto count = set.empty();
  ASSERT_EQ(my_count, count);
}

TEST(Set_Test_size, Test_1) {
  my::set<int> my_set({1, 2, 3});
  std::set<int> set({1, 2, 3});
  auto my_count = my_set.size();
  auto count = set.size();
  ASSERT_EQ(my_count, count);
}

TEST(Set_Test_size, Test_2) {
  my::set<int> my_set;
  std::set<int> set;
  auto my_count = my_set.size();
  auto count = set.size();
  ASSERT_EQ(my_count, count);
}

TEST(Set_Test_find, Test_1) {
  my::set<int> my_set({2, 4, 124, 12, 521, 3});
  std::set<int> set({2, 4, 124, 12, 521, 3});
  my::set<int>::iterator my_it = my_set.find(3);
  std::set<int>::iterator it = set.find(3);
  ASSERT_EQ(*my_it, *it);
}

TEST(Set_Test_find, Test_2) {
  my::set<int> my_set({23423, 23423, 1231, 2312, -343, 1});
  std::set<int> set({23423, 23423, 1231, 2312, -343, 1});
  my::set<int>::iterator my_it = my_set.find(2312);
  std::set<int>::iterator it = set.find(2312);
  ASSERT_EQ(*my_it, *it);
}

TEST(Set_Test_insert_bool, Test_1) {
  my::set<int> my_set({23423, 23423, 1231, 2312, -343, 1});
  std::set<int> set({23423, 23423, 1231, 2312, -343, 1});
  auto [my_it, my_success] = my_set.insert(12);
  auto [it, success] = set.insert(12);
  ASSERT_EQ(*my_it, *it);
  ASSERT_EQ(my_success, success);
}

TEST(Set_Test_insert_bool, Test_2) {
  my::set<int> my_set({23423, 23423, 1231, 2312, -343, 1});
  std::set<int> set({23423, 23423, 1231, 2312, -343, 1});
  auto [my_it, my_success] = my_set.insert(1111);
  auto [it, success] = set.insert(1111);
  ASSERT_EQ(*my_it, *it);
  ASSERT_EQ(my_success, success);
}

TEST(Set_Test_insert_bool, Test_3) {
  my::set<int> my_set({23423, 23423, 1231, 2312, -343, 1});
  std::set<int> set({23423, 23423, 1231, 2312, -343, 1});
  auto [my_it, my_success] = my_set.insert(1);
  auto [it, success] = set.insert(1);
  ASSERT_EQ(*my_it, *it);
  ASSERT_EQ(my_success, success);
}

TEST(Set_Test_contains_bool, Test_1) {
  my::set<int> my_set({23423, 23423, 1231, 2312, -343, 1});
  bool my_count = my_set.contains(1);
  ASSERT_EQ(my_count, 1);
}

TEST(Set_Test_contains_bool, Test_2) {
  my::set<int> my_set({23423, 23423, 1231, 2312, -343, 1});
  bool my_count = my_set.contains(999);
  ASSERT_EQ(my_count, 0);
}

TEST(Set_Test_swap, Test_1) {
  my::set<int> my_set({6, 2, 4, 56, 33, 25});
  my::set<int> result({-1, -2, -3, -4});
  my_set.swap(result);

  ASSERT_TRUE(my_set.contains(-2));
  ASSERT_TRUE(result.contains(56));

  ASSERT_EQ(my_set.size(), 4);
  ASSERT_EQ(result.size(), 6);
}

TEST(Set_Test_insert, Test_1) {
  my::set<int> my_set;
  std::set<int> set;
  my_set.insert(-2);
  set.insert(-2);

  ASSERT_TRUE(my_set.contains(-2));

  ASSERT_EQ(my_set.size(), 1);
  ASSERT_EQ(set.size(), 1);
}

TEST(Set_Test_insert, Test_2) {
  my::set<int> my_set({34, 32, 12});
  std::set<int> set({34, 32, 12});
  my_set.insert(66);
  set.insert(66);

  ASSERT_TRUE(my_set.contains(66));

  ASSERT_EQ(my_set.size(), 4);
  ASSERT_EQ(set.size(), 4);
}

TEST(Set_Test_erase, Test_1) {
  my::set<int> my_set({34, 32, 12});
  std::set<int> set({34, 32, 12});
  my_set.erase(34);
  set.erase(34);
  ASSERT_EQ(my_set.size(), 2);
  ASSERT_EQ(set.size(), 2);
}

TEST(Set_Test_erase, Test_2) {
  my::set<int> my_set({12});
  std::set<int> set({12});
  my_set.erase(12);
  set.erase(12);
  ASSERT_EQ(my_set.size(), 0);
  ASSERT_EQ(set.size(), 0);
}

TEST(Set_Test_erase, Test_3) {
  my::set<int> my_set({12, 33, 1});
  std::set<int> set({12, 33, 1});
  my_set.erase(1);
  set.erase(1);
  my::set<int>::iterator my_it = my_set.begin();
  std::set<int>::iterator it = set.begin();
  ASSERT_EQ(my_set.size(), set.size());
  ASSERT_EQ(*my_it, *it);
}

TEST(Set_Test_merge, Test_1) {
  my::set<int> my_set({6, 2, 4, 56, 16, 33, 25});
  my::set<int> result({16, 77, 1});
  my_set.merge(result);
  my::set<int>::iterator my_it = my_set.begin();
  std::cout << *my_it;
  ASSERT_EQ(*my_it, 1);
  ASSERT_TRUE(my_set.contains(77));
  ASSERT_EQ(my_set.size(), 10);
  ASSERT_TRUE(result.empty());
}

TEST(Set_Test_clear, Test_1) {
  my::set<int> my_set({12, 3423, 34});
  std::set<int> set({12, 1234, 123, 23});
  my_set.clear();
  set.clear();
  ASSERT_EQ(my_set.size(), set.size());
  ASSERT_EQ(my_set.size(), 0);
  ASSERT_EQ(set.size(), 0);
}

TEST(Set_Test_constr_copy, Test_1) {
  my::set<int> my_set({23423, 23423, 1231, 2312, -343, 1});
  my::set<int> result(my_set);
  my::set<int>::iterator my_it = result.begin();
  ASSERT_EQ(*my_it, -343);
  ASSERT_EQ(result.size(), 6);
}
TEST(Set_Test_constr_move, Test_1) {
  my::set<int> my_set({23423, 23423, 1231, 2312, -343, 1});
  my::set<int> result(std::move(my_set));
  my::set<int>::iterator my_it = result.begin();
  ASSERT_EQ(*my_it, -343);
  ASSERT_EQ(result.size(), 6);
}

TEST(Set_Test_constr_plus, Test_1) {
  my::set<int> my_set({1, 2, 3});
  std::set<int> set({1, 2, 3});
  my::set<int>::iterator my_it = my_set.begin();
  std::set<int>::iterator it = set.begin();
  ++it;
  ++my_it;
  ASSERT_EQ(*my_it, *it);
}

TEST(Set_Test_constr_minus, Test_1) {
  my::set<int> my_set({1, 2, 3});
  std::set<int> set({1, 2, 3});
  my::set<int>::iterator my_it = my_set.begin();
  std::set<int>::iterator it = set.begin();
  ++it;
  ++my_it;
  --it;
  --my_it;
  ASSERT_EQ(*my_it, *it);
}

TEST(Set_Test_no_equal, Test_1) {
  my::set<int> my_set({1, 2, 3});
  my::set<int>::iterator my_it = my_set.begin();
  auto my_it2 = my_it++;
  ++my_it;
  bool result = 0;
  if (*my_it != *my_it2) {
    result = 1;
  }
  ASSERT_TRUE(result);
}

TEST(Set_Test_equal, Test_1) {
  my::set<int> my_set({1, 2, 3});
  my::set<int>::iterator my_it = my_set.begin();
  auto my_it2 = ++my_it;
  bool result = 0;
  if (*my_it == *my_it2) {
    result = 1;
  }
  ASSERT_TRUE(result);
}

TEST(Set_set_test, swap) {
  my::set<int> mys({6, 2, 4, 56, 33, 25});
  my::set<int> mys1({-1, -2, -3, -4});
  mys.swap(mys1);

  ASSERT_TRUE(mys.contains(-2));
  ASSERT_TRUE(mys1.contains(56));

  ASSERT_EQ(mys.size(), 4);
  ASSERT_EQ(mys1.size(), 6);
}

TEST(Set_set_test, find) {
  my::set<int> mys({6, 2, 4, 56, 33, 25});

  my::set<int>::iterator pos_2 = mys.find(2);
  my::set<int>::iterator pos_25 = mys.find(25);

  ASSERT_EQ(2, *pos_2);
  ASSERT_EQ(25, *pos_25);
}

TEST(Set_set_test, ass_operator) {
  my::set<int> mys({6, 2, 4, 56, -1, 33, 25});
  my::set<int> mys1;
  mys1 = std::move(mys);
  ASSERT_TRUE(mys1.contains(33));
}

TEST(Set_set_test, insert) {
  my::set<int> mys;
  mys.insert(3);
  mys.insert(1);
  mys.insert(5);
  ASSERT_TRUE(mys.contains(1));
  ASSERT_EQ(mys.size(), 3);
}

TEST(Set_Test_emplase, Test_1) {
  my::set<int> my_set;
  my_set.emplace(4, 5, 7, 1, 3, 6);
  my::set<int>::iterator it = my_set.begin();
  ASSERT_EQ(my_set.size(), 6);
  ASSERT_EQ(*it, 1);
}

TEST(Set_Test_insert, Test_4) {
  my::set<int> my_set{1, 2, 3, 4, 5};
  int i = 1;
  my::set<int>::iterator it = my_set.begin();
  for (; it != my_set.end(); it++) {
    ASSERT_EQ(*it, i);
    i++;
  }
}
