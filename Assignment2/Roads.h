// THIS IS THE DECLARATION FILE OF THE CLASS Roads (Roads.h) 
#ifndef _ROADS_H_
#define _ROADS_H_
  
#include <vector>
#include <string>
//#include "Car.h"
class Car;

using namespace std;

 class Roads
  {
  public:
     Roads();
     Roads(const string baginJncVal, string endJncVal, int lengthVal, int numOfCarInsideVal, vector<Car> carsInRoadVal, vector<Car> CemeteryOfcarsVal,int baseSpeedVal);
     Roads(const Roads& copyRoad);
     virtual ~Roads();
     Roads& operator=(const Roads &RoadsRightArg);

	 void Roads::copy(const Roads &copyRoad);
	 //void Roads::clear();
     
     string getBaginJnc() const;
	 string getEndJnc() const;
     int getlength() const;
     int getNumOfCarInside() const;
	 vector<Car> getCarsInRoad() const;
	 vector<Car> getCemeteryOfcars() const;
	 int getBaseSpeed() const;
     
	 void setBaginJnc(string baginJncVal);
     void setEndJnc(string endJncVal);
     void setLength(int lengthVal);
     void updateNumOfCarInside();
	 void setCarsInRoad(vector<Car> carsInRoadVal);
	 void setCemeteryOfcars(vector<Car> CemeteryOfcarsVal);
	 void setBaseSpeed(int basespeedVal);

	 Car popFirstCarInRoad();
     void pushNewCarToRoad(Car& newCarRef); //meybe pointer*?
	 void baseSpeedUpdate();
	 void carSpeedUpdate();
	 void killCarInTheEnd(Car& oldCarRef);
	 
  private:
     string _baginJnc;
     string _endJnc;
     int _length;
     int _numOfCarInside;
     vector<Car> _carsInRoad;  
	 vector<Car> _CemeteryOfcars; 
	 int _baseSpeed;
  };   
  
  #endif //_ROADS_H_