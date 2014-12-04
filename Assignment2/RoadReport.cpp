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
	tree.put(Reports::getId().append(".start Junction"), getBeginJunc());
	tree.put(Reports::getId().append(".end JunctionId"), getEndJunc());
	string carWithBrackets = "";
	string thisRoadId = beginJnc_.append(",").append(endJnc_);
	//Roads* thisRoad = RoadsMap->find(thisRoadId)->second;
	vector<Car*>* carsInRoad = RoadsMap->find(thisRoadId)->second->getCarsInRoad();
	for (int c = 0; c < carsInRoad->size(); c = c + 1)
	{
		carWithBrackets.append("(");
		carWithBrackets.append((*carsInRoad)[c]->getID());
		carWithBrackets.append(",");
		string location = boost::lexical_cast<string>((*carsInRoad)[c]->getLocation());
		carWithBrackets.append(location);
		carWithBrackets.append(")");
	}
	tree.put(Reports::getId().append(".cars"), carWithBrackets);
}

string RoadReport::getBeginJunc(){ return beginJnc_; }
string RoadReport::getEndJunc(){ return endJnc_; }
void RoadReport::setBeginJunc(string newBeginJunc){ beginJnc_ = newBeginJunc; }
void RoadReport::setEndJunc(string newEndJunc){ endJnc_ = newEndJunc; }