namespace my {

template <class T>
void RBTree<T>::set_parent(RBTNode<T> *root, RBTNode<T> *parent) {
  if (root) {
    root->set_parent(parent);
  }
}

template <class T>
RBTNode<T> *RBTree<T>::get_left_child(RBTNode<T> *root) {
  return root ? root->get_left_child() : nullptr;
}

template <class T>
RBTNode<T> *RBTree<T>::get_right_child(RBTNode<T> *root) {
  return root ? root->get_right_child() : nullptr;
}

template <class T>
void RBTree<T>::set_left_child(RBTNode<T> *root, RBTNode<T> *child) {
  if (root) {
    root->set_left_child(child);
    set_parent(get_left_child(root), root);
  }
}

template <class T>
void RBTree<T>::set_right_child(RBTNode<T> *root, RBTNode<T> *child) {
  if (root) {
    root->set_right_child(child);
    set_parent(get_right_child(root), root);
  }
}

template <class T>
void RBTree<T>::set_color(RBTNode<T> *root, RBTColor color) {
  if (root) {
    root->set_color(color);
  }
}

template <class T>
RBTColor RBTree<T>::get_color(RBTNode<T> *root) {
  return root ? root->get_color() : Black;
}

template <class T>
RBTree<T>::RBTree() {}

template <class T>
RBTree<T>::~RBTree() {
  clear();
}
template <class T>
RBTNode<T> *RBTree<T>::get_parent(RBTNode<T> *root) {
  return root ? root->get_parent() : nullptr;
}

template <class T>
RBTNode<T> *RBTree<T>::right_rotate(RBTNode<T> *node) {
  RBTNode<T> *child = get_left_child(node);
  set_left_child(node, get_right_child(child));
  if (get_right_child(child) != nullptr) {
    set_parent(get_right_child(child), node);
  }

  if (child != nullptr) {
    set_parent(child, get_parent(node));
  }

  if (get_parent(node) != nullptr) {
    if (node == get_right_child(get_parent(node))) {
      set_right_child(get_parent(node), child);
    } else {
      set_left_child(get_parent(node), child);
    }
  } else {
    root_ = child;
  }

  set_right_child(child, node);
  if (node != nullptr) {
    set_parent(node, child);
  }
  return root_;
}

template <class T>
RBTNode<T> *RBTree<T>::left_rotate(RBTNode<T> *node) {
  RBTNode<T> *child = get_right_child(node);

  set_right_child(node, get_left_child(child));

  if (get_left_child(child) != nullptr) {
    set_parent(get_left_child(child), node);
  }

  if (child != nullptr) {
    set_parent(child, get_parent(node));
  }

  if (get_parent(node) != nullptr) {
    if (node == get_left_child(get_parent(node))) {
      set_left_child(get_parent(node), child);
    } else {
      set_right_child(get_parent(node), child);
    }
  } else {
    root_ = child;
  }

  set_left_child(child, node);
  if (node != nullptr) {
    set_parent(node, child);
  }
  return root_;
}

template <class T>
void RBTree<T>::print_node(RBTNode<T> *node) {
  if (node == nullptr) return;
  if (get_parent(node) == NULL)
    std::cout << node->get_value() << "(" << get_color(node) << ") is root"
              << std::endl;
  else if (get_left_child(get_parent(node)) == node) {
    std::cout << node->get_value() << "(" << get_color(node) << ") is "
              << get_parent(node)->get_value() << "'s "
              << "left child" << std::endl;
  } else {
    std::cout << node->get_value() << "(" << get_color(node) << ") is "
              << get_parent(node)->get_value() << "'s "
              << "right child" << std::endl;
  }
  print_node(get_left_child(node));
  print_node(get_right_child(node));
}

template <class T>
void RBTree<T>::print_tree() {
  if (root_ == NULL)
    std::cout << "empty RBtree\n";
  else
    print_node(root_);
}

template <class T>
void RBTree<T>::clear() noexcept {
  delete root_;
  root_ = nullptr;
  size_ = 0;
}

template <class T>
typename RBTree<T>::iterator RBTree<T>::insert(const T &value) {
  RBTNode<T> *node = new RBTNode<T>(value, Red);
  insert(node);
  return {node, root_};
}

template <class T>
void RBTree<T>::swap(RBTree &other) {
  std::swap(root_, other.root_);
  std::swap(size_, other.size_);
}

template <class T>
void RBTree<T>::insert_fixup(RBTNode<T> *node) {
  RBTNode<T> *uncle;

  while ((node != root_) && (get_color(get_parent(node)) == Red)) {
    if (get_parent(node) == get_left_child(get_parent(get_parent(node)))) {
      uncle = get_right_child(get_parent(get_parent(node)));
      if (get_color(uncle) == Red) {
        set_color(get_parent(node), Black);
        set_color(uncle, Black);
        set_color(get_parent(get_parent(node)), Red);
        node = get_parent(get_parent(node));
      } else {
        if (node == get_right_child(get_parent(node))) {
          node = get_parent(node);
          left_rotate(node);
        }
        set_color(get_parent(node), Black);
        set_color(get_parent(get_parent(node)), Red);

        right_rotate(get_parent(get_parent(node)));
      }
    } else {
      uncle = get_left_child(get_parent(get_parent(node)));
      if (get_color(uncle) == Red) {
        set_color(get_parent(node), Black);
        set_color(uncle, Black);
        set_color(get_parent(get_parent(node)), Red);
        node = get_parent(get_parent(node));
      } else {
        if (node == get_left_child(get_parent(node))) {
          node = get_parent(node);
          ;

          right_rotate(node);
        }
        set_color(get_parent(node), Black);
        set_color(get_parent(get_parent(node)), Red);
        left_rotate(get_parent(get_parent(node)));
      }
    }
  }

  set_color(root_, Black);
}

template <class T>
void RBTree<T>::insert(RBTNode<T> *node) {
  RBTNode<T> *parent = nullptr, *current = root_;
  while (current != nullptr) {
    parent = current;
    if (node->get_value() < current->get_value()) {
      current = get_left_child(current);
    } else
      current = get_right_child(current);
  }

  if (parent != nullptr) {
    if (node->get_value() < parent->get_value())
      set_left_child(parent, node);
    else
      set_right_child(parent, node);
  } else {
    root_ = node;
  }
  size_++;
  insert_fixup(node);
}

template <class T>
typename RBTree<T>::iterator RBTree<T>::find(const T &value) const {
  iterator it(find(root_, value), root_);
  if (it.node_ == nullptr) {
    return end();
  }
  return it;
}
template <class T>
RBTNode<T> RBTree<T>::Find(const T &value) const {
  auto result = find(root_, value);

  return result;
}

template <class T>
RBTNode<T> *RBTree<T>::find(RBTNode<T> *node, const T &value) {
  if (node == nullptr) {
    return nullptr;
  } else if (node->get_value() == value) {
    return node;
  } else if (node->get_value() > value) {
    return find(get_left_child(node), value);
  } else {
    return find(get_right_child(node), value);
  }
}

template <class T>
void RBTree<T>::erase(const T &value) {
  RBTNode<T> *node;
  node = find(root_, value);
  if (node != nullptr) {
    if (size_ == 1) {
      clear();
    } else if (size_ > 1) {
      erase(root_, node);
    }
  }
}

template <class T>
void RBTree<T>::erase(typename RBTree<T>::iterator pos) {
  erase(pos);
}

template <class T>
void RBTree<T>::transplant(RBTNode<T> *node, RBTNode<T> *relative) {
  if ((get_parent(node)) == nullptr) {
    root_ = relative;
  } else if (node == get_left_child(get_parent(node))) {
    set_left_child(get_parent(node), relative);
  } else {
    set_right_child(get_parent(node), relative);
  }
  set_parent(relative, get_parent(node));
}
template <class T>
RBTNode<T> *RBTree<T>::get_next(RBTNode<T> *node) {
  RBTNode<T> *next = get_parent(node);
  if (get_right_child(node)) {
    next = search_min(get_right_child(node));
  } else {
    while (next && node == get_right_child(next)) {
      node = next;
      next = get_parent(next);
    }
  }
  return next;
}

template <class T>
RBTNode<T> *RBTree<T>::search_min(RBTNode<T> *node) {
  if (node == nullptr) {
    return nullptr;
  }
  RBTNode<T> *min = node;
  while (get_left_child(min) != nullptr) {
    min = get_left_child(min);
  }

  return min;
}

template <class T>
void RBTree<T>::search_max() {
  search_max(root_);
}

template <class T>
RBTNode<T> *RBTree<T>::search_max(RBTNode<T> *node) {
  if (node == nullptr) {
    return nullptr;
  }
  RBTNode<T> *max = node;
  while (get_right_child(max) != nullptr) {
    max = get_right_child(max);
  }
  return max;
}

template <class T>
RBTNode<T> *RBTree<T>::get_prev(RBTNode<T> *node) {
  RBTNode<T> *prev = get_parent(node);
  ;

  if (get_left_child(node) != nullptr) {
    prev = search_max(get_left_child(node));
  } else {
    while (prev && node == get_left_child(prev)) {
      node = prev;
      prev = get_parent(prev);
    }
  }
  return prev;
}

template <class T>
void RBTree<T>::erase_fixup(RBTNode<T> *node) {
  RBTNode<T> *child;
  while ((node != root_) && (get_color(node) == Black)) {
    if (node == get_left_child(get_parent(node))) {
      child = get_right_child(get_parent(node));
      if (get_color(child) == Red) {
        set_color(child, Black);
        root_ = left_rotate(get_parent(node));
        child = get_right_child(get_parent(node));
      }
      if ((get_color(get_right_child(child)) == Black) &&
          (get_color(get_left_child(child)) == Black)) {
        set_color(child, Red);
        node = get_parent(node);
      } else {
        if (get_color(get_right_child(child)) == Black) {
          set_color(get_left_child(child), Black);
          set_color(child, Red);
          root_ = right_rotate(child);
          child = get_right_child(get_parent(node));
        }
        set_color(child, get_color(get_parent(node)));
        set_color(get_parent(node), Black);
        set_color(get_right_child(node), Black);
        root_ = left_rotate(get_parent(node));
        node = root_;
      }
    } else {
      child = get_left_child(get_parent(node));
      if (get_color(child) == Red) {
        set_color(child, Black);
        set_color(get_parent(node), Red);
        root_ = right_rotate(get_parent(node));
        child = get_left_child(get_parent(node));
      }
      if ((get_color(get_right_child(child)) == Black) &&
          (get_color(get_left_child(child)) == Black)) {
        set_color(child, Red);
        node = get_parent(node);
      } else {
        if (get_color(get_left_child(child)) == Black) {
          set_color(get_right_child(child), Black);
          set_color(child, Red);
          root_ = left_rotate(child);
          child = get_left_child(get_parent(node));
        }
        set_color(child, get_color(get_parent(node)));
        set_color(get_parent(node), Black);
        set_color(get_left_child(child), Black);
        root_ = right_rotate(get_parent(node));
        node = root_;
      }
    }
  }
  set_color(node, Black);
}

template <class T>
RBTNode<T> *RBTree<T>::erase(RBTNode<T> *&root, RBTNode<T> *node) {
  RBTNode<T> *y, *x;
  size_--;
  y = node;
  RBTColor y_color = get_color(y);

  if (get_left_child(node) == nullptr) {
    x = get_right_child(node);
    transplant(node, x);
    delete node;
  } else if (get_right_child(node) == nullptr) {
    x = get_left_child(node);
    transplant(node, x);
  } else {
    y = search_min(get_right_child(node));
    y_color = get_color(y);
    x = get_right_child(y);
    if (get_parent(y) == node) {
      set_parent(x, y);
    } else {
      transplant(y, x);
      set_right_child(y, get_right_child(node));
      set_parent(get_right_child(y), y);
    }
    root = y;
    set_left_child(y, get_left_child(node));
    set_parent(get_left_child(y), y);
    set_color(y, get_color(node));
  }
  if (y_color == Black) {
    erase_fixup(x);
  }
  return root;
}

template <class T>
typename RBTree<T>::iterator RBTree<T>::begin() const {
  iterator it(search_min(root_), root_);

  return it;
}

template <class T>
typename RBTree<T>::iterator RBTree<T>::end() const {
  iterator it(nullptr, root_);

  return it;
}

template <class T>
RBTNode<T> *RBTree<T>::copy_node(RBTNode<T> *node) {
  RBTNode<T> *result = nullptr;
  if (node) {
    result = new RBTNode<T>(*node);
    set_left_child(result, copy_node(get_left_child(node)));
    set_right_child(result, copy_node(get_right_child(node)));
  }
  return result;
}

template <class T>
RBTree<T>::RBTree(const RBTree &other) {
  if (other.size_ > 0) {
    size_ = other.size_;
    root_ = copy_node(other.root_);
  } else if (other.size_ == 0) {
    clear();
  }
}

template <class T>
RBTree<T> &RBTree<T>::operator=(const RBTree<T> &other) {
  if (other.size_ > 0) {
    size_ = other.size_;
    root_ = copy_node(other.root_);
  } else if (other.size_ == 0) {
    clear();
  }
  return *this;
}

template <class T>
RBTree<T>::RBTree(RBTree &&other) noexcept {
  if (other.size_ > 0) {
    swap(other);
  } else if (other.size_ == 0) {
    clear();
  }
}

template <class T>
RBTree<T> &RBTree<T>::operator=(RBTree<T> &&other) {
  if (other.size_ > 0) {
    swap(other);
  } else if (other.size_ == 0) {
    clear();
  }
  return *this;
}

template <class T>
bool RBTree<T>::empty() const {
  bool result = false;
  if (size_ == 0) {
    result = true;
  }
  return result;
}

template <class T>
size_t RBTree<T>::size() const {
  return size_;
}

template <class T>
size_t RBTree<T>::max_size() const {
  return std::numeric_limits<size_t>::max() / sizeof(RBTree<T>);
}

template <class T>
RBTree<T>::RBTree(std::initializer_list<T> const &list) {
  for (const auto element : list) {
    insert(element);
  }
}

template <class T>
void RBTree<T>::merge(RBTree &other) {
  for (auto it = other.begin(); it != other.end(); ++it) {
    insert(*it);
  }
  other.clear();
}

template <class T>
bool RBTree<T>::contains(const T &value) {
  bool result = true;
  iterator it(find(root_, value), root_);
  if (it == end()) {
    result = false;
  }
  return result;
}

template <class T>
size_t RBTree<T>::count(const T &key) {
  size_t count = 0;
  auto it = begin();
  for (; it != end(); ++it) {
    if (*it == key) {
      count++;
    }
  }
  return count;
}

template <class T>
typename RBTree<T>::iterator RBTree<T>::lower_bound(const T &key) {
  auto it = begin();
  bool count = 0;
  for (; it != end(); ++it) {
    if (*it == key) {
      count = 1;
      break;
    }
  }
  if (count == 0) {
    it = upper_bound(key);
  }

  return it;
}

template <class T>
typename RBTree<T>::iterator RBTree<T>::upper_bound(const T &key) {
  auto it = begin();
  for (; it != end(); ++it) {
    if (*it > key) {
      break;
    }
  }
  if (it == end()) {
    throw std::invalid_argument("the next is NULL");
  }
  return it;
}

template <class T>
std::pair<typename RBTree<T>::iterator, typename RBTree<T>::iterator>
RBTree<T>::equal_range(const T &key) {
  return {lower_bound(key), upper_bound(key)};
}

}  // namespace my
