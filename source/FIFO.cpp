#include "FIFO.hpp"

int FIFO( const int num_pages, const int num_frames, std::deque<int> sequence )
{
    int page, num_faults = 0;
    std::deque<int> memory;
    std::vector<bool> inserted( num_pages + 1, false );

    while ( !sequence.empty() )
    {
        page = sequence.front();
        sequence.pop_front();

        if ( !inserted[ page ] ) //If page is not in memory
        {
            if ( (int)memory.size() == num_frames ) //If memory is full
            {
                inserted[ memory.front() ] = false; 
                memory.pop_front(); //Remove the oldest page              
            }

            inserted[ page ] = true; 
            memory.push_back( page ); //Insert page in memory
            num_faults++;
        }
    }
    return num_faults;
}
