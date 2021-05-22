#include "data_structure.hpp"


namespace itis {

  void heapify(std::vector <int> &data, int used_size, int root)
  {
    // найти найбольший из 3 узлов: родителя и 2 его детей
    int largest_ind = root;
    int left_ind = 2 * root + 1;
    int right_ind = 2 * root + 2;

    if (left_ind < used_size && data[left_ind] > data[largest_ind])
    {
      largest_ind = left_ind;
    }

    if (right_ind < used_size && data[right_ind] > data[largest_ind])
    {
      largest_ind = right_ind;
    }

    if (largest_ind != root)
    {
      std::swap(data[root], data[largest_ind]);
      heapify(data, used_size, largest_ind);
    }
  }

  void heap_sort(std::vector<int> &data)
  {
    int size {static_cast<int>(data.size())};

    // создать максимальную кучу
    for (int i = (size - 2) / 2; i >=0; i--)
    {
      heapify(data, size, i);
    }


    // сортировать
    for (int i = size - 1; i >= 0; i--)
    {
      std::swap(data[0], data[i]);
      heapify(data, i, 0);
    }
  }

/*  void HeapSort::add(int x) {
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
  }*/

  void selection_sort(std::vector<int> &data, int n)
  {
    for (int i = 0; i < n-1; i++)
    {
      for (int j = i + 1; j < n; j++)
      {
        if (data.at(i) > data.at(j))
        {
          int x = data.at(i);
          data.at(i) = data.at(j);
          data.at(j) = x;
        }
      }
    }
  }
}  // namespace itis