#include <iostream>
#include <string>
#include "LinearGenerator5.h"
#include "LinearGenerator4.h"
#include "LinearGenerator3.h"
#include "LinearGenerator2.h"
#include "LinearGenerator1.h"
#include "Generator6.h"
#include "Generator7.h"
#include "Generator8.h"
#include "Generator9.h"
#include "Generator10.h"

using namespace std;


int main() {


	
	cout << "Generator1" << endl;
	LinearGenerator1 gen1;
	gen1.Gistogram();
	cout << "Generator2" << endl;
	LinearGenerator2 gen2;
	gen2.Gistogram();
	cout << "Generator3" << endl;
	LinearGenerator3 gen3;
	gen3.Gistogram();
	cout << "Generator4" << endl;
	LinearGenerator4 gen4;
	gen4.Gistogram();
	cout << "Generator5" << endl;
	LinearGenerator5 gen5;
	gen5.Gistogram();
	cout << "Generator6" << endl;
	Generator6 gen6;
	gen6.Gistogram();
	cout << "Generator7" << endl;
	Generator7 gen7;
	gen7.Gistogram();
	cout << "Generator8" << endl;
	Generator8 gen8;
	gen8.Gistogram();
	cout << "Generator9" << endl;
	Generator9 gen9;
	gen9.Gistogram();
	cout << "Generator10" << endl;
	Generator10 gen10;
	gen10.Gistogram();
	system("pause");
}