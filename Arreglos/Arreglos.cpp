/*/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
author: SOFIA PALACIOS CUEVAS
e-mail: sofiapalacioscuevas@comunidad.unam.mx
  date: 21 SEP 2021
//////////////////////////////////////////////////// PRACTICA 4. ARREGLOS /////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////// COMPUTACION I UNAM-EJ ///////////////////////////////////////////////////////////////////*/

#include <iostream>
#include <array>

#define LEN 3 //Número de elementos en los arreglos

// Añadir std para fácil llamado de funciones
using namespace std;

// Declaración de funciones
void ImprimirArreglo(array<float, LEN> arreglo);
array<float, LEN> LlenarArreglo(void);
array<float, LEN> MultiplicarArreglo(array<float, LEN> arreglo, float multiplo);
array<float, LEN> SumarArreglos(array<float, LEN> arr1, array<float, LEN> arr2);

int main()
{
    char decision;
    array<float, LEN> arr = { 0 }; // Inicializamos el arreglo con ceros como buena práctica
    arr = LlenarArreglo(); // Solicitamos al usuario que llene un arreglo y lo asignamos a nuestro arreglo principal
    cout << "Operacion: "; // We removed the accent
    cin >> decision;
    // Si la operación no es '+' de suma, o '*' de multiplicación, seguimos preguntando al usuario.
    while (decision != '+' && decision != '*')
    {
        cout << "Operacion: "; // We removed the accent
        cin >> decision;
    }
    // Si se ingresa la multiplicación
    if (decision == '*') {
        float factor;
        cout << "Factor: ";
        cin >> factor;  // Pedimos el factor a multiplicar
        arr = MultiplicarArreglo(arr, factor); // Multiplicamos nuestro arreglo principal por el factor y el resultado lo asignamos a nuestro arreglo principal.
    }
    // Si se ingresa la suma
    else if (decision == '+') {
        array<float, LEN> arr2 = {0}; // Creamos el segundo arreglo y lo inicializamos en ceros
        arr2 = LlenarArreglo(); // Pedimos al usuario que llene otro arreglo y lo asignamos a nuetsro nuevo arreglo
        arr = SumarArreglos(arr, arr2); // Sumamos ambos arreglos elemento a elemento, y reasignamos el resutlado a nuestro arreglo principal
    }
    cout << "Resultado: ";
    ImprimirArreglo(arr); // Imprimimos el resultado de la operación sobre el arreglo principal
    return 0; // Indicamos que salimos del programa con éxito
}

// Imprime los elementos del arreglo 'arreglo' separando cada elemento con un espacio en blanco
void ImprimirArreglo(array<float, LEN> arreglo)
{
    for (int i = 0; i < LEN; i++)
        cout << arreglo[i] << ' ';
    cout << '\n';
}

// Llena un arreglo de tamaño LEN y lo "regresa" como resultado
array<float, LEN> LlenarArreglo()
{
    array<float, LEN> arreglo {0}; // We declare 'arreglo' and start it in 0
    for (int i = 0; i < arreglo.size(); i++){ //we want i to be smaller than the size of 'arreglo' array
        cout << " Valor elemento [" << i << "]: "; // to show and input each element of the array
        cin >> arreglo[i];
    }
    return arreglo;
}

// Multiplica cada elemento del arreglo 'arreglo' por el factor 'mult'
array<float, LEN> MultiplicarArreglo(array<float, LEN> arreglo, float multiplo)
{
    for(int i = 0; i < arreglo.size(); i++){
        arreglo[i] *= multiplo; // we combine * & asignation
    }
    return arreglo;
}

// Suma elemento a elemento los arreglos 'arr1' y 'arr2' y regresa el arreglo resultante
array<float, LEN> SumarArreglos(array<float, LEN> arr1, array<float, LEN> arr2)
{
    array<float, LEN> arreglo {0}; // We have to declare 'arreglo' because it is not shown above // we start it on 0
    for(int i = 0; i < arreglo.size(); i++){
        arreglo[i] = arr1[i] + arr2[i]; // Can't be done with +=; 'case returns only arr2
    }
    return arreglo;
}