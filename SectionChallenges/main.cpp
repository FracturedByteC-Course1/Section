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

	return 0;
}