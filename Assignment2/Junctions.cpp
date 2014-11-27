#include "Junctions.h"

Junctions::Junctions(){}
Junctions:: Junctions(const string& idJunctionVal){}
Junctions:: Junctions(const string& idJunctionVal, vector<Roads*> roadsInJunctionVal,vector<int> timeSliceVal):_idJunction(idJunctionVal),_roadsInJunction(roadsInJunctionVal),_timeSlice(timeSliceVal){}

Junctions::Junctions(const Junctions& copyJunctions){
	copy(copyJunctions);
}
Junctions:: ~Junctions(){
	//for( vector<Roads*>::iterator ii=_roadsInJunction.begin(); ii!=_roadsInJunction.end(); ++ii)
	//	delete (*ii);
}
Junctions& Junctions::operator=(const Junctions &JunctionsRightArg){
  copy(JunctionsRightArg);
  return *this;
}

void Junctions::copy(const Junctions& copyJunctions){   
	_idJunction=copyJunctions.getIdJunction();
	 _roadsInJunction = copyJunctions.getRoadsInJunction();
	_timeSlice=copyJunctions.getTimeSlice();
}

     
string Junctions::getIdJunction() const{
	return _idJunction;
}

vector<Roads*> Junctions::getRoadsInJunction() const{
return _roadsInJunction;								 //meybe return *??
}
vector<int> Junctions::getTimeSlice() const{
	return _timeSlice;
}
     
void Junctions::setID(const string& idJunctionVal){
	_idJunction=idJunctionVal;
}
void Junctions::setTimeSlice(vector<int> timeSliceVal){
	 _timeSlice = timeSliceVal;	//memory ???? deep copy??
}
void Junctions::setRoadsInJunction(vector<Roads*> roadsInJunction){  
	_roadsInJunction=roadsInJunction;
}

	 
//void Junctions::initRoadsFromStringINI(){}
//void Junctions::initTimeSliceFromStringINI(){}
//void Junctions::greenLightManagement(){}
