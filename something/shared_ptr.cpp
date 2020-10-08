class shared_count {
 public:
  shared_count() : count_(1) {}
  void add_count() { ++count_; }
  long reduce_count() { return --count_; }
  long get_count() { return count_; }

 private:
  long count_;
};

template <typename T>
class shared_ptr {
 public:
  shared_ptr(T* ptr = nullptr) noexcept : ptr_(ptr) {
    if (ptr) {
      shared_count_ = new shared_count();
    }
  }
  ~shared_ptr() noexcept {
    if (ptr_ && !shared_count_->reduce_count()) {
      delete ptr_;
      delete shared_count_;
    }
  }

  T& operator*() const noexcept { return *ptr_; }
  T* operator->() const noexcept { return ptr_; }
  operator bool() const noexcept { return ptr_; }

  T* get() const noexcept { return ptr_; }

  shared_ptr& operator=(shared_ptr rhs) noexcept {
    rhs.swap(*this);
    return *this;
  }

  // 带模板的拷贝与移动构造函数 模板的各个实例间并不天然就有 friend
  // 关系，因而不能互访私有成员 ptr_ 和 shared_count_。 需要下面显示声明
  template <typename U>
  friend class shared_ptr;

  template <typename U>
  shared_ptr(const shared_ptr<T>& other) noexcept {
    ptr_ = other.ptr_;
    if (ptr_) {
      other.shared_count_->add_count();
      shared_count_ = other.shared_count_;
    }
  }

  template <typename U>
  shared_ptr(shared_ptr<U>&& other) noexcept {
    ptr_ = other.ptr_;
    if (ptr_) {
      shared_count_ = other.shared_count_;
      other.ptr_ = nullptr;
    }
  }

  void swap(shared_ptr& rhs) noexcept {
    using std::swap;
    swap(ptr_, rhs.ptr_);
    swap(shared_count_, rhs.shared_count_);
  }

  long use_count() const noexcept {
    if (ptr_) {
      return shared_count_->get_count();
    }
    return 0;
  }

 private:
  T* ptr_;
  shared_count* shared_count_;
};