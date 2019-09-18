#pragma once
#include <vector>

class LinearGenerator{
public:
	
	virtual void Gistogram() = 0;
	virtual double StartGenerate() = 0;
protected :
	
	virtual void PrintGistogram(std::vector <double> *gisto) = 0;
};