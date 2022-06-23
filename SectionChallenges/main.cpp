#include<numeric>
#include<algorithm>
#include"Movies.h"
#include"Account_Util.h"

void Section4();
void Section6();
void Section7();
void Section8();
void Section9();
void Section10();
void LetterPyramid();
void Section11();
void Section12();
void Section13();
void Section15();

char CheckChoice(char choice);
void Print(vector<int> v);
double AVG(vector<int> v);
int MIN(vector<int> v);
int MAX(vector<int> v);
bool Quit();

void print(const int *arr, size_t size);
int* apply_all(const int *arr1, size_t arr1_size, const int *arr2, size_t arr2_size);

void Section16();

int main() {
	//Section4();
	//Section6();
	//Section7();
	//Section8();
	//Section9();
	//Section10();
	//LetterPyramid();
	//Section11();
	//Section12();
	//Section13();
	//Section15();
	//Section16();
	return 0;
}

void Section16()
{
	Checking_Account c;
	cout << c << endl;

	Savings_Account s{ "Frank", 5000,2.6 };
	cout << s << endl;
	s.deposit(10000);
	cout << s << endl;
	s.withdraw(10000);
	cout << s << endl;

	Account *ptr = new Trust_Account{ "Leo", 10000, 2.6 };
	cout << *ptr << endl;
}

void Section15()
{
	cout.precision(2);
	cout << fixed;

	vector<Account> accounts;
	accounts.push_back(Account{});
	accounts.push_back(Account{ "Larry" });
	accounts.push_back(Account{ "Moe",2000 });
	accounts.push_back(Account{ "Curly", 5000 });

	display(accounts);
	deposit(accounts, 1000);
	withdraw(accounts, 2000);

	vector<Savings_Account> sav_accounts;
	sav_accounts.push_back(Savings_Account{});
	sav_accounts.push_back(Savings_Account{"Superman"});
	sav_accounts.push_back(Savings_Account{"Batman", 2000});
	sav_accounts.push_back(Savings_Account{"Wonderwoman",5000,5.0});

	display(sav_accounts);
	deposit(sav_accounts, 1000);
	withdraw(sav_accounts, 2000);

	vector<Checking_Account> check_accounts;
	check_accounts.push_back(Checking_Account{});
	check_accounts.push_back(Checking_Account{"Kirk"});
	check_accounts.push_back(Checking_Account{"Spock",2000});
	check_accounts.push_back(Checking_Account{"Spock",5000});
	
	display(check_accounts);
	deposit(check_accounts, 1000);
	withdraw(check_accounts, 2000);

	vector<Trust_Account> trust_accounts;
	trust_accounts.push_back(Trust_Account{});
	trust_accounts.push_back(Trust_Account{"Athos", 10000, 5.0});
	trust_accounts.push_back(Trust_Account{"Porthos", 20000, 4.0});
	trust_accounts.push_back(Trust_Account{"Aramis", 30000});
	
	display(trust_accounts);
	deposit(trust_accounts, 1000);
	withdraw(trust_accounts, 3000);

	for (int i = 1; i <= 5; ++i)
		withdraw(trust_accounts, 1000);
}

void Section13() 
{
	Movies my_movies;

	my_movies.display();

	my_movies.add_movie("Deadpool", "PG-13", 10);
	my_movies.add_movie("To Wong Foo, Thanks for Everything! Julie Newmar", "PG-13", 1);
	my_movies.add_movie("King Arthur: Legend of the Sword", "PG", 7);

	my_movies.display();
}

void Section12() 
{
	const size_t array1_size = 5;
	const size_t array2_size = 3;

	int array1[]{ 1,2,3,4,5 };
	int array2[]{ 10,20,30 };

	cout << "Array 1: ";
	print(array1, array1_size);

	cout << "Array 2: ";
	print(array2, array2_size);

	int* results = apply_all(array1, array1_size, array2, array2_size);
	constexpr size_t results_size{ array1_size * array2_size };

	cout << "Results: ";
	print(results, results_size);

	delete[] results;
	cout << endl;

}

void print(const int* arr, size_t size)
{
	cout << "[ ";
	for (size_t i = 0; i < size; ++i)
		cout << arr[i] << ' ';
	cout << ']' << endl;
}

int* apply_all(const int* arr1, size_t arr1_size, const int* arr2, size_t arr2_size)
{
	int* new_array;
	new_array = new int[arr1_size * arr2_size];

	int position = 0;
	for (size_t i = 0; i < arr2_size; ++i)
	{
		for (size_t j = 0; j < arr1_size; ++j)
		{
			new_array[position] = arr1[j] * arr2[i];
			++position;
		}
	}
	return new_array;
}

void Section11() {
	vector<int> list{ 1,2,3,4,5,6,7,8,9,10 };
	char selection{};
	int add;
	bool job = true;
	do {
		cout << "P - Print numbers" << endl;
		cout << "A - Add a number" << endl;
		cout << "M - Display mean of the numbers" << endl;
		cout << "S - Display the smallest number" << endl;
		cout << "L - Display the largest number" << endl;
		cout << "Q - Quit" << endl;
		cout << "\nEnter your choice: ";
		cin >> selection;

		switch (CheckChoice(selection))
		{
		case 'P':
		{
			cout << '[';
			if (list.size() > 0) {
				Print(list);
				cout << ']' << endl;
			}
			else
				cout << "] - the list is empty" << endl;
			break;
		}
		case 'A':
		{
			cin >> add;
			list.push_back(add);
			cout << list.at(list.size()-1) << " added" << endl;
			break;
		}
		case 'M':
		{
			if (list.size() > 0)
				cout << AVG(list) << endl;
			else
				cout << "Unable to calculate the mean - no data" << endl;
			break;
		}
		case 'S':
		{
			cout << "The smallest number is " << MIN(list) << endl;
			break;
		}
		case 'L':
		{
			cout << "The largest number is " << MAX(list) << endl;
			break;
		}
		case'Q':
			job = Quit(); break;
		default:
			cout << "Wrong choice" << endl;
			break;
		}
	} while (job);
}

char CheckChoice(char choice)
{
	switch (choice)
	{
	case 'p':
		return 'P'; break;
	case 'a':
		return 'A'; break;
	case'm':
		return 'M'; break;
	case 's':
		return 'S'; break;
	case 'l':
		return 'L'; break;
	case 'q':
		return 'Q'; break;
	default:
		break;
	}
}

void Print(vector<int> v)
{
	for (int i = 0; i < v.size(); ++i)
	{
		cout << " " << v.at(i) << " ";
	}
}

double AVG(vector<int> v)
{
	return accumulate(v.begin(), v.end(), 0.0) / v.size();
}

int MIN(vector<int> v)
{
	int s = v.at(0);
	for (int i = 0; i < v.size(); i++)
		if (v[i] < s)
			s = v[i];
	return s;
}

int MAX(vector<int> v)
{
	int l = v.at(0);
	for (int i = 0; i < v.size(); i++)
		if (v[i] > l)
			l = v[i];
	return l;
}

bool Quit() {
	cout << "Goodbye" << endl;
	return false;
}

void LetterPyramid() {
	string ref; //string letters
	cout << "Enter a string of letters so I can create a Letter Pyramid from it: ";
	getline(cin, ref);
	int pos;
	for (int i = 0; i < ref.length(); ++i)
	{
		pos = 0;
		for (int j = 0; j < ref.length(); j++)//draw half of the pyramid in ascending order
		{
			if (i + j >= ref.length()-1) {
				cout << ref[pos];
				pos++;
			}
			else
				cout << " ";
		}
		++pos;
		for (int j = ref.length(); j >=0; --j)//Draw the other side of the pyramid in descending order
		{
			if (i > j)
				cout << ref[j];
		}

		cout << endl;
	}
}

void Section10() {
	string alphabet{ "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ" };
	string key{ "ZXCVBNMASDFGHJKLQWERTYUIOPmnbvcxzlkjhgfdsapoiuytrewq" };

	string secret_message;
	cout << "Enter your secret message: ";
	getline(cin, secret_message);
	string encrypted_message;
	cout << "\nEncrypting message... " << endl;
	for (char c : secret_message) {
		int position = alphabet.find(c);
		if (position != string::npos)
		{
			char new_char = key[position];
			encrypted_message += new_char;
		}
		else
			encrypted_message += c;
	}

	cout << "\n Encrypted message: " << encrypted_message << endl;

	string dencrypted_message;
	cout << "\nDencrypting message... " << endl;
	for (char c : secret_message) {
		int position = alphabet.find(c);
		if (position != string::npos)
		{
			char new_char = alphabet[position];
			dencrypted_message += new_char;
		}
		else
			dencrypted_message += c;
	}

	cout << "\n Dencrypted message: " << dencrypted_message << endl;
}

void Section9()
{
	vector<int> list{1,2,3,4,5,6,7,8,9,10};
	char selection{};
	int add;
	int s = list.at(0), l = list.at(0);
	bool job = true;
	do {
		cout << "P - Print numbers" << endl;
		cout << "A - Add a number" << endl;
		cout << "M - Display mean of the numbers" << endl;
		cout << "S - Display the smallest number" << endl;
		cout << "L - Display the largest number" << endl;
		cout << "Q - Quit" << endl;
		cout << "\nEnter your choice: ";
		cin >> selection;

		switch (selection)
		{
		case'p':
		{
			cout << '[';
			if (list.size() > 0) {
				for (int i = 0; i < list.size(); ++i)
					cout << ' ' << list[i] << ' ';
				cout << ']'<< endl;
			}
			else
				cout << "] - the list is empty" << endl;
			break;
		}
		case 'a':
		{
			cin >> add;
			list.push_back(add);
			cout << add<< " added" << endl;
			break;
		}
		case 'm':
		{
			if (list.size() > 0)
				cout << accumulate(list.begin(), list.end(), 0.0) / list.size() << endl;
			else
				cout << "Unable to calculate the mean - no data" << endl;
			break;
		}
		case 's':
		{
			for (int i = 0; i < list.size(); i++)
				if (list[i] < s)
					s = list[i];
			cout << "The smallest number is " << s << endl;
			break;
		}
		case 'l':
		{
			for (int i = 0; i < list.size(); i++)
				if (list[i] > l)
					l = list[i];
			cout << "The largest number is " << l << endl;
			break;
		}
		case'q':
			cout << "Goodbye" << endl;
			job = false; break;
		default:
			cout << "Wrong choice" << endl;
			break;
		}
	} while (job);
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