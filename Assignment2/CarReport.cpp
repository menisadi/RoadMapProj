#include "CarReport.h"

CarReport::CarReport(){}

CarReport::CarReport(string reportId, int time, string carId)
	: Reports(reportId, time), carId_(carId) {}

CarReport::CarReport(CarReport &other) : Reports(other), carId_(other.carId_){}

CarReport& CarReport::operator=(const CarReport &R)
{
	Reports::operator=(R);
	carId_ = R.carId_;
	return *this;
}

CarReport::~CarReport(){}

void CarReport::writeReport(boost::property_tree::ptree &tree)
{
	// boost::property_tree::ptree pt;
	//string reportId = Reports::getId();
	// string check = Reports::getId();
	tree.put(Reports::getId().append(".car ID"), carId_);
	// Overwrites the value
	tree.put(Reports::getId().append(".history"), global_SimulationTime);
	// Adds a second node with the new value.
	tree.put(Reports::getId().append(".fault time left"), global_SimulationTime);
	// tree.put("a.try", 2);
}

string CarReport::getCarId(){ return carId_; }
void CarReport::setCarId(string newCarId){ carId_ = newCarId; }