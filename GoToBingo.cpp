/**********************************************************************************************************************
Author: Bryan Musungu
Description: Take in a interpro file go information and convert to bingo format for cytoscape.
The data should Column1 containing the geneid seperated by a tab
*************************************************************************************************************************/


#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <regex>
#include <unordered_map>
#include <math.h>
#include "statsAnalysis.h"




//bool fexists(const std::string& stringIn);
void returnfile(std::ifstream&, std::ofstream&);
double hypergeometricProb(int, int, int, int);
double fac(int);

int main() {
	using namespace std;

	string stringIn;
	string stringOut;
	string value;
	string value2;
	regex re("\\s+|\\|");
	sregex_token_iterator reg_end;


	
	/*
	cout << "Input the name of the file: " << endl;
	getline(cin, stringIn);
	cout << "The output file name is " << endl;
	getline(cin, stringOut);
	*/
	stringIn = "test.go.txt";
	stringOut = "output.txt"; // development
	
	ifstream inputFile(stringIn);
	ofstream outputFile(stringOut);

	ofstream * optr = &outputFile;
	ifstream * aptr = &inputFile;
	returnfile(*aptr, *optr);


	

	/*
	//It should iterate through the values using column and column2 delimited by the pipe sign.
	//For example GO:0005524|GO:0008026 and this could be of unknown length.
	while (getline(inputFile,value)) {
			sregex_token_iterator it(value.begin(), value.end(), re, -1);
			std::string p1 = (it++)->str();
			//std::cout << "This is P1: " << p1 << " and " << it->str() << std::endl;
			for (; it != reg_end; ++it) {
				//std::string test = it->str();
				//std::string test2 = test.substr(3, test.length());
				//outputFile << p1 << " " << test2 << endl;		
				outputFile << p1 << "=" << it->str()  << endl;	
				

			}
				}

	*/

	outputFile.close();
	inputFile.close();

	
	ifstream inputFile2("output.txt"); //create a stream to new input file
	//make a hash map
	unordered_map<string, vector<string>> mymap;
	
	while (getline(inputFile2, value, '\t')) {
		unordered_map<string, vector<string>>::const_iterator got = mymap.find(value); //iterator for find the key.
		
		//Conditional check for the key if not present initialize vector 
		if(got == mymap.end())
		{
			mymap.emplace(value, vector<string> {value2});
		}
		else
		{
			mymap.at(value).push_back(value2);
		}
	}

	statsAnalysis test;
	test.hypergeometrictest(3,297, 20000, 100);
	cout << "This is my cdf: " << test.returnCDF() << endl;
	cout << "This is my cdf: " << test.returnPDF() << endl;
	

	/*Print out values inorder to understand the values*/
	/*
	for (unordered_map<string, vector<string>>::const_iterator got2 = mymap.begin(); got2 != mymap.end(); got2++) {
		if (got2->second.size() != 1) 
		{
			for (int i = 0; i < got2->second.size(); i++) 
			{
				cout << got2->first << '\t' << got2->second[i];
			}
		}
		else
		{
			cout << got2->first << '\t' << got2->second[0];
		}
	}
	*/

	////cout << "Test Result: " << fac(5) << std::endl;
	//int a = atoi(argv[1]), b = atoi(argv[2]), c = atoi(argv[3]), d = atoi(argv[4]);
	//int n = a + b + c + d;
	//// find cutoff probability
	//double pCutoff = hypergeometricProb(a, b, c, d);
	//double pValue = 0;
	//// sum over probability smaller than the cutoff
	//for (int x = 0; x <= n; ++x) { // among all possible x
	//	if (a + b - x >= 0 && a + c - x >= 0 && d - a + x >= 0) { // consider valid x
	//		double p = hypergeometricProb(x, a + b - x, a + c - x, d - a + x);
	//		if (p <= pCutoff) pValue += p;
	//	}
	//}
	//std::cout << "Two-sided p-value is " << pValue << std::endl;




	system("pause");

	return 0;

}





	/*****************************************************************************************************************
	Perform hypergeometric test
	Params: converts file into the proper format for hypergeometric test
	******************************************************************************************************************/
	void returnfile(std::ifstream& file, std::ofstream& file2) {
		using namespace std;
		regex re("\\s+|\\|"); //escape the space the pipe in the beginning and end.
		sregex_token_iterator reg_end;  //regular expression
		string value;


		/*Loop is responsible for iterating through the values*/
		while (getline(file, value)) 
		{
			sregex_token_iterator it(value.begin(), value.end(), re, -1);
			std::string p1 = (it++)->str();
			for (; it != reg_end; ++it) {
				file2 << it->str() << "\t" << p1 << std::endl;

			}

		}


		
	}

	/*
	//Performs hypergeometric test
	//credit::https://genome.sph.umich.edu/w/images/f/ff/Biostat615-lecture2-handout-nup.pdf
	*/
	double fac(int n) {
		double ret;
		for (ret = 1; n > 0; --n) 
		{
			
			ret *= n;
			//std::cout << "This is: ret " << ret << " and n:" << n << std::endl;
		}
		return ret;
	}
	/*
	//hypergeometric test
	//paramaters
	*/
	double hypergeometricProb(int a, int b, int c, int d) {
		double num = fac(a + b) * fac(c + d) * fac(a + c) * fac(b + d);
		double den = fac(a) * fac(b) * fac(c) * fac(d) * fac(a + b + c + d);
		return num / den;

	}


	