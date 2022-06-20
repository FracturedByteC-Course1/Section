#include "Movies.h"

Movies::Movies()
{
}

Movies::~Movies()
{
}

bool Movies::add_movie(string _name, string _rating, int _watched)
{
    for (const Movie &movie : movies)
    {
        if (movie.get_name() == _name)
            return false;
    }
    Movie temp(_name, _rating, _watched);
    movies.push_back(temp);
    return true;
}

bool Movies::increment_watched(string _name)
{
    for (Movie& movie : movies) {
        if (movie.get_name() == _name)
        {
            movie.increment_watched();
            return true;
        }
    }
    return false;
}

void Movies::display() const
{
    if (movies.size() == 0)
        cout << "Sorry, no movies to display\n" << endl;
    else
    {
        cout << "=================================================" << endl;
        for (const auto &movie : movies)
            movie.display();
        cout << "=================================================" << endl;
    }
}
