/*
 * Printer.cpp
 *
 *  Created on: Dec 2, 2014
 *      Author: Ofer Caspi
 */

#include "Printer.h"

//Printer::Printer(map<string, Roads*>* roads_) : roads(roads_) {
Printer::Printer() {
}


//Printer::Printer(const Printer& printer) : roads(printer.roads) {
Printer::Printer(const Printer& printer) {
}

Printer& Printer::operator=(const Printer& printer) {
	return *this;
}

Printer::~Printer() {
}

void Printer::print(int currentTimeSlice) {
	int maxNumOfCars = 10;
	Car* car = NULL;
	string temp;
	ostringstream streamTemp;
	int tempInt;
	map<string, Roads*>::iterator it;

	//cin.ignore();

	for(int i = 0; i < 1; i++)
		cout << '\n';

	printf("%-18s%d\n", "Time:", global_SimulationTime);
	//printf("%-18s%d\n", "Time slice:", currentTimeSlice);

	printf("\n%-18s", "Green time left:");

	
	for(it = RoadsMap->begin(); it != RoadsMap->end(); it++) {
		tempInt = ( (*JunctionsMap->find(it->second->getEndJnc())->second->getTimeSlice())[0] );
		//tempInt = it->second->getEndJunction()->getGreenLightTimeLeft(it->second->getStartJunction()->getId());
		if(tempInt == 0)
			printf("%-11s", "0");
		else
			printf("%-11d", tempInt);
	}

	printf("\n%-18s", "Speed:");

	for(it = RoadsMap->begin(); it != RoadsMap->end(); it++) {
		tempInt = it->second->getBaseSpeed();
		printf("%-11d", tempInt);
	}

	printf("\n%-18s", "End junction:");

	for(it = RoadsMap->begin(); it != RoadsMap->end(); it++) {
		temp = it->second->getEndJnc();
		//temp = it->second->getEndJunction()->getId();
		printf("%-11s", temp.c_str());

		maxNumOfCars =  min(maxNumOfCars,it->second->getNumOfCarInside());
		//maxNumOfCars = max(maxNumOfCars, it->second->getNumOfCars());
	}

	printf("\n");

	for(int i = 0; i < maxNumOfCars; i++) {
		printf("%-18s", "Cars:");

		for(it = RoadsMap->begin(); it != RoadsMap->end(); it++) {
			car = (*(it->second->getCarsInRoad()))[i];
			//car = it->second->getCar(i);

			streamTemp.str("");
			if(car != NULL)
				streamTemp << car->getID() << "(" << car->getLocation() << "," << car->getCondition() << ")";
				//streamTemp << car->getId() << "(" << car->getDistance() << "," << car->getFaultyTimeLeft() << ")";
			else
				streamTemp << "^";

			printf("%-11s", streamTemp.str().c_str());
			//printf("%-11s", streamTemp.str().c_str());
		}

		printf("\n");
	}

	printf("%-18s", "Start junction:");

	for(it = RoadsMap->begin(); it != RoadsMap->end(); it++) {
		temp = it->second->getBaginJnc();
		//temp = it->second->getStartJunction()->getId();
		printf("%-11s", temp.c_str());
	}
	for(int i = 0; i < 1; i++)
		cout << '\n';
}
