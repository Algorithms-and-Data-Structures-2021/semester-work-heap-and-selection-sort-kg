#include <iostream>

#include "data_structure.hpp"

using namespace std;

int main(int argc, char *argv[]) {
  for (int index = 0; index < argc; index++) {
    cout << index << ": " << argv[index] << endl;
  }

  std::vector<int> v {10, 3, 2, 4, 11};
  itis::selection_sort(v, 5);
  for (int h: v){
    cout << h << endl;
  }
  return 0;
}