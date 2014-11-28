#include "TrafficSimulation.h"

TrafficSimulation::TrafficSimulation(){ }
TrafficSimulation::TrafficSimulation(int simulationTimeNewVal, int maxSpeedVal, int defultTimeSliceVal, int maxTimeSliceVal, int minTimeSliceVal) :_SimulationTime(simulationTimeNewVal), _maxSpeed(maxSpeedVal), _defultTimeSlice(defultTimeSliceVal), _maxTimeSlice(maxTimeSliceVal), _minTimeSlice(minTimeSliceVal){ 
global_SimulationTime=simulationTimeNewVal;
global_maxSpeed=maxSpeedVal;
global_defultTimeSlice=defultTimeSliceVal;
global_maxTimeSlice=maxTimeSliceVal; 
global_minTimeSlice=minTimeSliceVal;
}
TrafficSimulation::TrafficSimulation(int maxSpeedVal, int defultTimeSliceVal, int maxTimeSliceVal, int minTimeSliceVal) : _SimulationTime(0), _maxSpeed(maxSpeedVal), _defultTimeSlice(defultTimeSliceVal), _maxTimeSlice(maxTimeSliceVal), _minTimeSlice(minTimeSliceVal){ }
TrafficSimulation::TrafficSimulation(const TrafficSimulation& copyTrafficSimulation){}
TrafficSimulation::~TrafficSimulation(){}
//TrafficSimulation& TrafficSimulation::operator=(const TrafficSimulation &TrafficSimulationRightArg){}

int TrafficSimulation::getSimulationTimeNew(){return _SimulationTime;}
int TrafficSimulation::getMaxSpeedVal(){return _maxSpeed;}
int TrafficSimulation::getDefultTimeSlice(){return _defultTimeSlice;}
int TrafficSimulation::getMaxTimeSlice(){return _maxTimeSlice;}
int TrafficSimulation::getMinTimeSlice(){return _minTimeSlice;}

void TrafficSimulation::setSimulationTimeNew(int simulationTimeNewVal){_SimulationTime=simulationTimeNewVal;global_SimulationTime=simulationTimeNewVal;}
void TrafficSimulation::setMaxSpeed(int maxSpeedVal){_maxSpeed=maxSpeedVal;global_maxSpeed=maxSpeedVal;}
void TrafficSimulation::setDefultTimeSlice(int defultTimeSliceVal){_defultTimeSlice=defultTimeSliceVal;global_defultTimeSlice=defultTimeSliceVal;}
void TrafficSimulation::setMaxTimeSlice(int maxTimeSliceVal){ _maxTimeSlice=maxTimeSliceVal;global_maxTimeSlice=maxTimeSliceVal; }
void TrafficSimulation::setMinTimeSlice(int minTimeSliceVal){_minTimeSlice=minTimeSliceVal;global_minTimeSlice=minTimeSliceVal;}

void initTrafficSimulation(){}
