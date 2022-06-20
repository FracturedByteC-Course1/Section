#include "Movie.h"

Movie::Movie(string _name, string _rating, int _watched)
	:name(_name),rating(_rating), watched(_watched){}

Movie::Movie(const Movie& obj)
	:Movie(obj.name, obj.rating, obj.watched){}

Movie::~Movie(){}

void Movie::set_name(string _name) { name = _name; }

string Movie::get_name() const {return name;}

void Movie::set_rating(string _rating) { rating = _rating; }

string Movie::get_rating() const{ return rating;}

void Movie::set_watched(int _watched) { watched = _watched; }

int Movie::get_watched() const{return watched;}

void Movie::increment_watched() { ++watched; }

void Movie::display() const
{
	cout << name << ',' << rating << ',' << watched << endl;
}
