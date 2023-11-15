import numpy as np
from scipy.optimize import curve_fit
from scipy.stats import norm
import matplotlib.pyplot as plt

dati = np.loadtxt('punti.dat')

h, bin_edges, _ = plt.hist(dati, bins='auto', edgecolor='green', color='green', density=True)

plt.xlabel('valore')
plt.ylabel('densità')
plt.title('dist gauss')

plt.show()