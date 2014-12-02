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
	 string carId_;
      
  public:
	CarReport();
	CarReport(string reportId, int time, string carId);
	CarReport(CarReport &other);
	virtual ~CarReport();
	CarReport & operator=(const CarReport &R);
	virtual void writeReport();

	string getCarId();
	void setCarId(string newCarId);
  };   
  
  #endif //CARREPORT_H_