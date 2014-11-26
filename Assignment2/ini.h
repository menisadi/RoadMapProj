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

#include <boost/property_tree/ini_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/lexical_cast.hpp>

using namespace std;

class IniClass{
private:
	vector<string> IniClass::split(string toSplit);
public:
	IniClass();
	virtual ~IniClass();

	void IniClass::readEvents(vector<Event> allEvents);
	void IniClass::readCommands(vector<Commands> allCommands);
	void IniClass::readRoadMap(map<string, Junctions> junctions, map<string, Roads> roads);
	void IniClass::readConfiguration(); 
};

#endif /* INI_H_ */