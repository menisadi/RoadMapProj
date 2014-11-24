#include "AddCarEvent.h"
#include "Car.h""

AddCarEvent::AddCarEvent()
{
}

AddCarEvent::AddCarEvent(std::string carId, vector<std::string> carRoute, int carArrival)
{
	nameToAdd = carId;
	routeToAdd = carRoute;
	arrivalToAdd = carArrival;
}

AddCarEvent::~AddCarEvent()
{
}

void AddCarEvent::performEvent()
{
	// initialize new car
	//		ID = id
	//		Route = route
	//		arrival = Arrival
	//		condition = 0
	//		location in road = 0
	//		speed = 0
	Car* newCar = new Car(nameToAdd, routeToAdd, arrivalToAdd);
	
	// add more lines for:
	// add the car to certain road vector
	// increase tthe road's counter
}