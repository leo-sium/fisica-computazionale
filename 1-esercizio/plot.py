import numpy as np
from scipy.optimize import curve_fit
import matplotlib.pyplot as plt

def f(x):
    ris = 5*np.exp(-x)
    return ris

rawdata = np.loadtxt('datif1.dat')

x = rawdata[:, 0]
y = rawdata[:, 1]


plt.scatter(x, y, marker='.', color= 'purple', s=5, label='dati' )
plt.legend()
#plt.yscale("log")
plt.xscale("log")
plt.show()


"""
plt.plot(x,y)
plt.xlabel('N')
plt.ylabel('valore integrale')
plt.title('urlo del sium')
#plt.show()
plt.savefig('tutorial.png')
"""