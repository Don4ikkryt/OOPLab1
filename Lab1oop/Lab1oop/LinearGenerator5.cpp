#include "LinearGenerator5.h"
#include "LinearGenerator3.h"
#include "LinearGenerator2.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;


double LinearGenerator5::StartGenerate()
{
	static long zn = 0;
	LinearGenerator2 temp2;
	LinearGenerator3 temp3;
	zn = long(abs(temp2.StartGenerate() - temp3.StartGenerate())) % M;
	return zn;
}
void LinearGenerator5::Gistogram()
{
	vector <double> Gisto;
	size_t quantityOfNumbers = 150;
	for (size_t i = 0; i < quantityOfNumbers; i++)
	{
		Gisto.push_back(this->StartGenerate() / M);

	}
	PrintGistogram(&Gisto);

}
void LinearGenerator5::PrintGistogram(vector <double> *gisto)
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