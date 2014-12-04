
#ifndef _MAIN_H_
#define _MAIN_H_

#include <map>
#include <string>
#include <iostream>
#include "Car.h"
#include "Junctions.h"
// #include "Roads.h"
#include "TrafficSimulation.h"
#include "ini.h"
#include "Printer.h"

//for memory leak
#define CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

class Event;
//class Roads;
using namespace std;


//extern map<string, Car*>* CarMap;

void simulationManagement();
void simulationInit();
void deleteSimulation();

#endif