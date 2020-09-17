/*
 * Binnacle.cpp
 *
 *  Created on: 16 sep. 2020
 *      Author: luisd
 */

#include "../Headers/Binnacle.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <iterator>
#include <algorithm>


Binnacle::Binnacle() {
	// TODO Auto-generated constructor stub

}

Binnacle::~Binnacle() {
	// TODO Auto-generated destructor stub
}






int Binnacle::encodePorts(std::string num){
	if (num == "-"){
		return -1;
	}
	else{
		return stoi(num);
	}
}



void Binnacle::showEntries(){
	for(std::vector<BinnacleLine>::iterator it = this->data.begin(); it != this->data.end(); it++){
		std::cout << (*it) << std::endl;
	}
}


void Binnacle::showTotalNumberOfEntries(){
	std::cout << "Total Entries: " << this->data.size() <<std::endl;
}

void Binnacle::readCsvLines(std::string filename){
	std::ifstream file(filename);
	if(file.fail()) throw std::runtime_error("Could not open file");


	std::string date,time, oIP, oPort, oName,dIP,dPort,dName,line;
	int numOport, numDport;

	while(std::getline(file, line)){
		std::stringstream ss(line);
		getline(ss,date,',');
		getline(ss,time,',');
		getline(ss,oIP,',');
		getline(ss,oPort,',');
		getline(ss,oName,',');
		getline(ss,dIP,',');
		getline(ss,dPort,',');
		getline(ss,dName,',');
		numOport = encodePorts(oPort);
		numDport = encodePorts(dPort);
		BinnacleLine entry(date,time,oIP,numOport,oName,dIP,numDport,dName);
		data.push_back(entry);
	}


	file.close();
}



void Binnacle::searchComputer(std::string name){
	std::vector<BinnacleLine> originNames;
	std::vector<BinnacleLine> destinyNames;
	for(std::vector<BinnacleLine>::iterator it = this->data.begin(); it != this->data.end(); it++){
		if((*it).getOriginName() == name){
			originNames.push_back((*it));
		}
		else if((*it).getDestinyName() == name){
			destinyNames.push_back((*it));
		}
	}


	std::cout << "The following origin computers were found:" << std::endl;
	for(std::vector<BinnacleLine>::iterator it = originNames.begin(); it != originNames.end(); it++){
		std::cout << (*it) << std::endl;
	}
	std::cout << "The following destiny computers were found:" << std::endl;
	for(std::vector<BinnacleLine>::iterator it = destinyNames.begin(); it != destinyNames.end(); it++){
		std::cout << (*it) << std::endl;
	}


	std::cout << "Total computers named " << name << " found: " << originNames.size()+destinyNames.size() << std::endl;

}



std::string Binnacle::getSecondDate(){
	std::string first = this->data[0].getDate();
	for(std::vector<BinnacleLine>::iterator it = this->data.begin(); it != this->data.end(); it++){
		if((*it).getDate() != first){
			return (*it).getDate();
		}
	}
}





int Binnacle::entriesPerDate(std::string date){
	int num = 0;
	for(std::vector<BinnacleLine>::iterator it = this->data.begin(); it != this->data.end(); it++){
		if((*it).getDate() == date){
			num ++;
		}
		if(((*it).getDate() != date)&&(num >0)){
			break;
		}
	}
	return num;
}





std::string Binnacle::extractMailName(std::string mail){
	std::string name;
	std::stringstream ss(mail);
	std::getline(ss,name,'.');
	return name;
}


// Implement pending
int Binnacle::searchByName(std::string name){
	std::string extractedName, mail;

	int count = 0;
	for(std::vector<BinnacleLine>::iterator it = this->data.begin(); it != this->data.end(); it++){
		mail = (*it).getOriginName();
		extractedName = extractMailName(mail);
		if(extractedName == name){
			count ++;
		}
	}

	return count;
}
