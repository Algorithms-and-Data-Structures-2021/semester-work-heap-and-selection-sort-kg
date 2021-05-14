import random
import csv
import os


names_of_sets = ['1', '2', '3', '4', '5']
sort_kinds = ['heap_sort', 'selection_sort']
number_of_elements_list = [100,
                           1000,
                           10000,
                           100000,
                           200000,
                           300000,
                           400000,
                           500000,
                           600000,
                           700000,
                           800000,
                           900000,
                           1000000]
border = 10 ** 9

path_to_dataset = os.path.join(os.getcwd(), "data")
for method in sort_kinds:
    path_to_method = os.path.join(path_to_dataset, method)
    os.mkdir(path_to_method)

    for set in names_of_sets:
        path_to_set = os.path.join(path_to_method, set)
        os.mkdir(path_to_set)

        for number_of_elements in number_of_elements_list:
            path_to_file = os.path.join(path_to_set, str(number_of_elements) + '.csv')
            data = []
            data.clear()

            for i in range(number_of_elements):
                data.append(random.randint(0, border))

            file = open(path_to_file, "w")

            with file:
                writer = csv.writer(file)
                writer.writerow(data)
