#ifndef _CAR_H_
#define _CAR_H_

#include <vector>
#include <string>

using namespace std;
class Roads;

class Car
{
public:
	Car();
	Car(string idVal, vector<Roads*> routeVal, int arrivalVal,int conditionVal,int locationInRoadVal,int speedVal,string currentRoadVal,string historyVal);
	Car(const Car &other);
	~Car();
	Car & operator=(const Car& C);

	string getID() const;
	vector<Roads*> getRoute() const;
	int getArrival() const;
	int getCondition() const;
	int getLocation() const;
	int getspeed() const;
	string getCurrentRoad() const;
	string getHistory() const;

	void setID(string id);
	void setRoute(vector<Roads*> route);
	void setArrival(int arrival);
	void setCondition(int condition);
	void setLocation(int location);
	void setspeed(int speed);
	void setCurrentRoad(string currentRoad);
	void setHistory(string history);
	
	void Car::copy(const Car& other);

	void initRouteFromStringINI(string RouteStringINI);
	void updateMyRoad();
	void updateHistory();


private:
	string _ID;
	vector<Roads*> _route;
	int _arrival;
	int _condition;
	int _locationInRoad;
	int _speed;
	string _currentRoad;
	string _history;
};


  #endif //_CAR_H_