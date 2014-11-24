#pragma once
#include "Event.h"

class AddCarEvent :
	public Event
{
public:
	AddCarEvent();
	AddCarEvent(std::string carId,vector<std::string> carRoute,int carArrival);
	~AddCarEvent();
	void performEvent();
private:
	std::string nameToAdd;
	vector<std::string> routeToAdd;
	int arrivalToAdd;
};

