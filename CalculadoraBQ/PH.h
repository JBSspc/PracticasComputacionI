// Heidy Valdelamar & Sofía Palacios Cuevas
// CLASE 'PH'
# pragma

#include <string>
#include <array>

class PH
{
private:
    float result,a,b,c;
public:
    float setValues(float x);
    float CalcularPH(float temp1, float temp2, float temp3);
    float DominantSus(float temp1, float temp2);
    float IsoPoint(float temp1, float temp2);
    float GetResult();
};
