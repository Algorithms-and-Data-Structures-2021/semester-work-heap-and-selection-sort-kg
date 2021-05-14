#pragma once
#include <vector>

// Заголовочный файл с объявлением структуры данных

namespace itis {

  // Tip 1: объявите здесь необходимые структуры, функции, константы и прочее

  // Пример: объявление константы времени компиляции в заголовочном файле
  inline constexpr auto kStringConstant = "Hello, stranger!";

  // Пример: объявление структуры с полями и методами

  void selection_sort(std::vector<int> data){
    for (int i = 0; i < data.size()-1; i++){
      for (int j = i + 1; j < data.size(); j++){
        if (data[i] > data[j]) {
          std::swap(data[i], data[j]);
        }
      }
    }
  }

  struct HeapSort {
   public:
    int size_{0};
    int* data_{nullptr};
    int heap[1000000000];

    void add(int x){
      heap[size_] = x;
      size_++;
      int i = size_ - 1;
      while (i!=0 && heap[i]<heap[(i-1)/2]){
        std::swap(heap[i],heap[(i-1)/2]);
        i = (i-1)/2;
      }
    }

    int minDel(){
      int min = heap[0];
      std::swap(heap[0],heap[size_-1]);
      size_--;
      int i = 0;
      int leftChild = 2*i+1;
      if (leftChild+1<size_ && heap[leftChild]>heap[leftChild+1]) leftChild++;
      while (2*i<size_ && heap[i]>heap[leftChild]){
        std::swap(heap[i],heap[leftChild]);
        i = leftChild;
        leftChild = 2*i+1;
        if (leftChild+1<size_ && heap[leftChild]>heap[leftChild+1]) leftChild++;
      }
      return min;
    }

    void sort(){
      for (int i = 0; i<size_; i++) {
        add(heap[i]);
      }
      for (int i = 0; i<size_; i++) {
        heap[i] = minDel();
      }
    }


    // Tip 2: На начальном этапе разработки структуры данных можете определения методов задавать в
    // заголовочном файле, как только работа будет завершена, можно будет оставить здесь только объявления.

    int size() const {
      return size_;
    }
  };

}  // namespace itis