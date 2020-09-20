/*
 * Binnacle.h
 *
 *  Created on: 16 sep. 2020
 *      Author: luisd
 */

#ifndef BINNACLE_H_
#define BINNACLE_H_
#include "BinnacleLine.h"
#include <vector>

#pragma once

class Binnacle {
public:
	Binnacle();
	virtual ~Binnacle();
	void readCsvLines(std::string filename);
	int encodePorts(std::string);
	// shows the number of entries in the vector
	void showTotalNumberOfEntries();
	void showEntries();

	// Sets the data to a sorted BinnacleLine line vector (maybe will be useful)
	void setData(std::vector<BinnacleLine> sorted);


	// Given a computer name, it will search it in destination and origin
	void searchComputer(std::string name);

	// Auxiliary Function: Returns the second registered date in the archive
	std::string getSecondDate();
	// Given a date, it will count and return the number of entries registered in that day
	int entriesPerDate(std::string date);


	// Will extract the first portion of a mail
	std::string extractMailName(std::string mail);


	//Given a string representing a name, it will search the computer
	int searchByName(std::string name);


	// It will Iterate throught the data in order to set the order criteria in all elements
	void SetOrderCriteria(char oc);
private:
	std::vector<BinnacleLine> data;

};

#endif /* BINNACLE_H_ */
