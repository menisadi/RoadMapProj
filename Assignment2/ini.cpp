#include "ini.h"

IniClass::IniClass(){}

IniClass::~IniClass() {}

vector<Roads*> IniClass::split(string toSplit, map<string, Roads>*& allRoads)
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
		splitted.push_back(&(allRoads->find(nameOfRoad)->second));				
		indexStart = indexMiddle;
		indexMiddle = indexEnd;
	}
	std::rotate(splitted.begin(),
            splitted.end()-1, // this will be the new first element
            splitted.end());
	return splitted;
}

void IniClass::readEvents(map<int, Event*>*& eventsInTimeOrder, map<string, Roads>*& allRoads) {
	cout << "Starting to read events" << endl;
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
			//vector<Roads*> routeVector(split(carRoute,allRoads));
			vector<Roads*>* routeVector=new vector<Roads*>(split(carRoute,allRoads));
			AddCarEvent* tmp=new AddCarEvent(carName, routeVector, eventTime) ;
			//eventsInTimeOrder->push_back(tmp);
			(*eventsInTimeOrder)[eventTime]=tmp;

			// cout << ""<<endl;
		}
		else
		{
			typeNumber = 1;
			int faultTime = boost::lexical_cast<int>(property->second.data());
			//allEvents->push_back(new CarFaulttEvent(carName, faultTime, eventTime));
			(*eventsInTimeOrder)[eventTime]=new CarFaulttEvent(carName, faultTime, eventTime);
		}
	}
	cout << "Finished events" << endl;
}


void IniClass::readCommands(vector<Reports*>*& allReports)
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
		{
			typeNumber = 0;
			global_inputSimulationTime = CommandsTime;
		}
		else
		{
			property++;
			string reportId = property->second.data;
			property++;

			if (CommandsType[0] == 'c')
			{
				typeNumber = 1;
				string carId = property->second.data;
				allReports->push_back(new CarReport(CommandsName, CommandsTime, carId));
			}
			else if (CommandsType[0] == 'r')
			{
				typeNumber = 2;
				string startJunction = property->second.data;
				property++;
				string endJunction = property->second.data;
				allReports->push_back(new RoadReport(CommandsName,CommandsTime,startJunction,endJunction));
			}
			else if (CommandsType[0] == 'j')
			{
				typeNumber = 3;
				string junctionId = property->second.data;
				allReports->push_back(new JunctionReport(CommandsName, CommandsTime, junctionId));
			}
		}		
	}
	cout << "Finished Commands" << endl;
}


void IniClass::readRoadMap(map<string, Junctions>*& junctions, map<string, Roads>*& roads)
{
	cout << "Starting to read road map" << endl;
	boost::property_tree::ptree pt;
	boost::property_tree::ini_parser::read_ini("RoadMap.ini", pt);
	for (boost::property_tree::ptree::const_iterator section = pt.begin(); section != pt.end(); section++)
	{
		string endJunction = section->first;
		string startJunction;
		vector<Roads*>* roadsInJunction = new vector<Roads*>();
		vector<int> timeSlices;
		for (boost::property_tree::ptree::const_iterator property = section->second.begin(); property != section->second.end(); property++)
		{
			startJunction = property->first.data();
			int length = boost::lexical_cast<int>(property->second.data());
			string roadId = startJunction + "," + endJunction;
			Roads* pointerToRoad = new Roads(roadId, startJunction, endJunction, length);
			// Roads newRoad(roadId, startJunction, endJunction, length);
			// Roads* pointerToRoad = &newRoad;
			roads->insert(pair<string, Roads>(roadId, *pointerToRoad));
			pointerToRoad = &((roads->find(roadId))->second);
			roadsInJunction->push_back(pointerToRoad);
			timeSlices.push_back(global_defultTimeSlice);
		}
		Junctions newJunction(endJunction, *roadsInJunction, timeSlices);
		junctions->insert(pair<string, Junctions>(endJunction,newJunction));
		delete roadsInJunction;
	}
	cout << "Finished to read road map" << endl;
}

//void IniClass::readConfiguration(TrafficSimulation*& simulation)
void IniClass::readConfiguration()
{
	cout << "Starting to read configuration" << endl;
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
	
	cout << "Finished to read configuration" << endl;
}
