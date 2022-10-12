#ifndef SRC_INCLUDE_ARRAY_H_
#define SRC_INCLUDE_ARRAY_H_

#include <algorithm>
#include <iostream>
#include <utility>

namespace my {
template <class T, std::size_t size_>
struct array {
  using value_type = T;
  using reference = T &;
  using const_reference = const reference;
  using iterator = T *;
  using const_iterator = const iterator;
  using size_type = size_t;

  array();
  explicit array(std::initializer_list<value_type> const &items);
  array(array const &a);
  array(array &&a);
  ~array();

  array &operator=(const array &a);

  reference at(size_type pos);
  reference operator[](size_type pos);
  const_reference front();
  const_reference back();
  iterator data() noexcept;

  iterator begin() noexcept;
  iterator end() noexcept;

  bool empty();
  size_type size();
  size_type max_size();

  void swap(array &other);
  void fill(value_type value);

 private:
  T head_[size_ + 1];

  void copy(const array &other) {
    for (size_t i = 0; i < size_; i++) {
      head_[i] = other.head_[i];
    }
  }
};

template <typename T, size_t size_>
array<T, size_>::array() {
  for (size_t i = 0; i < size_ + 1; i++) head_[i] = 0;
}

template <typename T, size_t size_>
array<T, size_>::array(std::initializer_list<value_type> const &items) {
  std::copy_n(items.begin(), size(), begin());
}

template <typename T, std::size_t size_>
array<T, size_>::array(array const &a) {
  copy(a);
}

template <typename T, size_t size_>
array<T, size_>::array(array &&a) {
  copy(a);
}

template <typename T, size_t size_>
array<T, size_>::~array() {}

template <typename T, size_t size_>
array<T, size_> &array<T, size_>::operator=(const array &a) {
  copy(a);
  return *this;
}

template <typename T, size_t size_>
typename array<T, size_>::reference array<T, size_>::at(size_type pos) {
  if (pos >= size()) {
    throw std::out_of_range("array<T, size_>::at: pos >= size");
  }
  return head_[pos];
}

template <typename T, size_t size_>
typename array<T, size_>::reference array<T, size_>::operator[](size_type pos) {
  return head_[pos];
}

template <typename T, size_t size_>
typename array<T, size_>::const_reference array<T, size_>::front() {
  return head_[0];
}

template <typename T, size_t size_>
typename array<T, size_>::const_reference array<T, size_>::back() {
  return head_[size_ - 1];
}

template <typename T, size_t size_>
T *array<T, size_>::data() noexcept {
  return head_;
}

template <typename T, size_t size_>
typename array<T, size_>::iterator array<T, size_>::begin() noexcept {
  return iterator(data());
}

template <typename T, size_t size_>
typename array<T, size_>::iterator array<T, size_>::end() noexcept {
  return iterator(data() + size());
}

template <typename T, size_t size_>
bool array<T, size_>::empty() {
  return size() == 0;
}

template <typename T, size_t size_>
typename array<T, size_>::size_type array<T, size_>::size() {
  return size_;
}

template <typename T, size_t size_>
size_t array<T, size_>::max_size() {
  return std::allocator<my::array<T, size_>::value_type>().max_size();
}

template <typename T, std::size_t size_>
void array<T, size_>::swap(array &other) {
  std::swap_ranges(begin(), end(), other.begin());
}

template <typename T, std::size_t size_>
void array<T, size_>::fill(value_type value) {
  std::fill_n(begin(), size(), value);
}

}  // namespace my

#endif  //  SRC_INCLUDE_ARRAY_H_
