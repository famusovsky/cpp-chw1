# АиСД-2, 2023, задание 5
# Степанов А, БПИ212

import os
import pandas as pd
import matplotlib.pyplot as plt

csv_dir = os.path.dirname(os.path.realpath(__file__))
os.chdir(csv_dir)

csv_path = input("Enter the path to the CSV file: ")
data = pd.read_csv(csv_path, sep=';', header=0)

array_sizes = list(data.columns[1:])
algorithm_data = list(data[data.columns[0]])
algorithm_results = {}

for i, name in enumerate(algorithm_data):
    parts = name.split(' - ')
    algorithm_name = parts[0]
    measurement_type = parts[1]    
    measurements = list(data.iloc[i])[1:]
    if algorithm_name not in algorithm_results:
        algorithm_results[algorithm_name] = {}
    algorithm_results[algorithm_name][measurement_type] = measurements

for algorithm_name, measurement_data in algorithm_results.items():
    plt.figure()
    for measurement_type, measurements in measurement_data.items():
        if len(array_sizes) > 10:
            x_ticks = range(0, len(array_sizes), 10)
            x_tick_labels = [array_sizes[i] for i in x_ticks]
            plt.plot(measurements, label=measurement_type)
            plt.xticks(x_ticks, x_tick_labels)
        else:
            plt.plot(array_sizes, measurements, label=measurement_type)

    file_name = csv_path.split('/')[-1]
    plt.title(f'{algorithm_name} Effectiveness by Array Size ({file_name})')
    plt.xlabel('Array Size')
    plt.ylabel('Measurement Result')

    plt.legend()
    results_dir = os.path.join("results", algorithm_name)
    os.makedirs(results_dir, exist_ok=True)
    plot_file_name = os.path.join(results_dir, f'{algorithm_name}_{file_name}.png')
    plt.savefig(plot_file_name)

plt.show()
