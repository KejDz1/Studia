import numpy as np
import collections as c


def zad1(rozmiar):
    A = np.ones((rozmiar,rozmiar))
    liczba = 0

    for r in range(0,len(A)):
        i = 0
        liczba += 1
        for c in range(0, len(A[0])):
            A[r,c] = liczba**i
            i += 1
    return A

print(zad1(3))

#zad2 lub 3
def zad2(n):
    A = np.zeros((n,n))

    for i in range(A.shape(0)):
        tmp=np.array(range(n*i+1, n*(i+1)+1))
        if (i%2 == 0):
            A[i,:] = tmp
        else:
            A[i,:] = tmp[:, -1]
    return A
#zad4
B=zad2(4)
B[(A%5==0) | (A%3==0)] = 0
print(B)

#zad5
graf={1:[2,4,6], 2:[3], 3:[], 4:[], 5:[4,5], 6:[3]}
macierz= np.zeros((len(graf), len(graf)))
for key in graf:
    for ind in graf[key]:
        graf[key-1, ind-1]=1

#wyzej macierz przyleglosci, nizej macierz incydencji

macierz2 = np.zeros(6, 7)
krawedz = 0

for key in graf:
    for ind in graf[key]:
        graf[key-1, ind-1]=1
        graf[key-1, krawedz]=-1
        graf[ind-1, krawedz]=0
        if key==ind:
            macierz2[key-1, krawedz] = 2
        krawedz =+1


