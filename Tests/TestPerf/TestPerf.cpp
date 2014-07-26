#include <memory>
#include <fstream>
using std::ifstream;
#include "../../LCCRF/LCCRF.h"

int main(int argc, char* argv[])
{
	XType x;
	YType y;
	std::set<int> features;
	std::set<int> tags;

	// open file to load x,y
	ifstream f1("../TestLCCRFPy/x");
	int i; int j; int s1; int s2; int f;
	while( f1 >> i >> j >> s1 >> s2 >> f)
	{
		features.insert(f);
		x.SetFeature(i, j, s1, s2, f);
	}
	f1.close();

	printf("x readed\n");

	ifstream f2("../TestLCCRFPy/y");
	int t;
	while( f2 >> i >> j >> t)
	{
		tags.insert(t);
		y.SetTag(i, j, t);
	}
	f2.close();
	printf("y readed\n");

	size_t featureCount = features.size();
	size_t tagCount = tags.size();
	LCCRF* crf = new LCCRF(featureCount, tagCount);
	crf->Fit(x, y, 1000, 0.005, 0.001);
	return 0;
}