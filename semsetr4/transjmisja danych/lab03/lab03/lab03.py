import numpy as np
import matplotlib.pyplot as plt

# fn >> fm
fm = 2
fn = fm**12

Tc = 1
Fs = 2*fn
N = Tc * Fs

def genM():
    m = []
    for t in range(N):
        m.append(np.sin(2*np.pi*fm*t))
    return m

#sygna³ zmodulowany amplitudowo
def genZa(m, ka):
    za = []
    for t in range(N):
        za.append((ka*m[t]+1)*np.cos(2*np.pi*fn*t))
    return za

#sygna³ zmodulowany k¹towo
#modulacja fazy
def genZp(m, kp):
    zp = []
    for t in range(N):
        zp.append(np.cos(2*np.pi*fn*t+kp*m[t]))
    return zp

#modulacja czêstotliwoœci
def genZf(m, kf):
    zf = []
    for t in range(N):
        zf.append(np.cos(2*np.pi*fn*t+(kf/fm)*m[t]))
    return zf

def generuj(ka, kp, kf):
    sygnal = genM()
    za = genZa(sygnal, ka)
    zp = genZp(sygnal, kp)
    zf = genZf(sygnal, kf)
    wynik=[]
    wynik.append(za)
    wynik.append(zp)
    wynik.append(zf)

    return wynik
#zadanie 1

#a)
aKa = 0.9
aKp = 0.05
aKf = 0.2
sygnalModA = generuj(aKa, aKp, aKf)

#b)
bKa = 10
bKp = 2
bKf = 1
sygnalModB = generuj(bKa, bKp, bKf)

#c)
cKa = 25
cKp = 10
cKf = 15
sygnalModC = generuj (cKa, cKp, cKf)

#zadanie 2

#funckja do rysowania wykresów
czestotliwosc = []
def skalaCzest():
    for k in range(0, N):
        czestotliwosc.append(k*(Fs/N))
    return czestotliwosc
skala = skalaCzest()
def rysuj(x):   
    for i in range(3):
        if(x == 'a'):
            fftSygnal = np.abs(np.fft.fft(sygnalModA[i]))/N
        elif(x == 'b'):
            fftSygnal = np.abs(np.fft.fft(sygnalModB[i]))/N
        else:
            fftSygnal = np.abs(np.fft.fft(sygnalModC[i]))/N
        fftWidmo = 20*np.log10(np.abs(fftSygnal)) # <-- widmo
        plt.figure()
        plt.plot(skala, fftWidmo)
        if(i == 0):
            plt.title(x+') '+'Widmo amplitudowe za(t)')
        elif(i == 1):
            plt.title(x+') '+'Widmo amplitudowe zp(t)')
        else:
            plt.title(x+') '+'Widmo amplitudowe zf(t)')
        plt.xlabel('Czestotliwosc [Hz]')
        plt.ylabel('Amplituda [dB]')
        plt.show()
        plt.clf()

#print(sygnalModB[0])
rysuj('a')
rysuj('b')
rysuj('c')