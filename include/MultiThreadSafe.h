#ifndef _MULTI_THREAD_SAFE_H_
#define _MULTI_THREAD_SAFE_H_
#include <chrono>
#include <condition_variable>
#include <functional>
#include <iostream>
#include <memory>
#include <mutex>
#include <queue>
#include <thread>
#include <vector>
namespace Concurrency {

template <typename T>
class ThreadSafe final {  // can't be inherited
 public:
  void CreateMultiQueueVec(const int &element_num) {
    std::cout << "Concurrency::ThreadSafe::CreateMultiQueueVec() start" << std::endl;
    this->data_queue_vec.clear();
    this->data_queue_vec.shrink_to_fit();
    this->mutex_for_data_vec.clear();
    this->mutex_for_data_vec.shrink_to_fit();
    int i = 0;
    while (i++ < element_num) {
      this->data_queue_vec.emplace_back(std::queue<shared_ptr<T>>());
      this->mutex_for_data_vec.emplace_back(std::make_unique<std::mutex>());
    }
    std::cout << "Concurrency::ThreadSafe::CreateMultiQueueVec() end" << std::endl;
  }

  bool IsEmpty(const int &index) const {
    // check index && vector
    if (this->data_queue_vec.size() < 1) {
      std::cout << "[IsEmpty] data_queue_vec is empty." << std::endl;
      return true;
    } else if (index >= this->data_queue_vec || index < 0) {
      std::cout << "[IsEmpty] data_queue_vec[" << index << "] out of range." << std::endl;
      return true;
    }
    std::lock_guard<std::mutex> lock(*(this->mutex_for_data_vec[index]));
    return this->data_queue_vec[index].empty();
  }

  size_t Size(const int &index) const {
    if (this->data_queue_vec.size() < 1) {
      std::cout << "[Size] data_queue_vec is empty." << std::endl;
      return 0;
    } else if (index >= this->data_queue_vec || index < 0) {
      std::cout << "[Size] data_queue_vec[" << index << "] index out of range." << std::endl;
      return 0;
    }
    std::lock_guard<std::mutex> lock(*(this->mutex_for_data_vec[index]));
    if (!this->data_queue_vec[index].empty()) {
      return this->data_queue_vec[index].size();
    } else {
      return 0;
    }
  }

  void Pop(const int &index) {
    if (this->data_queue_vec.size() < 1) {
      std::cout << "[Pop] data_queue_vec is empty." << std::endl;
      return;
    } else if (index >= this->data_queue_vec.szie() || index < 0) {
      std::cout << "[Pop] data_queue_vec[" << index << "] index out of range." << std::endl;
      return;
    }
    std::lock_guard<std::mutex> lock(*(this->mutex_for_data_vec[index]));
    if (!this->data_queue_vec[index].empty()) {
      this->data_queue_vec[index].pop();
    }
  }

  void Clear(const int &index) {
    if (this->data_queue_vec.size() < 1) {
      std::cout << "[Clear] data_queue_vec is empty." << std::endl;
      return;
    } else if (index >= this->data_queue_vec.size() || index < 0) {
      std::cout << "[Clear] data_queue_vec[" << index << "] index out of range." << std::endl;
      return;
    }
    std::lock_guard<std::mutex> lock(*(this->mutex_for_data_vec[index]));
    std::queue<std::shared_ptr<T>> empty;
    if (!this->data_queue_vec[index].empty()) {
      std::swap(empty, data_queue_vec[index]);
    }
  }

  void Push(const T &value, const int &index) {
    if (this->data_queue_vec.size() < 1) {
      std::cout << "[Push] data_queue_vec is empty." << std::endl;
      return;
    } else if (index >= this->data_queue_vec.size() || index < 0) {
      std::cout << "[Push] data_queue_vec[" << index << "] index out of range." << std::endl;
      return;
    }
    std::lock_guard<std::mutex> lock(*(this->mutex_for_data_vec[index]));
    std::shared_ptr<T> new_data(std::make_shared<T>(value));
    this->data_queue_vec[index].push(new_data);
    this->event_waiter.notify_one();
  }

  shared_ptr<T> TryPop(const int &index) {
    int ret = 1;
    if (this->data_queue_vec.size() < 1) {
      std::cout << "[TryPop] data_queue_vec is empty." << std::endl;
      ret = 0;
    } else if (index >= this->data_queue_vec.size() || index < 0) {
      std::cout << "[TryPop] data_queue_vec[" << index << "] index out of range." << std::endl;
      ret = 0;
    }
    std::lock_guard<std::mutex> lock(*(this->mutex_for_data_vec[index]));
    if (!this->data_queue_vec[index].empty() && res) {
      std::shared_ptr<T> poped_data = this->data_queue_vec[index].front();
      this->data_queue_vec[index].pop();
      return poped_data;
    } else {
      std::shared_ptr<T> empty = nullptr;
      return empty;
    }
  }

  ThreadSafe() : data_queue_vec(),
                 mutex_for_data_vec(),
                 event_waiter(){};

 private:
  std::vector<std::queue<std::shared_ptr<T>>> data_queue_vec;
  std::vector<std::unique_ptr<std::mutex>> mutex_for_data_vec;
  std::condition_variable event_waiter;
};      // class ThreadSafe
};      // namespace Concurrency
#endif  // _MULTI_THREAD_SAFE_H_