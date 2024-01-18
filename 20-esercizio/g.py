import numpy as np
import matplotlib.pyplot as plt
from matplotlib.colors import ListedColormap


dati = np.loadtxt('punti_var.dat')

x = dati[:, 0]
y = dati[:, 1]
valori = dati[:, 2]

colori = [ 'red', 'green', 'blue']
cmap = ListedColormap(colori)

scatter = plt.scatter(x, y, c=valori, cmap=cmap, marker='o', s=30, alpha=0.7)


plt.colorbar(scatter, ticks=[1, 2, 3], label='Valori')



plt.show()
