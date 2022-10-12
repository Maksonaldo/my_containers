#include <gtest/gtest.h>

TEST(Map_Test_begin, Test_1) {
  my::map<int, int> my_map;
  std::map<int, int> map;
  my_map.insert(std::pair<int, int>(1, 22));
  my_map.insert(std::pair<int, int>(2, 2343));
  my_map.insert(std::pair<int, int>(3, 2234));
  my_map.insert(std::pair<int, int>(4, 231));

  map.insert(std::pair<int, int>(1, 22));
  map.insert(std::pair<int, int>(2, 2343));
  map.insert(std::pair<int, int>(3, 2234));
  map.insert(std::pair<int, int>(4, 231));

  my::map<int, int>::iterator my_it = my_map.begin();
  std::map<int, int>::iterator it = map.begin();
  ASSERT_EQ((*my_it).first, (*it).first);
  ASSERT_EQ((*my_it).second, (*it).second);
}

TEST(Map_Test_begin, Test_2) {
  my::map<int, int> my_map{
      std::pair<int, int>(423, 22), std::pair<int, int>(5644, 22),
      std::pair<int, int>(434, 32), std::pair<int, int>(11, 22),
      std::pair<int, int>(534, 3)};
  std::map<int, int> map{
      std::pair<int, int>(423, 22), std::pair<int, int>(5644, 22),
      std::pair<int, int>(434, 32), std::pair<int, int>(11, 22),
      std::pair<int, int>(534, 3)};

  my::map<int, int>::iterator my_it = my_map.begin();
  std::map<int, int>::iterator it = map.begin();
  ASSERT_EQ((*my_it).first, (*it).first);
  ASSERT_EQ((*my_it).second, (*it).second);
}

TEST(Map_Test_empty, Test_1) {
  my::map<int, int> my_map{
      std::pair<int, int>(423, 22), std::pair<int, int>(5644, 22),
      std::pair<int, int>(434, 32), std::pair<int, int>(11, 22),
      std::pair<int, int>(534, 3)};
  std::map<int, int> map{
      std::pair<int, int>(423, 22), std::pair<int, int>(5644, 22),
      std::pair<int, int>(434, 32), std::pair<int, int>(11, 22),
      std::pair<int, int>(534, 3)};
  auto my_count = my_map.empty();
  auto count = map.empty();
  ASSERT_EQ(my_count, count);
}

TEST(Map_Test_empty, Test_2) {
  my::map<int, int> my_map{
      std::pair<int, int>(423, 22), std::pair<int, int>(5644, 22),
      std::pair<int, int>(434, 32), std::pair<int, int>(11, 22),
      std::pair<int, int>(534, 3)};
  std::map<int, int> map{
      std::pair<int, int>(423, 22), std::pair<int, int>(5644, 22),
      std::pair<int, int>(434, 32), std::pair<int, int>(11, 22),
      std::pair<int, int>(534, 3)};
  auto my_count = my_map.empty();
  auto count = map.empty();
  ASSERT_EQ(my_count, count);
}

TEST(Map_Test_size, Test_1) {
  my::map<int, int> my_map{
      std::pair<int, int>(423, 22), std::pair<int, int>(5644, 22),
      std::pair<int, int>(434, 32), std::pair<int, int>(11, 22),
      std::pair<int, int>(534, 3)};
  std::map<int, int> map{
      std::pair<int, int>(423, 22), std::pair<int, int>(5644, 22),
      std::pair<int, int>(434, 32), std::pair<int, int>(11, 22),
      std::pair<int, int>(534, 3)};
  auto my_count = my_map.size();
  auto count = map.size();
  ASSERT_EQ(my_count, count);
}

TEST(Map_Test_size, Test_2) {
  my::map<int, int> my_map{
      std::pair<int, int>(423, 22), std::pair<int, int>(5644, 22),
      std::pair<int, int>(434, 32), std::pair<int, int>(11, 22),
      std::pair<int, int>(534, 3)};
  std::map<int, int> map{
      std::pair<int, int>(423, 22), std::pair<int, int>(5644, 22),
      std::pair<int, int>(434, 32), std::pair<int, int>(11, 22),
      std::pair<int, int>(534, 3)};
  auto my_count = my_map.size();
  auto count = map.size();
  ASSERT_EQ(my_count, count);
}

TEST(Map_Test_find, Test_1) {
  my::map<int, int> my_map{
      std::pair<int, int>(423, 22), std::pair<int, int>(5644, 22),
      std::pair<int, int>(434, 32), std::pair<int, int>(11, 22),
      std::pair<int, int>(534, 3)};
  std::map<int, int> map{
      std::pair<int, int>(423, 22), std::pair<int, int>(5644, 22),
      std::pair<int, int>(434, 32), std::pair<int, int>(11, 22),
      std::pair<int, int>(534, 3)};
  my::map<int, int>::iterator my_it = my_map.find(423);
  std::map<int, int>::iterator it = map.find(423);
  ASSERT_EQ((*my_it).first, (*it).first);
  ASSERT_EQ((*my_it).second, (*it).second);
}

TEST(Map_Test_find, Test_2) {
  my::map<int, int> my_map{
      std::pair<int, int>(12, 4356), std::pair<int, int>(-22, 22),
      std::pair<int, int>(3, 32), std::pair<int, int>(11, 22),
      std::pair<int, int>(56, 3)};
  std::map<int, int> map{
      std::pair<int, int>(12, 4356), std::pair<int, int>(-22, 22),
      std::pair<int, int>(3, 32), std::pair<int, int>(11, 22),
      std::pair<int, int>(56, 3)};
  my::map<int, int>::iterator my_it = my_map.find(11);
  std::map<int, int>::iterator it = map.find(11);
  ASSERT_EQ((*my_it).first, (*it).first);
  ASSERT_EQ((*my_it).second, (*it).second);
}

TEST(Map_Test_contains_bool, Test_1) {
  my::map<int, int> my_map{
      std::pair<int, int>(12, 4356), std::pair<int, int>(-22, 22),
      std::pair<int, int>(3, 32), std::pair<int, int>(11, 22),
      std::pair<int, int>(56, 3)};
  bool my_count = my_map.contains(3);
  ASSERT_EQ(my_count, 1);
}

TEST(Map_Test_contains_bool, Test_2) {
  my::map<int, int> my_map{
      std::pair<int, int>(12, 4356), std::pair<int, int>(-22, 22),
      std::pair<int, int>(3, 32), std::pair<int, int>(11, 22),
      std::pair<int, int>(56, 3)};

  bool my_count = my_map.contains(999);
  ASSERT_EQ(my_count, 0);
}

TEST(Map_Test_swap, Test_1) {
  my::map<int, int> my_map{
      std::pair<int, int>(12, 4356), std::pair<int, int>(-22, 22),
      std::pair<int, int>(3, 32), std::pair<int, int>(11, 22),
      std::pair<int, int>(56, 3)};
  my::map<int, int> result{std::pair<int, int>(1, 0),
                           std::pair<int, int>(-2, 4)};
  my_map.swap(result);

  ASSERT_TRUE(my_map.contains(-2));
  ASSERT_TRUE(result.contains(12));

  ASSERT_EQ(my_map.size(), 2);
  ASSERT_EQ(result.size(), 5);
}

TEST(Map_Test_insert, Test_1) {
  my::map<int, int> my_map{
      std::pair<int, int>(12, 4356), std::pair<int, int>(-22, 22),
      std::pair<int, int>(3, 32), std::pair<int, int>(11, 22),
      std::pair<int, int>(56, 3)};
  std::map<int, int> map{
      std::pair<int, int>(12, 4356), std::pair<int, int>(-22, 22),
      std::pair<int, int>(3, 32), std::pair<int, int>(11, 22),
      std::pair<int, int>(56, 3)};

  ASSERT_TRUE(my_map.contains(3));

  ASSERT_EQ(my_map.size(), 5);
  ASSERT_EQ(map.size(), 5);
}

TEST(Map_Test_merge, Test_1) {
  my::map<int, int> my_map{
      std::pair<int, int>(12, 4356), std::pair<int, int>(-22, 22),
      std::pair<int, int>(3, 32), std::pair<int, int>(11, 22),
      std::pair<int, int>(56, 3)};
  my::map<int, int> result;

  my_map.merge(result);
  my::map<int, int>::iterator my_it = my_map.begin();
  ASSERT_EQ((*my_it).first, -22);
  ASSERT_TRUE(my_map.contains(11));
  ASSERT_EQ(my_map.size(), 5);
  ASSERT_TRUE(result.empty());
}

TEST(Map_Test_clear, Test_1) {
  my::map<int, int> my_map{
      std::pair<int, int>(12, 4356), std::pair<int, int>(-22, 22),
      std::pair<int, int>(3, 32), std::pair<int, int>(11, 22),
      std::pair<int, int>(56, 3)};
  std::map<int, int> map{
      std::pair<int, int>(12, 4356), std::pair<int, int>(-22, 22),
      std::pair<int, int>(3, 32), std::pair<int, int>(11, 22),
      std::pair<int, int>(56, 3)};
  my_map.clear();
  map.clear();
  ASSERT_EQ(my_map.size(), map.size());
  ASSERT_EQ(my_map.size(), 0);
  ASSERT_EQ(map.size(), 0);
}

TEST(Map_Test_constr_copy, Test_1) {
  my::map<int, int> my_map{
      std::pair<int, int>(12, 4356), std::pair<int, int>(-22, 22),
      std::pair<int, int>(3, 32), std::pair<int, int>(11, 22),
      std::pair<int, int>(56, 3)};

  my::map<int, int> result(my_map);
  my::map<int, int>::iterator my_it = result.begin();
  ASSERT_EQ((*my_it).first, -22);
  ASSERT_EQ(result.size(), 5);
}

TEST(Map_Test_constr_move, Test_1) {
  my::map<int, int> my_map{
      std::pair<int, int>(12, 4356), std::pair<int, int>(-22, 22),
      std::pair<int, int>(3, 32), std::pair<int, int>(11, 22),
      std::pair<int, int>(56, 3)};

  my::map<int, int> result(std::move(my_map));
  my::map<int, int>::iterator my_it = result.begin();
  ASSERT_EQ((*my_it).first, -22);
  ASSERT_EQ(result.size(), 5);
}

TEST(Map_Test_constr_plus, Test_1) {
  my::map<int, int> my_map{
      std::pair<int, int>(12, 4356), std::pair<int, int>(-22, 22),
      std::pair<int, int>(3, 32), std::pair<int, int>(11, 22),
      std::pair<int, int>(56, 3)};
  std::map<int, int> map{
      std::pair<int, int>(12, 4356), std::pair<int, int>(-22, 22),
      std::pair<int, int>(3, 32), std::pair<int, int>(11, 22),
      std::pair<int, int>(56, 3)};
  my::map<int, int>::iterator my_it = my_map.begin();
  std::map<int, int>::iterator it = map.begin();
  ++it;
  ++my_it;
  ASSERT_EQ(*my_it, *it);
}

TEST(Map_Test_constr_minus, Test_1) {
  my::map<int, int> my_map{
      std::pair<int, int>(12, 4356), std::pair<int, int>(-22, 22),
      std::pair<int, int>(3, 32), std::pair<int, int>(11, 22),
      std::pair<int, int>(56, 3)};
  std::map<int, int> map{
      std::pair<int, int>(12, 4356), std::pair<int, int>(-22, 22),
      std::pair<int, int>(3, 32), std::pair<int, int>(11, 22),
      std::pair<int, int>(56, 3)};
  my::map<int, int>::iterator my_it = my_map.begin();
  std::map<int, int>::iterator it = map.begin();
  ++it;
  ++my_it;
  --it;
  --my_it;
  ASSERT_EQ(*my_it, *it);
}

TEST(Map_Test_no_equal, Test_1) {
  my::map<int, int> my_map{
      std::pair<int, int>(12, 4356), std::pair<int, int>(-22, 22),
      std::pair<int, int>(3, 32), std::pair<int, int>(11, 22),
      std::pair<int, int>(56, 3)};

  my::map<int, int>::iterator my_it = my_map.begin();
  auto my_it2 = my_it++;
  ++my_it;
  bool result = 0;
  if (*my_it != *my_it2) {
    result = 1;
  }
  ASSERT_TRUE(result);
}

TEST(Map_Test_equal, Test_1) {
  my::map<int, int> my_map{
      std::pair<int, int>(12, 4356), std::pair<int, int>(-22, 22),
      std::pair<int, int>(3, 32), std::pair<int, int>(11, 22),
      std::pair<int, int>(56, 3)};

  my::map<int, int>::iterator my_it = my_map.begin();
  auto my_it2 = ++my_it;
  bool result = 0;
  if (*my_it == *my_it2) {
    result = 1;
  }
  ASSERT_TRUE(result);
}

TEST(Map_Test_insert, Test_4) {
  my::map<int, int> my_map{
      std::pair<int, int>(1, 22), std::pair<int, int>(2, 23),
      std::pair<int, int>(3, 24), std::pair<int, int>(4, 25),
      std::pair<int, int>(5, 26)};
  int i = 1;
  int count = 22;
  my::map<int, int>::iterator it = my_map.begin();
  for (; it != my_map.end(); it++) {
    ASSERT_EQ((*it).first, i);
    ASSERT_EQ((*it).second, count);
    i++;
    count++;
  }
}

TEST(Map_Test_pair_insert_bool, Test_1) {
  my::map<int, int> my_map{
      std::pair<int, int>(1, 22), std::pair<int, int>(2, 23),
      std::pair<int, int>(3, 24), std::pair<int, int>(4, 25),
      std::pair<int, int>(5, 26)};
  auto [my_it, my_success] = my_map.insert(-12, 4);
  my::map<int, int>::iterator kk = my_map.begin();
  ASSERT_EQ((*my_it).first, -12);
  ASSERT_EQ((*my_it).second, 4);
  ASSERT_EQ(1, my_success);
  ASSERT_EQ((*kk).first, -12);
  ASSERT_EQ((*kk).second, 4);
}

TEST(Map_Test_pair_insert_bool, Test_2) {
  my::map<int, int> my_map{
      std::pair<int, int>(1, 22), std::pair<int, int>(2, 23),
      std::pair<int, int>(3, 24), std::pair<int, int>(4, 25),
      std::pair<int, int>(5, 26)};
  auto [my_it, my_success] = my_map.insert(1, 4);
  my::map<int, int>::iterator kk = my_map.begin();
  ASSERT_EQ((*my_it).first, 1);
  ASSERT_EQ((*my_it).second, 22);
  ASSERT_EQ(0, my_success);
  ASSERT_EQ((*kk).first, 1);
  ASSERT_EQ((*kk).second, 22);
}

TEST(Map_Test_pair_insert_or_assign, Test_1) {
  my::map<int, int> my_map{
      std::pair<int, int>(1, 22), std::pair<int, int>(2, 23),
      std::pair<int, int>(3, 24), std::pair<int, int>(4, 25),
      std::pair<int, int>(5, 26)};
  my::map<int, int> map{std::pair<int, int>(1, 22), std::pair<int, int>(2, 23),
                        std::pair<int, int>(3, 24), std::pair<int, int>(4, 25),
                        std::pair<int, int>(5, 26)};
  auto [my_it, my_success] = my_map.insert_or_assign(12, 4);
  auto [it, success] = map.insert_or_assign(12, 4);

  ASSERT_EQ((*my_it).first, (*it).first);
  ASSERT_EQ((*my_it).second, (*it).second);
  ASSERT_EQ(success, my_success);
}

TEST(Map_Test_pair_insert_or_assign, Test_2) {
  my::map<int, int> my_map{
      std::pair<int, int>(1, 22), std::pair<int, int>(2, 23),
      std::pair<int, int>(3, 24), std::pair<int, int>(4, 25),
      std::pair<int, int>(5, 26)};
  my::map<int, int> map{std::pair<int, int>(1, 22), std::pair<int, int>(2, 23),
                        std::pair<int, int>(3, 24), std::pair<int, int>(4, 25),
                        std::pair<int, int>(5, 26)};
  auto [my_it, my_success] = my_map.insert_or_assign(1, 22);
  auto [it, success] = map.insert_or_assign(1, 22);
  ASSERT_EQ((*my_it).first, (*it).first);
  ASSERT_EQ((*my_it).second, (*it).second);
  ASSERT_EQ(success, my_success);
}

TEST(Map_Test_pair_insert_or_assign, Test_3) {
  my::map<int, int> my_map{
      std::pair<int, int>(1, 22), std::pair<int, int>(2, 23),
      std::pair<int, int>(3, 24), std::pair<int, int>(4, 25),
      std::pair<int, int>(5, 26)};
  my::map<int, int> map{std::pair<int, int>(1, 22), std::pair<int, int>(2, 23),
                        std::pair<int, int>(3, 24), std::pair<int, int>(4, 25),
                        std::pair<int, int>(5, 26)};
  auto [my_it, my_success] = my_map.insert_or_assign(5, 66);
  auto [it, success] = map.insert_or_assign(5, 66);
  ASSERT_EQ((*my_it).first, (*it).first);
  ASSERT_EQ((*my_it).second, (*it).second);
  ASSERT_EQ(success, my_success);
}
