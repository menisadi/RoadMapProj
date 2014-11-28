#include "Main.h"

map<string, Roads>* RoadsMap;
map<string, Junctions>* JunctionsMap;
TrafficSimulation* TS1;
vector<Event*>* events1;

void simulationInit()
{
	//*Data base*//
	 IniClass ic;
	 ic.readRoadMap(JunctionsMap, RoadsMap, 150); //&JunctionsMap, &RoadsMap,
	 ic.readConfiguration(TS1);
	 ic.readEvents(events1,RoadsMap);

	 (*events1)[1]->performEvent();
	 events1->pop_back();
	 (*events1)[0]->performEvent();
	 events1->pop_back();
}

int main(void)
{
	RoadsMap = new map<string, Roads>();;
	JunctionsMap = new map<string, Junctions>();
	TS1 = new TrafficSimulation(0, 0, 0, 0, 0);
	events1 = new vector<Event*>();

	simulationInit();	
	// cout << TS1->getMaxTimeSlice() << endl;
	// cout << JunctionsMap << endl;
	// cout << TS1->getMaxSpeedVal << endl;
	return 0;
}







//Draft!!!!!//

	//** Just for test  - take the place of Boost Func**//
	/*
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
	
	*/
	//** Just for test **//

	//for( map<string, Car>::iterator ii=CarsMap.begin(); ii!=CarsMap.end(); ++ii)
   //}
      // cout << (*ii).first << ": " << (*ii).second << endl;
	   //cout << (*ii).second.getID() << ": " << (*ii).second.getLocation() << endl;
   //}