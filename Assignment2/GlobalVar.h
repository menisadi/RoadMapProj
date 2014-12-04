#ifndef _GLOBALVAR_H_
#define _GLOBALVAR_H_

#include <string>
#include <Map>
using namespace std;
class Car;
class Roads;
class Junctions;

extern  int global_inputSimulationTime;
extern  int global_SimulationTime;
extern  int global_maxSpeed;
extern  int global_defultTimeSlice;
extern  int global_maxTimeSlice;
extern  int global_minTimeSlice;
extern map<string, Car*>* CarMap;
extern map<string, Roads*>* RoadsMap;
extern map<string, Junctions*>* JunctionsMap;

#endif