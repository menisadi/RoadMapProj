#ifndef _EVENT_H_
#define _EVENT_H_

#include <vector>
#include <string>
#include "Roads.h"

using namespace std;

class Event
{
	public:
		Event();
		Event(Event &other);
		Event(int type, int time, const string& carId);
		virtual ~Event();
		Event & operator=(const Event &eventRightArg);
		
		virtual void performEvent() = 0;

		int getType();
		int getTime();
		string getCarId();
		void setType(int type);
		void setTime(int time);
		void setCarId(const string& carId);


	private:
		int _type;
		int _time;
		string _carId;
};

#endif