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




void printMap(std::unordered_map<std::string, std::vector<std::string>>);
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


	stringIn = "test.go.txt";
	stringOut = "output.txt"; // development
	
	ifstream inputFile(stringIn);
	ofstream outputFile(stringOut);

	ofstream * optr = &outputFile;
	ifstream * aptr = &inputFile;
	returnfile(*aptr, *optr);

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


	printMap(mymap);
	






	
	//statsAnalysis test;
	//test.hypergeometrictest(18, 100, 50, 2);
	//phyer(x-1, m, n = N-m,
	//test.hypergeometrictest(8, 92, 30 , 4);
	
	/*Parameters: (Number of genes with term, Number of genes with term - total population, number of genes submitted, number of marked genes in selection)*/
	//test.hypergeometrictest(611, 13588-611, 59 , 18);
	//cout << "This is my cdf: " << 1. - test.returnCDF() << endl;
	//cout << "This is my pdf: " << test.returnPDF() << endl;
	


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


	/*
	Function: is reponsible for printing an array 
	Print the unorder map function
	*/
	void printMap(std::unordered_map<std::string, std::vector<std::string>> mymap) {
		using namespace std;
		for (auto local_it = mymap.begin(); local_it != mymap.end(); local_it++)
		{
			if(local_it->second.size() != 1)
			{
				for(int inVal = 0; inVal < local_it->second.size(); inVal++)
				{
					cout << local_it->first << " : " << local_it->second.at(inVal);
				}
			}
			else
			{
				//define one due to there being a vector
				cout << local_it->first << " : " << local_it->second.at(0);
			}
		}
		

	}


	