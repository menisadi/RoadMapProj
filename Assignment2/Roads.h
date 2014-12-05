// THIS IS THE DECLARATION FILE OF THE CLASS Roads (Roads.h) 
#ifndef _ROADS_H_
#define _ROADS_H_
  
#include <vector>
#include <string>
#include "Car.h"
#include "Junctions.h"
#include "GlobalVar.h"
#include <iostream>
//#include "Main.h"

using namespace std;

 class Roads
  {
  public:
     Roads();
     Roads(const string& IdVal,const string& baginJncVal, const string& endJncVal, int lengthVal, int numOfCarInsideVal, vector<Car*>* carsInRoadVal, vector<Car*>* CemeteryOfcarsVal,int baseSpeedVal);
     Roads(const string& IdVal,const string& baginJncVal, const string& endJncVal,int lengthVal);
	 Roads(const Roads& copyRoad);
     virtual ~Roads();
     Roads& operator=(const Roads &RoadsRightArg);

	 void Roads::copy(const Roads &copyRoad);
	 //void Roads::clear();
     
	 string getId() const;
     string getBaginJnc() const;
	 string getEndJnc() const;
     int getlength() const;
     int getNumOfCarInside() const;
	 vector<Car*>* getCarsInRoad() const;
	 vector<Car*>* getCemeteryOfcars() const;
	 int getBaseSpeed() const;
     
	 void setId(const string& IdVal);
	 void setBaginJnc(const string& baginJncVal);
     void setEndJnc(const string& endJncVal);
     void setLength(int lengthVal);
     void updateNumOfCarInside();
	 void setCarsInRoad(vector<Car*>* carsInRoadVal);
	 void setCemeteryOfcars(vector<Car*>* CemeteryOfcarsVal);
	 void setBaseSpeed(int basespeedVal);

	 Car* returnFirstCarInRoad();
	 void popFirstCarInRoad();
     void pushNewCarToRoad(Car* newCarVal); //meybe pointer*?
	 void baseSpeedUpdate();
	 void carSpeedUpdate();
	 void killCarInTheEnd(Car* oldCarRef);
	 void advanceCarsInRoad();
	 
  private:
	 string _Id;
     string _baginJnc;
     string _endJnc;
     int _length;
     int _numOfCarInside;
     vector<Car*>* _carsInRoad;  
	 vector<Car*>* _CemeteryOfcars; 
	 int _baseSpeed;
  };   
  
  #endif //_ROADS_H_