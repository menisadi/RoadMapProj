#include "RoadReport.h"

RoadReport::RoadReport(){}

RoadReport::RoadReport(string reportId, int time, string beginJnc, string endJnc)
	:Reports(reportId, time), beginJnc_(beginJnc), endJnc_(endJnc) {}

RoadReport::RoadReport(RoadReport &other) :Reports(other), beginJnc_(other.beginJnc_), endJnc_(other.endJnc_){}

RoadReport& RoadReport::operator=(const RoadReport &R)
{
	Reports::operator=(R);
	beginJnc_ = R.beginJnc_;
	endJnc_ = R.endJnc_;
	return *this;
}

RoadReport::~RoadReport(){}

void RoadReport::writeReport(boost::property_tree::ptree &tree)
{

}

string RoadReport::getBeginJunc(){ return beginJnc_; }
string RoadReport::getEndJunc(){ return endJnc_; }
void RoadReport::setBeginJunc(string newBeginJunc){ beginJnc_ = newBeginJunc; }
void RoadReport::setEndJunc(string newEndJunc){ endJnc_ = newEndJunc; }