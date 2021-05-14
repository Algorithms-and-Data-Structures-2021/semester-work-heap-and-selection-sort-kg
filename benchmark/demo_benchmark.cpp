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

  // Tip 1: входные аргументы позволяют более гибко контролировать работу вашей программы.
  // Можете передать путь до входного/выходного тестового файла в качестве аргумента программы.

  for (int index = 0; index < argc; index++) {
    cout << "Arg: " << argv[index] << '\n';
  }

  // Tip 2: для перевода строки в число можете использовать функцию stoi (string to integer)

  // можете использовать функционал класса stringstream для обработки строки
  auto ss = stringstream("0 1 2");  // передаете строку (входной аргумент или строку из файла) и обрабатываете ее

  int number = 0;
  ss >> number;  // number = 0
  ss >> number;  // number = 1
  ss >> number;  // number = 2

  // работа с набором данных
  const auto path = string(kDatasetPath);
  cout << "Path to the 'dataset/' folder: " << path << endl;

  auto input_file = ifstream(path + "/dataset-example.csv");

  if (input_file) {
    // чтение и обработка набора данных ...
  }

  vector<string> mas{"1", "2", "3", "4", "5", "6", "7", "8", "9", "10"};
  vector<string> mas2{"100", "1000", "10000", "100000", "200000", "300000", "400000", "500000", "600000", "700000", "800000", "90000", "1000000"};
  vector<string> mas3{"1", "2", "3", "4", "5"};

  auto output_file = ofstream(path);
  output_file.open(path + "/" + "result.csv", ios::out | ios::app);
  output_file << "file" << "," << "count" << "," << "number" << "," << "heap_sort" << "," << "selection_sort" << endl;
  for(int i =0; i < 13; i++){
    for(int j = 0; j < 5; j++){
      auto path_file = string(mas3.at(j) + "/" + mas2.at(i));
      for(int k = 0; k < 10; k++){
        auto data = makeArray(path + path_file);
        itis::HeapSort *main_heap = new itis::HeapSort();
        int n = stoi(mas2.at(i));

        const auto time_point_before = chrono::steady_clock::now();
        itis::selection_sort(data, n);
        const auto time_point_after = chrono::steady_clock::now();
        const auto time_diff = time_point_after - time_point_before;
        const long time_elapsed_ns = chrono::duration_cast<chrono::nanoseconds>(time_diff).count();
//        const long time_elapsed_ns = 0;

        const auto time_point_before2 = chrono::steady_clock::now();
        main_heap->sort(data);
        const auto time_point_after2 = chrono::steady_clock::now();
        const auto time_diff2 = time_point_after2 - time_point_before2;
        const long time_elapsed_ns2 = chrono::duration_cast<chrono::nanoseconds>(time_diff2).count();

        output_file << mas3.at(j) << "," << mas2.at(i) << "," << mas.at(k) << "," << time_elapsed_ns << "," << time_elapsed_ns2 << endl;
      }
    }
  }
  output_file.close();

  // Контрольный тест: операции добавления, удаления, поиска и пр. над структурой данных

  // Tip 3: время работы программы (или участка кода) можно осуществить
  // как изнутри программы (std::chrono), так и сторонними утилитами

  const auto time_point_before = chrono::steady_clock::now();

  // здесь находится участок кода, время которого необходимо замерить

  const auto time_point_after = chrono::steady_clock::now();

  // переводим время в наносекунды
  const auto time_diff = time_point_after - time_point_before;
  const auto time_elapsed_ns = chrono::duration_cast<chrono::nanoseconds>(time_diff).count();

  cout << "Time elapsed (ns): " << time_elapsed_ns << '\n';

  return 0;
}
