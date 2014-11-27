#include "ini.h"

IniClass::IniClass(){}

IniClass::~IniClass() {}

vector<string> IniClass::split(string toSplit)
{
	vector<string> splitted;
	size_t indexStart = 0;
	size_t indexMiddle = 0;
	size_t indexEnd = 0;
	string tmpStr;
	string nameOfRoad;
	
	tmpStr = toSplit;
	indexStart = 0;
	indexMiddle = tmpStr.find_first_of(',') + 1;
	indexEnd = 0;

	while (indexEnd < tmpStr.length())
	{
		indexEnd = tmpStr.find_first_of(',', indexMiddle) + 1;
		nameOfRoad = tmpStr.substr(indexStart, (indexEnd - indexStart) - 1);
		splitted.push_back(nameOfRoad);
		indexStart = indexMiddle;
		indexMiddle = indexEnd;
	}
	return splitted;
}

void IniClass::readEvents(vector<Event> allEvents) {
	cout << "Starting to read events" << endl;
	boost::property_tree::ptree pt;
	boost::property_tree::ini_parser::read_ini("Events.ini", pt);
	for (boost::property_tree::ptree::const_iterator section = pt.begin(); section != pt.end(); section++) 
	{
		string eventName = section->first;
		boost::property_tree::ptree::const_iterator property = section->second.begin();
		string eventType = property->second.data;
		property++;
		int eventTime = property->second.data;
		property++;
		string carName = property->second.data;
		property++;
		int typeNumber;
		if (eventType[4] == 'a')
		{
			typeNumber = 0;
			string carRoute = property->second.data;
			vector<string> routeVector(split(carRoute));
			allEvents.push_back(AddCarEvent(carName, routeVector, eventTime));
		}
		else
		{
			typeNumber = 1;
			int faultTime = property->second.data;
			allEvents.push_back(new CarFaulttEvent(carName, faultTime, eventTime));
		}
	}
	cout << "Finished events" << endl;
}

void IniClass::readCommands(vector<Commands> allCommands)
{
	cout << "Starting to read Commands" << endl;
	boost::property_tree::ptree pt;
	boost::property_tree::ini_parser::read_ini("Commands.ini", pt);
	for (boost::property_tree::ptree::const_iterator section = pt.begin(); section != pt.end(); section++)
	{
		string CommandsName = section->first;
		boost::property_tree::ptree::const_iterator property = section->second.begin();
		string CommandsType = property->second.data;
		property++;
		int CommandsTime = property->second.data;
		int typeNumber;
		if (CommandsType[0] == 't')
			typeNumber = 0; // enter commandTime into the overall timer
		else
		{
			property++;
			string reportId = property->second.data;
			property++;

			if (CommandsType[0] == 'c')
			{
				typeNumber = 1;
				string carId = property->second.data;
				// allCommands.push_back(new CarReport());
			}
			else if (CommandsType[0] == 'r')
			{
				typeNumber = 2;
				string startJunction = property->second.data;
				property++;
				string startJunction = property->second.data;
				// allCommands.push_back(new CarReport());
			}
			else if (CommandsType[0] == 'j')
			{
				typeNumber = 3;
				string junctionId = property->second.data;
				// allCommands.push_back(new CarReport());
			}
		}		
	}
	cout << "Finished Commands" << endl;
}

void IniClass::readRoadMap(map<string, Junctions> junctions, map<string, Roads> roads)
{
	cout << "Starting to read road map" << endl;
	boost::property_tree::ptree pt;
	boost::property_tree::ini_parser::read_ini("RoadMap.ini", pt);
	for (boost::property_tree::ptree::const_iterator section = pt.begin(); section != pt.end(); section++)
	{
		string startJunction = section->first;
		vector<Roads*> roadsInJunction;
		for (boost::property_tree::ptree::const_iterator property = section->second.begin(); property != section->second.begin(); property++)
		{
			string endJunction = property->first.data;
			int length = property->second.data;
			string roadId = startJunction + "," + endJunction;
			Roads newRoad(roadId, startJunction, endJunction, length); // check if fits constructor
			Roads* pointerToRoad = &newRoad;
			roads.insert(pair<string, Roads>(roadId,newRoad));
			roadsInJunction.push_back(pointerToRoad);
		}
		Junctions newJunction(startJunction, roadsInJunction, timeSlice); // insert default timeSlices
		junctions.insert(pair<string, Junctions>(startJunction,newJunction));
	}
	cout << "Finished to read road map" << endl;
}

void IniClass::readConfiguration(TrafficSimulation simulation)
{
	cout << "Starting to read configuration" << endl;
	boost::property_tree::ptree pt;
	boost::property_tree::ini_parser::read_ini("Configuration.ini", pt);
	
	int MAX_SPEED = pt.get<int>("Configuration.MAX_SPEED");
	int DEFAULT_TIME_SLICE = pt.get<int>("Configuration.DEFAULT_TIME_SLICE");
	int MAX_TIME_SLICE = pt.get<int>("Configuration.MAX_TIME_SLICE");
	int MIN_TIME_SLICE = pt.get<int>("Configuration.MIN_TIME_SLICE");
	// insert into simulation's fiealds
	
}