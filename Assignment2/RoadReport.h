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
	 string beginJnc_;
     string endJnc_;
      
  public:
	  RoadReport();
	  RoadReport(string reportId, int time, string beginJnc, string endJnc);
	  RoadReport(RoadReport &other);
	  virtual ~RoadReport();
	  RoadReport & operator=(const RoadReport &R);
	  virtual void writeReport();

	  string getBeginJunc();
	  string getEndJunc();
	  void setBeginJunc(string newBeginJunc);
	  void setEndJunc(string newEndJunc);     
  };   
  
  #endif //_ROADREPORTS_H_