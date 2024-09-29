#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>
#include <set>
#include <functional>
#include <fstream>
#include "BaseObject.h"

#include "TypeFactory.h"
using namespace std;
string type1 = "", type2 = "";
void input() {

	cout << "Enter first type: ";
	while (type1 == "") {

		getline(cin, type1);
	}

	cout << "Enter second type : ";
	while (type2 == "") {

		getline(cin, type2);
	}
	return;
}
int main(void) {


	input();// inputting the types

//	cout << __cplusplus;
	cout << type1 << ' ' << type2 << endl;
	TypeFactory factory;
	//factory.Create(type1);

	try {
		auto object = factory.Create(type1);
		
		object->initialize();  // Initialize the object
		object->print();       // Print the initialized value
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	ofstream fout("func_1.cpp");
	fout << "#include <iostream>" << endl;
	fout << "int f(void) {" << endl;
	fout << type1 << " var1 = 1;" << endl;
	fout << type1 << " var2 {3};" << endl;
	fout << "std::cout << var1 + var2 << std::endl;" << endl;
	fout << "return 0;" << endl;
	fout << "}" << endl;
	fout.close();
	return 0;
}
