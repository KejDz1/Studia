import numpy as np
import matplotlib.pyplot as plt
import time

Tc = 2
Fs = 10000
N = Tc * Fs
f = 100
x = []
for k in range(int(N)):
    t = k/Fs
    x.append( np.sin(np.pi* (f/4) * t ) + np.sin(1.4*np.pi * f * t) - np.cos(0.3*np.pi * f * t)) #sygna³
#x = np.sin(np.pi* (f/4) * t ) + np.sin(1.4*np.pi * f * t) - np.cos(0.3*np.pi * f * t)
#z = 1.92 * (np.cos(3*np.pi * (t/2)) + np.cos((y**2)/((8*x+3)*t)))
y = []
for k in range(int(N)):
    t = k/Fs
    y.append((x[k]*(t**3))/3)

z = []
for k in range(int(N)):
    t = k/Fs
    if t == 0:
        t=1/Fs
    z.append(1.92 * (np.cos(3*np.pi * (t/2)) + np.cos((y[k]**2)/((8*x[k]+3)*t))))
    #v = ((y*z)/(x+2)) * np.cos(7.2*np.pi * t) + np.sin(np.pi * t**2)
v=[]

for k in range(int(N)):
    t = k/Fs
    if t == 0:
        t=1/Fs
    v.append(((y[k]*z[k])/(x[k]+2)) * np.cos(7.2*np.pi * t) + np.sin(np.pi * t**2))

u=[]
for i in range (int(N)):
    t = i/Fs
    if 0.1 > t and t >= 0:
        u.append( np.sin(6*np.pi * t) * np.cos(5*np.pi * t) )
    elif 0.4 > t and t >= 0.1:
        u.append( -1.1*t * np.cos(41*np.pi * (t**2)))
    elif 0.72 > t and t >= 0.4:
        u.append( t * np.sin(20*(t**4)))
    elif 1 > t and t >= 0.72:
        u.append( 3.3*(t-0.72) * np.cos(27*t+1.3) )

B1=0
B2=0
B3=0
b1 = []
b2 = []
b3 = []
h = 1
#dla H1= 5
for k in range (int(N)):
    t = k/Fs
    for i in range(1, 5):
        B1 = B1 + (((-1)**h)/h)*np.sin(h*np.pi*2*t)
        h=h+1
    B1 = B1*(2/np.pi)
    b1.append(B1)

#dla H2= 20
h=1
for k in range(int(N)):
    t = k/Fs
    for i in range(1, 20):
        B2 = B2 + (((-1)**h)/h)*np.sin(h*np.pi*2*t)
        h=h+1
    B2 = B2*(2/np.pi)
    b2.append(B2)
#dla H3=50
h=1
for k in range(int(N)):
    t = k/Fs
    for i in range(1, 50):
        B3 = B3 + (((-1)**h)/h)*np.sin(h*np.pi*2*t)
        h=h+1
    B3 = B3*(2/np.pi)
    b3.append(B3)
#zad1
def dft(x):
    summary = []
    for k in range(N):
        Re = 0
        Im = 0
        for i in range(N):
            if i < int(len(x)):
                Re += x[i]*np.cos((-2*np.pi*i*k)/N)
                Im += x[i]*np.sin((-2*np.pi*i*k)/N)
        summary.append([Re,Im])
    return summary

#zad2

#widmo apmplitudowe
widmoWynik = []
def widmo(summary, k):
    widm = np.sqrt(summary[k][0]**2 + summary[k][1]**2)
    widmoWynik.append(widm)
    return widmoWynik

#widmo w skali decybelowej
widmoDecy = []
def skalaDecy(widmoWynik, k):
    widmoDec = 10*np.log10(widmoWynik[k])
    widmoDecy.append(widmoDec)
    return widmoDecy

#skala czêstotliwoœci
czestotliwosc = []
def skalaCzest():
    for k in range(int(N/2)):
        czestotliwosc.append(k*(Fs/N))
    return czestotliwosc

#funckja do rysowania wykresów
def rysuj(a, b):
    summ = dft(a)
    # obliczenia widma sygna³u
    for k in range(int(N/2)):
        widmm= widmo(summ, k)
        skala = skalaDecy(widmm, k)

    # wykres widma w skali decybelowej
    plt.plot(skalaCzest(), skala)
    plt.title('Widmo amplitudowe '+b)
    plt.xlabel('Czestotliwosc [Hz]')
    plt.ylabel('Amplituda [dB]')
    plt.show()


    
#zad3
start = time.time()
rysuj(b3, "b3(t)")
end = time.time()
print("Czas dftX: ", end-start)

start = time.time()
fftX = np.abs(np.fft.fft(b3))
end = time.time()
print("Czas fftX: ", end-start)

#rysuj(y, "y(t)")

#rysuj(v, "v(t)")

#rysuj(u, "u(t)")

#rysuj(b1, "b1(t)")

#rysuj(b2, "b2(t)")

#rysuj(b3, "b3(t)")




