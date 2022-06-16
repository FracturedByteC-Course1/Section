#include<iostream>

using namespace std;

int main() {

	int favorite;

	cout << "Enter your favorite number between 1 and 100: " << endl;
	cin >> favorite;
	if (1 <= favorite && favorite <= 100)
		cout << "That's my favorite number too.\nNo really " << favorite << " is my favorite number.";
	else
		cout << "That's number more 100 or less 1";

	const double price_small_room{ 25 };
	const double price_large_room{ 35 };
	const double percent{ 6 };
	int count_small_rooms;
	int count_large_rooms;

	cout << "Hello, welcome to Frank's Carpet Cleaning Service\n\nHow many small rooms would you like clean? ";
	cin >> count_small_rooms;
	cout << "How many large rooms would you like clean? ";
	cin >> count_large_rooms;
	double sum = price_small_room * count_small_rooms + price_large_room * count_large_rooms;
	cout << "Estimate for carpet cleaning service\nNumber of small rooms: " << count_small_rooms
		<< "\nNumber of large rooms: " << count_large_rooms << "\nPrice per small room: $" << price_small_room
		<< "\nPrice per lrge room: $" << price_large_room << "\nCost: $" << sum << "\nTax: " << sum / 100 * percent << endl;
	cout << "=================================" << endl;
	cout << "Total estimate: $" << sum + (sum / 100 * percent) << "\nThis estimate is valid for 30 days\n";
	cout << "Time elapsed: " << __DATE__ << " " << __TIME__;

	return 0;
}