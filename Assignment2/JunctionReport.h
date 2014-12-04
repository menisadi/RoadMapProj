// THIS IS THE DECLARATION FILE OF THE CLASS JunctionReport (JunctionReport.h) 
#ifndef _JUNCTIONREPORT_H_
#define _JUNCTIONREPORT_H_

#include <vector>
#include <string>
#include "Junctions.h"
#include "Reports.h"
#include "GlobalVar.h"
#include <boost/lexical_cast.hpp>
//class Car;

using namespace std;

class JunctionReport : public Reports
  {
  private:
	 string idJunction_;
      
  public:
	  JunctionReport();
	  JunctionReport(string reportId, int time, string idJunction);
	  JunctionReport(JunctionReport &other);
	  virtual ~JunctionReport();
	  JunctionReport & operator=(const JunctionReport &R);
	  virtual void writeReport(boost::property_tree::ptree &tree);

	  string getIdJunction();
	  void setIdJunction(string newIdJunction);
  };   
  
  #endif //JUNCTIONREPORT_H_