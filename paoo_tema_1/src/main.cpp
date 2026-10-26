#include <playlist/playlist.hpp>
#include <iostream>
#include <utility>

int main() {
    std::cout << "--- 1. Constructor and encapsulation ---\n";
    Playlist rock("Rock", 2);
    rock.setSong(0, "Song 1");
    rock.setSong(1, "Song 2");
    rock.setSong(5, "Song 3");
    rock.print();

    std::cout << "\n--- 2. Destructor ---\n";
    {
        Playlist temp("Temporary", 100);
    }  

    std::cout << "\n--- 3. Copy constructor ---\n";
    Playlist mine = rock;                  
    mine.setSong(1, "New Song"); 
    std::cout << "Friend: "; rock.print();  
    std::cout << "Me:     "; mine.print();

    std::cout << "\n--- 4. Move constructor ---\n";
    Playlist moved = std::move(mine);
    std::cout << "Me:    "; mine.print();
    std::cout << "Moved: "; moved.print();

    std::cout << "\n--- End of main: destructors ---\n";
}
