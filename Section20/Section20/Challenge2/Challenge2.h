#pragma once
#include"Song.h"
#include<limits>
#include<cctype>

void display_menu();
void play_current_song(const Song &obj);
void display_playlist(const std::list<Song> &playlist, const Song &current_song);

int main()
{
	std::list<Song> playlist
	{
		{"Kaer Morhen", "Marcin Przybylowicz", 5},
		{"The Bank of the Sansretour", "Piotr Musial", 4},
		{"Thunderstruck","AC/DC", 5},
		{"Highway to Hell", "AC/DC", 5}
	};

	std::list<Song>::iterator current_song = playlist.begin();
	display_playlist(playlist, *current_song);

	bool job = true;
	char selection;
	do
	{
		display_menu();
		std::cin >> selection;
		selection = std::toupper(selection);
		switch (selection)
		{
		case 'F':
		{
			std::cout << "Playing first song" << std::endl;
			current_song = playlist.begin();
			play_current_song(*current_song);
			break; 
		}
		case'N':
		{	std::cout << "Playing next song" << std::endl;
			current_song++;
			if (current_song == playlist.end())
			{
				std::cout << "Wrapping to start of playlist" << std::endl;
				current_song = playlist.begin();
			}
			play_current_song(*current_song);
			break; 
		}
		case 'P':
		{	std::cout << "Playing previous song" << std::endl;
			if (current_song == playlist.begin())
			{
				std::cout << "Wrapping to end of playlist" << std::endl;
				current_song = playlist.end();
			}
			current_song--;
			play_current_song(*current_song);
			break;
		}
		case 'A':
		{
			std::string name, artist;
			int rating;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Adding and playing new song" << std::endl;
			std::cout << "Enter song name: ";
			getline(std::cin, name);
			std::cout << "Enter song artist: ";
			getline(std::cin, artist);
			std::cout << "Enter your ratingv(1-5): ";
			std::cin >> rating;
			playlist.insert(current_song, Song{ name, artist, rating });
			current_song--;
			play_current_song(*current_song);
			break;
		}
		case 'L':
		{
			std::cout << std::endl;
			display_playlist(playlist, *current_song);
		}
		case'Q':
		{
			std::cout << "Quitting" << std::endl;
			job = false;
			break;
		}
		default:
			std::cout << "Illegal choice, try again...";
			break;
		}
	} while (job);

	return 0;
}

void display_menu()
{
		std::cout << "\nF - Play First song" << std::endl;
		std::cout << "N - Play Next song" << std::endl;
		std::cout << "P - Play Previous song" << std::endl;
		std::cout << "A - Add and play a new Song at current location" << std::endl;
		std::cout << "L - List the current playlist" << std::endl;
		std::cout << "==========================================================================" << std::endl;
		std::cout << "Enter a selection (Q to quit): ";
}

void play_current_song(const Song& obj)
{
	std::cout << "Playing: " << std::endl;
	std::cout << obj << std::endl;
}

void display_playlist(const std::list<Song>& playlist, const Song& current_song)
{
	for (const Song& song : playlist)
		std::cout << song << std::endl;
	std::cout << "Current song: " << std::endl;
	std::cout << current_song << std::endl;
}
