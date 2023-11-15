import numpy as np
from scipy.optimize import curve_fit
import matplotlib.pyplot as plt

def f(x, a) :
    return a/np.sqrt(x)

rawdata = np.loadtxt("integrale_1.dat")

x = rawdata[:, 0]
y_hm = rawdata[:, 1]
y_mc = rawdata[:, 2]

a, covarianza_hm = curve_fit(f, x, y_hm)
y_fit_hm = f(x, a)


#x_f = np.linspace(1000, 99000)
#y_f = f(x_f)
#plt.plot(x_f, y_f, color='blue', label='f')


plt.scatter(x, y_hm, marker='.', color= 'purple', s=5, label='hit or miss' )
#plt.plot(x, y_hm, color= 'purple', label='hit or miss' )

plt.plot(x, y_fit_hm, color='blue', label='f')

plt.xlabel('N')
plt.ylabel('deviazione dal valore vero')
plt.yscale('log')
plt.xscale('log')
plt.legend()

plt.figure()
plt.scatter(x, y_mc, marker='.', color= 'red', s=5, label='monte carlo' )
#plt.plot(x, y_mc, color= 'red',  label='monte carlo' )

b, covarianza_mc = curve_fit(f, x, y_mc)
y_fit_mc = f(x, a)
plt.plot(x, y_fit_mc, color='blue', label='f')

plt.xlabel('N')
plt.ylabel('deviazione dal valore vero')
plt.yscale('log')
plt.xscale('log')
plt.legend()

plt.show()
