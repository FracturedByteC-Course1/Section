#include<iostream>
#include<vector>

using namespace std;

void Section4();
void Section6();
void Section7();
void Section8();


int main() {
	//Section4();
	//Section6();
	//Section7();
	Section8();
	return 0;
}

void Section8()
{
	const int dollar{ 100 };
	const int quarter{ 25 };
	const int dime{ 10 };
	const int nickel{ 5 };
	
	int amount;
	int dollars, quarters, dimes, nickels, pennies; //quarters - 25, dimes - 10, nickels - 5, pennies - 1
	cout << "Enter an amount in cents: ";
	cin >> amount;
	cout << "You can provide change for this change as follows:" << endl;
	if (amount >= 0)
	{
		if (amount >= dollar) {
			dollars = amount / dollar;
			amount -= dollars * dollar;
			cout << "dollars: " << dollars<< endl;
		}
		if (amount < dollar) {
			quarters = amount / quarter;
			amount -= quarters * quarter;
			cout << "quarters: " << quarters << endl;
		}
		if (amount < quarter) {
			dimes = amount / dime;
			amount -= dimes * dime;
			cout << "dimes: " << dimes << endl;
		}
		if (amount < dime) {
			nickels = amount / nickel;
			amount -= nickels * nickel;
			cout << "nickels: " << nickels << endl;
		}
		pennies = amount;
		cout << "pennies: " << pennies << endl;
	}
}

void Section4() {
	//Section 4
	int favorite;

	cout << "Enter your favorite number between 1 and 100: " << endl;
	cin >> favorite;
	if (1 <= favorite && favorite <= 100)
		cout << "That's my favorite number too.\nNo really " << favorite << " is my favorite number.";
	else
		cout << "That's number more 100 or less 1";
}
void Section6() {
	//Section 6
	const double price_small_room{ 25 };
	const double price_large_room{ 35 };
	const double percent{ 6 };
	int count_small_rooms;
	int count_large_rooms;

	cout << "\n\nHello, welcome to Frank's Carpet Cleaning Service\n\nHow many small rooms would you like clean? ";
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
}
void Section7() {
	//Section 7
	vector<int> vector1;
	vector<int> vector2;

	vector1.push_back(10);
	vector1.push_back(20);

	cout << "\n\nvector1:" << endl;
	for (int i = 0; i < vector1.size(); ++i)
		cout << vector1.at(i) << endl;
	cout << "vector1 contains " << vector1.size() << " elements" << endl;

	vector2.push_back(100);
	vector2.push_back(200);

	cout << "\nvector2:" << endl;
	for (int i = 0; i < vector2.size(); ++i)
		cout << vector2.at(i) << endl;
	cout << "vector2 contains " << vector2.size() << " elements" << endl;

	vector<vector<int>> vector2d;

	vector2d.push_back(vector1);
	vector2d.push_back(vector2);

	cout << "\nvector2d:" << endl;
	cout << vector2d.at(0).at(0) << " " << vector2d.at(0).at(1) << endl;
	cout << vector2d.at(1).at(0) << " " << vector2d.at(1).at(1) << endl;

	vector1.at(0) = 1000;

	cout << "vector2d:" << endl;
	cout << vector2d.at(0).at(0) << " " << vector2d.at(0).at(1) << endl;
	cout << vector2d.at(1).at(0) << " " << vector2d.at(1).at(1) << endl;

	cout << "\nvector1:" << endl;
	for (int i = 0; i < vector1.size(); ++i)
		cout << vector1.at(i) << endl;
	cout << "vector1 contains " << vector1.size() << " elements" << endl;
}