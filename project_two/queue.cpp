#include "queue.h"


Queue::Queue()
	:_head(nullptr), _tail(nullptr), _size(0)
{
}

Queue::~Queue()
{
	if (_size != 0)
	{
		_Node* tempHead = _head;
		while (_head != _tail)
		{
			_head = _head->next;
			delete[] tempHead;
			tempHead = _head;
		}
		_head = nullptr;
	}
}

/*
void Queue::_destroyNode(_Node* currNode)
{
	if (_head == nullptr) return;
	_destroyNode(_head->next);
	delete _head;
}
*/

bool Queue::_isEmpty()
{
	if (_size == 0) return true;
	return false;
}


int Queue::size() const 
{ 
	return _size; 
}


void Queue::enqueue(const RestaurantGroup& aGroup)
{

	_Node* newNode = new _Node(aGroup);
	if (!_head)
	{
		_head = newNode;
		_tail = newNode;
		_tail->next = _head; //NEW
	}
	else
	{
		_tail->next = newNode;
		_tail = newNode;
		_tail->next = _head; //NEW
	}
	_size++;
}


bool Queue::dequeue(RestaurantGroup& aGroup)
{
	if (_isEmpty()) return false;
	_Node* temp = _head;
	_head = _head->next;
	aGroup = *temp->data;
	delete temp;
	_size--;
	return true;
}

void Queue::loadFromFile(const char* file)
{
	std::fstream infile;
	infile.open(file);
	if (!infile)
	{
		std::cerr << "\nFailed to open " << file << " for reading!" << std::endl;
	}
	

	char tempName[MAX_CHAR];
	char tempEmail[MAX_CHAR];
	int tempNum = 0;
	bool tempPromotion;
	char tempSeating;
	
	RestaurantGroup tempGroup;
	
	while (!infile.eof())
	{
		infile.get(tempName, MAX_CHAR, ';');
		infile.get();

		infile.get(tempEmail, MAX_CHAR, ';');
		infile.get();

		infile >> tempSeating;
		infile.get();

		infile >> tempPromotion;
		infile.get();

		infile >> tempNum;
		infile.ignore(MAX_CHAR, '\n');

		tempGroup.setName(tempName);
		tempGroup.setEmail(tempEmail);
		tempGroup.setNumbeOfPeople(tempNum);
		tempGroup.setSpecialSeating(tempSeating);
		tempGroup.setPromotionChoice(tempPromotion);
		enqueue(tempGroup);
		infile.peek();
	}

	infile.close();
	std::cout << "\nUpdated List from file:" << file << '\n';
}

void Queue::print()
{
	if (_isEmpty())
	{
		std::cout << "!Empty waitlist\n";
	}
	
	else
	{
		int i = 0;
		for (_Node* current = _head; i < _size; current = current->next)
		{
			std::cout << *current->data << std::endl;
			i++;
		}
	}
}




