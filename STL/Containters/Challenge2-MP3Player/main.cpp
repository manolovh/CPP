#include <iostream>
#include <list>
#include <string>
#include <cctype>
#include <iomanip>
#include <limits>

class Song {
    friend std::ostream &operator<<(std::ostream &os, const Song &s);
    std::string name;
    std::string artist;
    int rating;
public:
    Song() = default;
    Song(std::string name, std::string artist, int rating)
        : name{name}, artist{artist}, rating{rating} {}
    std::string get_name() const {
        return name;
    }
    std::string get_artist() const {
        return artist;
    }
    int get_rating() const {
        return rating;
    }

    bool operator<(const Song &rhs) const {
        return this->name < rhs.name;
    }

    bool operator==(const Song &rhs) const {
        return this->name == rhs.name;
    }
    ~Song() = default;
};

std::ostream &operator<<(std::ostream &os, const Song &s) {
    os << std::setw(20) << std::left << s.get_name()
       << std::setw(30) << std::left << s.get_artist()
       << std::setw(2) << std::left << s.get_rating();
       return os;
}

void display_menu() {
    std::cout << "\nF - Play First Song" << std::endl;
    std::cout << "N - Play Next Song" << std::endl;
    std::cout << "P - Play Previous Song" << std::endl;
    std::cout << "A - Add and play a new song at current location" << std::endl;
    std::cout << "L - List the current playlist" << std::endl;
    std::cout << "==========================================================" << std::endl;
    std::cout << "Enter a selection (Q to quit): ";
}

void play_current_song(const Song &song) {
    std::cout << "\nPlaying: \n" << song << std::endl;
    display_menu();
}

void display_playlist(const std::list<Song> &playlist, const Song &current_song) {
    for (auto song: playlist)
        std::cout << song << std::endl;
    std::cout << "\nCurrent Song:\n" << current_song << std::endl;
}

int main() {
    std::list<Song> playlist {
        {"24/7", "Djaany", 5},
        {"God's Plan", "Drake", 3},
        {"Wait", "Tekashi", 3},
        {"Faded", "ZHU", 5}
    };
    
    std::list<Song>::iterator current_song = playlist.begin(); // auto also works

    display_playlist(playlist, *current_song);
    display_menu();
    char choice {};
    do {

        std::cin >> choice;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        choice = tolower(choice);
        // First
        if (choice == 'f') {
            current_song = playlist.begin();            
            play_current_song(*current_song);
        }
        // Next
        else if (choice == 'n') {
            if (*current_song == playlist.back()) {
                current_song = playlist.begin();
                play_current_song(*current_song);
            } else
                play_current_song(*(++current_song));
        }
        // Previous
        else if (choice == 'p') {
            if (*current_song == playlist.front()) {
                current_song = playlist.end();
                play_current_song(*(--current_song));
            } else
                play_current_song(*(--current_song));
        }
        // Add new
        else if (choice == 'a') {
            std::string name;
            std::string artist;
            int rating;
            std::cout << "Enter the song name: ";
            std::cin >> name;
            std::cout << "Enter the artist: ";
            std::cin >> artist;
            std::cout << "Enter your rating (1-5): ";
            std::cin >> rating;

            playlist.insert(current_song, {name, artist, rating});
            play_current_song(*(--current_song));
        } 
        // List All
        else if (choice == 'l') {
            display_playlist(playlist, *current_song);
            display_menu();
        }
        else {
            std::cout << "\n\n\t\tPlease select a valid option: \n";
            display_menu();
        }
    } while (tolower(choice) != 'q');
}