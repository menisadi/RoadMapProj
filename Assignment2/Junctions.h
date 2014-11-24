#ifndef _JUNCTIONS_H_
#define _JUNCTIONS_H_

// THIS IS THE DECLARATION FILE OF THE CLASS Junctions (Junctions.h) 
  class Junctions
  {
  private:
     String idJunction_;
     Vactor roadsInJunction_; 
	 int timeSlice_;	 
  public:
     Junctions();
     Junctions(const String idJunctionVal, int timeSliceVal);
     Junctions(const Junctions& copyJunctions);
     virtual ~Junctions();
     Junctions& operator=(const Junctions &JunctionsRightArg);
     
     String getID() const;
     int getTimeSlice() const;
     
     setTimeSlice(int timeSliceVal);
	 
	 Roads popFirstRoadInJunction();
     pushNewRoadToJunction(Roads& newRoadsRef);
	 trafficManagementWithinJunction();
	 
  };   
  
  #endif //_JUNCTIONS_H_