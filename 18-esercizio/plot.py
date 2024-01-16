import numpy as np
import matplotlib.pyplot as plt

dati = np.loadtxt('energia.dat')

tempi = dati[:, 0]
K = dati[:, 1]
U = dati[:, 2]
E = dati[:, 3]

plt.plot(tempi, U, label='energia potenziale')
plt.plot(tempi, K, label='energia cinetica')
plt.plot(tempi, E, label='energia totale')

plt.title('energie')
plt.xlabel('tempo')
plt.ylabel('energia')
plt.legend()

plt.show()






