#pragma once
#include "Event.h"
class EventList: public Event
{
private:
	struct List
	{
		List* next =nullptr;
		Event* event =nullptr;
		List(Event* hap);
		List();
	};
	List* BEGlista;
	List* ENDlista;
public:
	EventList(Coordinates Who);
	~EventList();
	void push(Event* hap);
	Event* pop();
	//bool EventList::czyNiePusta();
};