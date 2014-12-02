#include "Reports.h"

Reports::Reports(){}
Reports::Reports(string Id, int time):Id_(Id),time_(time) {}
Reports::Reports(Reports &other):Id_(other.getId),time_(other.getTime){}

Reports& Reports::operator=(const Reports &R)
{
	Id_ = R.getId;
	time_ = R.getTime;
	return *this;
}

void Reports::writeReport(){}

string Reports::getId(){ return Id_; }
int Reports::getTime(){ return time_; }
void Reports::setId(string newId){ Id_ = new; }
void Reports::setTime(int newTime){ time_ = newTime; }