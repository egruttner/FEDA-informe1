rm main.o
make

python3 plot.py csv/selection_results.csv
python3 plot.py csv/quicksort_results.csv
python3 plot.py csv/sortinterno_results.csv
python3 plot.py csv/mergesort_results.csv
python3 plot_todos.py csv/selection_results.csv csv/quicksort_results.csv csv/sortinterno_results.csv csv/mergesort_results.csv
