#ifndef SRC_INCLUDE_RBTITERATOR_H_
#define SRC_INCLUDE_RBTITERATOR_H_

namespace my {

template <class T>
class RBTree<T>::iterator {
  friend class RBTree;

 private:
  RBTNode<T> *node_ = nullptr;
  RBTNode<T> *root_ = nullptr;
  bool is_end_ = false;

 public:
  iterator(bool is_end, RBTNode<T> *root) : root_(root), is_end_(is_end) {}
  iterator(RBTNode<T> *node, RBTNode<T> *root)
      : node_(node), root_(root), is_end_(false) {}

  iterator() = default;
  iterator(const iterator &other) = default;
  iterator operator++(int) {
    iterator result(node_, root_);
    ++(*this);
    return result;
  }
  iterator operator--(int) {
    iterator result(node_, root_);
    operator--();
    return result;
  }
  iterator operator++() {
    auto next = get_next(node_);
    node_ = get_next(node_);
    if (next == nullptr) {
      is_end_ = true;
    }
    return *this;
  }
  iterator operator--() {
    if (is_end_) {
      node_ = search_max(root_);
      is_end_ = false;
    } else {
      node_ = get_prev(node_);
    }
    return *this;
  }
  bool operator!=(const iterator &other) const { return !(other == *this); }
  bool operator==(const iterator &other) const { return node_ == other.node_; }
  iterator &operator=(T &other) { return *this; }
  const T &operator*() const { return node_->get_value(); }
  const T *operator->() const { return &this->operator*(); }
};

}  // namespace my

#endif  // SRC_INCLUDE_RBTITERATOR_H_
