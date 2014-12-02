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
	Reports();
	Reports(string Id, int time);
	Reports(Reports &other);
	Reports& operator=(const Reports &R);
	virtual void writeReport()=0;

	string getId();
	int getTime();
	void setId(string newId);
	void setTime(int newTime);
  };   
  
  #endif //_REPORTS_H_