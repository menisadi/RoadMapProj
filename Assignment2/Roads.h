#ifndef _ROADS_H_
#define _ROADS_H_
  
#include <vector>
#include <string>
class Car;

using namespace std;


// THIS IS THE DECLARATION FILE OF THE CLASS Roads (Roads.h) 
  class Roads
  {
  private:
     string baginJnc_;
     string endJnc_;
     int length_;
     int numOfCarInside;
     //vector<Car> carsInRoad_;  
  public:
     Roads();
     Roads(const string baginJncVal, string endJncVal, int lengthVal);
     Roads(const Roads& copyRoad);
     virtual ~Roads();
     Roads& operator=(const Roads &RoadsRightArg);
     
     string getID() const;
     int getlength() const;
     int getNumOfCarInside() const;
     
	 void setBaginJnc(string baginJncVal);
     void setEndJnc(string endJncVal);
     void setLength(int lengthVal);
     void updateNumOfCarInside(int numOfCarInsideVal);
	 
	 Car popFirstCarInRoad();
     void pushNewCarToRoad(Car& newCarRef);
	 void baseSpeedUpdate();
	 void carSpeedUpdate();
  };   
  
  #endif //_ROADS_H_