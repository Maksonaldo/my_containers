#ifndef SRC_INCLUDE_MAP_H_
#define SRC_INCLUDE_MAP_H_

#include "set.h"

namespace my {
template <class Key, class Value>
class map : public set<std::pair<const Key, Value>> {
 public:
  using key_type = Key;
  using mapped_type = Value;
  using value_type = std::pair<const key_type, mapped_type>;
  using reference = value_type &;
  using const_reference = const value_type &;
  using iterator = typename set<std::pair<const Key, Value>>::iterator;
  using size_type = size_t;

  map() : set<value_type>(){};
  explicit map(std::initializer_list<value_type> const &items)
      : set<value_type>(items){};
  explicit map(const map<key_type, mapped_type> &other)
      : set<value_type>(other) {}
  explicit map(map<key_type, mapped_type> &&other)
      : set<value_type>(std::move(other)) {}

  map<key_type, mapped_type> &operator=(const map &other) {
    set<value_type>::operator=(other);
    return *this;
  }
  map<key_type, mapped_type> &operator=(map<key_type, mapped_type> &&other) {
    set<value_type>::operator=(std::move(other));
    return *this;
  }

  mapped_type &operator[](const key_type &key) { return (at(key)); }
  mapped_type &at(const key_type key) {
    if (contains(key) == false) {
      throw std::invalid_argument("Error");
    }
    auto value = map::find(key);

    return (mapped_type &)value->second;
  }
  bool contains(const key_type &key) {
    bool result = true;
    auto value = find(key);
    if (value == map::end()) {
      result = false;
    }
    return result;
  }

  map<key_type, mapped_type>::iterator find(key_type key) {
    auto it = map::begin();
    for (; it != map::end(); ++it)
      if ((*it).first == key) break;
    return it;
  }

  std::pair<iterator, bool> insert_or_assign(value_type value) {
    iterator it;

    bool result = false;
    if (!map::contains(value.first)) {
      map::insert(value);
      result = true;
      it = find(value.first);
    } else {
      it = find(value.first);
      (mapped_type &)it->second = value.second;
    }
    return {it, result};
  }

  std::pair<iterator, bool> insert_or_assign(const Key &key, const Value &obj) {
    return insert_or_assign({key, obj});
  }
  std::pair<iterator, bool> insert(const value_type &value) {
    iterator it = map::end();
    bool result = false;
    if (!map::contains(value.first)) {
      RBTree<value_type>::insert(value);
      it = find(value.first);
      result = true;
    } else {
      it = find(value.first);
    }
    return {it, result};
  }
  std::pair<iterator, bool> insert(const Key &key, const Value &obj) {
    return insert({key, obj});
  }
  template <class... Args>
  std::pair<iterator, bool> emplace(Args &&...args) {
    return (map::insert_or_assign(args), ...);
  }
};

}  // namespace my

#endif  // SRC_INCLUDE_MAP_H_
