import numpy as np
from scipy.optimize import curve_fit
from scipy.stats import norm
import matplotlib.pyplot as plt

dati = np.loadtxt('punti_1.dat')

tempi = dati[:, 0]
x_eulero = dati[:, 1]
v_eulero = dati[:, 2]
x_rk2 = dati[:, 3]
v_rk2 = dati[:, 4]
x_rk4 = dati[:, 5]
v_rk4 = dati[:, 6]

dati_s = np.loadtxt('punti_2.dat')

tempi_s = dati[:, 0]
x_eulero_s= dati[:, 1]
v_eulero_s = dati[:, 2]
x_rk2_s = dati[:, 3]
v_rk2_s = dati[:, 4]
x_rk4_s = dati[:, 5]
v_rk4_s = dati[:, 6]

plt.plot(tempi, x_eulero, label='eulero')
plt.plot(tempi, x_rk2, label='rk2')
plt.plot(tempi, x_rk4, label='rk4')

plt.title('posizioni')
plt.xlabel('tempo')
plt.xlabel('posizione/velocità')
plt.legend()

plt.figure()
plt.plot(tempi,v_eulero, label='eulero')
plt.plot(tempi,v_rk2, label='rk2')
plt.plot(tempi, v_rk4, label='rk4')

plt.title('velocità')
plt.xlabel('tempo')
plt.xlabel('velocità')
plt.legend()
#---------------------------------------------------------------

plt.figure()
plt.plot(tempi_s, x_eulero_s, label='eulero')
plt.plot(tempi_s, x_rk2_s, label='rk2')
plt.plot(tempi_s, x_rk4_s, label='rk4')

plt.title('oscillatore smorzato: posizione')
plt.xlabel('tempo')
plt.xlabel('posizione/velocità')
plt.legend()

plt.figure()
plt.plot(tempi_s, v_eulero_s, label='eulero')
plt.plot(tempi_s, v_rk2_s, label='rk2')
plt.plot(tempi_s, v_rk4_s, label='rk4')

plt.title('eulero:oscillatore smorzato: velocità')
plt.xlabel('tempo')
plt.xlabel('velocità')
plt.legend()


plt.show()


"""
plt.figure()
plt.plot(tempi, x_rk2, label='posizione')
plt.plot(tempi,v_rk2, label='velocità')

plt.title('runge-kutta 2')
plt.xlabel('tempo')
plt.xlabel('posizione/velocità')
plt.legend()

plt.figure()
plt.plot(tempi, x_rk4, label='posizione')
plt.plot(tempi, v_rk4, label='velocità')

plt.title('runge-kutta 4')
plt.xlabel('tempo')
plt.xlabel('posizione/velocità')
plt.legend()

plt.show()
"""