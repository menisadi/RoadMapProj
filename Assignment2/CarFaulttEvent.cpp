#include "CarFaulttEvent.h"


CarFaulttEvent::CarFaulttEvent(){}
CarFaulttEvent::CarFaulttEvent(CarFaulttEvent &other) :Event(other)
{
	_timeOfFault = other._timeOfFault;
}
	
CarFaulttEvent::CarFaulttEvent(const string& carId, int timeOfFault, int startTime) : Event(1, startTime, carId), _timeOfFault(timeOfFault){}
CarFaulttEvent::~CarFaulttEvent(){}
CarFaulttEvent& CarFaulttEvent::operator=(const CarFaulttEvent& E){
	 Event::operator=(E);
	 _timeOfFault = E.getTimeOfFault();
	 return *this;
}

void CarFaulttEvent::performEvent()
{
	// find car
	// change his condition to be _timeOfFault
	string currentCarIdStr = Event::getCarId();
	CarMap->find(currentCarIdStr)->second->setCondition(_timeOfFault);
}
	
//getters
int CarFaulttEvent::getTimeOfFault() const
{
	return _timeOfFault;
}

//setters
void CarFaulttEvent::setTimeOfFault(int timeOfFault)
{
	_timeOfFault = timeOfFault;
}

