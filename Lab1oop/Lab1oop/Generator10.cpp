#include "Generator10.h"
#include "LinearGenerator1.h"
#include "LinearGenerator2.h"
#include <iostream>
#include <vector>
#include <string>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;


double Generator10::StartGenerate()
{
	LinearGenerator1 temp1;
	LinearGenerator2 temp2;
	double U = 0;
	double X = 0;
	double Y = 0;
	double V = 0;
	double a = 50;
	do {
		do {
			U = temp1.StartGenerate() / double(M);
			Y = tan(M_PI * U);
			X = sqrt(2 * a - 1) * Y + a - 1;
		} while (X <= 0);
		V = temp2.StartGenerate() / double(M);
	} while (V > (1 + Y * Y)* exp(((a - 1)* log(X / (a - 1)) - sqrt(2 * a - 1) * Y)));
	return X ;


}
void Generator10::Gistogram()
{
	vector <double> Gisto;
	size_t quantityOfNumbers = 150;
	for (size_t i = 0; i < quantityOfNumbers; i++)
	{
		Gisto.push_back(this->StartGenerate());

	}
	PrintGistogram(&Gisto);

}
void Generator10::PrintGistogram(vector <double> *gisto)
{

	int QuantityOfNumbers[10] = { 0,0,0,0,0,0,0,0,0,0 };
	for (auto it = gisto->begin(); it != gisto->end(); ++it) {
		if (*it < 0 || *it > 100) {
			cout << "Err";
		}
		if (*it >= 0 && *it < 10) {
			QuantityOfNumbers[0]++;
			continue;
		}
		if (*it < 20) {
			QuantityOfNumbers[1]++;
			continue;
		}
		if (*it < 30) {
			QuantityOfNumbers[2]++;
			continue;
		}
		if (*it < 40) {
			QuantityOfNumbers[3]++;
			continue;
		}
		if (*it < 50) {
			QuantityOfNumbers[4]++;
			continue;
		}
		if (*it < 60) {
			QuantityOfNumbers[5]++;
			continue;
		}
		if (*it < 70) {
			QuantityOfNumbers[6]++;
			continue;
		}
		if (*it < 80) {
			QuantityOfNumbers[7]++;
			continue;
		}
		if (*it < 90) {
			QuantityOfNumbers[8]++;
			continue;
		}
		if (*it <= 100) {
			QuantityOfNumbers[9]++;
			continue;
		}
	}
	double lowLim, upLim, persents;
	string line;
	for (size_t i = 0; i < 10; i++)
	{
		cout << QuantityOfNumbers[i];
		lowLim = i*10;
		upLim = (i + 1)*10;
		persents = QuantityOfNumbers[i] / 150.;
		line = '[' + to_string(lowLim).substr(0, 3) + ',' + to_string(upLim).substr(0, 3) + "] : " + to_string(persents);
		cout << line << endl;
	}


}