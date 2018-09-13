#include "statsAnalysis.h"


/*Default constructor*/
statsAnalysis::statsAnalysis()
{
	pdf = 0;
	cdf = 0;
}

/*
*Description:  Perform hyper geometric test on value.
*
*/
void statsAnalysis::hypergeometrictest(int val1, int val2, int val3, int val4)
{
	unsigned int n1 = val1;
	unsigned int n2 = val2;
	unsigned int t = val3;
	unsigned int k = val4;
	boost::math::hypergeometric_distribution<double> hg_dist(n1, t, n1 + n2);
	pdf = boost::math::pdf<double>(hg_dist, k);
	cdf = boost::math::cdf<double>(hg_dist, k);
				

}

double statsAnalysis::returnPDF()
{
	return this->pdf;
}

double statsAnalysis::returnCDF()
{
	return this->cdf;
}


statsAnalysis::~statsAnalysis()
{
}
