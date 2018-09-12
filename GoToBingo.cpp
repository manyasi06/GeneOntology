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




//bool fexists(const std::string& stringIn);
void returnfile(std::ifstream&, std::ofstream&);

int main() {
	using namespace std;

	string stringIn;
	string stringOut;
	string value;
	string value2;
	regex re("\\s+|\\|");
	sregex_token_iterator reg_end;


	

	cout << "Input the name of the file: " << endl;
	getline(cin, stringIn);
	cout << "The output file name is " << endl;
	getline(cin, stringOut);
	
	
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

	/*Print out values inorder to understand the values*/

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
	




	system("pause");

	return 0;

}


/*
fexists(stringIn);
oexists(stringOut);
*/


/******************************************************************************************************************
	Purpose of this function is to check if the file exists.	
*******************************************************************************************************************/
	//bool fexists(const std::string& fileIn) {
	//	using namespace std;
	//	
	//	ifstream inputFile(fileIn.c_str());
	//	return (bool)inputFile;
	//
	//}
	//

	//bool oexists(const std::string& fileIn2) {
	//	using namespace std;

	//	ofstream outputFile(fileIn2.c_str());
	//	return (bool)outputFile;

	//}


	/*****************************************************************************************************************
	Perform hypergeometric test
	Params: inputfile = file and output file file2
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


	