#ifndef _CAR_H_
#define _CAR_H_

#include <vector>
#include <string>
#include "GlobalVar.h"
//#include "Roads.h"

using namespace std;
class Roads;

class Car
{
public:
	Car();
	Car(const string& idVal, vector<Roads*>* routeVal, int arrivalVal,int conditionVal,int locationInRoadVal,int speedVal,const string& currentRoadVal,const string& historyVal);
	Car(const string& idVal, vector<Roads*>* routeVal, int arrivalVal);
	Car(const string& idVal, int arrivalVal);
	Car(const Car &other);
	~Car();
	Car & operator=(const Car& C);

	string getID() const;
	vector<Roads*>* getRoute() const;
	int getArrival() const;
	int getCondition() const;
	int getLocation() const;
	int getspeed() const;
	string getCurrentRoad() const;
	string getHistory() const;

	void setID(const string& id);
	void setRoute(vector<Roads*>* route);
	void setArrival(int arrival);
	void setCondition(int condition);
	void setLocation(int location);
	void setspeed(int speed);
	void setCurrentRoad(const string& currentRoad);
	void setHistory(const string& history);
	
	void Car::copy(const Car& other);
	 
	Roads* popFirstRoadsInRoute();
	void initRouteFromStringINI(const string& RouteStringINI);
	void updateMyRoad();
	void updateHistory();
	


private:
	string _ID;
	vector<Roads*>* _route;
	int _arrival;
	int _condition;
	int _locationInRoad;
	int _speed;
	string _currentRoad;
	string _history;
};


  #endif //_CAR_H_