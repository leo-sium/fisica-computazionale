import numpy as np
from scipy.optimize import curve_fit
from scipy.stats import norm
import matplotlib.pyplot as plt

dati = np.loadtxt('punti.dat')

x_eulero = dati[:, 0]
y_eulero = dati[:, 1]

x_rk2 = dati[:, 0]
y_rk2 = dati[:, 2]

x_rk4 = dati[:, 0]
y_rk4 = dati[:, 3]

x_eu2 = dati[:, 0]
y_eu = dati[:, 4]

plt.scatter(x_eulero, y_eulero, marker='.', color= 'purple', s=6, label='eulero' )
#plt.plot(x_eulero,y_eulero, label='eulero')


plt.scatter(x_rk2, y_rk2, marker='.', color= 'green', s=5, label='rk2' )
#plt.plot(x_rk2,y_rk2, label='rk2')


#plt.scatter(x_rk4, y_rk4, marker='.', color= 'red', s=5, label='rk4' )
#plt.plot(x_rk4,y_rk4, label='rk4')

#plt.scatter(x_rk4, y_rk4, marker='.', color= 'red', s=5, label='rk4' )

plt.scatter(x_eu2, y_eu2, marker='x', s=5, label='eu2' )


plt.xlabel('N')
plt.xlabel('theta')
plt.xscale("log")
plt.yscale("log")



plt.legend()
plt.show()




