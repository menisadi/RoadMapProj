#include "CarReport.h"

CarReport::CarReport(){}

CarReport::CarReport(string reportId, int time, string carId)
	: Reports(reportId,time), carId_(carId) {}

CarReport::CarReport(CarReport &other):Reports(other),carId_(other.carId_){}

CarReport& CarReport::operator=(const CarReport &R)
{
	Reports::operator=(R);
	carId_ = R.carId_;
	return *this;
}

void CarReport::writeReport()
{

}

string CarReport::getCarId(){ return carId_; }
void CarReport::setCarId(string newCarId){ carId_ = newCarId; }