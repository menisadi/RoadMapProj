// THIS IS THE DECLARATION FILE OF THE CLASS TrafficSimulation (TrafficSimulation.h) 
#ifndef _TRAFFICSIMULATION_H_
#define _TRAFFICSIMULATION_H_

#include "GlobalVar.h"
//#include <map>
//#include <string>
//#include <iostream>
//#include "Car.h"
//#include "Junctions.h"
//#include "Roads.h"

//class Roads;
//class Car;
//class Junctions;

using namespace std;

  class TrafficSimulation
  {
  

  public:
     TrafficSimulation();
     TrafficSimulation(int simulationTimeNewVal  ,int maxSpeedVal ,int defultTimeSliceVal ,int maxTimeSliceVal ,int minTimeSliceVal);
	 TrafficSimulation(int maxSpeedVal ,int defultTimeSliceVal ,int maxTimeSliceVal ,int minTimeSliceVal);
     TrafficSimulation(const TrafficSimulation& copyTrafficSimulation);
     virtual ~TrafficSimulation();
     TrafficSimulation& operator=(const TrafficSimulation &TrafficSimulationRightArg);

	 int getSimulationTimeNew();
	 int getMaxSpeedVal();
	 int getDefultTimeSlice();
	 int getMaxTimeSlice();
	 int getMinTimeSlice();

	 void setSimulationTimeNew(int simulationTimeNewVal);
	 void setMaxSpeed(int maxSpeedVal);
	 void setDefultTimeSlice(int defultTimeSliceVal);
	 void setMaxTimeSlice(int maxTimeSliceVal);
	 void setMinTimeSlice(int minTimeSliceVal);
	 
	 void initTrafficSimulation();
	 void simulationManagement();

	 

  private:
	  int _SimulationTime;
	  int _maxSpeed;
	  int _defultTimeSlice;
	  int _maxTimeSlice;
	  int _minTimeSlice;
  };   
  
  #endif //_TRAFFICSIMULATION_H_