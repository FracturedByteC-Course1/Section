#pragma once
#include<iostream>
#include<string>
#include<iomanip>
#include<list>

class Song
{
	std::string name;
	std::string artist;
	int rating;
	friend std::ostream& operator<<(std::ostream& os, const Song& obj) {
		os << std::setw(20) << std::left << obj.name
			<< std::setw(30) << std::left << obj.artist
			<< std::setw(2) << std::left << obj.rating;
		return os;
	}
public:
	Song() = default;
	Song(std::string name, std::string artist, int rating)
		: name{ name }, artist{ artist }, rating{ rating }{}
	std::string get_name() const { return name; }
	std::string get_artist() const { return artist; }
	int get_rating() const { return rating; }
	bool operator<(const Song& obj) const { return name < obj.name; }
	bool operator==(const Song& obj) const { return name == obj.name; }

};

