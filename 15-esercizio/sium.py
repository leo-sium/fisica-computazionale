import numpy as np
from scipy.optimize import curve_fit
from scipy.stats import norm
import matplotlib.pyplot as plt

dati = np.loadtxt('RK2')

tempi_s = dati[:, 0]
x_eulero_s= dati[:, 1]
v_eulero_s = dati[:, 2]


plt.plot(tempi_s, x_eulero_s, label='eulero')


plt.title('oscillatore forzato: posizione')
plt.xlabel('tempo')
plt.ylabel('posizione')
plt.legend()

plt.figure()
plt.plot(tempi_s, v_eulero_s, label='eulero')


plt.title('eulero:oscillatore forzato: velocità')
plt.xlabel('tempo')
plt.ylabel('velocità')
plt.legend()

plt.figure()
plt.plot(x_eulero_s, v_eulero_s, label='eulero')


plt.title('eulero:oscillatore forzato: velocità')
plt.xlabel('posizione')
plt.ylabel('velocità')
plt.legend()

plt.show()