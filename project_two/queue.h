#pragma once
#include <fstream>
#include "RestaurantGroup.h"
const int MAX_CHAR = 101; 

class Queue
{
public:
	Queue();
	//Queue(const Queue& other);
	~Queue();
	
	void enqueue(const RestaurantGroup& aGroup);
	bool dequeue(RestaurantGroup& aGroup);
	//bool peek(RestaurantGroup& aGroup) const;
	bool _isEmpty();
		
	void print();
	int size() const;
	void loadFromFile(const char* file);

private:
	
	struct _Node
	{
		RestaurantGroup* data;
		_Node* next;

		_Node(const RestaurantGroup aGroup)
		{
			data = new RestaurantGroup(aGroup);
			next = nullptr;
		}
	};

	_Node* _head;
	_Node* _tail;
	int _size;
//	void _destroyNode(_Node* currNode);
};

