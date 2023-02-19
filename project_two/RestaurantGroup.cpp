#include "RestaurantGroup.h"


RestaurantGroup::RestaurantGroup()
	:_name(nullptr), _numberOfPeople(0), _email(nullptr), _specialSeating('n'), _receivePromotion(0)
{
}


RestaurantGroup::RestaurantGroup(const char* name, int numOfPeople, const char* email, char specialSeating, bool receivePromotion)
	:_name(nullptr), _numberOfPeople(numOfPeople), _email(nullptr), _specialSeating(specialSeating), _receivePromotion(receivePromotion)
{
	_allocateMemory(_name, name);
	_allocateMemory(_email, email);
}

RestaurantGroup::RestaurantGroup(const RestaurantGroup& other)
{
	*this = other;
}

void RestaurantGroup::_allocateMemory(char*& thisCharPtr, const char* buffer)
{
	int buffsize = strlen(buffer) + 1;
	thisCharPtr = new char[buffsize];
	memcpy(thisCharPtr,buffer,buffsize);
}


RestaurantGroup::~RestaurantGroup()
{
	if (_name && _email)
	{
		delete[] _name;
		delete[] _email;
		_name = nullptr;
		_email = nullptr;
	}
}


void RestaurantGroup::setName(const char* name)
{
	if (!_name)
	{
		delete[] _name;
	}
	_allocateMemory(_name, name);
}


void RestaurantGroup::setEmail(const char* email)
{
	if (!_email)
	{
		delete[] _email;
	}
	_allocateMemory(_email, email);
}


void RestaurantGroup::setNumbeOfPeople(int number)
{
	_numberOfPeople = number;
}


void RestaurantGroup::setSpecialSeating(char specialSeating)
{
	_specialSeating = specialSeating;
}


void RestaurantGroup::setPromotionChoice(bool choice)
{
	_receivePromotion = choice;
}


const char* RestaurantGroup::getName() const
{
	return _name;
}


const char* RestaurantGroup::getEmail() const
{
	return _email;
}


int RestaurantGroup::getNumberOfPeople() const
{
	return _numberOfPeople;
}


char RestaurantGroup::getSpecialSeating() const
{
	return _specialSeating;
}


bool RestaurantGroup::getReceivePromotion() const
{
	return _receivePromotion;
}

const RestaurantGroup& RestaurantGroup::operator= (const RestaurantGroup& other)
{
	if (this == &other) return *this;

	setName(other.getName());
	setNumbeOfPeople(other.getNumberOfPeople());
	setEmail(other.getEmail());
	setSpecialSeating(other.getSpecialSeating());
	setPromotionChoice(other.getReceivePromotion());
	return *this;
}

std::ostream& operator<<(std::ostream& out, const RestaurantGroup& other)
{
	out << "Name of Group: " << other.getName() << "\n"
		<< "Number of People: " << other.getNumberOfPeople() << "\n"
		<< "Name of email: " << other.getEmail() << "\n"
		<< "Special setting: " << other.getSpecialSeating() << "\n"
		<< "Promotional interest: " << other.getReceivePromotion() << "\n";
	return out;
}
