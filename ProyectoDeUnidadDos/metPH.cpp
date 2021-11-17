// Heidy Valdelamar & Sofía Palacios Cuevas

// Métodos de myPH

// Header
#include "PH.h"

// Librerías
#include<iostream>
#include<math.h> //log10
#include<stdio.h> 
using namespace std;

float PH::setValues(float x){
    result = x;
    return 0;
}

float PH::CalcularPH(float temp1, float temp2, float temp3){
   // result = - log10(((MolSusAg * VolSusAg) / (VolSusAg + VolAg)) + 0.0000001)
   // - (log10) did not work 
    a = temp1 * temp2;
    b = temp2 + temp3;
    c = a / b;
    // doing it step by step works!
    result = (log10(c)) * (-1);

    return 0;
}

float PH::DominantSus(float temp1, float temp2){
    result = (-(temp1)) - (-(temp2)); // we substract the exponents at which 10 is elevated to 
    if(result == 0){
        cout << "Ambas especies estan en equilibrio" <<endl;
    }
    else{
        if(result < 0 ){
            cout << "La especie desprotonada predomina"<<endl;
        }
        else{
            cout << "La especie protonada predomina"<<endl;
        }
    }
    return 0;
}

float PH::IsoPoint(float temp1, float temp2){
    result = (temp1 + temp2)/2;
    return 0;
}

float PH::GetResult(){
    return result;
}
