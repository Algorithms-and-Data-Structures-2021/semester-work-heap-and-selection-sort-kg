#include "data_structure.hpp"

// файл с определениями

namespace itis {

  // здесь должны быть определения методов вашей структуры

  void HeapSort::add(int x) {
    HeapSort::heap[size_] = x;
    size_++;
    int i = size_ - 1;
    while (i!=0 && HeapSort::heap[i]<HeapSort::heap[(i-1)/2]){
      std::swap(HeapSort::heap[i],HeapSort::heap[(i-1)/2]);
      i = (i-1)/2;
    }
  }

  int HeapSort::minDel() {
    int min = HeapSort::heap[0];
    std::swap(HeapSort::heap[0],HeapSort::heap[size_-1]);
    size_--;
    int i = 0;
    int leftChild = 2*i+1;
    if (leftChild+1<size_ && HeapSort::heap[leftChild]>HeapSort::heap[leftChild+1]) leftChild++;
    while (2*i<size_ && HeapSort::heap[i]>HeapSort::heap[leftChild]){
      std::swap(HeapSort::heap[i],HeapSort::heap[leftChild]);
      i = leftChild;
      leftChild = 2*i+1;
      if (leftChild+1<size_ && HeapSort::heap[leftChild]>HeapSort::heap[leftChild+1]) leftChild++;
    }
    return min;
  }

  void HeapSort::sort(std::vector<int> data) {
    for (int i = 0; i<size_; i++) {
      add(data.at(i));
    }
    for (int i = 0; i<size_; i++) {
      data.at(i) = minDel();
    }
  }

  void selection_sort(std::vector<int> &data, int n) {
    for (int i = 0; i < n-1; i++){
      for (int j = i + 1; j < n; j++){
        if (data.at(i) > data.at(j)) {
          int x = data.at(i);
          data.at(i) = data.at(j);
          data.at(j) = x;
        }
      }
    }
  }
}  // namespace itis