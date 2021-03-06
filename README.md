# Selection sort and heap sort

[![CMake](https://github.com/Algorithms-and-Data-Structures-2021/semester-work-template/actions/workflows/cmake.yml/badge.svg)](https://github.com/Algorithms-and-Data-Structures-2021/semester-work-template/actions/workflows/cmake.yml)

В данном проекте были реализованны две сортировки: selection sort, heap sort. Heap sort является модификацией сортировки выбором, работающей быстрее: selection heap за O(n^2), heap sort за O(n logn). Сортировка массива используется для упорядычевания данных для их удобного хранения или вывода пользователю.

## Команда "Girls’ Energy"


| Фамилия Имя   | Вклад (%) | Прозвище              |
| :---          |   ---:    |  ---:                 |
| Гордеева Елена   | 50        |  _боссесса первая_               |
| Корнеева Варвара   | 50        |  _боссесса вторая_ |


**Девиз команды**
> _Только вперёд!_

## Структура проекта

_Описание основных частей семестрового проекта._

Проект состоит из следующих частей:

- [`src`](src)/[`include`](include) - реализация структуры данных (исходный код и заголовочные файлы);
- [`benchmark`](benchmark) - контрольные тесты производительности структуры данных (операции добавления, удаления,
  поиска и пр.);
- [`dataset`](dataset) - наборы данных для запуска контрольных тестов и их генерация;

## Требования (Prerequisites)

1. С++ компилятор c поддержкой стандарта C++17 (например, _GNU GCC 8.1.x_ и выше).
2. Система автоматизации сборки _CMake_ (версия _3.12.x_ и выше).
3. Интерпретатор _Python_ (версия _3.7.x_ и выше).
4. Рекомендуемый объем оперативной памяти - не менее 8 ГБ.
5. Свободное дисковое пространство объемом ~ 300 МБ (набор данных для контрольных тестов).

## Сборка и запуск



#### Сборка проекта

Склонируйте проект к себе на устройство через [Git for Windows](https://gitforwindows.org/) (либо используйте
возможности IDE):

```shell
git clone https://github.com/Algorithms-and-Data-Structures-2021/semester-work-heap-and-selection-sort-kg.git
```

Для ручной сборки проекта в терминале введите:

```shell
# переход в папку с проектом
cd C:\Users\username\asd-projects\semester-work-heap-and-selection-sort-kg

# создание папки для файлов сборки (чтобы не засорять папку с проектом) 
mkdir -p build && cd build 

# сборка проекта
cmake .. -DCMAKE_BUILD_TYPE=RelWithDebInfo && cmake --config RelWithDebInfo --build . 
```

#### Генерация тестовых данных

Генерация тестового набора данных в
формате [comma-seperated values (CSV)](https://en.wikipedia.org/wiki/Comma-separated_values):

  1. Откройте вашу среду разработки.
  2. В директории dataset найдите файл generate_csv_dataset.py и запустите его, например, с помощью правой кнопки мыши (проверьте, чтобы у вас был настроен интерпетатор python). После этого в директории dataset/data начнётся генерация тестовых данных.

Сгенериравонные данные должны быть организавоны таким образом:

```shell
dataset/data/
  heap_sort/
    1/
      100.csv
      ...
      1000000.csv
    2/ ...
    ...
    5/ ...
  selection_sort/
    1/
      100.csv
      ...
      1000000.csv
    ...
    5/ ...
```

По названию директории `/dataset/data/heap_sort` можно понять, что здесь хранятся наборы данных для контрольных тестов для сортировки кучей. Названия файлов `100.csv`. `1000000.csv` и т.д. хранят информацию о размере набора данных (т.е. количество элементов). 

#### Контрольные тесты (benchmarks)

Для запуска контрольных тестов необходимо предварительно сгенерировать или скачать готовый набор тестовых данных.

Готовые наборы данных можно скачать по ссылке: https://drive.google.com/drive/folders/1wAdYI7-vRlfW-M6blZJtje5nrUXJHmNv.

##### Список контрольных тестов

| Название                  | Описание                                | Метрики         |
| :---                      | ---                                     | :---            |
| `selection sort`          | сортировка выбором                      | _время_         |
| `heap sort`               | сортировка кучей                        | _время_         |

##### Пример запуска

```shell
./benchmark
```
После запуска программы она протестирует обе сортировки на всех наборах данных и запишет результаты в файл result.csv.

## Источники

Selection sort:
  1. Selection sort (Wikipedia) - https://en.wikipedia.org/wiki/Selection_sort
  2. Selection Sort (GeeksforGeeks) - https://www.geeksforgeeks.org/selection-sort/

Heap sort:
  1. Heapsort (Wikipedia) - https://en.wikipedia.org/wiki/Heapsort
  2. Heap Sort Algorithm (Programiz) - https://www.programiz.com/dsa/heap-sort
