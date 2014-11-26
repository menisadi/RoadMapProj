#include "Car.h"

Car::Car():_arrival(0),_condition(0),_locationInRoad(0),_speed(0){
}

Car::Car(string id, vector<string> &newRoute , int arrival,int condition,int locationInRoad,int speed):_ID(id),_arrival(arrival),_condition(condition),_locationInRoad(locationInRoad),_speed(speed){	
}

Car::Car(const Car& other){
	_ID=other.getID();
	 _route = newRoute;
	_arrival=other.getArrival();
	_condition=other.getCondition();
	_locationInRoad=other.getLocation();
	_speed=other.getspeed();
}

Car::~Car(){
}

Car & Car::operator=(const Car& C){    
    Car *temp = C.copy();        // make temp point to a copy of C               
    clear();            // delete the original Car  

    _ID=temp->getID();
	_arrival=temp->getArrival();
	_condition=temp->getCondition();
	_locationInRoad=temp->getLocation();
	_speed=temp->getspeed();

	delete(temp);

  return *this;
}

void Car::clear(){	
}

Car* Car::copy() const{
	if (0 == this) {
		return 0;
	}
	else {
		Car *newCar = new Car(*this);
		return newCar;
	}
}


string Car::getID() const{
	return _ID;
}
vector<string> getRoute() const;
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


void Car::setID(string id){
	_ID=id;
}
void setRoute(vector<string> route);
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