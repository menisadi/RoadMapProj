// THIS IS THE DECLARATION FILE OF THE CLASS CarReport (CarReport.h) 
#ifndef _CARREPORT_H_
#define _CARREPORT_H_

#include <vector>
#include <string>
#include "Reports.h"

class Car;

using namespace std;

class CarReport : public Reports
  {
  private:
	 string baginJnc_;
     string endJnc_;
	 string carId_;
      
  public:
	virtual void writeReport()=0;
     
  };   
  
  #endif //CARREPORT_H_