/*
 * Printer.h
 *
 *  Created on: Dec 2, 2014
 *      Author: Ofer Caspi
 *
 *  Use instructions:
 *
 *  I assumed you represented Car, Road and Junction in classes with those names.
 *  In order to initialize this class, you need to provide a map<string, Road*>* that contains pointers to all your roads.
 *  There is a number of functions this class uses to display all the information,
 *  however, you can implement some of those functions to return some default value if you don't
 *  care about the information it provides.
 *
 *  This class needs you to implement to following functions:
 *
 *
 *  @param startJunction is the id of the junction from which the road we need starts at
 *  @return the time left for green light in the selected road
 *  int Junction::getGreenLightTimeLeft(string startJunctionId) const;
 *
 *  @return the id of the junction
 *  string Junction::getId() const;
 *
 *
 *  @return a pointer to the junction from which the roads start at
 *  const Junction* Road::getStartJunction() const;
 *
 *
 *  @return a pointer to the junction at which the road ends
 *  const Junction* Road::getEndJunction() const;
 *
 *
 *  @return the number of cars on the road
 *  int Road::getNumOfCars() const;
 *
 *
 *  @param location is the location of the car on the road, when the first car is the one closest to the end of the road
 *  @return the car at location @location on the road
 * 	for example, getCar(5) will return the 5th car on the road
 * 	if there is no such car, the function will return null
 *  Car* Road::getCar(int location) const;
 *
 *
 *  @return the last calculated speed of the road
 *  int Road::getBaseSpeed() const;
 *
 *
 *  @return the id of the car
 *  string Car::getId() const;
 *
 *
 *  @return time left for the car to be faulty
 *  int Car::getFaultyTimeLeft() const;
 *
 *
 *  @return the distance of the car on the road from the start junction
 *  int Car::getDistance() const;
 */


#ifndef SRC_PRINTER_H_
#define SRC_PRINTER_H_

#include <math.h>
#include <map>
#include <sstream>
#include <string>
#include "Car.h"
#include "Roads.h"
#include "Junctions.h"

using namespace std;

class Printer {
private:
	//map<string, Roads*>* roads;
public:
	//Printer(map<string, Roads*>* roads_);
	Printer();
	Printer(const Printer& printer);
	Printer& operator=(const Printer& printer);
	virtual ~Printer();

	void print(int currentTimeSlice);
};

#endif
