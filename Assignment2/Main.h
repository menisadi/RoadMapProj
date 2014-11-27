
#ifndef _MAIN_H_
#define _MAIN_H_

#include <map>
#include <string>
#include <iostream>
#include "Car.h"
#include "Junctions.h"
#include "Roads.h"
#include "TrafficSimulation.h"

using namespace std;

void simulationManagement();
void simulationInit();

//*VARS*//
map<string, Roads>* RoadsMap;
map<string,Junctions>* JunctionsMap;
TrafficSimulation TS1;


#endif