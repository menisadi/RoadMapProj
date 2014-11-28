#pragma once
#include "Event.h"

class AddCarEvent : public Event
{
public:
	AddCarEvent();
	AddCarEvent(const string& carId, vector<string> routeToAdd, int startTime);
	AddCarEvent(AddCarEvent &other);
	virtual ~AddCarEvent();
	AddCarEvent & operator=(const AddCarEvent &E);

	void performEvent();

	//getters
	vector<std::string> getCarRoute();

	//setters
	void AddCarEvent::setCarRoute(vector<std::string> route);

private:
	vector<string> _routeToAdd;
};

