from abc import ABC, abstractmethod
#zad1
class D:
    def __init__(self, a, b):
        self.a = a
        if(b<self.a**4):
            self.__b = b
        else:
            raise ValueError("Niedozwolona wartoœæ!")
    @property
    def b(self):
        return self.__b
    @b.setter
    def b(self, value):
        if(value<self.a**4):
            self.__b = value
        else:
            raise ValueError("Niedozwolona wartoœæ!")

b = D(2,5)
b.b = 8
print(b.a)
print(b.b)

#zad2
class Classifier(ABC):
    @abstractmethod
    def printType(self):
        pass

class AdaBoost(Classifier):

    def printType(self):
        return print("Boosting")

boost=AdaBoost()
boost.printType()

#zad 3
class AddX:
    def __init__(self, x):
        self.__x = x
    
    def __call__(self):
        self.__x *= self.__x
        return self.__x
add=AddX(2)
print(add())





