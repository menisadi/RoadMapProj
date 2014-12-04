#include "GlobalVar.h"

int global_inputSimulationTime=0;
int global_SimulationTime=0;
int global_maxSpeed=0;
int global_defultTimeSlice=0;
int global_maxTimeSlice=0;
int global_minTimeSlice=0;
map<string, Car*>* CarMap=new map<string, Car*>();
map<string, Roads*>* RoadsMap = new map<string, Roads*>();
map<string, Junctions*>* JunctionsMap = new map<string, Junctions*>();
