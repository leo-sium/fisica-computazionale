import numpy as np
from scipy.optimize import curve_fit
from scipy.stats import norm
import matplotlib.pyplot as plt

def f(x, media, dev):
    return norm.pdf(x, media, dev)

dati = np.loadtxt('punti.dat')

dati_unif = dati[:, 0]
dati_mon = dati [:, 1]

h_unif, bin_edges_unif, _ = plt.hist(dati_unif, bins='auto', edgecolor='green', color='green', density=True)

#al posto del fit uso i parametri calcolati dai dati e metto quelli nella funzione, così controllo nel caso, se li calcolo da qua, se le altre son giuste
par, covarianza = curve_fit(f, bin_edges_unif[:-1], h_unif, p0=[0,1])
media, dev = par
x_fit = np.linspace(min(bin_edges_unif), max(bin_edges_unif), 100)
y_fit = f(x_fit, media, dev)
plt.plot(x_fit, y_fit, color='blue', label=f'fit - Media {media:.2f}, Dev_std:{dev:.2f}')


plt.xlabel('valore')
plt.ylabel('densità')
plt.title('dist exp')
plt.legend()

plt.figure()

h_mon, bin_edges_mon, _ = plt.hist(dati_mon, bins=100, edgecolor='green', color='green', density=True)



plt.xlabel('valore')
plt.ylabel('densità')
plt.title('dist exp')
#plt.legend()

plt.show()