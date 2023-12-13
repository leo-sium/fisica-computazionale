import numpy as np
from scipy.optimize import curve_fit
from scipy.stats import norm
import matplotlib.pyplot as plt

dati = np.loadtxt('punti_3.dat')

tempi_s = dati[:, 0]
x_eulero_s= dati[:, 1]
v_eulero_s = dati[:, 2]
x_rk2_s = dati[:, 3]
v_rk2_s = dati[:, 4]
x_rk4_s = dati[:, 5]
v_rk4_s = dati[:, 6]

plt.plot(tempi_s, x_eulero_s, label='eulero')
plt.plot(tempi_s, x_rk2_s, label='rk2')
plt.plot(tempi_s, x_rk4_s, label='rk4')

plt.title('oscillatore forzato: posizione')
plt.xlabel('tempo')
plt.ylabel('posizione')
plt.legend()

plt.figure()
plt.plot(tempi_s, v_eulero_s, label='eulero')
plt.plot(tempi_s, v_rk2_s, label='rk2')
plt.plot(tempi_s, v_rk4_s, label='rk4')

plt.title('eulero:oscillatore forzato: velocità')
plt.xlabel('tempo')
plt.ylabel('velocità')
plt.legend()

plt.figure()
plt.plot(x_eulero_s, v_eulero_s, label='eulero')
plt.plot(x_rk2_s, v_rk2_s, label='rk2')
plt.plot(x_rk4_s, v_rk4_s, label='rk4')

plt.title('eulero:oscillatore forzato: velocità')
plt.xlabel('posizione')
plt.ylabel('velocità')
plt.legend()

plt.show()