
#include "ini.h"

#include <boost/property_tree/ini_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/lexical_cast.hpp>

IniClass::IniClass(){}

IniClass::~IniClass() {}

void IniClass::read1() const{
	cout << "Starting read1" << endl;
	boost::property_tree::ptree pt;
	boost::property_tree::ini_parser::read_ini("Events.ini", pt);
	int time = pt.get<int>("event_2.time");
	string carId = pt.get<string>("event_2.carId");
	string roadPlan = pt.get<string>("event_2.roadPlan");

	/*
	int name1 = pt.get<int>("Section1.name1");
	int name2 = pt.get<int>("Section1.name2");
	string string1 = pt.get<string>("Section2.name3");
	string string2 = pt.get<string>("Section2.name4");
	*/

	cout << "Event_2.time = " << time << endl;
	cout << "the car ID = " << carId << endl;
	cout << "road plan = " << roadPlan << endl;
	//cout << "Section2.name4 = " << string2 << endl;
	cout << "Finished read1" << endl;
}

void IniClass::read2() const{
	cout << "Starting read2" << endl;
	boost::property_tree::ptree pt;
	boost::property_tree::ini_parser::read_ini("file.ini", pt);
	for (boost::property_tree::ptree::const_iterator section = pt.begin(); section != pt.end(); section++) {
		cout << "[" << section->first << "]" << endl;
		if (((string)section->first)[7] == '1')
			for (boost::property_tree::ptree::const_iterator property = section->second.begin(); property != section->second.end(); property++) {
			cout << property->first << "=" << boost::lexical_cast<int>(property->second.data()) << endl;
			}
		else
			for (boost::property_tree::ptree::const_iterator property = section->second.begin(); property != section->second.end(); property++) {
			cout << property->first << "=" << boost::lexical_cast<string>(property->second.data()) << endl;
			}
	}
	cout << "Finished read2" << endl;
}

int main(){
	IniClass ic;
	ic.read1();
	// ic.read2();
}
