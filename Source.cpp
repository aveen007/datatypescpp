#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>
#include <set>
#include <functional>
#include <fstream>
#include <algorithm>


#include "BaseObject.h"

#include "TypeFactory.h"


using namespace std;
string type1 = "", type2 = "";


string trim(const string& str) {
	// Find the first character that is not a whitespace character
	size_t start = str.find_first_not_of(' ');
	// Find the last character that is not a whitespace character
	size_t end = str.find_last_not_of(' ');

	// If the string is all whitespace, return an empty string
	if (start == string::npos) {
		return "";
	}

	// Return the substring that excludes leading and trailing spaces
	return str.substr(start, end - start + 1);
}

void input() {

	cout << "Enter first type: ";
	while (type1 == "") {

		getline(cin, type1);
	}
	type1 = trim(type1);
	cout << "Enter second type : ";
	while (type2 == "") {

		getline(cin, type2);
	}
	type2 = trim(type2);
	return;
}
void output(string type1, string type2, string value1, string value2, vector<string> operations) {

	ofstream fout("func_1.cpp");
	fout << "#include <iostream>" << endl;
	fout << "int f(void) {" << endl;
	fout << type1 << " var1 = "<< value1<<";" << endl;
	fout << type1 << " var2 ="<<value2<<"; " << endl;
	for (string op: operations) {

	fout << "std::cout << var1"<<op<<" var2 << std::endl; " << endl;
	}
	fout << "return 0;" << endl;
	fout << "}" << endl;
	fout.close();

}
int main(void) {


	input();// inputting the types
	
//	cout << __cplusplus;
	cout << type1 << ' ' << type2 << endl;

	TypeFactory factory;
	vector< string> validOperations=factory.subtype2operation(type1, type2);

	try {
		auto object1 = factory.Create(type1);
		auto object2 = factory.Create(type2);
		
		object1->initialize();  // Initialize the object
		string value1= object1->print();       // Print the initialized value


		object2->initialize();  // Initialize the object
		string value2 = object2->print();       // Print the initialized value
		output(type1, type2, value1, value2, validOperations);
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	
	return 0;
}
