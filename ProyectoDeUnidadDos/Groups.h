// Heidy Valdelamar & Sofía Palacios Cuevas
// CLASE 'Groups'
# pragma

#include <string>
#include <iostream>
using namespace std;

class Groups{
    private:
        int main(){
            Groups myG;
        return 0;
        }
        string name; // nombre del grupo
        float pkr, result; // potencial de los radicales, resultado
        int charge; // carga del radical

    public:
        Groups(string, float, int); // constructor con parámetros
        Groups(); // constructor

        float setValues(float x);
        int CreateGroup(); // creamos nuevo 'grupo'
        void AskPh(float& ph); // pedimos pH
        int CalculateCharge(); // Calcular carga a cierto pH
        int GetCarga(); // recuperar la carga
        float GetPkr(); // recuperar pk de radicales
        float GetResult();


};
