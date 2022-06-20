#pragma once
#include<vector>
#include"Movie.h"
class Movies
{
	vector<Movie> movies;
public:
	Movies();
	~Movies();
	bool add_movie(string _name, string _rating, int _watched);
	bool increment_watched(string _name);
	void display() const;
};

