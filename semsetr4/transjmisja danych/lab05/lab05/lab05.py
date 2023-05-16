import numpy as np
import matplotlib.pyplot as plt


B = 20
Tc = 1
Tb = Tc/B
W = 2
A1 = 2
A2 = 10
fn = W * Tb**(-1)

fs = 200
fn1 = (W+1)/Tb
fn2 = (W+2)/Tb

N = Tc * fs
n = np.arange(0, B, 1)


t=n/fs

A = 1


# |XXXXXX| ASK, PSK, FSK - z poprzednich labów |XXXXXX|

def toBinary(string):
    binary = ''
    for i in string:
        ascii1 = ord(i) # ord() zwraca liczbowy kod Unicode dla pojedynczego znaku
        if ascii1 >= 32 and ascii1 <= 127:
            binary += bin(ascii1)[2:] #[2:] <-- poniewa¿ pomijamy dwa pierwsze znaki które wskazuj¹ na system zapisu binarnego
    return binary

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

slowo = toBinary('ABC')

ask = kluczASK(slowo)
psk = kluczPSK(slowo)
fsk = kluczFSK(slowo)

#|XXXXXX| Zadania z lab5 |XXXXXX| 
#h wybierasz recznie


#zad1
#|XXXXXX| ASK |XXXXXX|
def demodulatorASK(zt):
    summary = []
    xt = []
    for i in range(int(N)):
        T = i/fs
        xt.append(zt[i]*A*np.sin(2*np.pi*fn*T))

    pt = np.zeros(N)
    frag = 0
    frag1 = int(N/B)
    frag2 = frag1
    for i in range(B):
        for j in range(frag, frag1):
            pt[j] = sum(xt[frag:j])
        frag = frag1+1 
        frag1 += frag2

    h =  int(max(pt)/3)

    ct = []

    for i in range(B):
        if (pt[i] > h):
            ct.append(1)
        else:
            ct.append(0)

    summary.append(zt)
    summary.append(xt)
    summary.append(pt)
    summary.append(ct)

    return summary

#|XXXXXX| PSK |XXXXXX|
def demodulatorPSK(zt):
    summary = []
    xt = []
    for i in range(int(N)):
        T = i/fs
        xt.append(zt[i]*A*np.sin(2*np.pi*fn*T))

    pt = np.zeros(N)
    frag = 0
    frag1 = int(N/B)
    frag2 = frag1
    for i in range(B):
        for j in range(frag, frag1):
            pt[j] = sum(xt[frag:j])
        frag = frag1+1 
        frag1 += frag2


    ct = []

    for i in range(B):
        if (pt[i] < 0):
            ct.append(1)
        else:
            ct.append(0)

    summary.append(zt)
    summary.append(xt)
    summary.append(pt)
    summary.append(ct)

    return summary

#|XXXXXX| FSK |XXXXXX|
def demodulatorFSK(zt):
    summary = []
    x1t = []
    x2t = []
    for i in range(int(N)):
        T = i/fs
        x1t.append(zt[i]*A1*np.sin(2*np.pi*fn1*T))
        x2t.append(zt[i]*A2*np.sin(2*np.pi*fn2*T))

    p1t = np.zeros(N)
    p2t = np.zeros(N)
    frag = 0
    frag1 = int(N/B)
    frag2 = frag1
    for i in range(B):
        for j in range(frag, frag1):
            p1t[j] = sum(x1t[frag:j])
            p2t[j] = sum(x2t[frag:j])
        frag = frag1+1 
        frag1 += frag2
    p1t_ujemne = list(map(lambda x: -x, p1t))  #dodanie minusa przed ka¿d¹ wartoœæ
    pt = [a + b for a, b in zip(p1t_ujemne, p2t)]  #zsumowanie dwóch list
   
    ct = []

    for i in range(B):
        if (pt[i] > 0):
            ct.append(1)
        else:
            ct.append(0)

    summary.append(zt)
    summary.append(x1t)
    summary.append(x2t)
    summary.append(p1t)
    summary.append(p2t)
    summary.append(ct)

    return summary

#zad2
def rysuj(sygnal, x = 0):
    sygnaly = ['z(t)', 'x(t)', 'p(t)', 'c(t)']
    sygnaly2 = ['z(t)', 'x1(t)', 'x2(t)', 'p1(t)', 'p2(t)', 'c(t)']
    for i in range(len(sygnal)):
        plt.plot(sygnal[i])
        if (x == 1):
            plt.title(sygnaly2[i])
            plt.xlabel('Czestotliwosc [Hz]')
            plt.ylabel('Amplituda [dB]')
        else:
            plt.title(sygnaly[i])
            plt.xlabel('Czestotliwosc [Hz]')
            plt.ylabel('Amplituda [dB]')
        plt.show()

#plotowanie ask
demoASK=demodulatorASK(ask)
rysuj(demoASK)

#plotowanie psk
demoPSK=demodulatorPSK(psk)
rysuj(demoPSK)

#plotowanie fsk
demoFSK=demodulatorFSK(fsk)
rysuj(demoFSK, x = 1)

#zad3
def toBits(signal):
    binary = toBinary(''.join(map(str, signal))) # ³¹czy ci¹g wartoœci 0 i 1 w jeden string, a nastêpnie konwertuje na ci¹g bitów
    return binary

print(toBits(demoASK[3]))