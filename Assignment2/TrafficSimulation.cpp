#include "TrafficSimulation.h"

TrafficSimulation::TrafficSimulation():SimulationTime_(0){}

TrafficSimulation::TrafficSimulation(int SimulationTimeNew):SimulationTime_(SimulationTimeNew){}

TrafficSimulation::TrafficSimulation(const TrafficSimulation& copyTrafficSimulation)
{
}

TrafficSimulation::~TrafficSimulation()
{
}

//TrafficSimulation& TrafficSimulation::operator=(const TrafficSimulation &TrafficSimulationRightArg)
//{
	
//}

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
	map<string,Car> CarsMap;
	map<string, Roads> RoadsMap;
	map<string,Junctions> JunctionsMap;

	//** Just for test  - take the place of Boost Func**//
	Car C1;
	C1.setID("C1");
	C1.setArrival(5);
	C1.setCondition(0);
	C1.setLocation(20);
	C1.setspeed(5);
	Car C2("C2",6,0,10,2);

	Junctions J1;
	Roads R1;

	//** Just for test **//

	CarsMap.insert(std::pair<string,Car>(C2.getID(),C2));
	CarsMap[C1.getID()] = C1;


	for( map<string, Car>::iterator ii=CarsMap.begin(); ii!=CarsMap.end(); ++ii)
   {

      // cout << (*ii).first << ": " << (*ii).second << endl;
	   cout << (*ii).second.getID() << ": " << (*ii).second.getLocation() << endl;
	    //cout << "hi" << endl;
   }

	 cout << "hi" << endl;
	return 0;
}
