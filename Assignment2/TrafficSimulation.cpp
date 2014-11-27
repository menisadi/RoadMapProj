#include "TrafficSimulation.h"

TrafficSimulation::TrafficSimulation(){}
TrafficSimulation::TrafficSimulation(int simulationTimeNewVal,int maxSpeedVal ,int defultTimeSliceVal ,int maxTimeSliceVal ,int minTimeSliceVal):_SimulationTime(simulationTimeNewVal),_maxSpeed(maxSpeedVal),_defultTimeSlice(defultTimeSliceVal),_maxTimeSlice(maxTimeSliceVal),_minTimeSlice(minTimeSliceVal){}
TrafficSimulation::TrafficSimulation(int maxSpeedVal ,int defultTimeSliceVal ,int maxTimeSliceVal ,int minTimeSliceVal):_SimulationTime(0),_maxSpeed(maxSpeedVal),_defultTimeSlice(defultTimeSliceVal),_maxTimeSlice(maxTimeSliceVal),_minTimeSlice(minTimeSliceVal){}
TrafficSimulation::TrafficSimulation(const TrafficSimulation& copyTrafficSimulation){}
TrafficSimulation::~TrafficSimulation(){}
//TrafficSimulation& TrafficSimulation::operator=(const TrafficSimulation &TrafficSimulationRightArg){}

int TrafficSimulation::getSimulationTimeNew(){return _SimulationTime;}
int TrafficSimulation::getMaxSpeedVal(){return _maxSpeed;}
int TrafficSimulation::getDefultTimeSlice(){return _defultTimeSlice;}
int TrafficSimulation::getMaxTimeSlice(){return _maxTimeSlice;}
int TrafficSimulation::getMinTimeSlice(){return _minTimeSlice;}

void TrafficSimulation::setSimulationTimeNew(int simulationTimeNewVal){_SimulationTime=simulationTimeNewVal;}
void TrafficSimulation::setMaxSpeed(int maxSpeedVal){_maxSpeed=maxSpeedVal;}
void TrafficSimulation::setDefultTimeSlice(int defultTimeSliceVal){_defultTimeSlice=defultTimeSliceVal;}
void TrafficSimulation::setMaxTimeSlice(int maxTimeSliceVal){_maxSpeed=maxTimeSliceVal;}
void TrafficSimulation::setMinTimeSlice(int minTimeSliceVal){_minTimeSlice=minTimeSliceVal;}

void initTrafficSimulation()
{
	
}
void simulationManagement()
{
	//Data base// 
	map<string,Car*> CarsMap;  //The data base Is under the class of roads and here it's need to be Pointer*!
	map<string, Roads> RoadsMap;
	map<string,Junctions> JunctionsMap;
	TrafficSimulation TS1(100,5,10,1);

	
	//** Just for test  - take the place of Boost Func**//
	Junctions j1("j1");
	Junctions j2("j2");
	Junctions j3("j3");
	Junctions j4("j4");
	Junctions j5("j5");
	JunctionsMap[j1.getIdJunction()] = j1;
	JunctionsMap[j2.getIdJunction()] = j2;
	JunctionsMap[j3.getIdJunction()] = j3;
	JunctionsMap[j4.getIdJunction()] = j4;
	JunctionsMap[j5.getIdJunction()] = j5;
	Roads R13("j1j3","j1","j3",50);
	Roads R14("j1j4","j1","j5",20);
	Roads R15("j1j5","j1","j5",50);
	Roads R31("j3j1","j3","j1",70);
	Roads R52("j5j2","j5","j2",50);
	Roads R43("j4j3","j4","j3",90);
	RoadsMap[R13.getId()] = R13;
	RoadsMap[R14.getId()] = R14;
	RoadsMap[R15.getId()] = R15;
	RoadsMap[R31.getId()] = R31;
	RoadsMap[R52.getId()] = R52;
	RoadsMap[R43.getId()] = R43;
	Car C1("C1",0001);
	Car C2("C2",0002);
	Car C3("C3",0003);
	Car C4("C4",0004);
	Car C5("C5",0005);
	
	

	//** Just for test **//

}


int main(void)

{
	void simulationManagement();


	//for( map<string, Car>::iterator ii=CarsMap.begin(); ii!=CarsMap.end(); ++ii)
   //{

      // cout << (*ii).first << ": " << (*ii).second << endl;
	   //cout << (*ii).second.getID() << ": " << (*ii).second.getLocation() << endl;
	    //cout << "hi" << endl;
   //}





	 cout << "hi" << endl;
	return 0;
}
