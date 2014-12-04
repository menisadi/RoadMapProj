#include "Roads.h"

Roads::Roads(){}

Roads::Roads(const string& IdVal,const string& baginJncVal, const string& endJncVal, int lengthVal, int numOfCarInsideVal, vector<Car*>* carsInRoadVal, vector<Car*>* CemeteryOfcarsVal,int baseSpeedVal):_Id(IdVal),_baginJnc(baginJncVal),_endJnc(endJncVal),_length(lengthVal),_numOfCarInside(numOfCarInsideVal),_baseSpeed(baseSpeedVal){// missing ",_carsInRoad(carsInRoadVal) , _CemeteryOfcars(CemeteryOfcarsVal)
}
Roads::Roads(const string& IdVal,const string& baginJncVal, const string& endJncVal,int lengthVal):_Id(IdVal),_baginJnc(baginJncVal),_endJnc(endJncVal),_length(lengthVal),_numOfCarInside(0){
	Roads::baseSpeedUpdate();
	 _carsInRoad = new vector<Car*>();
	  _CemeteryOfcars = new vector<Car*>(); 
}

Roads::Roads(const Roads& copyRoad){
	copy(copyRoad);
}

Roads:: ~Roads(){
	 for( vector<Car*> ::iterator ii=_carsInRoad->begin(); ii!=_carsInRoad->end(); ++ii)
		delete (*ii);
	 for( vector<Car*> ::iterator ix=_CemeteryOfcars->begin(); ix!=_CemeteryOfcars->end(); ++ix)
		delete (*ix);
	 delete (_carsInRoad);
	 delete (_CemeteryOfcars);
}

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
vector<Car*>* Roads::getCarsInRoad() const{
	return _carsInRoad;
}
vector<Car*>* Roads::getCemeteryOfcars() const{
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
	_numOfCarInside = _carsInRoad->size();
}
void Roads::setCarsInRoad(vector<Car*>* carsInRoadVal){
	_carsInRoad=carsInRoadVal;
}
void Roads::setCemeteryOfcars(vector<Car*>* CemeteryOfcarsVal){
	_CemeteryOfcars=CemeteryOfcarsVal;
}
void Roads::setBaseSpeed(int basespeedVal){
	_baseSpeed=basespeedVal;
}

	 
Car* Roads::popFirstCarInRoad(){
	// std::vector<Car>::iterator it =_carsInRoad.back();
	rotate(_carsInRoad->begin(), _carsInRoad->begin() + 1, _carsInRoad->end());
	Car* tmpCar = _carsInRoad->back();
	//Car tmpCar = CarMaps
	_carsInRoad->pop_back();
	--_numOfCarInside;
	return tmpCar;
}					
void Roads::pushNewCarToRoad(Car* newCarVal){
	++_numOfCarInside;
	_carsInRoad->push_back(newCarVal);  //it's copy!!!!!!!!!!!!???? not good
	cout<<  "" <<endl;
	//~newCarVal();
}
void Roads::killCarInTheEnd(Car* oldCarRef){
	cout <<"id="+oldCarRef->getID() + " " +  oldCarRef->getHistory() << endl;   ///for Test!
	//_CemeteryOfcars->push_back(oldCarRef);
	_CemeteryOfcars->push_back(oldCarRef);
}
//void Roads::carSpeedUpdate(){}

void Roads::baseSpeedUpdate(){
	if(_numOfCarInside>0)
		_baseSpeed=int(ceil(_length/_numOfCarInside));
	else
		_baseSpeed=_length;

	if(_baseSpeed>global_maxSpeed)
		_baseSpeed=global_maxSpeed;
}

void Roads::advanceCarsInRoad(){
	baseSpeedUpdate();

	int counterFaultyCars = 0;
	int TheLastFaultyCarLocation=-1;
	int counterFaultyCarsInTheSameLine=0;

	for(std::vector<Car*>::iterator itCurrentCar = _carsInRoad->begin(); itCurrentCar != _carsInRoad->end(); ++itCurrentCar){
		(*itCurrentCar)->updateHistory();
		cout << "start of step:	" << global_SimulationTime << " car: " << (*itCurrentCar)->getID() << " || location: " << (*itCurrentCar)->getLocation() << " || in road: " << (*itCurrentCar)->getCurrentRoad() << endl;
		if ((*itCurrentCar)->getLocation() != TheLastFaultyCarLocation){counterFaultyCarsInTheSameLine=0;}
		if ( (*itCurrentCar)->getCondition() == 0)
		{
			int speedCalculation = int(ceil((_baseSpeed)/(pow(2,(counterFaultyCars-counterFaultyCarsInTheSameLine)))));
			(*itCurrentCar)->setspeed(speedCalculation);

			int locationCalculation = (*itCurrentCar)->getLocation() + speedCalculation;
			if (locationCalculation <= _length)
				(*itCurrentCar)->setLocation(locationCalculation);
			else
				(*itCurrentCar)->setLocation(_length);
		}
		else
		{
			++counterFaultyCars;
			(*itCurrentCar)->setCondition((*itCurrentCar)->getCondition()-1);
			if ((*itCurrentCar)->getLocation()==TheLastFaultyCarLocation)
				++counterFaultyCarsInTheSameLine;
			else
			{
				//(*itCurrentCar)->setLocation(TheLastFaultyCarLocation);
				TheLastFaultyCarLocation= (*itCurrentCar)->getLocation();
				counterFaultyCarsInTheSameLine=1;
			}
		}
		cout <<"end of step:	" << global_SimulationTime << " car: " << (*itCurrentCar)->getID() << " || location: " << (*itCurrentCar)->getLocation() << " || in road: " << (*itCurrentCar)->getCurrentRoad() << endl;
	}
}