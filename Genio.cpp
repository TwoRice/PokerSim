#include <iostream>
#include <sstream>
#include "Genio.h"

using namespace std;

int Genio::readInt(){

	string input;
	int myInt;

	while (true){

		getline(cin >> ws, input);

		stringstream stream(input);
		if (stream >> myInt){
			break;
		}
		cout << "Please only enter an integer value" << endl;
	}

	return myInt;

}

float Genio::readFloat(){

	string input;
	float myFloat;

	while (true){

		getline(cin >> ws, input);

		stringstream stream(input);
		if (stream >> myFloat){
			break;
		}
		cout << "Please only enter an float value" << endl;
	}

	return myFloat;

}

double Genio::readDouble(){

	string input;
	double myDouble;

	while (true){

		getline(cin >> ws, input);

		stringstream stream(input);
		if (stream >> myDouble){
			break;
		}
		cout << "Please only enter an double value" << endl;
	}

	return myDouble;

}

/**
* Converts a given string to lower case
*
* param - str : the string to be converted to lower case
* return - str : the converted lower case string
*/
string Genio::strToLower(string str){

	//A loop to iterate through each character of the string
	for(int i = 0; i < str.length(); i++){

		//Converts each character of the string to lower case
		str[i] = tolower(str[i]);

	}

	return str;

}

