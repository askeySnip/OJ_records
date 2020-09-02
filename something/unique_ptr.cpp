#include <iostream>

template <typename T>
class unique_ptr {
 public:
  unique_ptr(T* ptr) noexcept : ptr_(ptr){};
  ~unique_ptr() noexcept { delete ptr_; };

  T& operator*() const noexcept { return *ptr_; }
  T* operator->() const noexcept { return ptr_; }
  operator bool() const noexcept { return ptr_; }

  T* get() const noexcept { return ptr_; }

  // allow derived class to base class
  template <typename U>
  unique_ptr(unique_ptr<U>&& rhs) noexcept {
    ptr_ = rhs.release();
  }

  unique_ptr(unique_ptr&& rhs) noexcept { ptr_ = rhs.release(); }

  unique_ptr& operator=(unique_ptr rhs) noexcept {
    rhs.swap(*this);
    return *this;
  }

  T* release() {
    T* ptr = ptr_;
    ptr_ = nullptr;
    return ptr;
  }
  void swap(unique_ptr& rhs) noexcept {
    using std::swap;
    swap(ptr_, rhs.ptr_);
  }

 private:
  T* ptr_;
};

template <typename T>
void swap(unique_ptr<T>& lhs, unique_ptr<T>& rhs) {
  lhs.swap(rhs);
}

int main() {
  unique_ptr<int> ptr1{new int(10)};
  // error: call to implicitly-deleted copy constructor of 'unique_ptr<int>'
  // note: copy constructor is implicitly deleted because 'unique_ptr<int>' has
  // a user - declared move constructor
  // unique_ptr<int> ptr2{ptr1};
  unique_ptr<int> ptr2{std::move(ptr1)};

  unique_ptr<int> ptr3{new int(5)};
  // error: call to implicitly-deleted copy constructor of 'unique_ptr<int>'
  // note: copy constructor is implicitly deleted because 'unique_ptr<int>' has
  // a user-declared move constructor
  // ptr1 = ptr3;

  ptr3 = std::move(ptr1);
}
