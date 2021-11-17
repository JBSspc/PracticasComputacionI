// Heidy Valdelamar & Sofía Palacios Cuevas
// CLASE 'PH'
# pragma

#include <string>
#include <array>

class PH
{
    private:
        int main(){
            PH myPH;
        return 0;
        }
    public:
        float result, a, b, c;
        float setValues(float x);
        float CalcularPH(float temp1, float temp2, float temp3);
        float DominantSus(float temp1, float temp2);
        float IsoPoint(float temp1, float temp2);
        float GetResult();
};
