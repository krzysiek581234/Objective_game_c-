#include "EventList.h"
EventList::List::List() {}
EventList::List::List(Event* happening)
{
	this->next = nullptr;
	this->event = happening;
}

EventList::EventList(Coordinates kto)
{
	this->BEGlista = new List;
	this->ENDlista = BEGlista;
	this->What = Call::eventlist;
	this->Who = kto;
	this->Where = kto;

}
void EventList::push(Event* happening)
{
	List* temp = new List;

	ENDlista->next = temp;
	ENDlista = temp;
	ENDlista->event = happening;

	
}
Event* EventList::pop()
{
	List* temp = BEGlista;
	return 0;
}
EventList::~EventList()
{
	List* temp = BEGlista;
	while (temp->next != nullptr)
	{
		List* temp2 = temp->next;
		delete temp;
		temp = temp2;
	}
	delete temp;
}