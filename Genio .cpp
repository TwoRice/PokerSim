#include <iostream>
#include <sstream>
#include "Genio.h"

using namespace std;

static int Genio::readInt(){

	string input;
	int myInt;

	while (true){

		getline(cin, input);

		stringstream stream(input);
		if (stream >> myInt){
			break;
		}
		cout << "Please only enter an integer value" << endl;
	}

	return myInt;

}

static int Genio::readFloat(){

	string input;
	float myFloat;

	while (true){

		getline(cin, input);

		stringstream stream(input);
		if (stream >> myFloat){
			break;
		}
		cout << "Please only enter an float value" << endl;
	}

	return myFloat;

}

static int Genio::readDouble(){

	string input;
	double myDouble;

	while (true){

		getline(cin, input);

		stringstream stream(input);
		if (stream >> myDouble){
			break;
		}
		cout << "Please only enter an double value" << endl;
	}

	return myDouble;

}

