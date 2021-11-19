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
void AskPh(float& ph); // void PedirpH(float& ph);
Groups CreateGroup(int numGroups);// Grupo CrearGrupo(int numGrupo);


// plantilla para calcular carga mol. a cierto pH
template <typename groups>
int CalculateCharge(float& ph, groups AllGroups);

// función main
int main() {
    PH myPH; // instancia 'myPH' de la clase 'PH'
    // Groups myG; // instnacia 'myG' de la clase Groups
    // Declaración de variables
    const int numGroups = 3;
    float MolPh, temp1 = 0, temp2 = 0, temp3 = 0;
    char option;
    string MolName, x;
    array<Groups, numGroups> AllGroups;

    // Le pedimos al usuario elegir una opción
    option = AskOp(); // la opción se elige con la fun. AksOp
    switch (option) // Usamos un switch para que eliga
    {
    case '1': // Calcular el pH
        cout << " Ingrese los siguientes datos: " << endl;
        // Pedimos los datos necesarios
        cout << "Molaridad de la sustancia agregada: ";
        cin >> temp1;
        cout << "Volumen de la sustancia agregada (L):";
        cin >> temp2;
        cout << "Volumen del agua (L):";
        cin >> temp3;
        // Calculamos PH
        myPH.CalcularPH(temp1, temp2, temp3);
        cout << "Resultado: " << myPH.GetResult() << endl; // Imprime resultado
        break; // fin del case 1
    case '2': // Sustancia Dominante
        cout << "Ingrese los siguientes datos: " << endl;
        // Pedimos los datos necesarios
        cout << "Constante de acidez de la sustancia (pka): ";
        cin >> temp1;
        cout << "pH: ";
        cin >> temp2;
        myPH.DominantSus(temp1, temp2); // Obtenemos sus. dominante
        cout << "Resultado: " << myPH.GetResult() << endl; // Imprime resultado
        break; // fin del case 2
    case '3': // Punto isoeléctrico
        cout << "Ingrese los siguientes datos: " << endl;
        // Pedimos los datos necesarios
        cout << "pka1: ";
        cin >> temp1;
        cout << "pka2: ";
        cin >> temp2;
        myPH.IsoPoint(temp1, temp2); // Obtenemos PI
        cout << "Resultado: " << myPH.GetResult() << endl; // Imprime resultado
        break; // fin del case 3
    case '4': // carga eléctrica
        // Pedimos al usuario el nombre de la molécula
        cout << "Nombre de la molecula: ";
        cin >> MolName;

        // Arreglo de 'Groups' para los grupos de la molécula
        array <Groups, numGroups> AllGroups;
        // Pedimos información de cada grupo al usuario
        for (int i = 0; i < numGroups; i++)
            AllGroups[i] = CreateGroup(i);

        // Pedimos al usuario indicar el pH al que está la molécula
        AskPh(MolPh);

        // Calculamos la carga neta de la molécula a un cierto pH
        int MolCharge = CalculateCharge(MolPh, AllGroups);
        cout << "Carga neta de la molecula: " << MolCharge << endl;
        break; // fin del case 4
    };

    return 0;
}

char AskOp()
{
    char op;
    do {
        cout << "      Calculadora de Bioquimica      " << endl;
        cout << "-------------------------------------" << endl << endl;
        cout << "Seleccione un procedimiento" << endl;
        cout << "1 : Calcular pH" << endl;
        cout << "2 : Especie con mayor presencia" << endl;
        cout << "3 : Calcular punto isoelectrico" << endl;
        cout << "4 : Calcular la carga neta de la molécula a un cierto PH" << endl;
        cout << "Procedimeinto elegido: ";
        cin >> op;
    } while (op != '1' && op != '2' && op != '3' && op != '4');
    return op;
}

// Crea un nuevo 'Grupo' con la información ingresada por el usuario
Groups CreateGroup(int i)
{
    string GroupName;
    float GroupPka;
    int GroupCharge;
    cout << "Nombre grupo " << i << ": ";
    cin >> GroupName;
    cout << "pK del grupo " << GroupName << ": ";
    cin >> GroupPka;
    cout << "Carga del grupo " << GroupName << " a pH mayor a " << GroupPka << ": ";
    cin >> GroupCharge;
    Groups myGroup(GroupName, GroupPka, GroupCharge);
    return myGroup;
}

// Pedimos al usuario el pH 
void AskPh(float& ph)
{
    cout << "pH de la solucion (buffer): ";
    cin >> ph;
}

/* Calcula y regresa la carga eléctrica de la molécula dependiendo de la
 * carga de c/u de sus grupos a cierto pH
*/
template <typename groups>
int CalculateCharge(float& ph, groups AllGroups)
{
    int charge = 0;
    int MolCharge = 0;
    for (int i = 0; i < AllGroups.size(); i++) {

        if (ph < AllGroups[i].GetPkr()) {
            charge = AllGroups[i].GetCharge() + 1;
        }

        if (ph > AllGroups[i].GetPkr()) {
            charge = AllGroups[i].GetCharge();
        }

        MolCharge += charge;
    }
    return MolCharge;
}