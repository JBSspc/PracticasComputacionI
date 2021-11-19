// Heidy Valdelamar & Sof�a Palacios Cuevas
// CLASE 'Groups'
# pragma

# include <string>

using namespace std;


class Groups {
private:

    string name; // nombre de nuestro grupo
    float pkr; // potenciales de los radicales
    int charge, MolCharge; // carga del radical, carga de la mol�cula  
    float result; // resultado (ser� la carga neto de la mol�cula)

public:
    Groups(string, float, int); // constructor con par�metros
    Groups(); // constructor

    int setValues(); // result = MolCharge
    int GetCharge(); // recuperar la carga
    float GetPkr(); // obtener el pk de los radicales
        
};