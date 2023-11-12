import numpy as np
from scipy.optimize import curve_fit
import matplotlib.pyplot as plt

def f(x) :
    ris = np.exp(-x)
    return ris

def g(x) :
    ris = x*np.exp(-np.power(x, 2))
    return ris

dati1 = np.loadtxt('punti_1.dat')
dati2 = np.loadtxt('punti_2.dat')
dati3 = np.loadtxt('punti_3.dat')

#primo istogramma ---------------------------------------------------------------------------------------
h_1, bin_egdes_1, _ = plt.hist(dati1, bins='auto', edgecolor='purple', color='purple', density=True)

#sezione di creazione della funzione da sovrapporre
x_1 = np.linspace(min(bin_egdes_1), max(bin_egdes_1), 1000)
y_1 = f(x_1)
a_1 = np.trapz(y_1,x_1)
y_1 = y_1 / a_1
#opzioni aggiuntive del grafico
plt.plot(x_1,y_1, 'r-', label='f')
plt.xlabel('valore')
plt.ylabel('densità')
plt.title('dist exp')
plt.legend()

#secondo istogramma --------------------------------------------------------------------------------------
plt.figure()
h_2, bin_egdes_2, _ = plt.hist(dati2, bins='auto', edgecolor='purple', color='purple', density=True)

#sezione di creazione della funzione da sovrapporre
x_2 = np.linspace(min(bin_egdes_2), max(bin_egdes_2), 1000)
y_2 = f(x_2)
a_2 = np.trapz(y_2,x_2)
y_2 = y_2 / a_2

#opzioni aggiuntive del grafico
plt.plot(x_2,y_2, 'r-', label='f')
plt.xlabel('valore ')
plt.ylabel('densità')
plt.title('dist exp')
plt.legend()

#terzo istogramma ----------------------------------------------------------------------------------------
plt.figure()
h_3, bin_egdes_3, _ = plt.hist(dati3, bins='auto', edgecolor='purple', color='purple', density=True)

#sezione di creazione della funzione da sovrapporre
x_3 = np.linspace(min(bin_egdes_3), max(bin_egdes_3), 1000)
y_3 = g(x_3)
a_3 = np.trapz(y_3,x_3)
y_3 = y_3 / a_3

#opzioni aggiuntive del grafico
plt.plot(x_3,y_3, 'r-', label='g')
plt.xlabel('valore ')
plt.ylabel('densità')
plt.title('dist xexp(-x^2)')
plt.legend()

plt.show()