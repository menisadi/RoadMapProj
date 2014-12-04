#include "JunctionReport.h"

JunctionReport::JunctionReport(){}

JunctionReport::JunctionReport(string reportId, int time, string idJunction)
	: Reports(reportId, time), idJunction_(idJunction) {}

JunctionReport::JunctionReport(JunctionReport &other) :Reports(other), idJunction_(other.idJunction_){}

JunctionReport& JunctionReport::operator=(const JunctionReport &R)
{
	Reports::operator=(R);
	idJunction_ = R.idJunction_;
	return *this;
}

JunctionReport::~JunctionReport(){}

void JunctionReport::writeReport(boost::property_tree::ptree &tree)
{
	tree.put(Reports::getId().append(".junction Id"), getIdJunction());
	string slicesWithBrackets = "";
	vector<int>* timeSlices = JunctionsMap->find(getIdJunction())->second->getTimeSlice();
	for (int t = 0; t < timeSlices->size(); t = t + 1)
		slicesWithBrackets.append("(").append(boost::lexical_cast<string>((*timeSlices)[t]))
			.append(",").append(boost::lexical_cast<string>(t)).append(")");

	tree.put(Reports::getId().append(".time slices"), slicesWithBrackets);
	/*
	string roadsWithBrackets = "";
	vector<Roads*>* roadIn = JunctionsMap->find(getIdJunction())->second->getRoadsInJunction();
	for (int r = 0; r < roadIn->size(); r = r + 1)
		roadsWithBrackets.append("(").append(boost::lexical_cast<string>((*timeSlices)[t]))
		.append(",").append(boost::lexical_cast<string>(t)).append(")");

	tree.put(Reports::getId().append(".time slices"), roadsWithBrackets);
	*/
	//<incomingJunctionId >= (<carId>)*
}

string JunctionReport::getIdJunction(){ return idJunction_; }
void JunctionReport::setIdJunction(string newIdJunction){ idJunction_ = newIdJunction; }