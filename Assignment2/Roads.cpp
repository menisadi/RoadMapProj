#include "Roads.h"
	 

Roads::Roads(){}
Roads::Roads(const string baginJncVal, string endJncVal, int lengthVal, vector<Car> carsInRoadVal):baginJnc_(baginJncVal),endJnc_(endJncVal),length_(lengthVal),carsInRoad_(carsInRoadVal){
	updateNumOfCarInside(carsInRoadVal); //mybe send only Ref& ?
}
Roads::Roads(const Roads& copyRoad){
	baginJnc_=copyRoad.getBaginJnc();
	endJnc_=copyRoad.getEndJnc();
	length_=copyRoad.getlength();
	numOfCarInside_=copyRoad.getNumOfCarInside();
	carsInRoad_=copyRoad.getCarsInRoad();
}
Roads:: ~Roads(){}
Roads& Roads::operator=(const Roads &RoadsRightArg){
	Roads *temp = RoadsRightArg.copy();                     
    clear();           

	baginJnc_=temp->getBaginJnc();
	endJnc_=temp->getEndJnc();
	length_=temp->getlength();
	numOfCarInside_=temp->getNumOfCarInside();
	carsInRoad_=temp->getCarsInRoad();

	delete(temp);

  return *this;
}
    
void Roads::clear(){	
}
Roads* Roads::copy() const{    //Built just like the function, copy,in class of car/Junction / !Unnecessary duplication
	if (0 == this) {
		return 0;
	}
	else {
		Roads *newRoads = new Roads(*this);
		return newRoads;
	}
}

string Roads::getBaginJnc() const{
	return baginJnc_;
}
string Roads::getEndJnc() const{
	return endJnc_;
}
int Roads::getlength() const{
	return length_;
}
int Roads::getNumOfCarInside() const{
	return numOfCarInside_;
}
vector<Car> Roads::getCarsInRoad() const{
	return carsInRoad_;
}
     
void Roads::setBaginJnc(string baginJncVal){
	baginJnc_=baginJncVal;
}
void Roads::setEndJnc(string endJncVal){
	endJnc_=endJncVal;
}
void Roads::setLength(int lengthVal){
	length_=lengthVal;
}
void Roads::updateNumOfCarInside(vector<Car> &carsInRoadVal){
	numOfCarInside_=carsInRoadVal.size();
}

	 
//Car Roads::popFirstCarInRoad(){}
void Roads::pushNewCarToRoad(Car& newCarRef){}
void Roads::baseSpeedUpdate(){}
void Roads::carSpeedUpdate(){}