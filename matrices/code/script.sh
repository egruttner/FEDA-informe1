rm main.o

#REALIZA EXPERIMENTOS CON DIFERENTES DATASETS

num_datasets=5

for (( i=1; i <= $num_datasets; ++i ))
do
    make num_dataset=$i

    python3 plot.py csv/csv$i/standard_results.csv
    python3 plot.py csv/csv$i/transpose_results.csv
    python3 plot.py csv/csv$i/strassen_results.csv
    python3 plot_dos.py csv/csv$i/standard_results.csv csv/csv$i/transpose_results.csv
    python3 plot_todos.py csv/csv$i/standard_results.csv csv/csv$i/transpose_results.csv csv/csv$i/strassen_results.csv

done

rm main.o
