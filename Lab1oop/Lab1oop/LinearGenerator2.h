#pragma once
#include "LinearGenerator.h"

class LinearGenerator2 : LinearGenerator {
public:
	void Gistogram() override;
   double StartGenerate() override;
private:
	
	void PrintGistogram(std::vector <double> *gisto) override;


	const unsigned M = 16000;

};