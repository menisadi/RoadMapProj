#pragma once
#include "Event.h"
class CarFaulttEvent :
	public Event
{
public:
	CarFaulttEvent();
	CarFaulttEvent(CarFaulttEvent &other);
	CarFaulttEvent(string carId, int timeOfFault, int startTime);
	virtual ~CarFaulttEvent();
	CarFaulttEvent & operator=(const CarFaulttEvent &E);

	void performEvent();
	
	//getters
	int getTimeOfFault();

	//setters
	void setTimeOfFault(int timeOfFault);

private:
	int _timeOfFault;


};

