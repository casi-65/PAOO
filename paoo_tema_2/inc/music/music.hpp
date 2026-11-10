#pragma once
#include <iostream>
#include <string>

class Song {
public:
    Song();  
    Song(const std::string& title, int durationSec);
    void print() const;

private:
    std::string title_;
    int totalSec_;  
    int minutes_; 
    int seconds_;
};

class Library {
public:
    Library();
    void add(const Song& song);

private:
    int count_;
};
Library& library();


class Album {
public:
    Album(const std::string& artist, int year);
    void print() const;

private:
    const std::string& artist_;
    const int year_;
};

class Ticket {
public:
    explicit Ticket(int serial);
    Ticket(const Ticket&) = delete;
    Ticket& operator=(const Ticket&) = delete;
    void print() const;

private:
    int serial_;
};

class OldTicket {
public:
    explicit OldTicket(int serial) : serial_(serial) {}
    void print() const { std::cout << "Old ticket #" << serial_ << '\n'; }

private:
    OldTicket(const OldTicket&);
    OldTicket& operator=(const OldTicket&);
    int serial_;
};
