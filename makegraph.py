import pandas as pd
import matplotlib.pyplot as plt

# Get the path to the CSV file from user input
csv_path = input("Enter the path to the CSV file: ")

# Load the data from the CSV file into a Pandas dataframe
data = pd.read_csv(csv_path, sep=';', header=0)

# Extract the array sizes from the first row of the dataframe
array_sizes = list(data.columns[1:])

# Extract the algorithm names and measurement types from the first column of the dataframe
algorithm_data = list(data[data.columns[0]])

# Create a dictionary to hold the measurement results for each algorithm
algorithm_results = {}

# Iterate over the algorithm data and populate the dictionary
for i, name in enumerate(algorithm_data):
    # Extract the algorithm name and measurement type from the string
    parts = name.split(' - ')
    algorithm_name = parts[0]
    measurement_type = parts[1]
    
    # Extract the measurement results for the algorithm
    measurements = list(data.iloc[i])[1:]
    
    # Add the results to the dictionary
    if algorithm_name not in algorithm_results:
        algorithm_results[algorithm_name] = {}
    algorithm_results[algorithm_name][measurement_type] = measurements

# Create a line plot for each algorithm's measurement results
for algorithm_name, measurement_data in algorithm_results.items():
    for measurement_type, measurements in measurement_data.items():
        # Get the file name from the csv_path variable
        file_name = csv_path.split('/')[-1]

        if len(array_sizes) > 10:
            # Only include every 10th array size on the x-axis
            x_ticks = range(0, len(array_sizes), 10)
            x_tick_labels = [array_sizes[i] for i in x_ticks]

            plt.plot(measurements, label=measurement_type)

            # Set the x-axis ticks and tick labels
            plt.xticks(x_ticks, x_tick_labels)
        else:
            # Plot the data
            plt.plot(array_sizes, measurements, label=measurement_type)

        # Set the title and axis labels for the plot with file name included
        plt.title(f'{algorithm_name} Effectiveness by Array Size ({file_name})')
        plt.xlabel('Array Size')
        plt.ylabel('Measurement Result')

    # Add a legend and display the plot
    plt.legend()
    plt.show()
