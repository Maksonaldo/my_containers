#include <gtest/gtest.h>

TEST(construct, case_1) {
  my::array<int, 5> custom;
  std::array<int, 5> current;
  EXPECT_EQ(custom.size(), current.size());
}

TEST(list_construct, case_1) {
  my::array<int, 6> custom{1, 2, 9, 0, 6, 54};
  std::array<int, 6> current{1, 2, 9, 0, 6, 54};

  EXPECT_EQ(custom.size(), current.size());

  auto it = custom.begin();
  auto it2 = current.begin();

  for (; it != custom.end(); it++, it2++) {
    EXPECT_EQ(*it, *it2);
  }
}

TEST(copy_construct, case_1) {
  my::array<int, 6> first{1, 9, 4, 89, 7, -3};
  std::array<int, 6> second{1, 9, 4, 89, 7, -3};

  my::array<int, 6> custom(first);
  std::array<int, 6> current(second);

  EXPECT_EQ(custom.size(), current.size());

  auto it = custom.begin();
  auto it2 = current.begin();

  for (; it != custom.end(); it++, it2++) {
    EXPECT_EQ(*it, *it2);
  }
}

TEST(move_construct, case_1) {
  my::array<int, 6> first{1, 2, 9, 0, 6, 54};
  std::array<int, 6> second{1, 2, 9, 0, 6, 54};

  my::array<int, 6> custom = std::move(first);
  std::array<int, 6> current = std::move(second);

  EXPECT_EQ(custom.size(), current.size());
  EXPECT_EQ(first.size(), second.size());

  auto it = custom.begin();
  auto it2 = current.begin();

  for (; it != custom.end(); it++, it2++) {
    EXPECT_EQ(*it, *it2);
  }

  auto elem1 = first.begin();
  auto elem2 = second.begin();

  for (; elem1 != first.end(); elem1++, elem2++) {
    EXPECT_EQ(*elem1, *elem2);
  }
}

TEST(assign_operator, case_1) {
  std::array<int, 5> current{9, 8, 7, 6, 5};
  my::array<int, 5> custom{9, 8, 7, 6, 5};

  std::array<int, 5> currentReceiver;
  my::array<int, 5> customReceiver;

  currentReceiver = current;
  customReceiver = custom;

  EXPECT_EQ(customReceiver.size(), custom.size());

  auto it = customReceiver.begin();
  auto it2 = currentReceiver.begin();

  for (; it != customReceiver.end(); it++, it2++) {
    EXPECT_EQ(*it, *it2);
  }
}

TEST(begin, case_1) {
  std::array<int, 5> current{9, 8, 7, 6, 5};
  my::array<int, 5> custom{9, 8, 7, 6, 5};

  auto itCustom = custom.begin();
  auto itCurrent = current.begin();

  EXPECT_EQ(*itCustom, *itCurrent);
}

TEST(begin, case_2) {
  std::array<int, 0> current;
  my::array<int, 0> custom;

  auto itCustom = custom.begin();
  auto endCustom = custom.end();
  auto itCurrent = current.begin();
  auto endCurrent = current.end();

  EXPECT_EQ(itCurrent, endCurrent);
  EXPECT_EQ(itCustom, endCustom);
}

TEST(end, case_1) {
  std::array<int, 5> current{9, 8, 7, 6, 5};
  my::array<int, 5> custom{9, 8, 7, 6, 5};

  EXPECT_NO_THROW(custom.end());
  EXPECT_NO_THROW(current.end());
}

TEST(at, case_1) {
  std::array<int, 5> current{9, 8, 7, 6, 5};
  my::array<int, 5> custom{9, 8, 7, 6, 5};

  EXPECT_EQ(current.at(4), custom.at(4));
}

TEST(at, case_2) {
  my::array<int, 5> custom{9, 8, 7, 6, 5};

  EXPECT_ANY_THROW(custom.at(6));
}

TEST(access_operator, case_1) {
  std::array<int, 5> current{9, 8, 7, 6, 5};
  my::array<int, 5> custom{9, 8, 7, 6, 5};

  for (size_t i = 0; i < current.size(); i++) {
    EXPECT_EQ(current[i], custom[i]);
  }
}

TEST(front, case_1) {
  std::array<int, 5> current{9, 8, 7, 6, 5};
  my::array<int, 5> custom{9, 8, 7, 6, 5};

  EXPECT_EQ(current.front(), custom.front());
}

TEST(back, case_1) {
  std::array<int, 5> current{9, 8, 7, 6, 5};
  my::array<int, 5> custom{9, 8, 7, 6, 5};

  EXPECT_EQ(current.back(), custom.back());
}

TEST(data, case_1) {
  std::array<int, 5> current{9, 8, 7, 6, 5};
  my::array<int, 5> custom{9, 8, 7, 6, 5};

  int* _pCurr = current.data();
  int* _pCust = custom.data();

  for (size_t i = 0; i < current.size(); i++) {
    EXPECT_EQ(_pCurr[i], _pCust[i]);
  }
}

TEST(fill, case_1) {
  std::array<int, 5> current{9, 8, 7, 6, 5};
  my::array<int, 5> custom{9, 8, 7, 6, 5};

  current.fill(359);
  custom.fill(359);

  int* _pCurr = current.data();
  int* _pCust = custom.data();

  for (size_t i = 0; i < current.size(); i++) {
    EXPECT_EQ(_pCurr[i], _pCust[i]);
  }
}

TEST(swap, case_1) {
  const int c_size = 5;
  std::array<int, c_size> _firstCurrent{1, 2, 3, 4, 5};
  std::array<int, c_size> _secondCurrent{98, 456, 54, 0, -89};

  my::array<int, c_size> _firstCustom{1, 2, 3, 4, 5};
  my::array<int, c_size> _secondCustom{98, 456, 54, 0, -89};

  _firstCurrent.swap(_secondCurrent);
  _firstCustom.swap(_secondCustom);

  for (size_t i = 0; i < c_size; i++) {
    EXPECT_EQ(_firstCurrent[i], _firstCustom[i]);
  }
}
