#include "Main.h"

//Global var
map<string, Roads>* RoadsMap;
map<string, Junctions>* JunctionsMap;
multimap<int, Event*>* eventsInTimeOrder;
multimap<int, Reports*>* reportsInTimeOrder;
map<string, Car*>* CarMap;
boost::property_tree::ptree* pt = new boost::property_tree::ptree();

void simulationInit()
{
	CarMap = new map<string, Car*>();
	RoadsMap = new map<string, Roads>();
	JunctionsMap = new map<string, Junctions>();
	eventsInTimeOrder = new multimap<int, Event*>();
	reportsInTimeOrder = new multimap<int, Reports*>();
	IniClass ic;
	ic.readConfiguration();
	ic.readRoadMap(JunctionsMap, RoadsMap); 
	ic.readEvents(eventsInTimeOrder,RoadsMap);
	ic.readCommands(reportsInTimeOrder);
	cout << "just a bbreakpoint" << endl;
}

void simulationManagement()
{
	//1. Execute Events
		multimap<int, Event*>::iterator itEvents = eventsInTimeOrder->begin(); 
		while( (!(eventsInTimeOrder->empty())) && ((*itEvents).first == global_SimulationTime )){
				((*itEvents).second)->performEvent();
				eventsInTimeOrder->erase(itEvents);
				itEvents = eventsInTimeOrder->begin();
			}
	//1.1 Output reports
		multimap<int, Reports*>::iterator itReports = reportsInTimeOrder->begin();
		while ((!(reportsInTimeOrder->empty())) && ((*itReports).first == global_SimulationTime)){
			((*itReports).second)->writeReport(*pt);
			reportsInTimeOrder->erase(itReports);
			itReports = reportsInTimeOrder->begin();
		}
	//1.2 Update car History
	//2. Execute Commands
	//3. Advance cars in roads
		for( map<string, Roads>::iterator itRoads=RoadsMap->begin(); itRoads!=RoadsMap->end(); ++itRoads)  //i stop here! Note: So far the vehicles are in. Should check out the following functions from here on also need to add the issue of reports and operating history of the event Car Damaged
			(*itRoads).second.advanceCarsInRoad();
	//4. Advance cars in junctions
		for( map<string, Junctions>::iterator itJunctions =JunctionsMap->begin(); itJunctions!=JunctionsMap->end(); ++itJunctions)
			(*itJunctions).second.advanceCarsInJunctions();
}

int main(void)
{
	
	// global_inputSimulationTime=20;
	simulationInit();
	for(global_SimulationTime = 1; global_SimulationTime <= global_inputSimulationTime ; ++global_SimulationTime )
		simulationManagement();
	write_ini("Reports.ini", *pt);
	return 0;
}