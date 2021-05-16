#include <fstream>      // ifstream
#include <iostream>     // cout
#include <string>       // string, stoi
#include <string_view>  // string_view
#include <chrono>       // high_resolution_clock, duration_cast, nanoseconds
#include <sstream>      // stringstream

// подключаем вашу структуру данных
#include "data_structure.hpp"

using namespace std;
using namespace itis;

// абсолютный путь до набора данных и папки проекта
static constexpr auto kDatasetPath = string_view{PROJECT_DATASET_DIR};
static constexpr auto kProjectPath = string_view{PROJECT_SOURCE_DIR};

vector<int> makeArray(string path){
  auto input_file = ifstream(path);
  vector<int> data;
  if (input_file) {
    std::string line;
    while (std::getline(input_file, line)){
      std::istringstream s(line);
      std::string field;
      while (std::getline(s, field, ',')) {
        data.push_back(stoi(field));
      }
    }
  }
  return data;
}


int main(int argc, char **argv) {

  const auto path = string(kDatasetPath);

  vector<string> mas{"1", "2", "3", "4", "5", "6", "7", "8", "9", "10"};
//  vector<string> mas{"1", "2", "3", "4", "5"};
//  vector<string> mas2{"100", "1000", "10000", "100000", "200000", "300000", "400000", "500000", "600000", "700000", "800000", "900000", "1000000"};
//  vector<string> mas2{"100", "1000", "10000", "200000", "400000", "600000", "800000", "1000000"};
  vector<string> mas2{"100", "1000", "10000", "250000", "500000", "750000", "1000000"};
  vector<string> mas3{"1", "2", "3", "4", "5"};

  auto output_file = ofstream(path);
  output_file.open(path + "/" + "result.csv", ios::out | ios::app);
  output_file << "file" << "," << "count" << "," << "number" << "," << "selection_sort" << "," << "heap_sort" << endl;
  for(int i =0; i < 7; i++){
    for(int j = 0; j < 5; j++){
      for(int k = 0; k < 10; k++){
        auto path_file = string("/selection_sort/" + mas3.at(j) + "/" + mas2.at(i) + ".csv");
        auto data = makeArray(path + path_file);
        itis::HeapSort *main_heap = new itis::HeapSort();
        int n = stoi(mas2.at(i));

        const auto time_point_before = chrono::steady_clock::now();
        itis::selection_sort(data, n);
        const auto time_point_after = chrono::steady_clock::now();
        const auto time_diff = time_point_after - time_point_before;
        const auto time_elapsed_ns = chrono::duration_cast<chrono::milliseconds>(time_diff).count();

        auto path_file2 = string("/heap_sort/" + mas3.at(j) + "/" + mas2.at(i) + ".csv");
        auto data2 = makeArray(path + path_file2);
        const auto time_point_before2 = chrono::steady_clock::now();
        main_heap->sort(data2);
        const auto time_point_after2 = chrono::steady_clock::now();
        const auto time_diff2 = time_point_after2 - time_point_before2;
        const long time_elapsed_ns2 = chrono::duration_cast<chrono::microseconds>(time_diff2).count();

        output_file << mas3.at(j) << "," << mas2.at(i) << "," << mas.at(k) << "," << time_elapsed_ns << "," << time_elapsed_ns2 << endl;
      }
    }
  }
  output_file.close();
  return 0;
}
