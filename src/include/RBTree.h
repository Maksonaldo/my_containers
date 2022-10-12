#ifndef SRC_INCLUDE_RBTTREE_H_
#define SRC_INCLUDE_RBTTREE_H_

#include <iostream>
#include <limits>
#include <utility>

#include "RBTNode.h"

namespace my {

template <class T>
class RBTree {
 private:
  RBTNode<T> *root_ = nullptr;
  RBTNode<T> *null_ = nullptr;
  size_t size_ = 0;

 public:
  RBTree();
  explicit RBTree(std::initializer_list<T> const &list);
  RBTree(const RBTree &other);
  RBTree(RBTree &&other) noexcept;
  RBTree<T> &operator=(const RBTree<T> &other);
  RBTree<T> &operator=(RBTree<T> &&other);
  ~RBTree();

  class iterator;
  virtual iterator begin() const;
  virtual iterator end() const;

  virtual bool empty() const;
  virtual size_t size() const;
  virtual size_t max_size() const;

  void clear() noexcept;
  virtual void erase(const T &value);
  virtual void erase(iterator pos);
  virtual void merge(RBTree &other);
  void swap(RBTree &other);

  virtual iterator find(const T &value) const;
  virtual bool contains(const T &value);

  iterator insert(const T &value);

  size_t count(const T &key);
  iterator lower_bound(const T &key);
  iterator upper_bound(const T &key);
  std::pair<iterator, iterator> equal_range(const T &key);
  void print_tree();

  RBTNode<T> Find(const T &value) const;

 private:
  void insert(RBTNode<T> *node);
  void insert_fixup(RBTNode<T> *node);

  static RBTNode<T> *search_min(RBTNode<T> *node);
  static RBTNode<T> *search_max(RBTNode<T> *node);
  static RBTNode<T> *get_prev(RBTNode<T> *node);

  static RBTNode<T> *find(RBTNode<T> *node, const T &value);

  RBTNode<T> *erase(RBTNode<T> *&root, RBTNode<T> *node);
  void erase_fixup(RBTNode<T> *node);
  void transplant(RBTNode<T> *u, RBTNode<T> *v);

  RBTNode<T> *left_rotate(RBTNode<T> *node);
  static RBTNode<T> *get_left_child(RBTNode<T> *root);
  static RBTNode<T> *get_right_child(RBTNode<T> *root);
  RBTNode<T> *right_rotate(RBTNode<T> *node);

  static RBTNode<T> *get_next(RBTNode<T> *node);

  static RBTNode<T> *get_parent(RBTNode<T> *root);
  static RBTColor get_color(RBTNode<T> *root);

  static void set_color(RBTNode<T> *root, RBTColor color);
  static void set_parent(RBTNode<T> *root, RBTNode<T> *parant);
  static void set_left_child(RBTNode<T> *root, RBTNode<T> *child);
  static void set_right_child(RBTNode<T> *root, RBTNode<T> *child);

  RBTNode<T> *copy_node(RBTNode<T> *node);

  void print_node(RBTNode<T> *node);
  void search_max();
};

}  // namespace my

#include "RBTIterator.h"
#include "RBTree.inl"

#endif  // SRC_INCLUDE_RBTTREE_H_
