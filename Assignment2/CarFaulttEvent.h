#ifndef _CARFAULTTEVENT_H_
#define _CARFAULTTEVENT_H_

#include "Event.h"


class CarFaulttEvent:public Event{
public:
	CarFaulttEvent();
	CarFaulttEvent(CarFaulttEvent &other);
	CarFaulttEvent(const string& carId, int timeOfFault, int startTime);
	virtual ~CarFaulttEvent();
	CarFaulttEvent & operator=(const CarFaulttEvent &E);

	void performEvent();
	
	//getters
	int getTimeOfFault() const;

	//setters
	void setTimeOfFault(int timeOfFault);

private:
	int _timeOfFault;
};

#endif