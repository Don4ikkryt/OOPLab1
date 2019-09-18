#pragma once
#include <vector>

class Generator8 {
public:

	 void Gistogram() ;
	 double StartGenerate() ;
protected:
	const unsigned M = 16000;
     void PrintGistogram(std::vector <double> *gisto) ;
};
