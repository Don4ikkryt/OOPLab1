#include "Generator8.h"
#include "LinearGenerator1.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;


double Generator8::StartGenerate()
{

	double x, y, zn = 0;
	LinearGenerator1 temp1;
	bool isCreated = false;
	while (!isCreated) {
		x = temp1.StartGenerate() / double(M);
		y = temp1.StartGenerate() / double(M);
		zn = (sqrt(8 / (exp(1))))*((y - 0.5) / x);
		if ((zn*zn) <= (5 - (4 * pow((exp(1)), (1 / 4))*x)))
			isCreated = true;
		else if ((zn*zn) < ((4 * pow((exp(1)), ((-1)*1.35)) / x) + 1.4))
			if ((zn*zn) <= ((-4)*log(x)))
				isCreated = true;
	}

	return zn;
}
void Generator8::Gistogram()
{
	vector <double> Gisto;
	size_t quantityOfNumbers = 150;
	for (size_t i = 0; i < quantityOfNumbers; i++)
	{
		Gisto.push_back(this->StartGenerate());

	}
	PrintGistogram(&Gisto);

}
void Generator8::PrintGistogram(vector <double> *gisto)
{

	int QuantityOfNumbers[10] = { 0,0,0,0,0,0,0,0,0,0 };
	for (auto it = gisto->begin(); it != gisto->end(); ++it) {
		if (*it < -3 || *it > 3) {
			cout << "Err";
		}
		if (*it >= -3 && *it < -2.4) {
			QuantityOfNumbers[0]++;
			continue;
		}
		if (*it < -1.8) {
			QuantityOfNumbers[1]++;
			continue;
		}
		if (*it < -1.2) {
			QuantityOfNumbers[2]++;
			continue;
		}
		if (*it < -0.6) {
			QuantityOfNumbers[3]++;
			continue;
		}
		if (*it < 0) {
			QuantityOfNumbers[4]++;
			continue;
		}
		if (*it < 0.6) {
			QuantityOfNumbers[5]++;
			continue;
		}
		if (*it < 1.2) {
			QuantityOfNumbers[6]++;
			continue;
		}
		if (*it < 1.8) {
			QuantityOfNumbers[7]++;
			continue;
		}
		if (*it < 2.4) {
			QuantityOfNumbers[8]++;
			continue;
		}
		if (*it <= 3) {
			QuantityOfNumbers[9]++;
			continue;
		}
	}
	double lowLim, upLim, persents;
	string line;
	for (size_t i = 0; i < 10; i++)
	{
		cout << QuantityOfNumbers[i];
		lowLim = -3 + i * 6 / 10.;
		upLim = -3 + 6 * (i + 1) / 10.;
		persents = QuantityOfNumbers[i] / 150.;
		line = '[' + to_string(lowLim).substr(0, 3) + ',' + to_string(upLim).substr(0, 3) + "] : " + to_string(persents);
		cout << line << endl;
	}


}