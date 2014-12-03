#include "Reports.h"

Reports::Reports(){}

Reports::Reports(string Id, int time):Id_(Id),time_(time) {}

Reports::Reports(Reports &other):Id_(other.Id_),time_(other.time_){}

Reports& Reports::operator=(const Reports &R)
{
	Id_ = R.Id_;
	time_ = R.time_;
	return *this;
}

Reports::~Reports(){}

void Reports::writeReport(boost::property_tree::ptree &tree){}

string Reports::getId(){ return Id_; }
int Reports::getTime(){ return time_; }
void Reports::setId(string newId){ Id_ = newId; }
void Reports::setTime(int newTime){ time_ = newTime; }

