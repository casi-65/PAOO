#include <music/music.hpp>

int main() {
    std::cout << "--- Item 4: initialize before use ---\n";
    int added = 0;  
    Song song("Song 1", 185);
    song.print();
    library().add(song);
    ++added;
    library().add(Song("Song 2", 200));  
    ++added;
    std::cout << "added = " << added << '\n';

    std::cout << "\n--- Item 5: functions the compiler writes ---\n";
    Song empty;       
    Song copy(song); 
    empty = song;     
    copy.print();
    empty.print();    

    std::string artistA = "Artist A", artistB = "Artist B";
    Album first(artistA, 2001), second(artistB, 2010);
    Album firstCopy(first); 
    firstCopy.print();
    second.print();
#ifdef SHOW_ERRORS
    first = second;  
#endif

    std::cout << "\n--- Item 6: disallow what you don't want ---\n";
    Ticket ticket(1001);
    OldTicket oldTicket(1002);
    ticket.print();
    oldTicket.print();
#ifdef SHOW_ERRORS
    Ticket ticketCopy(ticket);     
    OldTicket oldCopy(oldTicket); 
#endif
}
