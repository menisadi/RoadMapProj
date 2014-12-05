#include "Car.h"

Car::Car(){}
Car::Car(const string& idVal, vector<Roads*>* routeVal, int arrivalVal,int conditionVal,int locationInRoadVal,int speedVal,const string& currentRoadVal,const string& historyVal):_ID(idVal),_route(routeVal),_arrival(arrivalVal),_condition(conditionVal),_locationInRoad(locationInRoadVal),_speed(speedVal),_currentRoad(currentRoadVal),_history(historyVal){	}
Car::Car(const string& idVal, vector<Roads*>* routeVal, int arrivalVal):_ID(idVal),_route(routeVal),_arrival(arrivalVal),_condition(0),_locationInRoad(0),_speed(0),_history(""){}
Car::Car(const string& idVal, int arrivalVal):_ID(idVal),_arrival(arrivalVal){	}

Car::Car(const Car& other){
		copy(other);
}

Car::~Car(){
	for( vector<Roads*>::iterator ii=_route->begin(); ii!=_route->end(); ++ii)
		delete (*ii);
	 delete (_route);
}

Car & Car::operator=(const Car& C){    
  copy(C);
  return *this;
}

void Car::copy(const Car& other){
		_ID=other.getID();
		_route = other.getRoute();
		_arrival=other.getArrival();
		_condition=other.getCondition();
		_locationInRoad=other.getLocation();
		_speed=other.getspeed();
		_currentRoad=other.getCurrentRoad();
		_history=other.getHistory();
}

string Car::getID() const{
	return _ID;
}
vector<Roads*>* Car::getRoute() const{
	return _route;						
}
int Car::getArrival() const{
	return _arrival;
}
int Car:: getCondition() const{
	return _condition;
}
int Car::getLocation() const{
	return _locationInRoad;
}
int Car::getspeed() const{
	return _speed;
}
string Car::getCurrentRoad() const{
	return _currentRoad;
}
string Car::getHistory() const{
	return _history;
}


void Car::setID(const string& id){
	_ID=id;
}
void Car::setRoute(vector<Roads*>* newRoute){
	 _route = newRoute;	
}
void Car::setArrival(int arrival){
	_arrival=arrival;
}
void Car::setCondition(int condition){
	_condition=condition;
}
void Car::setLocation(int location){
	_locationInRoad=location;
}
void Car::setspeed(int speed){
	if(speed>=global_maxSpeed)
		_speed=global_maxSpeed;
	else
		_speed=speed;
}
void Car::setCurrentRoad(const string& currentRoad){
	_currentRoad=currentRoad;
}
void Car::setHistory(const string& history){
	_history=history;
}
Roads* Car::popFirstRoadsInRoute(){
	Roads* tmpRoad = (_route->back());
	_route->pop_back();
	return  tmpRoad;
}

void Car::updateHistory(){
	_history=_history + "(" + to_string(global_SimulationTime) + "," + _currentRoad + "," + to_string(_locationInRoad )+ ")" ;
}