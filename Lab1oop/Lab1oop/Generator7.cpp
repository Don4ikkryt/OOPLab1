#include "Generator7.h"
#include "LinearGenerator1.h"
#include "LinearGenerator2.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;


tuple <double, double> Generator7::StartGenerate()
{

	static long x = 1, y = -1;
	LinearGenerator1 temp1;
	LinearGenerator2 temp2;
	double ux = 0, uy = 0, s = 0, v1 = 0, v2 = 0, z1 = 0, z2 = 0;
	for (; ;) {
		ux = temp1.StartGenerate() / double(M);
		uy = temp2.StartGenerate() / double(M);
		v1 = 2 * ux - 1;
		v2 = 2 * uy - 1;
		s = v1 * v1 + v2 * v2;
		if (s >= 1) continue;
		else {
			z1 = v1 * (sqrt(((-2)*log(s)) / s));
			z2 = v2 * (sqrt(((-2)*log(s)) / s));
			break;
		}
	}
	return make_tuple(z1, z2);
}
void Generator7::Gistogram()
{
	vector <double> Gisto;
	size_t quantityOfNumbers = 75;
	for (size_t i = 0; i < quantityOfNumbers; i++){
	{
		tuple<double, double> temp = this->StartGenerate();
		
			Gisto.push_back(get<0>(temp));
			Gisto.push_back(get<1>(temp));
		}
	}
	PrintGistogram(&Gisto);

}
void Generator7::PrintGistogram(vector <double> *gisto)
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
		persents = QuantityOfNumbers[i] / 75.;
		line = '[' + to_string(lowLim).substr(0, 3) + ',' + to_string(upLim).substr(0, 3) + "] : " + to_string(persents);
		cout << line << endl;
	}


}