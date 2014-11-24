#include <vector>
#include <string>

using namespace std;

class Car
{
public:
	Car();
	Car(std::string id, vector<string> startRoute, int carArrival);
	~Car();

private:
	std::string ID;
	vector<std::string> route;
	int arrival;
	int condition;
	int locationInRoad;
	int speed;
};



