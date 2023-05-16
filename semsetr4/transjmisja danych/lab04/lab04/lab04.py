import numpy as np
import matplotlib.pyplot as plt
#ograniczac wykresy do 10 bitow

B = 10
Tc = 2
Tb = Tc/B
W = 2
A1 = 2
A2 = 10
fn = W * Tb**(-1)

fs = 300
fn1 = (W+1)/Tb
fn2 = (W+2)/Tb

N = Tc * fs
n = np.arange(0, B, 1)


t=n/fs

# zad1
def toBinary(string):
    binary = ''
    for i in string:
        ascii1 = ord(i) # ord() zwraca liczbowy kod Unicode dla pojedynczego znaku
        if ascii1 >= 32 and ascii1 <= 127:
            binary += bin(ascii1)[2:] #[2:] <-- poniewa¿ pomijamy dwa pierwsze znaki które wskazuj¹ na system zapisu binarnego
    return binary

#print(toBinary('A'))
#print(toBinary('B'))
#print(toBinary('AB'))

# zad2

#Kluczowanie:
#ASK
def kluczASK(string):
    zA = []
    Tb=Tc/len(string)
    i=0
    for n in range(int(N)):
        t = n/fs
        if string[i] == '0':
            zA.append(A1*np.sin(2*np.pi*fn*t))
        if string[i]=='1':
            zA.append(A2*np.sin(2*np.pi*fn*t))
        if t>=Tb:
            Tb=Tb+Tc/len(string)
            i=i+1
    return zA

#PSK
def kluczPSK(string):
    zP = []
    Tb=Tc/len(string)
    i=0
    for n in range(int(N)):
        t = n/fs
        if string[i] == '0':
            zP.append(np.sin(2*np.pi*fn*t))
        if string[i] == '1':
            zP.append(np.sin(2*np.pi*fn*t+np.pi))
        if t>=Tb:
            Tb=Tb+Tc/len(string)
            i=i+1
    return zP

#FSK
def kluczFSK(string):
    zF = []
    Tb=Tc/len(string)
    i=0
    for n in range(int(N)):
        t = n/fs
        if string[i] == '0':
            zF.append(np.sin(2*np.pi*fn1*t))
        if string[i] == '1':
            zF.append(np.sin(2*np.pi*fn2*t))
        if t>=Tb:
            Tb=Tb+Tc/len(string)
            i=i+1
    return zF

slowo = toBinary('ABCDE')
#print(slowo)
ask = kluczASK(slowo[:B])
psk = kluczPSK(slowo[:B])
fsk = kluczFSK(slowo[:B])


# zad3
plt.plot(ask)
plt.xlabel("Czas [s]")
plt.ylabel("Amplituda")
plt.title("Przebieg czasowy zA(t)")
plt.show()

plt.plot(psk)
plt.xlabel("Czas [s]")
plt.ylabel("Amplituda")
plt.title("Przebieg czasowy zP(t)")
plt.show()

plt.plot(fsk)
plt.xlabel("Czas [s]")
plt.ylabel("Amplituda")
plt.title("Przebieg czasowy zF(t)")
plt.show()

#zad4 funckje z poprzedniego labu

def widmoWynik(summary):
    widmo = []
    for i in range(0,int(N/2)):
        widm = np.sqrt(summary[i].real**2+summary[i].imag**2)
        widmo.append([widm])
    return widmo

def skalaDecy(widmo):
    return 10*np.log10(widmo)

def skalaCzest():
    czestotliwosc = []
    for k in range(0, int(N/2)):
        czestotliwosc.append(k*(fs/N))
    return czestotliwosc

skala = skalaCzest()

def rysuj(x):   
    if(x == 'a'):
        fft = np.abs(np.fft.fft(kluczASK(slowo)))
    elif(x == 'b'):
        fft = np.abs(np.fft.fft(kluczPSK(slowo)))
    else:
        fft = np.abs(np.fft.fft(kluczFSK(slowo)))
    widmo = widmoWynik(fft)
    amplituda = skalaDecy(widmo)

    if(x == 0):
        plt.title('Widmo amplitudowe za(t)')
    elif(x == 1):
        plt.title('Widmo amplitudowe zp(t)')
    else:
        plt.title('Widmo amplitudowe zf(t)')

    plt.plot(skala, amplituda)
    plt.xlabel('Czestotliwosc [Hz]')
    plt.ylabel('Amplituda [dB]')
    plt.show()

rysuj('a')  #ASK
rysuj('b')  #PSK
rysuj('c')  #FSK

#zad5

def pasmo(amplituda, dB):  
    fmax = np.max(amplituda)
    fmax = fmax - dB
    fmin = np.min(amplituda)
    B = fmax - fmin
    return B

def obliczPasma():
    sygnaly = [kluczASK(slowo), kluczPSK(slowo), kluczFSK(slowo)]
    mod = ["amplitudowo", "fazowo", "czestotliwoscia"]
    dB = [3, 6, 12]
    funckje = ["zA(t)", "zP(t)", "zF(t)"]
    for j in range(3):
        reim = np.abs(np.fft.fft(sygnaly[j]))
        widmo = widmoWynik(reim)
        amplituda = skalaDecy(widmo)
        for k, db in enumerate(dB):
            summary = pasmo(amplituda, db)
            print("Dla sygnal "+funckje[j]+" zmodywikowany "+mod[j]+":")
            print("B"+str(db)+" = "+str(np.abs(summary)))
    print(" ")

obliczPasma()

#wnioski szerokosc pasma wzgledem modulacji; porownanie szerokosci pasm itd