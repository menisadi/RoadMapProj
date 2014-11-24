#pragma once
#include "Event.h"

class AddCarEvent :
	public Event
{
public:
	AddCarEvent();
	AddCarEvent(string carId,vector<string> carRoute,int carArrival);
	AddCarEvent(AddCarEvent &other);
	virtual ~AddCarEvent();
	AddCarEvent & operator=(const AddCarEvent &E);

	void performEvent();

	//getters
	vector<std::string> getRoute();

	//setters
	void setRoute(vector<string> route);

private:
	vector<string> _routeToAdd;
	
};

