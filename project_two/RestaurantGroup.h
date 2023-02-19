#pragma once
#include <cstring>
#include <iostream>

class RestaurantGroup
{
public:
	RestaurantGroup();
	RestaurantGroup(const char* name, int numOfPeople, const char* email, char specialSeating, bool receivePromotion);
	RestaurantGroup(const RestaurantGroup& other);
	~RestaurantGroup();

	const char* getName() const;
	int getNumberOfPeople() const;
	const char* getEmail() const;
	char getSpecialSeating() const;
	bool getReceivePromotion() const;
	
	void setName(const char* name);
	void setNumbeOfPeople(int num);
	void setEmail(const char* email);
	void setSpecialSeating(char choice);
	void setPromotionChoice(bool choice);

	friend std::ostream& operator<<(std::ostream& out, const RestaurantGroup& other);
	////friend bool operator==(const RestaurantGroup& other);
	const RestaurantGroup& operator=(const RestaurantGroup& other);


private:
	char* _name;
	int _numberOfPeople;
	char* _email;
	char _specialSeating;
	bool _receivePromotion;

	void _allocateMemory(char*& thisCharPtr, const char* buffer);

};
