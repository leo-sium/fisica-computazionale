import numpy as np
from scipy.optimize import curve_fit
from scipy.stats import norm
import matplotlib.pyplot as plt

def f(x) : 
    for a in x :
        if a<1 :
            return a*np.exp(1-a*a)/np.sqrt(np.pi)
        else :
            return 1./np.sqrt(np.pi)

dati = np.loadtxt('punti.dat')


h, bin_edges, _ = plt.hist(dati, bins='auto', edgecolor='green', color='green', density=True)

x = np.linspace(min(bin_edges), max(bin_edges), 1000)
y = f(x)
#b = np.trapz(y,x)
#y = y / b
plt.plot(x,y, 'r-', label='f')




plt.xlabel('valore')
plt.ylabel('densità')
plt.title('dist gauss')

plt.show()