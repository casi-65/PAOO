#pragma once
#include <string>

class Playlist {
private:
    const std::string name_; 
    std::string* songs_;      
    int count_;

public:
    Playlist(const std::string& name, int count);
    ~Playlist();
#ifdef SHALLOW_COPY
    Playlist(const Playlist& other) = default;  
#else
    Playlist(const Playlist& other);         
#endif
    Playlist(Playlist&& other) noexcept;

    void setSong(int index, const std::string& title);
    void print() const;
};
