#from matplotlib.pyplot import imread, imsave, imshow, show
#import numpy as np
#import scipy.ndimage as ni
#from matplotlib import cm
##wyswietlanie obrazu musi byc show()
#img = imread('logo.png')
#imshow(img)
#show()

##negatyw obrazu - zad1

#img = np.abs(img - 1.0)
#imshow(img)
#show()
#imsave('logoN.png', img) # <-- zapis do nowego pliku

##zad 2
#img = imread('logo.png')

#def toGray(rgb):
#    r, g, b =rgb[:,:,0], rgb[:,:,1], rgb[:,:,2]
#    gray = 0.2989*r+0.587*g+0.114*b
#    return gray

#img = toGray(img)   #na szaro

#img = img[:,0:len(img)] #wyciecie kawalku
#img -=70/255            # przyciemnienie
#img[img<0] = 0          # zamiana minusowych wartosci na 0

#img = ni.rotate(img, 45)    #obrot obrazu o 45 stopni

#imshow(img, cmap = cm.gray)
#show()

#imsave('logol.png', img, cmap = cm.gray)

from scipy.optimize import minimize
from scipy import integrate
import math as m
#def f (X):
#    x1, x2 = X
#    return x1**2 + x2**3
#res = minimize(f, x0=[2, 3], tol=1e-6, method='Nelder-Mead')
#print(res)

#nie dziala
#def f(x):
#    x1, x2 = x
#    return ((x1+2*x2-7)**2)+((2*x1+x**2-5)**2)
#res = minimize(f, x0=[-10, -10], tol = 1e-6, method='SLSQP', bounds =[[-10,-10],[10,10]]) 
#print(res)

# zad6
#def f(x1,x2):
#    return x1**2+x2**3
#print(integrate.nquad(f,[[0,3],[3,8]]))

#def f1(x1,x2):
#    return m.exp(x1+2*x2)
#print(integrate.nquad(f1,[[0,1],[0,1]]))

#def f2(x1,x2):
#    return x1+(x2**2)*x1
#print(integrate.nquad(f2,[[0,2],[2,3]]))

#def f3(x1,x2):
#    return (x1*m.sin(x1))+(6*(x2**2))
#print(integrate.nquad(f3,[[0,2],[0,m.pi]]))

from scipy import interpolate

#x = [2, 3, 4, 7]
#y = [1 ,3, 2, -5]
#f = interpolate.interp1d(x ,y, kind = 'cubic')
#print(f(5))
#print(f([5,6]))

#zad 8

godz = [7, 10, 11, 15, 19]
temp = [7, 12, 13, 15, 13]
f = interpolate.interp1d(godz ,temp, kind = 'cubic')

print(f(9.75))
print(f(12.1))
print(f(17))