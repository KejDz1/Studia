#class Power:
#    def __init__(self, power):
#        self.__power = power
#    def __call__(self, bae):
#        return bae ** self.__power

#poweroftwo = Power(2)
#print(poweroftwo(3))



#class NewRange:
#    def __init__(self, a, b):
#        self.__current = a
#        self.__min = a
#        self.__max = b
#    def __iter__(self):
#        self.__current = self.__min
#        return self
#    def __next__(self):
#        if self.__current > self.__max:
#            raise StopIteration
#        else:
#            self.__current+=1
#        return self.__current-1
#for i in NewRange(2, 5):
#    print(i)
#def NewRange2(a, b):
#    c = a
#    while c <= b:
#        yield c
#        c += 1
#for i in NewRange2(2, 5):
#    print(i)

#wejsciowka!!!!!!!!
#klasa abstrakcyjna, wlasciwosci, generator albo to drugie
#l = [i for i in range(2, 100)]
#g = [i for i in range(2, 100)]

#for i in g:
#    print(i)

#for i in reversed(g):
#    print(i)

#__len__(self):
#    return n
#__reversed__(self):
#__getitem__(self):
#__setitem__(self):

#zad1

#class Power:
#    def __init__(self, a = 0):
#        self.__a = a
#    def __call__(self, b):
#        wynik = b ** self.__a
#        self.__a+=1
#        return wynik
#power1=Power()
#for i in range(10):
#    print(power1(2))


#zad2

#def Powers(mini, maxi, base):
#    while mini <= maxi:
#        yield base**mini
#        mini +=1
#for i in Powers(2, 6, 2):
#    print(i)
    
#zad3

from pickle import FALSE


class DList:
    class Element:
        def __init__(self, value, next = None, prev = None):
            self.__value = value
            self.next = None
            self.prev = None

        @property
        def value(self):
            return self.__value

    def __init__(self, args):
        self.__root = None
        self.__end = None
        for i in args:
            self.insert(i)

    def insert(self, value):
        # - przypadek, gdy lista jest pusta
        # - przypadek, gdy trzeba przeiterowac szukajac 
        # wiekszego elementu i wstawic przed nim
        # - przypadek, gdy wstawiamy na koncu
        elem = DList.Element(value)
        if self.__root is None:
            self.__root = elem
            self.__end = elem
        else:
            if self.__root.value > value:
                self.__root.prev = elem
                elem.next = self.__root
                self.__root = elem
            elif self.__end.value < value:
                self.__end.next = elem
                elem.prev = self.__end
                self.end = elem
            else:
                current = self.__root
                while(current.value < value):
                    current = current.next
                current.prev.next = elem
                elem.prev = current.prev
                elem.next = current
                current.prev = elem
        pass

    def __iter__(self):
        curr = self.__root
        while not (curr is None):
            yield curr.value
            curr = curr.next

    def __reversed__(self):
        current = self.__end
        while not (current is None):
            yield current.value
            current = current.prev
        pass

    def __contains__(self, value):
        # przebiega po liscie az trafi 
        # na rowny lub wiekszy elemnet
        # jesli wiekszy lub koniec listy
        # zwraca false
        if value > self.end.value:
            return False
        current = self.__root
        while(current.value < value):
            current = current.next
            if current.value == value:
                return True
        pass

#----------------- TESTY -----------------
dlista = DList([2, 3, 4, 5])
for i in dlista:
    print(i)
print('\n--------\n')

dlista = DList([8, 10, 9, 13])
dlista.insert(7)
dlista.insert(12)
dlista.insert(15)
for i in reversed(dlista):
    print(i)

print('\n--------\n')
print('Contain 8:', 8 in dlista)
print('Contain 13:', 13 in dlista)
print('Contain 15:', 15 in dlista)
print('Contain 6:', 6 in dlista)
print('Contain 11:', 11 in dlista)
print('Contain 17:', 17 in dlista)





