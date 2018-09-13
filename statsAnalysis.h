/*Author: Bryan
 *Description:  Perform the hypergeometric test to determine the p-value.
 */

#include <boost\math\distributions\hypergeometric.hpp>
#include <cstdlib>
#include <boost\math\policies\policy.hpp>

#pragma once
class statsAnalysis
{
private:
	double pdf;
	double cdf;

public:
	statsAnalysis();
	void hypergeometrictest(int, int, int, int);
	double returnPDF();
	double returnCDF();
	~statsAnalysis();
};

