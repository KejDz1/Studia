import numpy as np
import matplotlib.pyplot as plt

Tc = 1
fs = 22050
N = Tc * fs
n = np.arange(0, N-1)
Ts = 1/fs

t = n/fs
f = 20000


x = np.sin(np.pi* (f/4) * t ) + np.sin(1.4*np.pi * f * t) - np.cos(0.3*np.pi * f * t)


y = (x * (t**3))/3
z = 1.92 * (np.cos(3*np.pi * (t/2)) + np.cos((y**2)/((8*x+3)*t)))
v = ((y*z)/(x+2)) * np.cos(7.2*np.pi * t) + np.sin(np.pi * t**2)

#zadanie 4 - funkcja nr 1
b1 = 0
b2 = 0
b3 = 0

h = 1
#dla H1= 5
for i in range(1, 5):
    b1 = b1 + (((-1)**h)/h)*np.sin(h*np.pi*2*t)
    h=h+1
b1 = b1*(2/np.pi)

#dla H2= 20
h=1
for i in range(1, 20):
    b2 = b2 + (((-1)**h)/h)*np.sin(h*np.pi*2*t)
    h=h+1
b2 = b2*(2/np.pi)

#dla H3=50
h=1
for i in range(1, 50):
    b3 = b3 + (((-1)**h)/h)*np.sin(h*np.pi*2*t)
    h=h+1
b3 = b3*(2/np.pi)


plt.title("b1(t)   H1 = 5")
plt.xlabel("Probki")
plt.ylabel("Amplituda")
plt.plot(b1)
plt.show()

plt.title("b2(t)   H2 = 20")
plt.xlabel("Probki")
plt.ylabel("Amplituda")
plt.plot(b2)
plt.show()

plt.title("b3(t)   H3 = 50")
plt.xlabel("Probki")
plt.ylabel("Amplituda")
plt.plot(b3)
plt.show()

