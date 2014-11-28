#ifndef INI_H_
#define INI_H_

#include <iostream>
#include <string>
#include <map>
#include "AddCarEvent.h"
#include "CarFaulttEvent.h"
#include "Commands.h"
#include "CarReport.h"
#include "Junctions.h"
#include "Roads.h"
#include "TrafficSimulation.h"

#include <boost/property_tree/ini_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/lexical_cast.hpp>

using namespace std;

class IniClass{
private:
	vector<Roads*> IniClass::split(string toSplit, map<string, Roads>*& allRoads);
public:
	IniClass();
	virtual ~IniClass();

	void IniClass::readEvents(vector<Event>*& allEvents, map<string, Roads>*& allRoads) {
	void readCommands(vector<Commands> allCommands);
	void readRoadMap(map<string, Junctions>*& junctions, map<string, Roads>*& roads, int defaultTimeSlice);
	void readConfiguration(TrafficSimulation*& simulation);

};

#endif /* INI_H_ */