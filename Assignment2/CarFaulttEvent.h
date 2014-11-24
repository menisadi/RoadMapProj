#pragma once
#include "Event.h"
class CarFaulttEvent :
	public Event
{
public:
	CarFaulttEvent();
	~CarFaulttEvent();
	void performEvent();
};

