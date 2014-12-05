#include "ini.h"

IniClass::IniClass(){}

IniClass::~IniClass() {}

vector<Roads*> IniClass::split(string toSplit, map<string, Roads*>*& allRoads)
{
	vector<Roads*> splitted;
	size_t indexStart = 0;
	size_t indexMiddle = 0;
	size_t indexEnd = 0;
	string tmpStr;
	string nameOfRoad;
	
	tmpStr = toSplit;
	tmpStr.append(",");
	indexStart = 0;
	indexMiddle = tmpStr.find_first_of(',') + 1;
	indexEnd = 0;

	while (indexEnd < tmpStr.length())
	{
		indexEnd = tmpStr.find_first_of(',', indexMiddle) + 1;
		nameOfRoad = tmpStr.substr(indexStart, (indexEnd - indexStart) - 1);
		splitted.push_back(allRoads->find(nameOfRoad)->second);				
		indexStart = indexMiddle;
		indexMiddle = indexEnd;
	}
	reverse(splitted.begin(),splitted.end());
	return splitted;
}

void IniClass::readEvents(multimap<int, Event*>*& eventsInTimeOrder, map<string, Roads*>*& allRoads) {
	//std::cout << "Starting to read events" << endl;
	boost::property_tree::ptree pt;
	boost::property_tree::ini_parser::read_ini("Events.ini", pt);
	for (boost::property_tree::ptree::const_iterator section = pt.begin(); section != pt.end(); section++) 
	{
		string eventName = section->first;
		boost::property_tree::ptree::const_iterator property = section->second.begin();
		string eventType = property->second.data();
		property++;
		int eventTime = boost::lexical_cast<int>(property->second.data());
		property++;
		string carName = property->second.data();
		property++;
		int typeNumber;
		if (eventType[4] == 'a')
		{
			typeNumber = 0;
			string carRoute = property->second.data();
			vector<Roads*>* routeVector=new vector<Roads*>(split(carRoute,allRoads));
			AddCarEvent* tmp = new AddCarEvent(carName, routeVector, eventTime) ;
			eventsInTimeOrder->insert(pair<int, AddCarEvent*>(eventTime, tmp));
			// cout << ""<<endl;
		}
		else
		{
			typeNumber = 1;
			int faultTime = boost::lexical_cast<int>(property->second.data());
			//allEvents->push_back(new CarFaulttEvent(carName, faultTime, eventTime));
			CarFaulttEvent* newFaultEvent = new CarFaulttEvent(carName, faultTime, eventTime);
			eventsInTimeOrder->insert(pair<int, CarFaulttEvent*>(eventTime, newFaultEvent));
		}
	}
	//std::cout << "Finished events" << endl;
}

void IniClass::readCommands(multimap<int, Reports*>*& allReports)
{
	//std::cout << "Starting to read Commands" << endl;
	boost::property_tree::ptree pt;
	boost::property_tree::ini_parser::read_ini("Commands.ini", pt);
	for (boost::property_tree::ptree::const_iterator section = pt.begin(); section != pt.end(); section++)
	{
		string CommandsName = section->first;
		boost::property_tree::ptree::const_iterator property = section->second.begin();
		string CommandsType = property->second.data();
		property++;
		int CommandsTime = boost::lexical_cast<int>(property->second.data());
		int typeNumber;
		if (CommandsType[0] == 't')
		{
			typeNumber = 0;
			global_inputSimulationTime = CommandsTime;
		}

		else
		{
			property++;
			string reportId = property->second.data();
			property++;
			if (CommandsType[0] == 'c')
			{
				typeNumber = 1;
				string carId = property->second.data();
				// (*allReports)[CommandsTime] = new CarReport(CommandsName, CommandsTime, carId);
				CarReport* newCarReport = new CarReport(CommandsName, CommandsTime, carId);
				allReports->insert(pair<int, CarReport*>(CommandsTime, newCarReport));
			}
			
			else if (CommandsType[0] == 'r')
			{
				typeNumber = 2;
				string startJunction = property->second.data();
				property++;
				string endJunction = property->second.data();
				// (*allReports)[CommandsTime] = new RoadReport(CommandsName, CommandsTime, startJunction, endJunction);
				RoadReport* newRoadReport = new RoadReport(CommandsName, CommandsTime, startJunction, endJunction);
				allReports->insert(pair<int, RoadReport*>(CommandsTime, newRoadReport));
			}
			else if (CommandsType[0] == 'j')
			{
				typeNumber = 3;
				string junctionId = property->second.data();
				// (*allReports)[CommandsTime] = new JunctionReport(CommandsName, CommandsTime, junctionId);
				JunctionReport* newJunctionReport = new JunctionReport(CommandsName, CommandsTime, junctionId);
				allReports->insert(pair<int, JunctionReport*>(CommandsTime, newJunctionReport));
			}
			
		}
		
	}
	//std::cout << "Finished Commands" << endl;
}


void IniClass::readRoadMap(map<string, Junctions*>*& junctions, map<string, Roads*>*& roads)
{
	//std::cout << "Starting to read road map" << endl;
	boost::property_tree::ptree pt;
	boost::property_tree::ini_parser::read_ini("RoadMap.ini", pt);
	for (boost::property_tree::ptree::const_iterator section = pt.begin(); section != pt.end(); section++)
	{
		string endJunction = section->first;
		string startJunction;
		vector<Roads*>* roadsInJunction = new vector<Roads*>();
		vector<int>* timeSlices = new vector<int>();
		vector<int>* timeSliceBeforeTheGreenLight = new vector<int>();
		for (boost::property_tree::ptree::const_iterator property = section->second.begin(); property != section->second.end(); property++)
		{
			startJunction = property->first.data();
			int length = boost::lexical_cast<int>(property->second.data());
			string roadId = startJunction + "," + endJunction;
			Roads* pointerToRoad = new Roads(roadId, startJunction, endJunction, length);
			roads->insert(pair<string, Roads*>(roadId, pointerToRoad));
			pointerToRoad = (roads->find(roadId))->second;
			roadsInJunction->push_back(pointerToRoad);
			timeSlices->push_back(global_defultTimeSlice);
			timeSliceBeforeTheGreenLight->push_back(global_defultTimeSlice);
		}
		Junctions* newJunction = new Junctions(endJunction, roadsInJunction, timeSlices,timeSliceBeforeTheGreenLight);
		junctions->insert(pair<string, Junctions*>(endJunction,newJunction));
		//delete roadsInJunction;
	}
	//std::cout << "Finished to read road map" << endl;
}

//void IniClass::readConfiguration(TrafficSimulation*& simulation)
void IniClass::readConfiguration()
{
	//std::cout << "Starting to read configuration" << endl;
	boost::property_tree::ptree pt;
	boost::property_tree::ini_parser::read_ini("Configuration.ini", pt);
	
	int MAX_SPEED = pt.get<int>("Configuration.MAX_SPEED");
	int DEFAULT_TIME_SLICE = pt.get<int>("Configuration.DEFAULT_TIME_SLICE");
	int MAX_TIME_SLICE = pt.get<int>("Configuration.MAX_TIME_SLICE");
	int MIN_TIME_SLICE = pt.get<int>("Configuration.MIN_TIME_SLICE");
	global_maxSpeed=MAX_SPEED;
	global_defultTimeSlice=DEFAULT_TIME_SLICE;
	global_maxTimeSlice=MAX_TIME_SLICE; 
	global_minTimeSlice=MIN_TIME_SLICE;
	
	/*
	simulation->setMaxSpeed(MAX_SPEED);
	simulation->setDefultTimeSlice(DEFAULT_TIME_SLICE);
	simulation->setMaxTimeSlice(MAX_TIME_SLICE);
	simulation->setMinTimeSlice(MIN_TIME_SLICE);
	*/
	
	//std::cout << "Finished to read configuration" << endl;
}
