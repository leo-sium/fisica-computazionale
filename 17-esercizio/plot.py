import numpy as np
import matplotlib.pyplot as plt

dati_eu = np.loadtxt('punti_eulero.dat')
dati_rk2 = np.loadtxt('punti_rk2.dat')
dati_rk4 = np.loadtxt('punti_rk4.dat')

tempi = dati_rk4[:, 0]
x_rk4 = dati_rk4[:, 1]
y_rk4 = dati_rk4[:, 2] 
z_rk4 = dati_rk4[:, 3]

x_rk2 = dati_rk2[:, 1]
y_rk2 = dati_rk2[:, 2] 
z_rk2 = dati_rk2[:, 3]

x_eu = dati_eu[:, 1]
y_eu = dati_eu[:, 2] 
z_eu = dati_eu[:, 3]

plt.plot(x_rk4, y_rk4, label='rk4')
plt.plot(x_rk2, y_rk2, label='rk2')
plt.plot(x_eu, y_eu, label='eulero')


plt.title('posizioni')
plt.xlabel('tempo')
plt.ylabel('posizione')
plt.legend()

plt.figure()

plt.plot(x_rk4, z_rk4, label='rk4')
plt.plot(x_rk2, z_rk2, label='rk2')
plt.plot(x_eu, z_eu, label='eulero')

plt.title('posizioni')
plt.xlabel('tempo')
plt.ylabel('posizione')
plt.legend()

plt.figure()

plt.plot(y_rk4, z_rk4, label='rk4')
plt.plot(y_rk2, z_rk2, label='rk2')
plt.plot(y_eu, z_eu, label='eulero')

plt.title('posizioni')
plt.xlabel('tempo')
plt.ylabel('posizione')
plt.legend()

plt.show()