import numpy as np
import matplotlib.pyplot as plt
from matplotlib.colors import ListedColormap


dati = np.loadtxt('punti.dat')

x = dati[:, 0]
y = dati[:, 1]
valori = dati[:, 2]

colori = ['purple', 'red', 'green', 'blue']
cmap = ListedColormap(colori)

scatter = plt.scatter(x, y, c=valori, cmap=cmap, marker='o', s=30, alpha=0.7)


plt.colorbar(scatter, ticks=[0, 1, 2, 3], label='Valori')



plt.show()
