#ifndef SRC_INCLUDE_MULTISET_H_
#define SRC_INCLUDE_MULTISET_H_

namespace my {

template <class T>
class multiset : public RBTree<T> {
  friend class iterator;

 public:
  using key_type = T;
  using value_type = key_type;
  using reference = value_type &;
  using const_reference = const value_type &;
  using iterator = typename RBTree<T>::iterator;
  using size_type = size_t;

  multiset() : RBTree<value_type>(){};
  explicit multiset<value_type>(std::initializer_list<value_type> const &items)
      : RBTree<value_type>(items){};
  explicit multiset<value_type>(const multiset<value_type> &other)
      : RBTree<value_type>(other){};
  explicit multiset<value_type>(multiset<value_type> &&other)
      : RBTree<value_type>(std::move(other)){};
  ~multiset() = default;

  multiset<value_type> &operator=(multiset<value_type> &other) {
    RBTree<value_type>::operator=(other);
    return *this;
  }
  multiset<value_type> &operator=(multiset<value_type> &&other) {
    RBTree<value_type>::operator=(std::move(other));
    return *this;
  }
  template <class... Args>
  iterator emplace(Args &&...args) {
    return (RBTree<T>::insert(args), ...);
  }
};

}  // namespace my

#endif  // SRC_INCLUDE_MULTISET_H_
