#include <iostream>

#include "data_structure.hpp"

using namespace std;

int main(int argc, char *argv[]) {
  for (int index = 0; index < argc; index++) {
    cout << index << ": " << argv[index] << endl;
  }

  vector<int> vec {10, 3, 76, 34, 23, 32};
  itis::heap_sort(vec);
//  itis::selection_sort(vec);

  for (int i: vec)
  {
    cout << i << "  ";
  }
  return 0;
}