#include "AddCarEvent.h"


AddCarEvent::AddCarEvent(){}
AddCarEvent::AddCarEvent(AddCarEvent &other) :Event(other)
{
	_routeToAdd = other._routeToAdd;
}

AddCarEvent::AddCarEvent(const string& carId, vector<Roads*>* routeToAdd, int startTime) : Event(0, startTime, carId), _routeToAdd(routeToAdd){
//_routeToAdd = new vector<Roads*>();
}
AddCarEvent::~AddCarEvent(){
	//for( vector<Roads*>::iterator ii=_routeToAdd->begin(); ii!=_routeToAdd->end(); ++ii)
		//	delete (*ii);
	 delete (_routeToAdd);
}
AddCarEvent& AddCarEvent::operator=(const AddCarEvent& E){
	Event::operator=(E);
	_routeToAdd = E._routeToAdd;
	return *this;
}

void AddCarEvent::performEvent()
{
	string currentCarIdStr = Event::getCarId();
	CarMap->insert(pair<string, Car*>(currentCarIdStr,new Car(currentCarIdStr, _routeToAdd, Event::getTime())));
	int sizeOfRouteVector = _routeToAdd->size();
	CarMap->find(currentCarIdStr)->second->setCurrentRoad((*_routeToAdd)[sizeOfRouteVector-1]->getId());
	if (sizeOfRouteVector > 0)
	{
		(*_routeToAdd)[sizeOfRouteVector-1]->pushNewCarToRoad((CarMap->find(currentCarIdStr)->second));
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

