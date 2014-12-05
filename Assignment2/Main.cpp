#include "Main.h"

//Global var
multimap<int, Event*>* eventsInTimeOrder;
multimap<int, Reports*>* reportsInTimeOrder;
boost::property_tree::ptree* pt = new boost::property_tree::ptree();
Printer printerSim;

void simulationInit()
{
	eventsInTimeOrder = new multimap<int, Event*>();
	reportsInTimeOrder = new multimap<int, Reports*>();
	IniClass ic;
	ic.readConfiguration();
	ic.readRoadMap(JunctionsMap, RoadsMap); 
	ic.readEvents(eventsInTimeOrder,RoadsMap);
	ic.readCommands(reportsInTimeOrder);
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
	//2. Execute Commands
		multimap<int, Reports*>::iterator itReports = reportsInTimeOrder->begin();
		while ((!(reportsInTimeOrder->empty())) && ((*itReports).first == global_SimulationTime)){
			((*itReports).second)->writeReport(*pt);
			reportsInTimeOrder->erase(itReports);
			itReports = reportsInTimeOrder->begin();
		}
	//print all
		printerSim.print(global_defultTimeSlice);
	//3. Update car History
	//3. Advance cars in roads
		for( map<string, Roads*>::iterator itRoads=RoadsMap->begin(); itRoads!=RoadsMap->end(); ++itRoads)  
			(*itRoads).second->advanceCarsInRoad();
	//4. Advance cars in junctions
		for( map<string, Junctions*>::iterator itJunctions =JunctionsMap->begin(); itJunctions!=JunctionsMap->end(); ++itJunctions)
			(*itJunctions).second->advanceCarsInJunctions();
}

void deleteSimulation(){
	for( map<string, Junctions*>::iterator ii=JunctionsMap->begin(); ii!=JunctionsMap->end(); ++ii)
		 delete (ii->second);
	delete(JunctionsMap);
	delete(RoadsMap);
	delete(CarMap);
	for( multimap<int, Event*>::iterator ii=eventsInTimeOrder->begin(); ii!=eventsInTimeOrder->end(); ++ii)
		 delete (ii->second);
	delete(eventsInTimeOrder);
	for( multimap<int, Reports*>::iterator ii=reportsInTimeOrder->begin(); ii!=reportsInTimeOrder->end(); ++ii)
		 delete (ii->second);
	delete(reportsInTimeOrder);

	delete(pt);

	_CrtDumpMemoryLeaks();
}

int main(void)
{
	simulationInit();
	for(global_SimulationTime = 1; global_SimulationTime <= global_inputSimulationTime ; ++global_SimulationTime )
		simulationManagement();
	write_ini("Reports.ini", *pt);
	deleteSimulation();
	return 0;
}