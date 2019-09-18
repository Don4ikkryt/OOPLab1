#pragma once
#include <vector>

class Generator9 {
public:

	void Gistogram();
	double StartGenerate();
protected:
	const unsigned M = 16000;
	void PrintGistogram(std::vector <double> *gisto);
};
