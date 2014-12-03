// THIS IS THE DECLARATION FILE OF THE CLASS Reports (Reports.h) 
#ifndef _REPORTS_H_
#define _REPORTS_H_

#include <vector>
#include <string>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ini_parser.hpp>
#include "GlobalVar.h"
// #include "Commands.h"

using namespace std;


class Reports // : public Commands
  {
  private:
	string Id_;
	int time_;
      
  public:
	Reports();
	Reports(string Id, int time);
	Reports(Reports &other);
	Reports& operator=(const Reports &R);
	virtual ~Reports();
	virtual void writeReport(boost::property_tree::ptree &tree) = 0;

	string getId();
	int getTime();
	void setId(string newId);
	void setTime(int newTime);
  };   
  
  #endif //_REPORTS_H_