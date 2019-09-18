#pragma once
#include "LinearGenerator.h"

class LinearGenerator4 : LinearGenerator {
public:
	void Gistogram() override;
	double StartGenerate() override;
private:

	void PrintGistogram(std::vector <double> *gisto) override;


	const unsigned M = 16000;
	const unsigned P = 1013;

};