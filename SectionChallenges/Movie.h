#pragma once
#include<string>
#include<iostream>
using namespace std;

class Movie
{
	string name;
	string rating;
	int watched;
public:
	Movie(string _name, string _rating, int _watched);
	Movie(const Movie &obj);
	~Movie();
	void set_name(string _name);
	string get_name() const;
	void set_rating(string _rating);
	string get_rating() const;
	void set_watched(int _watched);
	int get_watched() const;

	void increment_watched();
	void display() const; 
};

