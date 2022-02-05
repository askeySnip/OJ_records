#include <atomic>
#include <chrono>
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <queue>
#include <thread>

using namespace std;

void producer_consumer() {
  queue<int> produced_nums;
  mutex mtx;
  condition_variable cv;
  bool notified = false;

  auto producer = [&]() {
    for (int i = 0;; i++) {
      this_thread::sleep_for(chrono::milliseconds(900));
      unique_lock<mutex> lock(mtx);
      cout << "producing " << i << endl;
      produced_nums.push(i);
      notified = true;
      cv.notify_all();
    }
  };

  auto consumer = [&]() {
    while (true) {
      unique_lock<mutex> lock(mtx);
      while (!notified) cv.wait(lock);
      lock.unlock();
      this_thread::sleep_for(chrono::milliseconds(1000));
      lock.lock();
      while (!produced_nums.empty()) {
        cout << "consuming " << produced_nums.front() << endl;
        produced_nums.pop();
      }
      notified = false;
    }
  };

  thread p(producer);
  thread cs[2];
  for (int i = 0; i < 2; i++) cs[i] = thread(consumer);
  p.join();
  for (int i = 0; i < 2; i++) {
    cs[i].join();
  }
}

void reference(int& v) { cout << "left" << endl; }

void reference(int&& v) { cout << "right" << endl; }

template <typename T>
void pass(T&& v) {
  cout << "normal parameter pass" << endl;
  reference(v);
}

class ThreadPool {
  using Task = function<void()>;

 public:
  ThreadPool(int n) : _thread_num(n), _is_running(false) {}
  ThreadPool() {
    if (_is_running) stop();
  }
  ThreadPool& operator=(const ThreadPool& other) = delete;
  ThreadPool(const ThreadPool&) = delete;

  void start() {
    _is_running = true;
    for (int i = 0; i < _thread_num; i++)
      _threads.push_back(thread(&ThreadPool::work, this));
  }

  void stop() {
    {
      unique_lock<mutex> lk(_mtx);
      _is_running = false;
      _cond.notify_all();
    }
    for (thread& t : _threads) {
      if (t.joinable()) {
        t.join();
      }
    }
  }

  void appendTask(const Task task) {
    if (_is_running) {
      unique_lock<mutex> lk(_mtx);
      _tasks.push(task);
      _cond.notify_one();
    }
  }

 private:
  void work() {
    printf("begin work. Thread: %d\n", this_thread::get_id());

    while (_is_running) {
      Task task;
      {
        unique_lock<mutex> lk(_mtx);
        if (!_tasks.empty()) {
          task = _tasks.front();
          _tasks.pop();
        } else if (_is_running) {
          _cond.wait(lk);
        }
      }
      if (task) task();
    }

    printf("end work. Thread: %d\n", this_thread::get_id());
  }

  int _thread_num;
  atomic_bool _is_running;
  mutex _mtx;
  condition_variable _cond;
  vector<thread> _threads;
  queue<Task> _tasks;
};
void fun1() {
  std::cout << "working in thread " << std::this_thread::get_id() << std::endl;
}

void fun2(int x) {
  std::cout << "task " << x << " working in thread "
            << std::this_thread::get_id() << std::endl;
}

int main() {
  //   producer_consumer();
  // cout << "pass right value" << endl;
  // pass(1);
  // cout << "pass left value" << endl;
  // int l = 1;
  // pass(l);
  // ThreadPool thread_pool(3);
  // thread_pool.start();
  // this_thread::sleep_for(chrono::milliseconds(500));
  // for (int i = 0; i < 6; i++) {
  //   thread_pool.appendTask(bind(fun2, i));
  //   this_thread::sleep_for(chrono::milliseconds(500));
  // }
  // thread_pool.stop();

  return 0;
}