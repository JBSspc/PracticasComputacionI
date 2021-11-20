# SOFÍA PALACIOS CUEVAS | 19 NOV 2021 | PRÁCTICA GJ-Python

# Importamos la librería NumPy
import numpy as np
# Importamos sys para salir del programa cuando se divida entre 0
import sys

# Pedimos al usuario que ingrese el número de variables
v = int(input('Número de ecuaciones: '))

# Hacemos un arreglo (matriz) de v x v + 1
# v + 1 --> # columnas = # variables + 1 (columna de solución)
# La inicializamos en 0 con np.zeros
z = np.zeros((v,v + 1))

# Hacemos un arrglo para la solución
# Tamaño: n x 1 (para que sea vector columna) #no salió :(
# Lo inicializamos en 0
x = np.zeros((v , 1))

# Pedimos al usuario los coef. de la matriz aumentada
print('\nCoeficientes de la matriz aumentada: ')
for i in range(v):
  for j in range(v + 1):
    z [i][j] = float(input('Valor elemento [' + str(i) +'][' + str(j) + ']: '))

# Método de Gauss Jordan
for i in range(v):
  if z[i][j] == 0.0:
    sys.exit('Alto! Divides entre 0!')
  for j in range(v):
    if i != j:
      r = z[j][i] / z[i][i]
      for k in range (v + 1):
        z[j][k] = z[j][k] - r * z[i][k]

# Para la solución
for i in range (v):
  x[i] = z[i][v] / z[i][i]

# Mostrar la solución en consola
print('\nSolución: ')
for i in range(v):
  print('X%d = %0.2f' %(i, x[i]), end = '\t')