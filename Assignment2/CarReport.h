// THIS IS THE DECLARATION FILE OF THE CLASS CarReport (CarReport.h) 
#ifndef _CARREPORT_H_
#define _CARREPORT_H_

#include <vector>
#include <string>
#include <iostream>
#include "Reports.h"
#include "Car.h"
//class Car;

using namespace std;

class CarReport : public Reports
  {
  private:
	 string carId_;
      
  public:
	CarReport();
	CarReport(string reportId, int time, string carId);
	CarReport(CarReport &other);
	CarReport & operator=(const CarReport &R);
	virtual ~CarReport();
	virtual void writeReport(boost::property_tree::ptree &tree);

	string getCarId();
	void setCarId(string newCarId);
  };   
  
  #endif //CARREPORT_H_