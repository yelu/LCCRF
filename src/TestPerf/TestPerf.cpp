// TestPerf.cpp : Defines the entry point for the console application.
//

#include "..\lib\LCCRF.h"

int main()
{
	LCCRF lccrf;
	string data = ".\\train.lccrf.converted.dat";
	string model = ".\\model.bin";
	lccrf.Fit(data, 50, 0.001, 0.001);
	lccrf.Save(model);
    return 0;
}

