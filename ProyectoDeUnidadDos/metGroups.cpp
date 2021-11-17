// Heidy Valdelamar & Sofía Palacios Cuevas
// Métodos de Groups

// Header
# include "Groups.h"

// Librerías
#include <string>
#include <array>

using namespace std;

// constructor
Groups::Groups(){ 
    name = " ";
    pkr = 0;
    charge = 0;
}

Groups::Groups(string GroupName, float GroupPka, int GroupCharge){
    name = GroupName;
    pkr = GroupPka;
    charge = GroupCharge;
}

float Groups::setValues(float x){
    result = x;
    return 0;
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

void Groups::AskPh(float& ph){
    cout << "ph del buffer: ";
    cin >> ph;
}

// Regresa carga según su relación (<,>) con el pH
int Groups::GetCarga(){

  return charge;
}

// Regresa pkr
float Groups::GetPkr(){
  return pkr;
}

// Calcula y regresa la carga eléctrica de la molécula dependiendo de la
// carga eléctrica de cada uno de sus grupos a un cierto pH.

template <class groups>
int CalcularCargaApH(float& ph, groups AllGroups)
{
    float result;
    int charge = 0;
    int MolCharge = 0;
    for (int i = 0; i<AllGroups.size(); i++){
        
        if(ph <AllGroups[i].GetPkr()){
            charge = AllGroups[i].GetCarga() + 1;
        }

        if(ph >AllGroups[i].GetPkr()){
            charge = AllGroups[i].GetCarga();
        }

        result = MolCharge + charge;
    }
    return 0;
}

float Groups::GetResult(){
    return result;
}
