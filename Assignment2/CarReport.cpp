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
	tree.put(Reports::getId().append(".car ID"), carId_);
	//string history = (*CarMap)[carId_]->getHistory();
	string history =CarMap->find(carId_)->second->getHistory();
	tree.put(Reports::getId().append(".history"), history);
	tree.put(Reports::getId().append(".fault time left"), (*CarMap)[carId_]->getCondition());
}

string CarReport::getCarId(){ return carId_; }
void CarReport::setCarId(string newCarId){ carId_ = newCarId; }