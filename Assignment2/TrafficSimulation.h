#ifndef _TRAFFICSIMULATION_H_
#define _TRAFFICSIMULATION_H_

// THIS IS THE DECLARATION FILE OF THE CLASS TrafficSimulation (TrafficSimulation.h) 
  class TrafficSimulation
  {
  private:
	 vactor<> Event_;
	 Vactor Commands_;
     Vactor Roads_;  
	 Vactor Cars_;
	 int SimulationTime;
  public:
     TrafficSimulation();
     TrafficSimulation(????);
     TrafficSimulation(const TrafficSimulation& copyTrafficSimulation);
     virtual ~TrafficSimulation();
     TrafficSimulation& operator=(const TrafficSimulation &TrafficSimulationRightArg);
	 
	 initTrafficSimulation();
	 simulationManagement();
	 
  };   
  
  #endif //_TRAFFICSIMULATION_H_