#include <playlist/playlist.hpp>
#include <iostream>

Playlist::Playlist(const std::string& name, int count)
    : name_(name), songs_(new std::string[count]), count_(count) {
    std::cout << "[ctor] " << name_ << ": " << count_ << " songs allocated at " << songs_ << '\n';
}

Playlist::~Playlist() {
    std::cout << "[dtor] " << name_ << ": freeing " << songs_ << '\n';
    delete[] songs_;  
}

#ifndef SHALLOW_COPY
Playlist::Playlist(const Playlist& other)
    : name_(other.name_), songs_(other.songs_ ? new std::string[other.count_] : nullptr),
      count_(other.count_) {
    for (int i = 0; i < count_; ++i) songs_[i] = other.songs_[i];
    std::cout << "[copy] " << name_ << ": songs copied to a new address " << songs_ << '\n';
}
#endif

Playlist::Playlist(Playlist&& other) noexcept
    : name_(other.name_), songs_(other.songs_), count_(other.count_) {
    other.songs_ = nullptr;  
    other.count_ = 0;
    std::cout << "[move] " << name_ << ": taking over the songs from " << songs_ << '\n';
}

void Playlist::setSong(int index, const std::string& title) {
    if (index < 0 || index >= count_) {
        std::cout << "Invalid index: " << index << '\n';
        return;
    }
    songs_[index] = title;
}

void Playlist::print() const {
    std::cout << name_ << " (" << count_ << " songs):";
    for (int i = 0; i < count_; ++i) std::cout << " [" << songs_[i] << "]";
    std::cout << '\n';
}
