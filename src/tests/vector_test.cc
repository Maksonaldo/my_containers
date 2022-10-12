#include <gtest/gtest.h>

TEST(test_vector_constructor, default_constructor) {
  my::vector<int> vec;
  std::vector<int> stdVec;

  EXPECT_EQ(vec.size(), stdVec.size());
  EXPECT_EQ(vec.empty(), stdVec.empty());
}

TEST(test_vector_constructor, pametrized_constructor) {
  my::vector<int> vec(500);
  std::vector<int> stdVec(500);

  EXPECT_EQ(vec.size(), stdVec.size());
  EXPECT_EQ(vec.empty(), stdVec.empty());
}

TEST(test_vector_constructor, initializer_list_constructor) {
  my::vector<int> vec({359, 50, 3000, 1});
  std::vector<int> stdVec({359, 50, 3000, 1});

  compare_vector_data(vec, stdVec);

  EXPECT_EQ(vec.size(), stdVec.size());
  EXPECT_EQ(vec.empty(), stdVec.empty());
}

TEST(test_vector_constructor, copy_constructor) {
  my::vector<int> vec1({359, 50, 3000, 1});
  my::vector<int> vec(vec1);
  std::vector<int> stdVec1({359, 50, 3000, 1});
  std::vector<int> stdVec(stdVec1);

  compare_vector_data(vec, stdVec);

  EXPECT_EQ(vec.size(), stdVec.size());
  EXPECT_EQ(vec.empty(), stdVec.empty());
}

TEST(test_vector_constructor, move_constructor) {
  my::vector<int> vec1({359, 50, 3000, 1});
  my::vector<int> vec(std::move(vec1));
  std::vector<int> stdVec1({359, 50, 3000, 1});
  std::vector<int> stdVec(std::move(stdVec1));

  compare_vector_data(vec, stdVec);

  EXPECT_EQ(vec.size(), stdVec.size());
  EXPECT_EQ(vec.empty(), stdVec.empty());
}

TEST(test_vector_operator, eq_operator) {
  my::vector<int> vec1({359, 50, 3000, 1});
  my::vector<int> vec;
  std::vector<int> stdVec1({359, 50, 3000, 1});
  std::vector<int> stdVec;

  vec = vec1;
  stdVec = stdVec1;

  compare_vector_data(vec, stdVec);

  EXPECT_EQ(vec.size(), stdVec.size());
  EXPECT_EQ(vec.empty(), stdVec.empty());
}

TEST(test_vector_methods, element_access) {
  my::vector<int> vec({359, 50, 3000, 1});
  std::vector<int> stdVec({359, 50, 3000, 1});
  int* p_vec = vec.data();
  int* p_stdVec = stdVec.data();

  for (size_t i = 0; i < vec.size(); ++i) {
    EXPECT_EQ(vec.at(i), stdVec.at(i));
    EXPECT_EQ(vec[i], stdVec[i]);
    EXPECT_EQ(p_vec[i], p_stdVec[i]);
  }
  EXPECT_EQ(vec.front(), stdVec.front());
  EXPECT_EQ(vec.back(), stdVec.back());

  EXPECT_ANY_THROW(vec.at(1003));

  EXPECT_EQ(vec.size(), stdVec.size());
  EXPECT_EQ(vec.empty(), stdVec.empty());
}

TEST(test_vector_methods, modifiers_capacity) {
  my::vector<int> vec({359, 50, 3000, 1});
  std::vector<int> stdVec({359, 50, 3000, 1});
  my::vector<int> vec1;
  std::vector<int> stdVec1;

  vec.reserve(7000);
  stdVec.reserve(7000);
  vec1.reserve(7000);
  stdVec1.reserve(7000);

  EXPECT_EQ(vec.empty(), stdVec.empty());
  EXPECT_EQ(vec.size(), stdVec.size());
  EXPECT_EQ(vec.max_size(), stdVec.max_size());
  EXPECT_EQ(vec.capacity(), stdVec.capacity());

  EXPECT_EQ(vec1.empty(), stdVec1.empty());
  EXPECT_EQ(vec1.size(), stdVec1.size());
  EXPECT_EQ(vec1.max_size(), stdVec1.max_size());
  EXPECT_EQ(vec1.capacity(), stdVec1.capacity());

  vec.reserve(1);
  stdVec.reserve(1);
  vec1.reserve(1);
  stdVec1.reserve(1);

  EXPECT_EQ(vec.empty(), stdVec.empty());
  EXPECT_EQ(vec.size(), stdVec.size());
  EXPECT_EQ(vec.max_size(), stdVec.max_size());
  EXPECT_EQ(vec.capacity(), stdVec.capacity());

  EXPECT_EQ(vec1.empty(), stdVec1.empty());
  EXPECT_EQ(vec1.size(), stdVec1.size());
  EXPECT_EQ(vec1.max_size(), stdVec1.max_size());
  EXPECT_EQ(vec1.capacity(), stdVec1.capacity());

  vec.shrink_to_fit();
  stdVec.shrink_to_fit();
  vec1.shrink_to_fit();
  stdVec1.shrink_to_fit();

  EXPECT_EQ(vec.empty(), stdVec.empty());
  EXPECT_EQ(vec.size(), stdVec.size());
  EXPECT_EQ(vec.max_size(), stdVec.max_size());
  EXPECT_EQ(vec.capacity(), stdVec.capacity());

  EXPECT_EQ(vec1.empty(), stdVec1.empty());
  EXPECT_EQ(vec1.size(), stdVec1.size());
  EXPECT_EQ(vec1.max_size(), stdVec1.max_size());
  EXPECT_EQ(vec1.capacity(), stdVec1.capacity());
}

TEST(test_vector_methods, modifiers_clear) {
  my::vector<int> vec({359, 50, 3000, 1});
  std::vector<int> stdVec({359, 50, 3000, 1});

  compare_vector_data(vec, stdVec);

  vec.clear();
  stdVec.clear();

  compare_vector_data(vec, stdVec);
}

TEST(test_vector_methods, modifiers_insert) {
  my::vector<int> vec({359, 50, 3000, 1});
  std::vector<int> stdVec({359, 50, 3000, 1});

  auto iter = vec.begin();
  auto jter = stdVec.begin();

  vec.insert(iter, 444);
  stdVec.insert(jter, 444);

  compare_vector_data(vec, stdVec);
}

TEST(test_vector_methods, modifiers_erase) {
  my::vector<int> vec({359, 50, 3000, 1});
  std::vector<int> stdVec({359, 50, 3000, 1});

  auto iter = vec.begin();
  auto jter = stdVec.begin();

  vec.erase(iter);
  stdVec.erase(jter);

  compare_vector_data(vec, stdVec);
}

TEST(test_vector_methods, modifiers_push_back) {
  my::vector<int> vec({359, 50, 3000, 1});
  std::vector<int> stdVec({359, 50, 3000, 1});

  vec.push_back(66);
  stdVec.push_back(66);

  compare_vector_data(vec, stdVec);
}

TEST(test_vector_methods, modifiers_pop_front) {
  my::vector<int> vec({359, 50, 3000, 1});
  std::vector<int> stdVec({359, 50, 3000, 1});

  vec.pop_back();
  stdVec.pop_back();

  compare_vector_data(vec, stdVec);
}

TEST(test_vector_methods, modifiers_swap) {
  my::vector<int> vec({359, 50, 3000, 1});
  std::vector<int> stdVec({359, 50, 3000, 1});
  my::vector<int> vec1({22, 55});
  std::vector<int> stdVec1({22, 55});

  vec.swap(vec1);
  stdVec.swap(stdVec1);

  compare_vector_data(vec, stdVec);
  compare_vector_data(vec1, stdVec1);
}

TEST(test_vec_methods, modifiers_emplaces) {
  my::vector<int> vec({3000});
  std::vector<int> stdVec({3000});

  vec.reserve(10);
  stdVec.reserve(10);
  auto iter = vec.begin();
  auto jter = stdVec.begin();

  vec.emplace(iter, 33);
  stdVec.emplace(jter, 33);

  vec.emplace_back(359);
  stdVec.emplace_back(359);

  vec.emplace_front(1703);
  stdVec.insert(jter, 1703);

  compare_vector_data(vec, stdVec);
  EXPECT_EQ(vec.size(), stdVec.size());
}
