#include "algorithm.hpp"

namespace itis {

  void heapify(std::vector <int> &data, int range, int root)
  {
    // найти найбольший из 3 узлов: родителя и 2 его детей
    auto largest_ind {static_cast<unsigned int>(root)};
    auto left_ind {static_cast<unsigned int>(2 * root + 1)};
    auto right_ind {static_cast<unsigned int>(2 * root + 2)};

    if (left_ind < static_cast<unsigned int>(range)
        && data[left_ind] > data[largest_ind])
    {
      largest_ind = left_ind;
    }

    if (right_ind < static_cast<unsigned int>(range)
        && data[right_ind] > data[largest_ind])
    {
      largest_ind = right_ind;
    }

    if (largest_ind != static_cast<unsigned int>(root))
    {
      std::swap(data[static_cast<unsigned int>(root)], data[largest_ind]);
      heapify(data, range, static_cast<int>(largest_ind));
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
      std::swap(data[0], data[static_cast<unsigned int>(i)]);
      heapify(data, i, 0);
    }
  }


  void selection_sort(std::vector<int> &data)
  {
    unsigned int size = data.size();

    for (unsigned int i = 0; i < size - 1; i++)
    {
      for (unsigned int j = i + 1; j < size; j++)
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