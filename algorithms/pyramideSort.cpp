#include <vector>
#include <iostream>

// Класс, представляющий собой кучу
class Heap {
public:
    Heap(int *arr, int n) {
        for (int i = 0; i < n; i++) {
            heap_.push_back(arr[i]);
        }
        for (int i = heap_.size() / 2; i >= 0; --i) {
            heapify(i);
        }
    }

    size_t getSize() {
        return heap_.size();
    }

    int top() {
        return heap_[0];
    }

    void pop() {
        heap_[0] = heap_[heap_.size() - 1];
        heap_.pop_back();
        heapify(0);
    }

    void add(int value) {
        heap_.push_back(value);
        int i = heap_.size() - 1;
        int parent = (i - 1) / 2;
        while (i > 0 && heap_[parent] < heap_[i]) {
            std::swap(heap_[parent], heap_[i]);
            i = parent;
            parent = (i - 1) / 2;
        }
    }

    void heapify(int i) {
        int left_child, right_child, largest;
        while (true) {
            left_child = 2 * i + 1;
            right_child = 2 * i + 2;
            largest = i;
            if (left_child < static_cast<int>(heap_.size()) && heap_[left_child] > heap_[largest]) {
                largest = left_child;
            }
            if (right_child < static_cast<int>(heap_.size()) &&
                heap_[right_child] > heap_[largest]) {
                largest = right_child;
            }
            if (largest == i) {
                break;
            }
            std::swap(heap_[i], heap_[largest]);
            i = largest;
        }
    }

private:
    std::vector<int> heap_;
};

// Метод пирамидальной сортировки
void pyramideSort(int *arr, int n, int k) {
    Heap heap(arr, n);
    for (int i = n - 1; i >= 0; --i) {
        arr[i] = heap.top();
        heap.pop();
    }
}