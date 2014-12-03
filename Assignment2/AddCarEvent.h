#ifndef _ADDCAREVENT_H_
#define _ADDCAREVENT_H_
#include "Event.h"
#include "Car.h"
#include "Main.h"


class AddCarEvent : public Event
{
public:
	AddCarEvent();
	AddCarEvent(const string& carId, vector<Roads*>* routeToAdd, int startTime);
	AddCarEvent(AddCarEvent &other);
	virtual ~AddCarEvent();
	AddCarEvent & operator=(const AddCarEvent &E);

	void performEvent();

	//getters
	vector<Roads*> getCarRoute();

	//setters
	void AddCarEvent::setCarRoute(vector<Roads*>* route);

private:
	vector<Roads*>* _routeToAdd;
};

#endif