#pragma once
#include <vector>
#include <string>

using namespace std;

class Event
{
	public:
		Event();
		Event(Event &other);
		Event(int type, int time, string carId);
		virtual ~Event();
		Event & operator=(const Event &E);
		
		virtual void performEvent() = 0;

		int getType();
		int getTime();
		string getCarId();
		void setType(int type);
		void setTime(int time);
		void setCarId(string carId);


	private:
		int _type;
		int _time;
		string _carId;
};

