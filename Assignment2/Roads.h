// THIS IS THE DECLARATION FILE OF THE CLASS Roads (Roads.h) 
#ifndef _ROADS_H_
#define _ROADS_H_
  
#include <vector>
#include <string>
class Car;

using namespace std;

 class Roads
  {
  private:
     string baginJnc_;
     string endJnc_;
     int length_;
     int numOfCarInside_;
     vector<Car> carsInRoad_;  
  public:
     Roads();
     Roads(const string baginJncVal, string endJncVal, int lengthVal, vector<Car> carsInRoadVal);
     Roads(const Roads& copyRoad);
     virtual ~Roads();
     Roads& operator=(const Roads &RoadsRightArg);

	 Roads* Roads::copy() const;
	 void Roads::clear();
     
     string getBaginJnc() const;
	 string getEndJnc() const;
     int getlength() const;
     int getNumOfCarInside() const;
	 vector<Car> getCarsInRoad() const;
     
	 void setBaginJnc(string baginJncVal);
     void setEndJnc(string endJncVal);
     void setLength(int lengthVal);
     void updateNumOfCarInside(vector<Car> &carsInRoadVal);

	 
	 Car popFirstCarInRoad();
     void pushNewCarToRoad(Car& newCarRef);
	 void baseSpeedUpdate();
	 void carSpeedUpdate();
  };   
  
  #endif //_ROADS_H_