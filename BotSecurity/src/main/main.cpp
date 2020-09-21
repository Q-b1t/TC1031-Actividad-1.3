//============================================================================
// Name        : BotSecurity.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>

#include <iterator>
#include <stdio.h>
#include <algorithm>/* printf, scanf, puts, NULL */


#include "../Headers/Binnacle.h"
#include "../Headers/OrderAl.h"


/*
 * Since this is not a Binnacle strict functionality (more like a particular homework auxiliary function), i did not considered
 * pertinent to include it inside of the class.
 */
void answerThree(Binnacle g){
	std::string persons[7] = {"jeffrey","betty","katherine","scott","benjamin","samuel","raymond"};
	for(int i = 0; i < 7; i++){
		g.sortedSearchByName(persons[i]);
		std::cout << std::endl;
	}
}







int main() {

	Binnacle bin;
	std::string filename = "equipo5.csv";
	bin.readCsvLines(filename);
	//bin.showEntries();


	// Question 1:
	bin.showTotalNumberOfEntries();

	// Question 2:
	std::string secondDate = bin.getSecondDate();
	std::cout << "Second date registered is: " << secondDate << std::endl;
	std::cout << "Entries: " << bin.entriesPerDate(secondDate) << std::endl;

	// Question 3:
	answerThree(bin);

	// Question 5
	bin.searchComputer("server.reto.com");


	// Question 7:
	std::cout << "Ports below 1000: " << std::endl;
	bin.printDestinyPorts(1000,OrderAl<int>::asc);


	std::cout << "finish" << std::endl;

	return 0;
}
