rm main.o
make

python3 plot.py csv/selection_results.csv csv/bubble_results.csv csv/quicksort_results.csv csv/sortinterno_results.csv csv/mergesort_results.csv
