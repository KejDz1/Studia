import numpy as np

#zad1
#dane = np.loadtxt('irisP.txt', delimiter = ',', usecols=(3,4), dtype = [('szerokosc_platka', 'float'), ('class', 'bytes', 17)])

#setosa = dane['class'] == b'Iris-setosa'
#versicolor = dane['class'] == b'Iris-versicolor'
#virginica = dane['class'] == b'Iris-virginica'

#print('Iris-setosa: ',dane['szerokosc_platka'][setosa].mean())
#print('Iris-versicolor: ',dane['szerokosc_platka'][versicolor].mean())
#print('Iris-virginica: ',dane['szerokosc_platka'][virginica].mean())

#zad2

#dane2 = np.genfromtxt('irisP2.txt', skip_header = 1, missing_values = '?', filling_values = -100, delimiter = ',', usecols = (2,4), dtype = [('dlugosc_platka', 'float'), ('class', 'bytes', 17)])
#print(dane2)

## //////////////////setosa////////////////////
#setosa = (dane2['class'] == b'Iris-setosa') & (dane2['dlugosc_platka'] != -100)
#srednia = dane2['dlugosc_platka'][setosa].mean() 

#setosa2 = (dane2['class'] == b'Iris-setosa') & (dane2['dlugosc_platka'] == -100)
#dane2['dlugosc_platka'][setosa2] = np.round(srednia,1)
## ///////////////////versicolor///////////////////
#versicolor = (dane2['class'] == b'Iris-versicolor') & (dane2['dlugosc_platka'] != -100)
#srednia2 = dane2['dlugosc_platka'][versicolor].mean() 

#versicolor2 = (dane2['class'] == b'Iris-versicolor') & (dane2['dlugosc_platka'] == -100)
#dane2['dlugosc_platka'][versicolor2] = np.round(srednia2,1)
## ////////////////////virginica//////////////////
#virginica = (dane2['class'] == b'Iris-virginica') & (dane2['dlugosc_platka'] != -100)
#srednia3 = dane2['dlugosc_platka'][virginica].mean() 

#virginica2 = (dane2['class'] == b'Iris-virginica') & (dane2['dlugosc_platka'] == -100)
#dane2['dlugosc_platka'][virginica2] = np.round(srednia3,1)

#print(dane2)

#zad3

#Data = np.loadtxt('contact-lenses.txt', delimiter = ',', dtype = [('age', 'bytes', 14), ('spectacle-prescrip', 'bytes', 12),  ('astigmatism', 'bytes', 5), ('tear-prod-rate', 'bytes', 7), ('contact-lenses', 'bytes', 4)])

#Data['age'] = np.char.upper(Data['age'])
#Data['spectacle-prescrip'] = np.char.upper(Data['spectacle-prescrip'])
#Data['astigmatism'] = np.char.upper(Data['astigmatism'])
#Data['tear-prod-rate'] = np.char.upper(Data['tear-prod-rate'])
#Data['contact-lenses'] = np.char.upper(Data['contact-lenses'])

 

#Data['astigmatism'] = np.char.replace(Data['astigmatism'], b'NO', b'FALSE')
#Data['astigmatism'] = np.char.replace(Data['astigmatism'], b'YES', b'TRUE')
##a_no = Data['astigmatism'] == b'NO'
##Data['astigmatism'][a_no] = b'FALSE'
##a_yes = Data['astigmatism'] == b'YES'
##Data['astigmatism'][a_yes] = b'TRUE'

#np.savetxt('contact-lenses-res.txt', Data, delimiter = ',', fmt='%s')

#zad4

Data = np.loadtxt('irisP.txt', delimiter = ',', dtype = [('sepallength', 'float'), ('sepalwidth', 'float'), ('petallength', 'float'), ('petalwidth', 'float'),('class', 'bytes', 17)])
Data['class'] = np.char.replace(Data['class'], b'Iris-', b'')
np.savetxt('iris-res.txt', Data, fmt='%.1f,%.1f,%.1f,%.1f,%s')