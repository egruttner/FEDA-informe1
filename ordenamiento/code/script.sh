rm main.o

#REALIZA EXPERIMENTOS CON DIFERENTES DATASETS
make foo=1
python3 plot.py csv/selection_results.csv
python3 plot.py csv/quicksort_results.csv
python3 plot.py csv/sortinterno_results.csv
python3 plot.py csv/mergesort_results.csv
python3 plot_todos.py csv/selection_results.csv csv/quicksort_results.csv csv/sortinterno_results.csv csv/mergesort_results.csv
python3 plot_tres.py csv/quicksort_results.csv csv/sortinterno_results.csv csv/mergesort_results.csv

make foo=2
python3 plot.py csv/selection_results.csv
python3 plot.py csv/quicksort_results.csv
python3 plot.py csv/sortinterno_results.csv
python3 plot.py csv/mergesort_results.csv
python3 plot_todos.py csv/selection_results.csv csv/quicksort_results.csv csv/sortinterno_results.csv csv/mergesort_results.csv
python3 plot_tres.py csv/quicksort_results.csv csv/sortinterno_results.csv csv/mergesort_results.csv

make foo=3
python3 plot.py csv/selection_results.csv
python3 plot.py csv/quicksort_results.csv
python3 plot.py csv/sortinterno_results.csv
python3 plot.py csv/mergesort_results.csv
python3 plot_todos.py csv/selection_results.csv csv/quicksort_results.csv csv/sortinterno_results.csv csv/mergesort_results.csv
python3 plot_tres.py csv/quicksort_results.csv csv/sortinterno_results.csv csv/mergesort_results.csv

make foo=4
python3 plot.py csv/selection_results.csv
python3 plot.py csv/quicksort_results.csv
python3 plot.py csv/sortinterno_results.csv
python3 plot.py csv/mergesort_results.csv
python3 plot_todos.py csv/selection_results.csv csv/quicksort_results.csv csv/sortinterno_results.csv csv/mergesort_results.csv
python3 plot_tres.py csv/quicksort_results.csv csv/sortinterno_results.csv csv/mergesort_results.csv


rm main.o
