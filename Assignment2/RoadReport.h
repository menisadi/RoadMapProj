// THIS IS THE DECLARATION FILE OF THE CLASS RoadReport (RoadReport.h) 
#ifndef _ROADREPORT_H_
#define _ROADREPORT_H_

#include <vector>
#include <string>
#include "Reports.h"
class Car;

using namespace std;


class RoadReport : public Reports
  {
  private:
	 string baginJnc_;
     string endJnc_;
      
  public:
	virtual void writeReport()=0;
     
  };   
  
  #endif //_ROADREPORTS_H_