#ifndef _MOVIES_H_
#define _MOVIES_H_
#include <iostream>
#include <vector>
#include <string>
#include "Movie.h"

using std::string;
using std::vector;

class Movie;


class Movies {
private:
    vector<Movie> *all_movies;
public:
    void add_watch_count(string);
    void display_all_movies();
    void add_movie(string, string, int);
    Movies();
    ~Movies();
};

#endif