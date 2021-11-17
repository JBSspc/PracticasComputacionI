// Heidy Valdelamar & Sofía Palacios Cuevas
// PROYECTO DE UNIDAD 2 | COMPUTACIÓN I | UNAM - ENES JURIQUILLA
// NOV 15, 2021

/////////////////////// CALCULADORA BIOQUÍMICA /////////////////////

#include <iostream>
#include <cmath> // para log
#include <array> // para arreglos
#include <string> // para cadenas de caracteres

// Headers
#include "PH.h"
#include "Groups.h"

using namespace std; // para simplificar sintaxis

// Declaración de funciones
char AskOp();
void AskPh(float& ph);
Groups CreateGroup(int numGroups);
// plantilla para pedir datos
template <class temp> 
    temp SetDatos (temp a){
        cin >> a;
        return 0;
    }
// plantilla para calcular carga mol. a cierto pH
template <typename groups>
int CalculateCharge(float& ph, groups AllGroups);

// función main
int main(){
    PH myPH; // instancia 'myPH' de la clase 'PH'
    Groups myG; // instnacia 'myG' de la clase Groups
    // Declaración de variables
    const int numGroups = 3;
    float a,b,c, MolPh, GroupPka, GroupCharge, ph;
    float temp1 = 0, temp2 = 0, temp3 = 0;
    int MolCharge;
    char option;
    string MolName, x;
    array<Groups, numGroups> AllGroups;

    // Le pedimos al usuario elegir una opción
    option = AskOp(); // la opción se elige con la fun. AksOp
    switch (option) // Usamos un switch para que eliga
    {
        case '1': // Calcular el pH
            cout << " Ingrese los siguientes datos: " <<endl; 
            // Pedimos los datos necesarios
            cout << "Molaridad de la sustancia agregada: ";
            temp1 = SetDatos<float>(a); 
            cout << "Volumen de la sustancia agregada (L):";
            temp2 = SetDatos<float>(b);
            cout << "Volumen del agua (L):";
            temp3 = SetDatos<float>(c);
             // Calculamos PH
            myPH.CalcularPH(temp1,temp2,temp3);
            break; // fin del case 1
        case '2': // Sustancia Dominante
            cout << "Ingrese los siguientes datos: "<<endl;
            // Pedimos los datos necesarios
            cout << "Constante de acidez de la sustancia (pka): ";
            temp1 = SetDatos<float>(a);
            cout << "pH: ";
            temp2 = SetDatos<float>(b);
            myPH.DominantSus(temp1, temp2); // Obtenemos sus. dominante
            break; // fin del case 2
        case '3': // Punto isoeléctrico
            cout << "Ingrese los siguientes datos: "<<endl;
            // Pedimos los datos necesarios
            cout << "pka1: ";
            temp1 = SetDatos<float>(a);
            cout << "pka2: ";
            temp2 = SetDatos<float>(b);
            myPH.IsoPoint(temp1, temp2); // Obtenemos PI          
            break; // fin del case 3
        case '4': // carga eléctrica
            cout << "Nombre de la molecula: ";
            // Nombramos la molécula
            MolName = SetDatos<string>(x);
            // Pedimos la info. de cada grupo
            for(int i = 0; i < numGroups; i++)
                AllGroups[i] = CreateGroup(i);
            // Pedimos PH de la molecula
            myG.AskPh(MolPh);
            // Calculamos la carga neta de mol. a cierto pH
            int CalcularCargaApH(float& ph, Groups AllGroups);
            break; // fin del case 4
    }
    cout << "Resultado: " << myPH.GetResult() || myG.GetResult() ;
    return 0;
}

char AskOp()
{
  char op;
  do{
    cout << "      Calculadora de Bioquimica      " << endl;
    cout << "-------------------------------------" << endl <<endl;
    cout << "Seleccione un procedimiento" << endl;
    cout << "1 : Calcular pH" << endl;
    cout << "2 : Especie con mayor presencia" << endl;
    cout << "3 : Calcular punto isoelectrico" << endl;
    cout << "4 : Calcular la carga neta de la molécula a un cierto PH"<< endl;
    cout << "Procedimeinto elegido: ";
    cin >> op;
  }while (op != '1' && op !='2' && op !='3' && op !='4');
  return op;
}
