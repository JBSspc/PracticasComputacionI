// Heidy Valdelamar & Sofía Palacios Cuevas
// CLASE 'Groups'
# pragma

# include <string>

using namespace std;


class Groups {
private:

    string name; // nombre de nuestro grupo
    float pkr; // potenciales de los radicales
    int charge, MolCharge; // carga del radical, carga de la molécula  
    float result; // resultado (será la carga neto de la molécula)

public:
    Groups(string, float, int); // constructor con parámetros
    Groups(); // constructor

    int setValues(); // result = MolCharge
    int GetCharge(); // recuperar la carga
    float GetPkr(); // obtener el pk de los radicales
        
};