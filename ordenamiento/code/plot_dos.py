import matplotlib.pyplot as plt
import pandas as pd
import sys


data1 = pd.read_csv(sys.argv[1])
data2 = pd.read_csv(sys.argv[2])


label1 = sys.argv[1].split('_')[0]
label1 = label1[9:]
label2 = sys.argv[2].split('_')[0]
label2 = label2[9:]


x1 = data1['n'].values
y1 = data1['tiempo[ms]'].values

x2 = data2['n'].values
y2 = data2['tiempo[ms]'].values


plt.plot(x1, y1, label=label1)
plt.legend()
plt.plot(x2, y2, label=label2)
plt.legend()


plt.xlabel('n')
plt.ylabel('tiempo[ms]')

plt.title('Gráfico comparativo de algoritmos de ordenamiento')

plt.grid()

plt.show()
