import numpy as np
from scipy.optimize import curve_fit
import matplotlib.pyplot as plt

def f(x) :
    ris = np.exp(-x)
    return ris

rawdata = np.loadtxt('punti.dat')

num_bins = 100
h, bin_egdes, _ = plt.hist(rawdata, bins='auto', edgecolor='purple', color='purple', density=True)

x = np.linspace(min(bin_egdes), max(bin_egdes), 1000)
y = f(x)
a = np.trapz(y,x)
y = y / a

plt.plot(x,y, 'r-', label='f')

plt.xlabel('valore')
plt.ylabel('frequenza')
plt.title('dist exp')

plt.show()

