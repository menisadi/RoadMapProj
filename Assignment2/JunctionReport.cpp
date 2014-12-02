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

void JunctionReport::writeReport()
{

}

string JunctionReport::getIdJunction(){ return idJunction_; }
void JunctionReport::setIdJunction(string newIdJunction){ idJunction_ = newIdJunction; }