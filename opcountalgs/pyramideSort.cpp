#include <iostream>
#include <vector>

// Класс, представляющий собой кучу, все методы которого включают в себя подсчет операций
class Heap {
 public:
  Heap(int *arr, int n, int64_t &count) {
    count += n;
    for (int i = 0; i < n; i++) {
      heap_.push_back(arr[i]);
    }
    for (int i = heap_.size() / 2; i >= 0; --i) {
      heapify(i, count);
    }
  }

  size_t getSize() {
    return heap_.size();
  }

  int top(int64_t &count) {
    count += 2;
    return heap_[0];
  }

  void pop(int64_t &count) {
    count += 3;
    heap_[0] = heap_[heap_.size() - 1];
    heap_.pop_back();
    heapify(0, count);
  }

  void add(int value, int64_t &count) {
    count += 2;
    heap_.push_back(value);
    int i = heap_.size() - 1;
    int parent = (i - 1) / 2;
    while (i > 0 && heap_[parent] < heap_[i]) {
      count += 3;
      std::swap(heap_[parent], heap_[i]);
      i = parent;
      parent = (i - 1) / 2;
    }
  }

  void heapify(int i, int64_t &count) {
    count++;
    int left_child, right_child, largest;
    while (true) {
      count += 4;
      left_child = 2 * i + 1;
      right_child = 2 * i + 2;
      largest = i;
      if (left_child < static_cast<int>(heap_.size()) && heap_[left_child] > heap_[largest]) {
        count++;
        largest = left_child;
      }
      if (right_child < static_cast<int>(heap_.size()) && heap_[right_child] > heap_[largest]) {
        count++;
        largest = right_child;
      }
      if (largest == i) {
        break;
      }
      count += 3;
      std::swap(heap_[i], heap_[largest]);
      i = largest;
    }
  }

 private:
  std::vector<int> heap_;
};

// Метод пирамидальной сортировки, с подсчетом операций
void pyramideSortOP(int *arr, int n, int k, int64_t &count) {
  Heap heap(arr, n, count);
  for (int i = n - 1; i >= 0; --i) {
    arr[i] = heap.top(count);
    heap.pop(count);
  }
}
