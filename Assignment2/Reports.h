// THIS IS THE DECLARATION FILE OF THE CLASS Reports (Reports.h) 
#ifndef _REPORTS_H_
#define _REPORTS_H_

#include <vector>
#include <string>
#include "Commands.h"

using namespace std;


class Reports : public Commands
  {
  private:
	string Id_;
	int time_;
      
  public:
	virtual void writeReport()=0;
     
  };   
  
  #endif //_REPORTS_H_