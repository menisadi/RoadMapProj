// THIS IS THE DECLARATION FILE OF THE CLASS Junctions (Junctions.h) 
#ifndef _JUNCTIONS_H_
#define _JUNCTIONS_H_

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include "Roads.h"
//class Roads;

using namespace std;

  class Junctions{

  public:
     Junctions();
	 Junctions(const string& idJunctionVal);
     Junctions(const string& idJunctionVal, vector<Roads*>* roadsInJunctionVal,vector<int>* timeSliceVal ,vector<int>* timeSliceBeforeTheGreenLight);
     Junctions(const Junctions& copyJunctions);
     virtual ~Junctions();
     Junctions& operator=(const Junctions &JunctionsRightArg);

	void Junctions::copy(const Junctions& copyJunctions);
     
     string getIdJunction() const;
	 vector<Roads*>* getRoadsInJunction() const;
     vector<int>* getTimeSlice() const;
	 int Junctions::getTimeSliceByAppeared() const;
	 vector<int>* getTimeSliceBeforeTheGreenLight() const;
	 int getCurrentlyGreenLightRoadIndex() const;
	 int getConterStasticCarPass() const;
	 int getNoCarPassInThisTime() const;
	 int getForPrinterNumTimesAppeared() const;
     
	 void setID(const string& idJunctionVal);
     void setTimeSlice(vector<int>* timeSliceVal);
	 void setTimeSliceBeforeTheGreenLight(vector<int>* timeSliceVal);
	 void setRoadsInJunction(vector<Roads*>* roadsInJunction); 
	 void setCurrentlyGreenLightRoadIndex(int index);
	 void setConterStasticCarPass(int statstic);
	 void setNoCarPassInThisTime(int boolPass);
	 void setForPrinterNumTimesAppearedPlusOne();
	 void setForPrinterNumTimesAppearedZero();

	 void advanceCarsInJunctions();
	 void MoveCarFirstOnVectorFromSourceRoadFirstOnVectorToDestinationRoad(int i);
	 void replaceRoadinJunction(int MaxTimeSlice,int MinTimeSlice,int i);

	 private:
     string _idJunction;
     vector<Roads*>* _roadsInJunction; 
	 vector<int>* _timeSlice;
	 unsigned int _currentlyGreenLightRoadIndex;
	 vector<int>* _timeSliceBeforeTheGreenLight;
	 int _conterStasticCarPass;
	 int _noCarPassInThisTime;
	 int _forPrinterNumTimesAppeared;
	 
  };   
  
  #endif //_JUNCTIONS_H_