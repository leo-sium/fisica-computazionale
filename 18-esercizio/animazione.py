import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
from matplotlib.animation import FuncAnimation

dati = np.loadtxt('animazione.dat')

tempo = dati[:, 0]
r1 = dati[:, 1:4]
r2 = dati[:, 4:7]
r3 = dati[:, 7:10]

fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')



def update(frame):

    ax.cla()

    ax.set_xlabel('X')
    ax.set_ylabel('Y')
    ax.set_zlabel('Z')

    ax.set_title(f'Tempo: {tempo[frame]:.2f}')

    ax.plot(r1[:frame+1, 0], r1[:frame+1, 1], r1[:frame+1, 2], color='blue')
    ax.plot(r2[:frame+1, 0], r2[:frame+1, 1], r2[:frame+1, 2], color='red')
    ax.plot(r3[:frame+1, 0], r3[:frame+1, 1], r3[:frame+1, 2], color='green')

    ax.scatter(r1[frame, 0], r1[frame, 1], r1[frame, 2], label='Corpo 1')
    ax.scatter(r2[frame, 0], r2[frame, 1], r2[frame, 2], label='Corpo 2')
    ax.scatter(r3[frame, 0], r3[frame, 1], r3[frame, 2], label='Corpo 3')

    ax.set_xlim(-2, 2)
    ax.set_ylim(-2, 2)
    ax.set_zlim(-2, 2)

    ax.legend()

durata_animazione = tempo[-1] - tempo[0]

numero_totale_frame = len(tempo)

intervallo_animazione = durata_animazione / numero_totale_frame * 100  # Convertito in millisecondi




# Crea l'animazione
animation = FuncAnimation(fig, update, frames=len(tempo), interval=intervallo_animazione)

# Mostra l'animazione
plt.show()
