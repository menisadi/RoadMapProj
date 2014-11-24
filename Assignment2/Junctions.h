#ifndef _JUNCTIONS_H_
#define _JUNCTIONS_H_

#include <vector>
#include <string>
#include "Roads.h"

using namespace std;

// THIS IS THE DECLARATION FILE OF THE CLASS Junctions (Junctions.h) 
  class Junctions
  {
  private:
     string idJunction_;
     vector<Roads> roadsInJunction_; 
	 vector<int> timeSlice_;	
  public:
     Junctions();
     Junctions(const string idJunctionVal, int timeSliceVal);
     Junctions(const Junctions& copyJunctions);
     virtual ~Junctions();
     Junctions& operator=(const Junctions &JunctionsRightArg);
     
     string getID() const;
     int getTimeSlice() const;
     
     void setTimeSlice(int timeSliceVal);
	 
	 Roads popFirstRoadInJunction();
     void pushNewRoadToJunction(Roads& newRoadsRef);
	 void trafficManagementWithinJunction();
	 
  };   
  
  #endif //_JUNCTIONS_H_