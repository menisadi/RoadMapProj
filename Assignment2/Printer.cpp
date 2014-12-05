/*
 * Printer.cpp
 *
 *  Created on: Dec 2, 2014
 *      Author: Ofer Caspi
 */

#include "Printer.h"

Printer::Printer() {
}

Printer::Printer(const Printer& printer) {
}

Printer& Printer::operator=(const Printer& printer) {
	return *this;
}

Printer::~Printer() {
}

void Printer::print(int currentTimeSlice) {
	int maxNumOfCars = 4;
	Car* car = NULL;
	string temp;
	ostringstream streamTemp;
	int tempInt;
	map<string, Roads*>::iterator it;

	for(int i = 0; i < 1; i++)
		{cout << '\n';}
	printf("%-18s%d\n", "Time:", global_SimulationTime);
	printf("\n%-18s", "Green time left:");
	
	for(it = RoadsMap->begin(); it != RoadsMap->end(); it++) {
		tempInt = JunctionsMap->find(it->second->getEndJnc())->second->getTimeSliceByAppeared();
		JunctionsMap->find(it->second->getEndJnc())->second->setForPrinterNumTimesAppearedPlusOne();
		if(tempInt == 0)
			{printf("%-11s", "0");}
		else
			{printf("%-11d", tempInt);}
	}
	for(it = RoadsMap->begin(); it != RoadsMap->end(); it++) {
		JunctionsMap->find(it->second->getEndJnc())->second->setForPrinterNumTimesAppearedZero();
	}

	printf("\n%-18s", "Speed:");

	for(it = RoadsMap->begin(); it != RoadsMap->end(); it++) {
		tempInt = it->second->getBaseSpeed();
		printf("%-11d", tempInt);
	}

	printf("\n%-18s", "End junction:");

	for(map<string, Junctions*>::iterator iv = JunctionsMap->begin(); iv != JunctionsMap->end(); iv++) {
		for(int p = 0; p < (iv->second->getRoadsInJunction()->size()) ; p++) {
			temp = iv->second->getIdJunction();
			printf("%-11s", temp.c_str());
			maxNumOfCars =  max(maxNumOfCars,(*iv->second->getRoadsInJunction())[p]->getNumOfCarInside());
		}
	}
		
	printf("\n");
	for(int i = 0; i < maxNumOfCars; i++) {
		printf("%-18s", "Cars:");
		for(map<string, Junctions*>::iterator iv = JunctionsMap->begin(); iv != JunctionsMap->end(); iv++) {
			for(int p = 0; p < (iv->second->getRoadsInJunction()->size()) ; p++) {
				if(  !((*iv->second->getRoadsInJunction())[p]->getCarsInRoad()->empty()) && ((*iv->second->getRoadsInJunction())[p]->getCarsInRoad()->size() > i)  ) {
					car = (*((*iv->second->getRoadsInJunction())[p]->getCarsInRoad()))[i];
					streamTemp.str("");
					if(car != NULL)
						{streamTemp << car->getID() << "(" << car->getLocation() << "," << car->getCondition() << ")";}
					else
						{streamTemp << "^";}
					
					printf("%-11s", streamTemp.str().c_str());

				}
				else{printf("%-11s","");}
			}
		}
		printf("\n");
	}

		printf("%-18s", "Start junction:");

		for(map<string, Junctions*>::iterator iv = JunctionsMap->begin(); iv != JunctionsMap->end(); iv++) {
			for(int p = 0; p < (iv->second->getRoadsInJunction()->size()) ; p++) {
				temp = (*iv->second->getRoadsInJunction())[p]->getBaginJnc();
				printf("%-11s", temp.c_str());
			}
		}

		for(int i = 0; i < 2; i++)
		{cout << '\n';}
	
}
