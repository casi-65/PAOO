#include <music/music.hpp>

Song::Song() : title_("Untitled"), totalSec_(0), minutes_(0), seconds_(0) {}

Song::Song(const std::string& title, int durationSec)
    : title_(title), totalSec_(durationSec), minutes_(totalSec_ / 60), seconds_(totalSec_ % 60) {}

void Song::print() const {
    std::cout << title_ << " " << minutes_ << ":" << (seconds_ < 10 ? "0" : "") << seconds_ << '\n';
}

Library::Library() : count_(0) {
    std::cout << "[library] created on first use\n";
}

void Library::add(const Song& song) {
    ++count_;
    std::cout << "[library] song #" << count_ << ": ";
    song.print();
}

Library& library() {
    static Library lib;  
    return lib;
}

Album::Album(const std::string& artist, int year) : artist_(artist), year_(year) {}

void Album::print() const {
    std::cout << artist_ << " (" << year_ << ")\n";
}

Ticket::Ticket(int serial) : serial_(serial) {}

void Ticket::print() const {
    std::cout << "Ticket #" << serial_ << '\n';
}
