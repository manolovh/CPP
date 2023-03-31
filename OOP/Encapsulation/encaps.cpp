#include <iostream>
#include <string>
#include <vector>
#include "Movies.h"
#include "Movie.h"


class Movie;
class Movies;

using namespace std;

Movies::Movies(){
    all_movies = new vector<Movie>;
}

void Movies::display_all_movies() {
    for (auto movie: (*all_movies)) {
        cout << "Title: " << movie.name << " | ";
        cout << "Rating: " << movie.rating << " | ";
        cout << "Watched " << movie.watch_count << " times" << endl;
    }
}

void Movies::add_movie(string name, string rating, int count) {
    bool is_in {false};
    for (auto movie: (*all_movies)) {
        if (movie.name == name) {
            cout << name << " is already in the collection. Add another movie." << endl;
            is_in = true;
        }
    }
    if (!is_in)
        (*all_movies).push_back(Movie{name, rating, count});
}

Movies::~Movies() {
    delete all_movies;
}

Movie::Movie(string new_name, string new_rating, int new_watch_count) {
    name = new_name;
    rating = new_rating;
    watch_count = new_watch_count;
}

void Movies::add_watch_count(string name) {
    bool is_in {false};
    for (auto movie: (*all_movies)) {
        if (movie.name == name) {
            movie.watch_count += 1;
            is_in = true;
        }
    }
    if (!is_in)
        cout << name << " is not included in the collection." << endl;
}

int main() {
    Movies mov {};
    mov.add_movie("Joe", "PG", 3);
    mov.add_movie("Pesho", "G", 0);
    mov.add_movie("Pesho", "G", 0);
    mov.add_watch_count("Gosho");
    mov.display_all_movies();
    return 0;
}