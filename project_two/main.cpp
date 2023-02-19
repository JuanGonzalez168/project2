#include <iostream>
#include "RestaurantGroup.h"
#include "queue.h"

int main()
{
	RestaurantGroup group("Juan", 10, "juandg168@gmail.com",'w', true);
	RestaurantGroup group2("Steph", 5, "Stephanie@gmail.com",'w', false);
	//RestaurantGroup group3("Erin", 3, "ErinGonzalez@gmail.com", 'w', true);
	RestaurantGroup temp;
	Queue waitlist;
	
	waitlist.loadFromFile("data.txt");
	std::cout << waitlist.size() << '\n';
	waitlist.print();

	//waitlist.enqueue(group3);
	//waitlist.print();
	
	waitlist.dequeue(temp);
	std::cout << temp << "\n";
	
	waitlist.dequeue(temp);
	std::cout << temp << "\n";

	waitlist.print();

	return 0;
}