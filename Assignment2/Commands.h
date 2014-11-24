#ifndef _ROADS_H_
#define _ROADS_H_

// THIS IS THE DECLARATION FILE OF THE CLASS Roads (Roads.h) 
  class Roads
  {
  private:
     String baginJnc_;
     String endJnc_;
     int length_;
     int numOfCarInside;
     Vactor carsInRoad_;  
  public:
     Roads();
     Roads(const String baginJncVal, String endJncVal, int lengthVal);
     Roads(const Roads& copyRoad);
     virtual ~Roads();
     Roads& operator=(const Roads &RoadsRightArg);
     
     String getID() const;
     int getlength() const;
     int getNumOfCarInside() const;
     
     setBaginJnc(String baginJncVal);
     setEndJnc(String endJncVal);
     setLength(int lengthVal);
     updateNumOfCarInside(int numOfCarInsideVal);
	 
	 Car popFirstCarInRoad();
     pushNewCarToRoad(car& newCarRef);
	 baseSpeedUpdate();
	 carSpeedUpdate();
  };   
  
  #endif //_ROADS_H_