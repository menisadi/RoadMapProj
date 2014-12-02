#include "AddCarEvent.h"


AddCarEvent::AddCarEvent(){}
AddCarEvent::AddCarEvent(AddCarEvent &other) :Event(other)
{
	_routeToAdd = other._routeToAdd;
}

AddCarEvent::AddCarEvent(const string& carId, vector<Roads*>* routeToAdd, int startTime) : Event(0, startTime, carId), _routeToAdd(routeToAdd){}
AddCarEvent::~AddCarEvent(){}
AddCarEvent& AddCarEvent::operator=(const AddCarEvent& E){
	Event::operator=(E);
	_routeToAdd = E._routeToAdd;
	return *this;
}

void AddCarEvent::performEvent()
{
	Car* newCar = new Car(Event::getCarId(), _routeToAdd, Event::getTime());
	int sizeOfRouteVector = _routeToAdd->size();
	if (sizeOfRouteVector > 0)
	{
		(*_routeToAdd)[sizeOfRouteVector-1]->pushNewCarToRoad(*newCar);
		(*_routeToAdd)[sizeOfRouteVector-1]->updateNumOfCarInside();
		_routeToAdd->pop_back();
	}
}

//getters
vector<Roads*> AddCarEvent::getCarRoute()
{
	return *_routeToAdd;
}

//setters
void AddCarEvent::setCarRoute(vector<Roads*>* route)
{
	_routeToAdd = route;
}

