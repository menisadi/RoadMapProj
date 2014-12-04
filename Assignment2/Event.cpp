#include "Event.h"

Event::Event(){}
Event::Event(Event &other){}

Event::Event(int typeVal, int timeVal, const string& carIdVal):_type(typeVal),_time(timeVal),_carId(carIdVal){}
Event::~Event(){
	cout<<""<<endl;
}
Event & Event::operator=(const Event &eventRightArg){
	_type=eventRightArg._type;
	_time=eventRightArg._time;
	_carId=eventRightArg._carId;
	return *this;
}
		
//void Event:: performEvent(){}

int Event::getType(){return _type;}
int Event::getTime(){return _time;}
string Event::getCarId(){return _carId;}
void Event::setType(int type){_type=type;}
void Event::setTime(int time){_time=time;}
void Event::setCarId(const string& carId){_carId=carId;}