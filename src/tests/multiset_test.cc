#include <gtest/gtest.h>

TEST(Multiset_Test_begin, Test_1) {
  my::multiset<int> my_multiset({1, 2, 3});
  std::multiset<int> multiset({1, 2, 3});
  my::multiset<int>::iterator my_it = my_multiset.begin();
  std::multiset<int>::iterator it = multiset.begin();
  ASSERT_EQ(*my_it, *it);
}

TEST(Multiset_Test_begin, Test_2) {
  my::multiset<int> my_multiset({44, 423, 3242, 4234234, 12, 111});
  std::multiset<int> multiset({12, 44, 66, 32});
  my::multiset<int>::iterator my_it = my_multiset.begin();
  std::multiset<int>::iterator it = multiset.begin();
  ASSERT_EQ(*my_it, *it);
}

TEST(Multiset_Test_empty, Test_1) {
  my::multiset<int> my_multiset({44, 423, 3242, 4234234, 12, 111});
  std::multiset<int> multiset({12, 44, 66, 32});
  auto my_count = my_multiset.empty();
  auto count = multiset.empty();
  ASSERT_EQ(my_count, count);
}

TEST(Multiset_Test_empty, Test_2) {
  my::multiset<int> my_multiset;
  std::multiset<int> multiset;
  auto my_count = my_multiset.empty();
  auto count = multiset.empty();
  ASSERT_EQ(my_count, count);
}

TEST(Multiset_Test_size, Test_1) {
  my::multiset<int> my_multiset({1, 2, 3});
  std::multiset<int> multiset({1, 2, 3});
  auto my_count = my_multiset.size();
  auto count = multiset.size();
  ASSERT_EQ(my_count, count);
}

TEST(Multiset_Test_size, Test_2) {
  my::multiset<int> my_multiset;
  std::multiset<int> multiset;
  auto my_count = my_multiset.size();
  auto count = multiset.size();
  ASSERT_EQ(my_count, count);
}

TEST(Multiset_Test_find, Test_1) {
  my::multiset<int> my_multiset({2, 4, 124, 12, 521, 3});
  std::multiset<int> multiset({2, 4, 124, 12, 521, 3});
  my::multiset<int>::iterator my_it = my_multiset.find(3);
  std::multiset<int>::iterator it = multiset.find(3);
  ASSERT_EQ(*my_it, *it);
}

TEST(Multiset_Test_find, Test_2) {
  my::multiset<int> my_multiset({23423, 23423, 1231, 2312, -343, 1});
  std::multiset<int> multiset({23423, 23423, 1231, 2312, -343, 1});
  my::multiset<int>::iterator my_it = my_multiset.find(2312);
  std::multiset<int>::iterator it = multiset.find(2312);
  ASSERT_EQ(*my_it, *it);
}

TEST(Multiset_Test_contains_bool, Test_1) {
  my::multiset<int> my_multiset({23423, 23423, 1231, 2312, -343, 1});
  bool my_count = my_multiset.contains(1);
  ASSERT_EQ(my_count, 1);
}
TEST(Multiset_Test_contains_bool, Test_2) {
  my::multiset<int> my_multiset({23423, 23423, 1231, 2312, -343, 1});
  bool my_count = my_multiset.contains(999);
  ASSERT_EQ(my_count, 0);
}

TEST(Multiset_Test_swap, Test_1) {
  my::multiset<int> my_multiset({6, 2, 4, 56, 33, 25});
  my::multiset<int> result({-1, -2, -3, -4});
  my_multiset.swap(result);

  ASSERT_TRUE(my_multiset.contains(-2));
  ASSERT_TRUE(result.contains(56));

  ASSERT_EQ(my_multiset.size(), 4);
  ASSERT_EQ(result.size(), 6);
}

TEST(Multiset_Test_insert, Test_1) {
  my::multiset<int> my_multiset;
  std::multiset<int> multiset;
  my_multiset.insert(-2);
  multiset.insert(-2);

  ASSERT_TRUE(my_multiset.contains(-2));

  ASSERT_EQ(my_multiset.size(), 1);
  ASSERT_EQ(multiset.size(), 1);
}

TEST(Multiset_Test_insert, Test_2) {
  my::multiset<int> my_multiset({34, 32, 12});
  std::multiset<int> multiset({34, 32, 12});
  my_multiset.insert(66);
  multiset.insert(66);

  ASSERT_TRUE(my_multiset.contains(66));

  ASSERT_EQ(my_multiset.size(), 4);
  ASSERT_EQ(multiset.size(), 4);
}

TEST(Multiset_Test_erase, Test_1) {
  my::multiset<int> my_multiset({34, 32, 12});
  std::multiset<int> multiset({34, 32, 12});
  my_multiset.erase(34);
  multiset.erase(34);
  ASSERT_EQ(my_multiset.size(), 2);
  ASSERT_EQ(multiset.size(), 2);
}

TEST(Multiset_Test_erase, Test_2) {
  my::multiset<int> my_multiset({12});
  std::multiset<int> multiset({12});
  my_multiset.erase(12);
  multiset.erase(12);
  ASSERT_EQ(my_multiset.size(), 0);
  ASSERT_EQ(multiset.size(), 0);
}

TEST(Multiset_Test_erase, Test_3) {
  my::multiset<int> my_multiset({12, 33, 1});
  std::multiset<int> multiset({12, 33, 1});
  my_multiset.erase(1);
  multiset.erase(1);
  my::multiset<int>::iterator my_it = my_multiset.begin();
  std::multiset<int>::iterator it = multiset.begin();
  ASSERT_EQ(my_multiset.size(), multiset.size());
  ASSERT_EQ(*my_it, *it);
}

TEST(Multiset_Test_merge, Test_1) {
  my::multiset<int> my_multiset({6, 2, 4, 56, 16, 33, 25});
  my::multiset<int> result({16, 77, 1});
  my_multiset.merge(result);
  my::multiset<int>::iterator my_it = my_multiset.begin();
  std::cout << *my_it;
  ASSERT_EQ(*my_it, 1);
  ASSERT_TRUE(my_multiset.contains(77));
  ASSERT_EQ(my_multiset.size(), 10);
  ASSERT_TRUE(result.empty());
}

TEST(Multiset_Test_clear, Test_1) {
  my::multiset<int> my_multiset({12, 3423, 34});
  std::multiset<int> multiset({12, 1234, 123, 23});
  my_multiset.clear();
  multiset.clear();
  ASSERT_EQ(my_multiset.size(), multiset.size());
  ASSERT_EQ(my_multiset.size(), 0);
  ASSERT_EQ(multiset.size(), 0);
}

TEST(Multiset_Test_constr_copy, Test_1) {
  my::multiset<int> my_multiset({23423, 23423, 1231, 2312, -343, 1});
  my::multiset<int> result(my_multiset);
  my::multiset<int>::iterator my_it = result.begin();
  ASSERT_EQ(*my_it, -343);
  ASSERT_EQ(result.size(), 6);
}

TEST(Multiset_Test_constr_move, Test_1) {
  my::multiset<int> my_multiset({23423, 23423, 1231, 2312, -343, 1});
  my::multiset<int> result(std::move(my_multiset));
  my::multiset<int>::iterator my_it = result.begin();
  ASSERT_EQ(*my_it, -343);
  ASSERT_EQ(result.size(), 6);
}

TEST(Multiset_Test_constr_plus, Test_1) {
  my::multiset<int> my_multiset({1, 2, 3});
  std::multiset<int> multiset({1, 2, 3});
  my::multiset<int>::iterator my_it = my_multiset.begin();
  std::multiset<int>::iterator it = multiset.begin();
  ++it;
  ++my_it;
  ASSERT_EQ(*my_it, *it);
}

TEST(Multiset_Test_constr_minus, Test_1) {
  my::multiset<int> my_multiset({1, 2, 3});
  std::multiset<int> multiset({1, 2, 3});
  my::multiset<int>::iterator my_it = my_multiset.begin();
  std::multiset<int>::iterator it = multiset.begin();
  ++it;
  ++my_it;
  --it;
  --my_it;
  ASSERT_EQ(*my_it, *it);
}

TEST(Multiset_Test_no_equal, Test_1) {
  my::multiset<int> my_multiset({1, 2, 3});
  my::multiset<int>::iterator my_it = my_multiset.begin();
  auto my_it2 = my_it++;
  ++my_it;
  bool result = 0;
  if (*my_it != *my_it2) {
    result = 1;
  }
  ASSERT_TRUE(result);
}

TEST(Multiset_Test_equal, Test_1) {
  my::multiset<int> my_multiset({1, 2, 3});
  my::multiset<int>::iterator my_it = my_multiset.begin();
  auto my_it2 = ++my_it;
  bool result = 0;
  if (*my_it == *my_it2) {
    result = 1;
  }
  ASSERT_TRUE(result);
}

TEST(Multiset_multiset_test, swap) {
  my::multiset<int> mys({6, 2, 4, 56, 33, 25});
  my::multiset<int> mys1({-1, -2, -3, -4});
  mys.swap(mys1);

  ASSERT_TRUE(mys.contains(-2));
  ASSERT_TRUE(mys1.contains(56));

  ASSERT_EQ(mys.size(), 4);
  ASSERT_EQ(mys1.size(), 6);
}

TEST(Multiset_multiset_test, find) {
  my::multiset<int> mys({6, 2, 4, 56, 33, 25});

  my::multiset<int>::iterator pos_2 = mys.find(2);
  my::multiset<int>::iterator pos_25 = mys.find(25);

  ASSERT_EQ(2, *pos_2);
  ASSERT_EQ(25, *pos_25);
}

TEST(Multiset_multiset_test, ass_operator) {
  my::multiset<int> mys({6, 2, 4, 56, -1, 33, 25});
  my::multiset<int> mys1;
  mys1 = std::move(mys);
  ASSERT_TRUE(mys1.contains(33));
}

TEST(Multiset_multiset_test, insert) {
  my::multiset<int> mys;
  mys.insert(3);
  mys.insert(1);
  mys.insert(5);
  ASSERT_TRUE(mys.contains(1));
  ASSERT_EQ(mys.size(), 3);
}

TEST(Multiset_Test_insert, Test_4) {
  my::multiset<int> my_multiset{1, 2, 3, 4, 5};
  int i = 1;
  my::multiset<int>::iterator it = my_multiset.begin();
  for (; it != my_multiset.end(); it++) {
    ASSERT_EQ(*it, i);
    i++;
  }
}

TEST(Multiset_Test_count, Test_1) {
  my::multiset<int> my_multiset{1, 2, 3, 4, 5, 3, 3, 3};
  std::multiset<int> multiset{1, 2, 3, 4, 5, 3, 3, 3};
  ASSERT_EQ(my_multiset.count(3), multiset.count(3));
}

TEST(Multiset_Test_count, Test_2) {
  my::multiset<int> my_multiset{1, 2, 3, 4, 5, 3, 3, 3};
  std::multiset<int> multiset{1, 2, 3, 4, 5, 3, 3, 3};
  ASSERT_EQ(my_multiset.count(1), multiset.count(1));
}

TEST(Multiset_Test_count, Test_3) {
  my::multiset<int> my_multiset{1, 2, 3, 4, 5, 3, 3, 3};
  std::multiset<int> multiset{1, 2, 3, 4, 5, 3, 3, 3};
  ASSERT_EQ(my_multiset.count(0), multiset.count(0));
}

TEST(Multiset_Test_find, Test_3) {
  my::multiset<int> my_multiset{1, 2, 3, 4, 5, 3, 3, 3};
  std::multiset<int> multiset{1, 2, 3, 4, 5, 3, 3, 3};
  my::multiset<int>::iterator my_it = my_multiset.find(2);
  std::multiset<int>::iterator it = multiset.find(2);
  ASSERT_EQ(*my_it, *it);
}

TEST(Multiset_Test_find, Test_4) {
  my::multiset<int> my_multiset{1, 2, 3, 4, 5, 3, 3, 3};
  std::multiset<int> multiset{1, 2, 3, 4, 5, 3, 3, 3};
  my::multiset<int>::iterator my_it = my_multiset.find(3);
  std::multiset<int>::iterator it = multiset.find(3);
  ASSERT_EQ(*my_it, *it);
}

TEST(Multiset_Test_contains, Test_1) {
  my::multiset<int> my_multiset{1, 2, 3, 4, 5, 3, 3, 3};
  std::multiset<int> multiset{1, 2, 3, 4, 5, 3, 3, 3};
  ASSERT_EQ(my_multiset.contains(1), 1);
}

TEST(Multiset_Test_contains, Test_2) {
  my::multiset<int> my_multiset{1, 2, 3, 4, 5, 3, 3, 3};
  std::multiset<int> multiset{1, 2, 3, 4, 5, 3, 3, 3};
  ASSERT_EQ(my_multiset.contains(3), 1);
}

TEST(Multiset_Test_contains, Test_3) {
  my::multiset<int> my_multiset{1, 2, 3, 4, 5, 3, 3, 3};
  std::multiset<int> multiset{1, 2, 3, 4, 5, 3, 3, 3};
  ASSERT_EQ(my_multiset.contains(99), 0);
}

TEST(Multiset_Test_equal_range, Test_1) {
  my::multiset<int> my_multiset{1, 2, 3, 4, 5, 3, 3, 3};
  std::multiset<int> multiset{1, 2, 3, 4, 5, 3, 3, 3};
  const auto [it1, it2] = multiset.equal_range(4);
  const auto [my_it1, my_it2] = my_multiset.equal_range(4);
  ASSERT_EQ(*it1, *my_it1);
  ASSERT_EQ(*it2, *my_it2);
}

TEST(Multiset_Test_equal_range, Test_2) {
  my::multiset<int> my_multiset{342, 343, 32, 32, 32, 1, 1, 3};
  std::multiset<int> multiset{342, 343, 32, 32, 32, 1, 1, 3};
  const auto [it1, it2] = multiset.equal_range(1);
  const auto [my_it1, my_it2] = my_multiset.equal_range(1);
  ASSERT_EQ(*it1, *my_it1);
  ASSERT_EQ(*it2, *my_it2);
}

TEST(Multiset_Test_equal_range, Test_3) {
  my::multiset<int> my_multiset{342, 343, 32, 32, 32, 1, 1, 3};
  std::multiset<int> multiset{342, 343, 32, 32, 32, 1, 1, 3};
  const auto [it1, it2] = multiset.equal_range(342);
  const auto [my_it1, my_it2] = my_multiset.equal_range(342);
  ASSERT_EQ(*it1, *my_it1);
  ASSERT_EQ(*it2, *my_it2);
}

TEST(Multiset_Test_lower_bound, Test_1) {
  my::multiset<int> my_multiset{342, 343, 32, 32, 32, 1, 1, 3};
  std::multiset<int> multiset{342, 343, 32, 32, 32, 1, 1, 3};
  const auto it = multiset.lower_bound(342);
  const auto my_it = my_multiset.lower_bound(342);
  ASSERT_EQ(*it, *my_it);
}

TEST(Multiset_Test_lower_bound, Test_2) {
  my::multiset<int> my_multiset{342, 343, 32, 32, 32, 1, 1, 3};
  std::multiset<int> multiset{342, 343, 32, 32, 32, 1, 1, 3};
  const auto it = multiset.lower_bound(1);
  const auto my_it = my_multiset.lower_bound(1);
  ASSERT_EQ(*it, *my_it);
}

TEST(Multiset_Test_lower_bound, Test_3) {
  my::multiset<int> my_multiset{342, 343, 32, 32, 32, 1, 1, 3};
  std::multiset<int> multiset{342, 343, 32, 32, 32, 1, 1, 3};
  const auto it = multiset.lower_bound(32);
  const auto my_it = my_multiset.lower_bound(32);
  ASSERT_EQ(*it, *my_it);
}

TEST(Multiset_Test_upper_bound, Test_1) {
  my::multiset<int> my_multiset{342, 343, 32, 32, 32, 1, 1, 3};
  std::multiset<int> multiset{342, 343, 32, 32, 32, 1, 1, 3};
  const auto it = multiset.upper_bound(32);
  const auto my_it = my_multiset.upper_bound(32);
  ASSERT_EQ(*it, *my_it);
}

TEST(Multiset_Test_upper_bound, Test_2) {
  my::multiset<int> my_multiset{342, 343, 32, 32, 32, 1, 1, 3};
  std::multiset<int> multiset{342, 343, 32, 32, 32, 1, 1, 3};
  const auto it = multiset.upper_bound(1);
  const auto my_it = my_multiset.upper_bound(1);
  ASSERT_EQ(*it, *my_it);
}

TEST(Multiset_Test_upper_bound, Test_3) {
  my::multiset<int> my_multiset{342, 343, 32, 32, 32, 1, 1, 3};
  std::multiset<int> multiset{342, 343, 32, 32, 32, 1, 1, 3};
  const auto it = multiset.upper_bound(342);
  const auto my_it = my_multiset.upper_bound(342);
  ASSERT_EQ(*it, *my_it);
}

TEST(Multiset_Test_insert, insert) {
  my::multiset<int> mys;
  mys.insert(3);
  mys.insert(1);
  mys.insert(1);
  mys.insert(5);
  ASSERT_TRUE(mys.contains(1));
  ASSERT_EQ(mys.size(), 4);
}
