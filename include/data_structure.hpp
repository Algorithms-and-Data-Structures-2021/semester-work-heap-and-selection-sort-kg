#pragma once
#include <vector>


namespace itis {

  void selection_sort(std::vector<int> &data);

  void heapify(std::vector <int> &data, int used_size, int index);

  void heap_sort(std::vector<int> &data);

/*  struct HeapSort {
   public:
    int size_{0};
    int heap[1000000];

    void add(int x);

    int minDel();

    void sort(std::vector<int> data);


    // Tip 2: На начальном этапе разработки структуры данных можете определения методов задавать в
    // заголовочном файле, как только работа будет завершена, можно будет оставить здесь только объявления.

    int size() const {
      return size_;
    }
  };*/

}  // namespace itis