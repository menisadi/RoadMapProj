#include "Car.h"

Car::Car(){
}

Car::Car(string idVal, vector<Roads*> routeVal, int arrivalVal,int conditionVal,int locationInRoadVal,int speedVal,string currentRoadVal,string historyVal):_ID(idVal),_route(routeVal),_arrival(arrivalVal),_condition(conditionVal),_locationInRoad(locationInRoadVal),_speed(speedVal),_currentRoad(currentRoadVal),_history(historyVal){	
}

Car::Car(const Car& other){
		copy(other);
}

Car::~Car(){
	//for( vector<Roads*>::iterator ii=_route.begin(); ii!=_route.end(); ++ii)
	//	delete (*ii);
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
vector<Roads*> Car::getRoute() const{
	return _route;						//meybe return *??
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


void Car::setID(string id){
	_ID=id;
}
void Car::setRoute(vector<Roads*> newRoute){
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
	_speed=speed;
}
void Car::setCurrentRoad(string currentRoad){
	_currentRoad=currentRoad;
}
void Car::setHistory(string history){
	_history=history;
}

//void initRouteFromStringINI(string RouteStringINI){}
//void updateMyRoad(){}
//void updateHistory(){}