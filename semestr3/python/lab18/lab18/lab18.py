

import matplotlib.pyplot as plt
import numpy as np

#x = np.linspace(-5,5,100)
#y1=np.sin(x)
#y2=np.cos(x)
#plt.plot(x,y1,'r-', label='sin')
#plt.plot(x,y2,'g-', label='cos')
#plt.legend(loc='upper left', frameon=True)
#plt.xticks([-3.14,0,3.14],[r'$\-pi$','0',r'$\pi$'])

#plt.show()

#zad1 wykres liniowy
#x=np.linspace(-3.14,3.14,128)
#f1=np.cos(x)
#f2=np.sign(x)

#plt.plot(x,f1,'k-', label='cosx')
#plt.plot(x,f2,'r-', label ='signx')

#plt.legend(loc='upper left', frameon=True)
#plt.xticks([-np.pi,-np.pi/2,0,np.pi/2,np.pi], [r'$-\pi$',r'$-\frac{\pi}{2}$','0',r'$\frac{\pi}{2}$',r'$\pi$'])
#plt.yticks([-1,0,1])
#plt.show()
#plt.savefig("wykresZad1.png",dpi=None,dacecolor='w',edgecolor='w')

#do zad2
from mpl_toolkits.mplot3d import Axes3D
from matplotlib import cm

#fig = plt.figure()
#ax = fig.gca(projection = '3d')
#x=np.arange(1,5,0.5)
#y=np.arange(1,5,0.5)
#X,Y = np.meshgrid(x,y)
#Z = np.sin(X)*np.sin(Y)
#ax.plot_surface(X,Y,Z, cmap = cm.coolwarm)
#plt.show()

#zad2 wykres 3D

#fig = plt.figure()
#ax = fig.gca(projection = '3d')

#x=np.arange(-5,5,0.25)
#y=np.arange(-5,5,0.25)
#X,Y = np.meshgrid(x,y)
#Z = np.sin(X)*np.cos(Y-1)
#ax.plot_surface(X,Y,Z, cmap = cm.coolwarm)
#plt.show()

#do zad3
#subplot
#x=np.linspace(-5,5,100)
#plt.subplot(3,3,(1,3)) #podluzny wykres 1x3
#plt.plot(x,np.sin(x))
#plt.subplot(3,3,(4,7)) #podluzny 2x1
#plt.plot(x, np.cos(x))
#plt.subplot(3,3,5)
#plt.plot(x, np.tan(x))
#plt.show()

#axes
##zeby okno zaczynalo sie od 10% od brzegu to: i pozniej szerokosc oraz wysokosc
#x=np.linspace(-5,5,100)
#plt.axes([0.1,0.1,0.8,0.3])
#plt.plot(x, np.sin(x))
#plt.axes([0.1,0.5,0.7,0.2])
#plt.plot(x, np.cos(x))
#plt.show()
#zad3

#x=np.linspace(-np.pi,np.pi,128)

#plt.axes([0.1,0.1,0.8,0.8])
#plt.plot(x,np.sin(10*x))
#plt.ylim([-1,3])
#plt.xlim([-3,3])
#plt.axes([0.25,0.65,0.5,0.2])
#plt.plot(x, np.sin(10*x))
#plt.ylim([-1,1])
#plt.xlim([-3,3])
#plt.show()

#zad4
#x = np.random.normal(0,1,1024)
#y = np.random.normal(0,1,1024)

#cl=(np.round(x)+np.round(y))%2

##mapa bwr

#plt.scatter(x, y, c=cl, s= 75, alpha = 0.5, cmap='bwr')
#plt.xlim(-1.5,1.5)
#plt.ylim(-1.5,1.5)
#plt.show()

#zad5
data = np.loadtxt('hist.txt', delimiter=',')
oceny = np.arange(1.5,6.0,0.5)
plt.hist(data[:,1], bins=oceny, label='oceny', align = 'left', rwidth = 0.7, color = 'green')
plt.ylabel('oceny')
plt.xlabel('Liczba ocen')
plt.show()