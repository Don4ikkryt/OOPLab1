#include "Generator9.h"
#include "LinearGenerator1.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;


double Generator9::StartGenerate()
{
	LinearGenerator1 temp;
	double xn = 0, ux = 0;
	ux = temp.StartGenerate() / double(M);
	xn = -log(ux);

	return xn ;

	
}
void Generator9::Gistogram()
{
	vector <double> Gisto;
	size_t quantityOfNumbers = 150;
	for (size_t i = 0; i < quantityOfNumbers; i++)
	{
		Gisto.push_back(this->StartGenerate());

	}
	PrintGistogram(&Gisto);

}
void Generator9::PrintGistogram(vector <double> *gisto)
{

	int QuantityOfNumbers[10] = { 0,0,0,0,0,0,0,0,0,0 };
	for (auto it = gisto->begin(); it != gisto->end(); ++it) {
		if (*it < 0 || *it > 10) {
			cout << "Err";
		}
		if (*it >= 0 && *it < 1) {
			QuantityOfNumbers[0]++;
			continue;
		}
		if (*it < 2) {
			QuantityOfNumbers[1]++;
			continue;
		}
		if (*it < 3) {
			QuantityOfNumbers[2]++;
			continue;
		}
		if (*it < 4) {
			QuantityOfNumbers[3]++;
			continue;
		}
		if (*it < 5) {
			QuantityOfNumbers[4]++;
			continue;
		}
		if (*it < 6) {
			QuantityOfNumbers[5]++;
			continue;
		}
		if (*it < 7) {
			QuantityOfNumbers[6]++;
			continue;
		}
		if (*it < 8) {
			QuantityOfNumbers[7]++;
			continue;
		}
		if (*it < 9) {
			QuantityOfNumbers[8]++;
			continue;
		}
		if (*it <= 10) {
			QuantityOfNumbers[9]++;
			continue;
		}
	}
	double lowLim, upLim, persents;
	string line;
	for (size_t i = 0; i < 10; i++)
	{
		cout << QuantityOfNumbers[i];
		lowLim = i ;
		upLim = (i + 1) ;
		persents = QuantityOfNumbers[i] / 150.;
		line = '[' + to_string(lowLim).substr(0, 3) + ',' + to_string(upLim).substr(0, 3) + "] : " + to_string(persents);
		cout << line << endl;
	}


}