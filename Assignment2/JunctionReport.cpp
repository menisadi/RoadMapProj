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
	vector<int>* timeSlicesBeforeGreen = JunctionsMap->find(getIdJunction())->second->getTimeSliceBeforeTheGreenLight();
	for (int t = 0; t < timeSlices->size(); t = t + 1)
		slicesWithBrackets.append("(").append(boost::lexical_cast<string>((*timeSlices)[t]))
		.append(",").append(boost::lexical_cast<string>((*timeSlicesBeforeGreen)[t])).append(")");	
	tree.put(Reports::getId().append(".time slices"), slicesWithBrackets);
	
	//	1 iterate roads in junction
	//		1.1 iterate cars in road
	//			1.1.1 append (car) to stringRoad_i 
	//		1.2	tree.put(Reports::getId().append("road_i"), stringRoad_i )
	string roadsDivided = "";
	vector<Roads*>* roadIn = JunctionsMap->find(getIdJunction())->second->getRoadsInJunction();
	for (int r = 0; r < roadIn->size(); r = r + 1)
	{
		vector<Car*>* carsIn = (*roadIn)[r]->getCarsInRoad();
		string stringOfCars = "";
		for (int c = 0; c < carsIn->size(); c = c + 1)
			stringOfCars.append("(").append((*carsIn)[c]->getID()).append(")");
		tree.put(Reports::getId().append(".").append((*roadIn)[r]->getBaginJnc()), stringOfCars);
	}
}

string JunctionReport::getIdJunction(){ return idJunction_; }
void JunctionReport::setIdJunction(string newIdJunction){ idJunction_ = newIdJunction; }