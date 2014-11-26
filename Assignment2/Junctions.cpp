#include "Junctions.h"

Junctions::Junctions(){}
Junctions:: Junctions(const string idJunctionVal, vector<Roads> roadsInJunctionVal,vector<int> timeSliceVal):idJunction_(idJunctionVal),timeSlice_(timeSliceVal){}
Junctions::Junctions(const Junctions& copyJunctions){
	idJunction_=copyJunctions.getIdJunction();
	// roadsInJunction_ = copyJunctions.getRoadsInJunction();
	timeSlice_=copyJunctions.getTimeSlice();
}
Junctions:: ~Junctions(){}
Junctions& Junctions::operator=(const Junctions &JunctionsRightArg){
	Junctions *temp = JunctionsRightArg.copy();        // make temp point to a copy of C               
    clear();            // delete the original Car  

    idJunction_=temp->getIdJunction();
	// roadsInJunction_ = temp->getRoadsInJunction();
	timeSlice_=temp->getTimeSlice();

	delete(temp);

  return *this;
}

void Junctions::clear(){	
}
Junctions* Junctions::copy() const{    //Built just like the function, copy,in class of car / !Unnecessary duplication
	if (0 == this) {
		return 0;
	}
	else {
		Junctions *newJunction = new Junctions(*this);
		return newJunction;
	}
}

     
string Junctions::getIdJunction() const{
	return idJunction_;
}
//vector<Roads> Junctions::getRoadsInJunction() const{
//return roadsInJunction_;
//}
vector<int> Junctions::getTimeSlice() const{
	return timeSlice_;
}
     
void Junctions::setID(string idJunctionVal){
	idJunction_=idJunctionVal;
}
void Junctions::setTimeSlice(vector<int> timeSliceVal){
	 timeSlice_ = timeSliceVal;	//memory ???? deep copy??
}
//void Junctions::setRoadsInJunction(vector<Roads> roadsInJunction){
//	roadsInJunction_=roadsInJunction;//memory ???? deep copy??
//}

	 
//Roads Junctions::popFirstRoadInJunction(){}
void Junctions::pushNewRoadToJunction(Roads& newRoadsRef){}
void Junctions::trafficManagementWithinJunction(){}
