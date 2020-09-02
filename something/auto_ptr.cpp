#include <iostream>

template <typename T>
class auto_ptr {
 public:
  explicit auto_ptr(T* ptr = nullptr) noexcept : ptr_(ptr){};
  ~auto_ptr() noexcept { delete ptr_; };
  T* operator*() const noexcept { return *ptr_; }
  T& operator->() const noexcept { return ptr_; }
  operator bool() const noexcept { return ptr_; }

  T* get() const noexcept { return ptr_; }

  // 拷贝构造，other 释放所有权
  auto_ptr(auto_ptr& other) noexcept { ptr_ = other.release(); }

  // copy and swap
  auto_ptr& operator=(auto_ptr& rhs) noexcept {
    auto_ptr(rhs.release()).swap(*this);
    return *this;
  }

  T* release() noexcept {
    T* ptr = ptr_;
    ptr_ = nullptr;
    return ptr;
  }

  void swap(auto_ptr& rhs) {
    using std::swap;
    swap(ptr_, rhs.ptr_);
  }

 private:
  T* ptr_;
};
template <typename T>
void swap(auto_ptr<T>& lhs, auto_ptr<T>& rhs) noexcept {
  lhs.swap(rhs);
}

int main() {
  auto_ptr<int> ptr1{new int(10)};
  auto_ptr<int> ptr2{ptr1};
  if (ptr1.get() == nullptr && ptr2.get()) {
    std::cout << "拷贝构造：ptr1释放了所有权,ptr2获得了所有权" << std::endl;
  }
  ptr1 = ptr1;

  auto_ptr<int> ptr3{new int(1)};
  ptr1 = ptr3;
  if (ptr1.get() && ptr3.get() == nullptr) {
    std::cout << "赋值操作：始终只有一个对象管理一个区块!ptr3释放了所有权,"
                 "ptr1获得了所有权"
              << std::endl;
  }
}