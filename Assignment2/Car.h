#include <vector>
#include <string>

using namespace std;

class Car
{
public:
	Car();
	Car(string id, vector<string> newRoute, int arrival,int condition,int locationInRoad,int speed);
	Car(const Car &other);
	~Car();
	Car & operator=(const Car& C);

	string getID() const;
	vector<string> getRoute() const;
	int getArrival() const;
	int getCondition() const;
	int getLocation() const;
	int getspeed() const;

	void setID(string id);
	void setRoute(vector<string> route);
	void setArrival(int arrival);
	void setCondition(int condition);
	void setLocation(int location);
	void setspeed(int speed);
	
	Car* Car::copy() const;
	void Car::clear();

private:
	string _ID;
	vector<string> _route;
	int _arrival;
	int _condition;
	int _locationInRoad;
	int _speed;
	//HISTORY <time,road,location>
};



