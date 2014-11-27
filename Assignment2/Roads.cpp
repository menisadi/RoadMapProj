#include "Roads.h"

Roads::Roads(){}

Roads::Roads(const string& IdVal,const string& baginJncVal, const string& endJncVal, int lengthVal, int numOfCarInsideVal, vector<Car> carsInRoadVal, vector<Car> CemeteryOfcarsVal,int baseSpeedVal):_Id(IdVal),_baginJnc(baginJncVal),_endJnc(endJncVal),_length(lengthVal),_numOfCarInside(numOfCarInsideVal),_baseSpeed(baseSpeedVal){// missing ",_carsInRoad(carsInRoadVal) , _CemeteryOfcars(CemeteryOfcarsVal)
}
Roads::Roads(const string& IdVal,const string& baginJncVal, const string& endJncVal,int lengthVal):_Id(IdVal),_baginJnc(baginJncVal),_endJnc(endJncVal),_length(lengthVal){}

Roads::Roads(const Roads& copyRoad){
	copy(copyRoad);
}

Roads:: ~Roads(){}

Roads& Roads::operator=(const Roads &RoadsRightArg){
  copy(RoadsRightArg);
  return *this;
}
 
void Roads::copy(const Roads &copyRoad){
	_Id=copyRoad.getId();
	_baginJnc=copyRoad.getBaginJnc();
	_endJnc=copyRoad.getEndJnc();
	_length=copyRoad.getlength();
	_numOfCarInside=copyRoad.getNumOfCarInside();  
	_carsInRoad=copyRoad.getCarsInRoad();				
	_CemeteryOfcars=copyRoad.getCemeteryOfcars();
	 _baseSpeed=copyRoad.getBaseSpeed();
}

string Roads::getId() const{
	return _Id;
}
string Roads::getBaginJnc() const{
	return _baginJnc;
}
string Roads::getEndJnc() const{
	return _endJnc;
}
int Roads::getlength() const{
	return _length;
}
int Roads::getNumOfCarInside() const{
	return _numOfCarInside;
}
vector<Car> Roads::getCarsInRoad() const{
	return _carsInRoad;
}
vector<Car> Roads::getCemeteryOfcars() const{
	return _CemeteryOfcars;
}
int Roads::getBaseSpeed() const{
	return _baseSpeed;
}
 
void Roads::setId(const string& IdVal){
	_Id=IdVal;
}
void Roads::setBaginJnc(const string& baginJncVal){
	_baginJnc=baginJncVal;
}
void Roads::setEndJnc(const string& endJncVal){
	_endJnc=endJncVal;
}
void Roads::setLength(int lengthVal){
	_length=lengthVal;
}
void Roads::updateNumOfCarInside(){
		//_numOfCarInside=_carsInRoad.size;	/// ! not work
}
void Roads::setCarsInRoad(vector<Car> carsInRoadVal){
	_carsInRoad=carsInRoadVal;
}
void Roads::setCemeteryOfcars(vector<Car> CemeteryOfcarsVal){
	_CemeteryOfcars=CemeteryOfcarsVal;
}
void Roads::setBaseSpeed(int basespeedVal){
	_baseSpeed=basespeedVal;
}

	 
//Car Roads::popFirstCarInRoad(){}
//void Roads::pushNewCarToRoad(Car& newCarRef){}
//void Roads::killCarInTheEnd(Car& oldCarRef){}
//void Roads::carSpeedUpdate(){}

void Roads::baseSpeedUpdate(){
	_baseSpeed=_length/_numOfCarInside;
}

void Roads::advanceCarsInRoad(){
	baseSpeedUpdate();

	int counterFaultyCars = 0;
	int TheLastFaultyCarLocation=-1;
	int counterFaultyCarsInTheSameLine=0;

	for(std::vector<Car>::iterator itCurrentCar = _carsInRoad.begin(); itCurrentCar != _carsInRoad.end(); ++itCurrentCar){
		if (itCurrentCar->getLocation!=TheLastFaultyCarLocation){counterFaultyCarsInTheSameLine=0;}
		if ( itCurrentCar->getCondition() == 0)
		{
			int speedCalculation = (_baseSpeed)/(ceil(2*(counterFaultyCars-counterFaultyCarsInTheSameLine)));
			itCurrentCar->setspeed(speedCalculation);

			int locationCalculation = itCurrentCar->getLocation + speedCalculation;
			if (locationCalculation <= _length)
				itCurrentCar->setLocation(locationCalculation);
			else
				itCurrentCar->setLocation(_length);
		}
		else
		{
			++counterFaultyCars;
			if (itCurrentCar->getLocation==TheLastFaultyCarLocation)
				++counterFaultyCarsInTheSameLine;
			else
			{
				itCurrentCar->getLocation=TheLastFaultyCarLocation;
				counterFaultyCarsInTheSameLine=1;
			}
		}
	}
}