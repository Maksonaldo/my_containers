#ifndef SRC_INCLUDE_SET_H_
#define SRC_INCLUDE_SET_H_

#include "RBTree.h"

namespace my {

template <class T>
class set : public RBTree<T> {
  friend class iterator;

 public:
  using key_type = T;
  using value_type = key_type;
  using reference = value_type &;
  using const_reference = const value_type &;
  using iterator = typename RBTree<T>::iterator;
  using size_type = size_t;

  set() : RBTree<value_type>() {}
  explicit set(std::initializer_list<value_type> const &items)
      : RBTree<value_type>(items){};
  explicit set(const set<value_type> &other) : RBTree<value_type>(other){};
  explicit set(set<value_type> &&other)
      : RBTree<value_type>(std::move(other)){};
  ~set() = default;

  std::pair<iterator, bool> insert(const value_type &value) {
    iterator it;
    bool result = false;
    if (!RBTree<T>::contains(value)) {
      it = RBTree<T>::insert(value);
      result = true;
    } else {
      it = RBTree<T>::find(value);
    }
    return {it, result};
  }

  set<value_type> &operator=(const set<value_type> &other) {
    RBTree<value_type>::operator=(other);
    return *this;
  }
  set<value_type> &operator=(set<value_type> &&other) noexcept {
    RBTree<value_type>::operator=(std::move(other));
    return *this;
  }
  template <class... Args>
  std::pair<iterator, bool> emplace(Args &&...args) {
    return (insert(args), ...);
  }

 private:
};

}  // namespace my

#endif  // SRC_INCLUDE_SET_H_
