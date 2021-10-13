/*
author: SOFIA PALACIOS CUEVAS
e-mail: sofiapalacioscuevas@comunidad.unam.mx
  date: OCT 12 2021
*/

class Punto2D
{
    public:
        float SetPosicion( float x, float y);
        float Trasladar(float temp1, float temp2);
        float RotarRespectoAlOrigen( float temp1);
        float Escalar (float temp1, float temp2);
        float GetX();
        int GetY();
};