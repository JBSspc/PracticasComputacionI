// Heidy Valdelamar & Sof�a Palacios Cuevas
// M�todos de Groups

// Header
# include "Groups.h"

//librer�as
# include <string>
# include <array>
# include <iostream>

using namespace std;

Groups::Groups() {
	name = " ";
	pkr = 0;
	charge = 0;
}

// le decimos que nuestras variables del constructor de arriba son
// las mismas que las de las instrucciones del main
Groups::Groups(string nombreGrupo, float pkGrupo, int cargaGrupo) {
	name = nombreGrupo;
	pkr = pkGrupo;
	charge = cargaGrupo;
}

int Groups::setValues() {
	result = MolCharge;
	return 0;
}

// regresa la carga seg�n su relaci�n (<,>) con el pH
int Groups::GetCharge() {
	return charge;
}

float Groups::GetPkr() {
	return pkr;
}
