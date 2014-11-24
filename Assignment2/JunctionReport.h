// THIS IS THE DECLARATION FILE OF THE CLASS JunctionReport (JunctionReport.h) 
#ifndef _JUNCTIONREPORT_H_
#define _JUNCTIONREPORT_H_

#include <vector>
#include <string>
#include "Reports.h"

//class Car;

using namespace std;

class JunctionReport : public Reports
  {
  private:
	 string idJunction_;
      
  public:
	virtual void writeReport()=0;
     
  };   
  
  #endif //JUNCTIONREPORT_H_