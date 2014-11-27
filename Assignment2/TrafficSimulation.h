// THIS IS THE DECLARATION FILE OF THE CLASS TrafficSimulation (TrafficSimulation.h) 
#ifndef _TRAFFICSIMULATION_H_
#define _TRAFFICSIMULATION_H_

#include <map>
#include <string>
//#include "Car.h"
//#include "Roads.h"
//#include "Junctions.h"
#include <iostream>


using namespace std;

  class TrafficSimulation
  {
  private:
	  int SimulationTime_;

  public:
     TrafficSimulation();
     TrafficSimulation(int SimulationTimeNew);
     TrafficSimulation(const TrafficSimulation& copyTrafficSimulation);
     virtual ~TrafficSimulation();
     TrafficSimulation& operator=(const TrafficSimulation &TrafficSimulationRightArg);
	 
	 void initTrafficSimulation();
	 void simulationManagement();
	 
  };   
  
  #endif //_TRAFFICSIMULATION_H_