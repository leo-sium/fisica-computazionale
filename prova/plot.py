import numpy as np
import matplotlib.pyplot as plt

dati = np.loadtxt('punti_rk4.dat')

tempi = dati[:, 0]
x = dati[:, 1]
y = dati[:, 2] 
z = dati[:, 3]

plt.plot(x, y, label='xy')


plt.title('posizioni')
plt.xlabel('tempo')
plt.ylabel('posizione')
plt.legend()

plt.figure()

plt.plot(x, z, label='y')

plt.title('posizioni')
plt.xlabel('tempo')
plt.ylabel('posizione')
plt.legend()

plt.figure()

plt.plot(y, z, label='z')

plt.title('posizioni')
plt.xlabel('tempo')
plt.ylabel('posizione')
plt.legend()

plt.show()




