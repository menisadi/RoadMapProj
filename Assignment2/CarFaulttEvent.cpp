#include "CarFaulttEvent.h"


CarFaulttEvent::CarFaulttEvent(){}
CarFaulttEvent::CarFaulttEvent(CarFaulttEvent &other){}
CarFaulttEvent::CarFaulttEvent(const string& carId, int timeOfFault, int startTime):Event(1,timeOfFault, carId),_timeOfFault(timeOfFault){}
CarFaulttEvent::~CarFaulttEvent(){}
CarFaulttEvent& CarFaulttEvent::operator=(const CarFaulttEvent& E){
	 Event::operator=(E);
	 return *this;
}

void CarFaulttEvent::performEvent(){}
	
//getters
int CarFaulttEvent::getTimeOfFault(){}

//setters
void CarFaulttEvent::setTimeOfFault(int timeOfFault){}

