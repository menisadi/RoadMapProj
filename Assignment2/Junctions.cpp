#include "Junctions.h"

Junctions::Junctions(){}
Junctions:: Junctions(const string& idJunctionVal):_idJunction(idJunctionVal){}
Junctions:: Junctions(const string& idJunctionVal, vector<Roads*>* roadsInJunctionVal,vector<int>* timeSliceVal,vector<int>* timeSliceBeforeTheGreenLight):_idJunction(idJunctionVal),_roadsInJunction(roadsInJunctionVal),_timeSlice(timeSliceVal),_currentlyGreenLightRoadIndex(0),_timeSliceBeforeTheGreenLight(timeSliceBeforeTheGreenLight), _conterStasticCarPass(0), _noCarPassInThisTime(0),_forPrinterNumTimesAppeared(0){
}

Junctions::Junctions(const Junctions& copyJunctions){
	copy(copyJunctions);
}
Junctions:: ~Junctions(){
	for( vector<Roads*>::iterator ii=_roadsInJunction->begin(); ii!=_roadsInJunction->end(); ++ii)
		delete (*ii);													
	delete (_timeSliceBeforeTheGreenLight);  
	delete (_roadsInJunction);
	delete (_timeSlice);
}
Junctions& Junctions::operator=(const Junctions &JunctionsRightArg){
  copy(JunctionsRightArg);
  return *this;
}

void Junctions::copy(const Junctions& copyJunctions){   
	_idJunction=copyJunctions.getIdJunction();
	 _roadsInJunction = copyJunctions.getRoadsInJunction();
	_timeSlice=copyJunctions.getTimeSlice();
	_timeSliceBeforeTheGreenLight=copyJunctions.getTimeSliceBeforeTheGreenLight();
	_currentlyGreenLightRoadIndex=copyJunctions.getCurrentlyGreenLightRoadIndex();
}

     
string Junctions::getIdJunction() const{
	return _idJunction;
}

vector<Roads*>* Junctions::getRoadsInJunction() const{
return _roadsInJunction;								 //meybe return *??
}
vector<int>* Junctions::getTimeSlice() const{
	return _timeSlice;
}
int Junctions::getTimeSliceByAppeared() const{
	return (*_timeSlice)[_forPrinterNumTimesAppeared];
}
vector<int>* Junctions::getTimeSliceBeforeTheGreenLight() const{
	return _timeSliceBeforeTheGreenLight;
}

int Junctions::getCurrentlyGreenLightRoadIndex() const{
	return _currentlyGreenLightRoadIndex;
}
int Junctions::getConterStasticCarPass() const{
	return _conterStasticCarPass;
}
int Junctions::getNoCarPassInThisTime() const{
	return _noCarPassInThisTime;
}
int Junctions::getForPrinterNumTimesAppeared() const{
	return _forPrinterNumTimesAppeared;
}
     
void Junctions::setID(const string& idJunctionVal){
	_idJunction=idJunctionVal;
}
void Junctions::setTimeSlice(vector<int>* timeSliceVal){
	 _timeSlice = timeSliceVal;
}
void Junctions::setTimeSliceBeforeTheGreenLight(vector<int>* timeSliceVal){
	 _timeSliceBeforeTheGreenLight = timeSliceVal;
}
void Junctions::setRoadsInJunction(vector<Roads*>* roadsInJunction){  
	_roadsInJunction=roadsInJunction;
}


void Junctions::setCurrentlyGreenLightRoadIndex(int index){  
	_currentlyGreenLightRoadIndex=index;
}

void Junctions::setConterStasticCarPass(int statstic){  
	_conterStasticCarPass=statstic;
}
void Junctions::setNoCarPassInThisTime(int boolPass){  
	_noCarPassInThisTime=boolPass;
}
void Junctions::setForPrinterNumTimesAppearedPlusOne(){  
	++_forPrinterNumTimesAppeared;
}
void Junctions::setForPrinterNumTimesAppearedZero(){
	_forPrinterNumTimesAppeared=0;
}

void Junctions::MoveCarFirstOnVectorFromSourceRoadFirstOnVectorToDestinationRoad(int i){
	if(((*_roadsInJunction)[i]->getCarsInRoad()->size() > 0)){													//if there is cars in this road?
		if((*(*_roadsInJunction)[i]->getCarsInRoad())[0]->getLocation()==(*_roadsInJunction)[i]->getlength()){  //there is cars wait for pass?
			Car *carGoesGreen =(*_roadsInJunction)[i]->returnFirstCarInRoad();
			Roads* theNextRoad = carGoesGreen->popFirstRoadsInRoute();
			carGoesGreen->setCurrentRoad(theNextRoad->getId());
			carGoesGreen->setLocation(0);
			theNextRoad->pushNewCarToRoad(carGoesGreen);
			(*_roadsInJunction)[i]->popFirstCarInRoad();
			++_conterStasticCarPass;
			}
		}
}

void Junctions::replaceRoadinJunction(int MaxTimeSlice, int MinTimeSlice,int i){
		if(_conterStasticCarPass==0){
			(*_timeSliceBeforeTheGreenLight)[i]=max((*_timeSliceBeforeTheGreenLight)[i]-1,MinTimeSlice);
		}
		else if (_conterStasticCarPass>=(*_timeSliceBeforeTheGreenLight)[i]){
			(*_timeSliceBeforeTheGreenLight)[i]=min((*_timeSliceBeforeTheGreenLight)[i]+1,MaxTimeSlice);
		}
		
		(*_timeSlice)[i]=-1;
		++_currentlyGreenLightRoadIndex;
		if(_currentlyGreenLightRoadIndex >= _roadsInJunction->size())
			_currentlyGreenLightRoadIndex=0;//only when the all circle of Roads was over
}

void Junctions::advanceCarsInJunctions(){
		/* Advance in junction:
		1---if time slice left is 0, replace road and update next time slice for that road by if any cars passed at that time (by the rules in the assignment)
		2---find car in the new road (or old if time slice was > 0)
		3---if car found push it.
		4---reduce time slice for that road.
		*/
	int sizeOfRoadsInJunction=(*_roadsInJunction).size();
	

	if(sizeOfRoadsInJunction>0){
		if((*_timeSlice)[_currentlyGreenLightRoadIndex]>0 ){
			MoveCarFirstOnVectorFromSourceRoadFirstOnVectorToDestinationRoad(_currentlyGreenLightRoadIndex);
			--(*_timeSlice)[_currentlyGreenLightRoadIndex];
		}
		else{
			MoveCarFirstOnVectorFromSourceRoadFirstOnVectorToDestinationRoad(_currentlyGreenLightRoadIndex);
			replaceRoadinJunction(global_maxTimeSlice,global_minTimeSlice,_currentlyGreenLightRoadIndex);
			_conterStasticCarPass=0;
			(*_timeSlice)[_currentlyGreenLightRoadIndex]=(*_timeSliceBeforeTheGreenLight)[_currentlyGreenLightRoadIndex];
			}	
	}
}

