#ifndef SRC_INCLUDE_RBTNODE_H_
#define SRC_INCLUDE_RBTNODE_H_

namespace my {

enum RBTColor { Black, Red };

template <class T>
struct RBTNode {
 public:
  RBTNode<T>(const T &value, RBTColor color)
      : value_(value),
        parent_(nullptr),
        left_(nullptr),
        right_(nullptr),
        color_(color) {}
  RBTNode<T>(const RBTNode<T> &other)
      : value_(other.value_),
        parent_(nullptr),
        left_(nullptr),
        right_(nullptr),
        color_(other.color_) {}

  RBTNode<T> *get_parent() const { return parent_; }
  void set_parent(RBTNode<T> *parent) { parent_ = parent; }
  RBTNode<T> *get_left_child() const { return left_; }
  void set_left_child(RBTNode<T> *left) { left_ = left; }
  RBTNode<T> *get_right_child() const { return right_; }
  void set_right_child(RBTNode<T> *right) { right_ = right; }
  RBTColor get_color() const { return color_; }
  void set_color(RBTColor color) { color_ = color; }
  const T &get_value() const { return value_; }

  ~RBTNode<T>() {
    delete right_;
    delete left_;
  }

 private:
  T value_;
  RBTNode *left_;
  RBTNode *right_;
  RBTNode *parent_;
  RBTColor color_;
};

}  // namespace my

#endif  // SRC_INCLUDE_RBTNODE_H_
