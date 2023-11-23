import numpy as np
from scipy.optimize import curve_fit
from scipy.stats import norm
import matplotlib.pyplot as plt

def f(x) :
    return np.cos(x + 3./2.*np.pi)


dati = np.loadtxt('evol.dat')

x = dati[:, 0]
y = dati[:, 1]

a = np.linspace (0, 10, 1000)
b = f(a)


plt.scatter(x, y, marker='.', color= 'purple', s=6, label='x' )
plt.plot(a,b, label='f')


plt.xlabel('t')
plt.ylabel('x')

plt.legend()
plt.show()

