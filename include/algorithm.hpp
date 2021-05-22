#pragma once
#include <vector>


namespace itis {
  void selection_sort(std::vector<int> &data);

  void heap_sort(std::vector<int> &data);

  void heapify(std::vector <int> &data, int range, int index);

}  // namespace itis