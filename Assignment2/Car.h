#include <vector>
#include <string>

using namespace std;

class Car
{
public:
	Car();
	Car(string id, vector<string> route, int arrival);
	Car(Car &other);
	~Car();
	Car & operator=(const Car& C);

	string getID();
	vector<string> getRoute();
	int getArrival();
	int getCondition();
	int getLocation();
	int getspeed();

	void setID(string id);
	void setRoute(vector<string> route);
	void setArrival(int arrival);
	void setCondition(int condition);
	void setLocation(int location);
	void setspeed(int speed);

private:
	string _ID;
	vector<string> _route;
	int _arrival;
	int _condition;
	int _locationInRoad;
	int _speed;
	//HISTORY <time,road,location>
};



