#include "AddCarEvent.h"
#include "Car.h""

AddCarEvent::AddCarEvent(){}
AddCarEvent::AddCarEvent(AddCarEvent &other) :Event(other)
{
	_routeToAdd = other._routeToAdd;
}

AddCarEvent::AddCarEvent(const string& carId, vector<string> routeToAdd, int startTime) : Event(0, startTime, carId), _routeToAdd(routeToAdd){}
AddCarEvent::~AddCarEvent(){}
AddCarEvent& AddCarEvent::operator=(const AddCarEvent& E){
	Event::operator=(E);
	_routeToAdd = E._routeToAdd;
	return *this;
}

void AddCarEvent::performEvent()
{
	Car* newCar = new Car(Event::getCarId, _routeToAdd, Event::getTime);

	// add more lines for:
	// add the car to certain road vector
	// increase tthe road's counter
}

//getters
vector<std::string> AddCarEvent::getCarRoute()
{
	return _routeToAdd;
}

//setters
void AddCarEvent::setCarRoute(vector<std::string> route)
{
	_routeToAdd = route;
}

