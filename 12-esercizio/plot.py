import numpy as np
from scipy.optimize import curve_fit
from scipy.stats import norm
import matplotlib.pyplot as plt

#def f(x) : 
#   
#    ris = np.where(x<1, 1./np.sqrt(np.pi), x*np.exp(1-x*x)/np.sqrt(np.pi) )
#    return ris

def f(x) :
    ris = 1./np.sqrt(np.pi)*np.exp(-x*x)
    return ris

dati = np.loadtxt('punti.dat')


h, bin_edges, _ = plt.hist(dati, bins='auto', edgecolor='green', color='green', density=True)

x = np.linspace(min(bin_edges), max(bin_edges), 1000)
y = f(x)
b = np.trapz(y,x)
y = y / b
plt.plot(x,y, 'r-', label='f')




plt.xlabel('valore')
plt.ylabel('densità')
plt.title('dist gauss')

plt.show()