#include "Generator6.h"
#include "LinearGenerator1.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;


double Generator6::StartGenerate()
{

	double sum = 0, u = 0;
	LinearGenerator1 temp1;
	for (int j = 0; j < 12; j++)
		sum += temp1.StartGenerate() / double(M);
	return (sum - 6);
}
void Generator6::Gistogram()
{
	vector <double> Gisto;
	size_t quantityOfNumbers = 150;
	for (size_t i = 0; i < quantityOfNumbers; i++)
	{
		Gisto.push_back(this->StartGenerate());

	}
	PrintGistogram(&Gisto);

}
void Generator6::PrintGistogram(vector <double> *gisto)
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
		lowLim = -3 + i*6 / 10.;
		upLim = -3 + 6*(i + 1) / 10.;
		persents = QuantityOfNumbers[i] / 150.;
		line = '[' + to_string(lowLim).substr(0, 4) + ',' + to_string(upLim).substr(0, 4) + "] : " + to_string(persents);
		cout << line << endl;
	}


}