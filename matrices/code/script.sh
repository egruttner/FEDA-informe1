rm main.o
make

python3 plot.py csv/standard_results.csv
python3 plot.py csv/transpose_results.csv
python3 plot.py csv/strassen_results.csv
python3 plot_dos.py csv/standard_results.csv csv/transpose_results.csv
python3 plot_todos.py csv/standard_results.csv csv/transpose_results.csv csv/strassen_results.csv


rm main.o
