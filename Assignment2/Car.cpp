#include "Car.h"


Car::Car()
{
}

Car::Car(std::string id, vector<std::string> startRoute, int carArrival)
{
	ID = id, route = startRoute, arrival = carArrival, condition = 0, locationInRoad = 0, speed = 0;
}

Car::~Car()
{
}
