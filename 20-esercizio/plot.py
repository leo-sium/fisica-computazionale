import numpy as np
import matplotlib.pyplot as plt

dati = np.loadtxt('punti.dat')

x = dati[:, 0]
y = dati[:, 1]
it = dati[:, 2]

colormap = plt.cm.get_cmap('viridis')  
plt.scatter(x, y, c=it, cmap=colormap, edgecolors='none', marker='s', s=50)

barra_colori = plt.colorbar()
barra_colori.set_label('Iterazioni')

plt.xlabel('Asse reale')
plt.ylabel('Asse immaginario')
plt.title('Grafico delle iterazioni in base alla posizione di partenza')

plt.show()





