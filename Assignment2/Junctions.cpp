#include "Junctions.h"

Junctions::Junctions(){}
Junctions:: Junctions(const string& idJunctionVal):_idJunction(idJunctionVal){}
Junctions:: Junctions(const string& idJunctionVal, vector<Roads*>* roadsInJunctionVal,vector<int>* timeSliceVal):_idJunction(idJunctionVal),_roadsInJunction(roadsInJunctionVal),_timeSlice(timeSliceVal){
}

Junctions::Junctions(const Junctions& copyJunctions){
	copy(copyJunctions);
}
Junctions:: ~Junctions(){
	for( vector<Roads*>::iterator ii=_roadsInJunction->begin(); ii!=_roadsInJunction->end(); ++ii)
		delete (*ii);
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
     
void Junctions::setID(const string& idJunctionVal){
	_idJunction=idJunctionVal;
}
void Junctions::setTimeSlice(vector<int>* timeSliceVal){
	 _timeSlice = timeSliceVal;	//memory ???? deep copy??
}
void Junctions::setRoadsInJunction(vector<Roads*>* roadsInJunction){  
	_roadsInJunction=roadsInJunction;
}
void Junctions::MoveCarFirstOnVectorFromSourceRoadFirstOnVectorToDestinationRoad(){
	if(((*_roadsInJunction)[0]->getCarsInRoad()->size() > 0)){													//if there is cars in this road?
			if((*(*_roadsInJunction)[0]->getCarsInRoad())[0]->getLocation()==(*_roadsInJunction)[0]->getlength()){  //there is cars wait for pass?
				std::vector<Roads*>::iterator itsourceRoad =(*_roadsInJunction).begin();
				Car *carGoesGreen =(*_roadsInJunction)[0]->popFirstCarInRoad();
				carGoesGreen->setLocation(0);
				if(carGoesGreen->getRoute()->size()>0){
					Roads* theNextRoad = carGoesGreen->popFirstRoadsInRoute();
					carGoesGreen->setCurrentRoad(theNextRoad->getId());
					theNextRoad->pushNewCarToRoad(carGoesGreen);
				}
				else{
					carGoesGreen->setCurrentRoad("END");
					(*_roadsInJunction)[0]->killCarInTheEnd(carGoesGreen);
				}
				//	delete all ptr!!
				cout << "car moved road: " << carGoesGreen->getID() << endl;
			}
		}
		
		
}

void Junctions::replaceRoadinJunction(int conterStasticCarPass, int MaxTimeSlice, int MinTimeSlice){
		if(conterStasticCarPass==0)
			(*_timeSlice)[0]=max((*_timeSlice)[0]-1,MinTimeSlice);
		else if (conterStasticCarPass==(*_roadsInJunction)[0]->getlength())
			(*_timeSlice)[0]=min((*_timeSlice)[0]+1,MaxTimeSlice);
		else{
			swap(_timeSlice[0], _timeSlice[(*_timeSlice).size()-1]);
			swap(_roadsInJunction[0], _roadsInJunction[(*_roadsInJunction).size()-1]);
		}
}

void Junctions::advanceCarsInJunctions(){
		/* Advance in junction:
		1---if time slice left is 0, replace road and update next time slice for that road by if any cars passed at that time (by the rules in the assignment)
		2---find car in the new road (or old if time slice was > 0)
		3---if car found push it.
		4---reduce time slice for that road.
		*/
	int conterStasticCarPass=0;
	if((*_roadsInJunction).size()>0){
		if((*_timeSlice)[0]<0 ){
			replaceRoadinJunction(conterStasticCarPass,global_maxTimeSlice,global_minTimeSlice);
			conterStasticCarPass=0;
		}
		MoveCarFirstOnVectorFromSourceRoadFirstOnVectorToDestinationRoad();
		--(*_timeSlice)[0];
		++conterStasticCarPass;	
	}
}

