// THIS IS THE DECLARATION FILE OF THE CLASS Junctions (Junctions.h) 
#ifndef _JUNCTIONS_H_
#define _JUNCTIONS_H_

#include <vector>
#include <string>
class Roads;

using namespace std;

  class Junctions{
  private:
     string idJunction_;
    // vector<Roads*> roadsInJunction_; //In fact we want it to be an array of Ref&
	 vector<int> timeSlice_;	

  public:
     Junctions();
     Junctions(const string idJunctionVal, vector<Roads> roadsInJunctionVal,vector<int> timeSliceVal);
     Junctions(const Junctions& copyJunctions);
     virtual ~Junctions();
     Junctions& operator=(const Junctions &JunctionsRightArg);

	Junctions* Junctions::copy() const;
	void Junctions::clear();
     
     string getIdJunction() const;
	 vector<Roads> getRoadsInJunction() const; 
     vector<int> getTimeSlice() const;
     
	 void setID(string idJunctionVal);
     void setTimeSlice(vector<int> timeSliceVal);
	 void setRoadsInJunction(vector<Roads> roadsInJunction); 

	 
	 Roads popFirstRoadInJunction();
     void pushNewRoadToJunction(Roads& newRoadsRef);
	 void trafficManagementWithinJunction();


	 
  };   
  
  #endif //_JUNCTIONS_H_