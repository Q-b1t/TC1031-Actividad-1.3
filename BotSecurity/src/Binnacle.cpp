/*
 * Binnacle.cpp
 *
 *  Created on: 16 sep. 2020
 *      Author: luisd
 */

#include "Binnacle.h"
#include <iostream>
#include <sstream>
#include <fstream>


Binnacle::Binnacle() {
	// TODO Auto-generated constructor stub

}

Binnacle::~Binnacle() {
	// TODO Auto-generated destructor stub
}


void Binnacle::readCsvLines(std::string filename){
	std::ifstream file(filename);
	if(file.fail()) throw std::runtime_error("Could not open file");
	std::string line;
	while(std::getline(file, line)){
		getline(file, line);
		std::cout << line << std::endl;

	}
	file.close();


}