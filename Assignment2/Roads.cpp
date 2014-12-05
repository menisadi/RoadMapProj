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

 void Roads::popFirstCarInRoad(){
	rotate(_carsInRoad->begin(), _carsInRoad->begin()+1, _carsInRoad->end());
	_carsInRoad->pop_back();
	--_numOfCarInside;
}	

Car* Roads::returnFirstCarInRoad(){
	return (*_carsInRoad)[0];
}					
void Roads::pushNewCarToRoad(Car* newCarVal){
	++_numOfCarInside;
	_carsInRoad->push_back(newCarVal);
}
void Roads::killCarInTheEnd(Car* oldCarRef){
	oldCarRef->setLocation(0);
	oldCarRef->setCurrentRoad("END");
	_CemeteryOfcars->push_back(oldCarRef);
}

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
	
	for(int z=0; z <_carsInRoad->size() ; ++z){
		(*_carsInRoad)[z]->updateHistory();
		if ((*_carsInRoad)[z]->getLocation() != TheLastFaultyCarLocation){counterFaultyCarsInTheSameLine=0;}
		if ( (*_carsInRoad)[z]->getCondition() == 0)
		{
			int speedCalculation = int(ceil((_baseSpeed)/(pow(2,(counterFaultyCars-counterFaultyCarsInTheSameLine)))));
			(*_carsInRoad)[z]->setspeed(speedCalculation);

			int locationCalculation = (*_carsInRoad)[z]->getLocation() + speedCalculation;
			if (locationCalculation < _length)
				{(*_carsInRoad)[z]->setLocation(locationCalculation);}
			else{
				(*_carsInRoad)[z]->setLocation(_length);
				if((*_carsInRoad)[z]->getRoute()->empty()) {
					killCarInTheEnd((*_carsInRoad)[z]); 
					popFirstCarInRoad();
					--z;
				}
			}
		}
		else{
			++counterFaultyCars;
			(*_carsInRoad)[z]->setCondition((*_carsInRoad)[z]->getCondition()-1);
			if ((*_carsInRoad)[z]->getLocation()==TheLastFaultyCarLocation)
				{++counterFaultyCarsInTheSameLine;}
			else
			{
				TheLastFaultyCarLocation= (*_carsInRoad)[z]->getLocation();
				counterFaultyCarsInTheSameLine=1;
			}
		}
	}
}