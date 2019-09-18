#pragma once
#include <vector>

class Generator6 {
public:

	virtual void Gistogram();
	virtual double StartGenerate() ;
protected:
	const unsigned M = 16000;
	virtual void PrintGistogram(std::vector <double> *gisto) ;
};
