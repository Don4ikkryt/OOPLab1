#include "LinearGenerator4.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;


double LinearGenerator4::StartGenerate()
{
	static long a = 1, c = 3, xn = 2;
	int i = 0;
	for (i = 0; i < P; i++)
		if (xn*i % P == 1) break;
	xn = (a*i + c) % P;
	return xn;
}
void LinearGenerator4::Gistogram()
{
	vector <double> Gisto;
	size_t quantityOfNumbers = 150;
	for (size_t i = 0; i < quantityOfNumbers; i++)
	{
		Gisto.push_back(this->StartGenerate() / P);

	}
	PrintGistogram(&Gisto);

}
void LinearGenerator4::PrintGistogram(vector <double> *gisto)
{

	int QuantityOfNumbers[10] = { 0,0,0,0,0,0,0,0,0,0 };
	for (auto it = gisto->begin(); it != gisto->end(); ++it) {
		if (*it < 0 || *it > 1) {
			cout << "Err";
		}
		if (*it >= 0 && *it < 0.1) {
			QuantityOfNumbers[0]++;
			continue;
		}
		if (*it < 0.2) {
			QuantityOfNumbers[1]++;
			continue;
		}
		if (*it < 0.3) {
			QuantityOfNumbers[2]++;
			continue;
		}
		if (*it < 0.4) {
			QuantityOfNumbers[3]++;
			continue;
		}
		if (*it < 0.5) {
			QuantityOfNumbers[4]++;
			continue;
		}
		if (*it < 0.6) {
			QuantityOfNumbers[5]++;
			continue;
		}
		if (*it < 0.7) {
			QuantityOfNumbers[6]++;
			continue;
		}
		if (*it < 0.8) {
			QuantityOfNumbers[7]++;
			continue;
		}
		if (*it < 0.9) {
			QuantityOfNumbers[8]++;
			continue;
		}
		if (*it <= 1) {
			QuantityOfNumbers[9]++;
			continue;
		}
	}
	double lowLim, upLim, persents;
	string line;
	for (size_t i = 0; i < 10; i++)
	{
		cout << QuantityOfNumbers[i];
		lowLim = i / 10.;
		upLim = (i + 1) / 10.;
		persents = QuantityOfNumbers[i] / 150.;
		line = '[' + to_string(lowLim).substr(0, 3) + ',' + to_string(upLim).substr(0, 3) + "] : " + to_string(persents);
		cout << line << endl;
	}


}