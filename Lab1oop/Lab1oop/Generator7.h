#pragma once
#include <vector>
#include <tuple>

class Generator7 {
public:

	 void Gistogram() ;
	 std::tuple<double, double> StartGenerate() ;
protected:
	const unsigned M = 16000;
	 void PrintGistogram(std::vector <double> *gisto) ;
};
