#ifndef _MOVIE_H_
#define _MOVIE_H_
#include <iostream>
#include <vector>
#include <string>
#include "Movies.h"

using std::string;

class Movies;

class Movie {
    friend class Movies;
private:
    string name;
    string rating;
    int watch_count;

public:
    Movie(string, string, int);
};

#endif