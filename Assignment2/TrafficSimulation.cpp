#include "TrafficSimulation.h"

TrafficSimulation::TrafficSimulation(){}
TrafficSimulation::TrafficSimulation(int simulationTimeNewVal,int maxSpeedVal ,int defultTimeSliceVal ,int maxTimeSliceVal ,int minTimeSliceVal):_SimulationTime(simulationTimeNewVal),_maxSpeed(maxSpeedVal),_defultTimeSlice(defultTimeSliceVal),_maxTimeSlice(maxTimeSliceVal),_minTimeSlice(minTimeSliceVal){}
TrafficSimulation::TrafficSimulation(int maxSpeedVal ,int defultTimeSliceVal ,int maxTimeSliceVal ,int minTimeSliceVal):_maxSpeed(maxSpeedVal),_defultTimeSlice(defultTimeSliceVal),_maxTimeSlice(maxTimeSliceVal),_minTimeSlice(minTimeSliceVal){}
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
	//1. Execute Events
		//1.1 Output reports
		//1.2 Update car History
	//2. Execute Commands
	//3. Advance cars in roads
	//4. Advance cars in junctions
}


int main(void)

{
	//Data base// 
	map<string,Car*> CarsMap;  //The data base Is under the class of roads and here it's need to be Pointer*!
	map<string, Roads> RoadsMap;
	map<string,Junctions> JunctionsMap;

	//** Just for test  - take the place of Boost Func**//

	//const char *testRouteinit[] = {"j1", "j2", "j3"};
	//vector<string> testRoute(testRouteinit, end(testRouteinit)); 

	Junctions j1("j1");
	Junctions j2("j2");
	Junctions j3("j3");
	Junctions j4("j4");
	Junctions j5("j5");
	Roads R1("j1j3","j1","j3",50);
	Roads R1("j1j4","j1","j5",20);
	Roads R1("j1j5","j1","j5",50);
	Roads R1("j3j1","j3","j1",70);
	Roads R1("j5j2","j5","j2",50);
	Roads R1("j4j3","j4","j3",90);

   //  Roads(const string& IdVal,const string& baginJncVal, const string& endJncVal,int lengthVal);

	//Roads R1;

	Car C1;
	Car C2;

	//const char *testRouteinit2[] = {"j2", "j3"};
	//vector<string> testRoute2(testRouteinit2, end(testRouteinit2)); 
	//Car C2("C2",testRoute2,6,0,10,2);

	

	//** Just for test **//

	//CarsMap.insert(std::pair<string,Car>(C2.getID(),C2));
	//CarsMap[C1.getID()] = C1;


	//for( map<string, Car>::iterator ii=CarsMap.begin(); ii!=CarsMap.end(); ++ii)
   //{

      // cout << (*ii).first << ": " << (*ii).second << endl;
	   //cout << (*ii).second.getID() << ": " << (*ii).second.getLocation() << endl;
	    //cout << "hi" << endl;
   //}

	 cout << "hi" << endl;
	return 0;
}
