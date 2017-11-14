#include "LRU.hpp"

int LRU( const int num_pages, const int num_frames, std::deque<int> sequence )
{
    int time = 0, victim, page, num_faults = 0;
    std::vector<int> memory;
    memory.reserve( num_frames );
    std::vector<int> addresses( num_pages + 1, -1 );
    std::vector<int> counter( num_pages + 1, INT_MAX );

    while ( !sequence.empty() )
    {
        page = sequence.front();
        sequence.pop_front();
        counter[ page ] = time; //Update counter

        if ( addresses[ page ] == -1 ) //If page is not in memory
        {
            if ( (int)memory.size() < num_frames ) //If memory is not full
            {
                addresses[ page ] = memory.size(); //Adress of available frame 
                memory.push_back( page ); //Insert page in memory
            }
            else
            {
                victim = distance( counter.begin(), std::min_element( counter.begin(), counter.end() ) ); //Search for the least recently used page
                addresses[ page ] = addresses[ victim ];
                memory[ addresses[ page ] ] = page; //Inserting page
                addresses[ victim ] = -1;
                counter[ victim ] = INT_MAX; //Reset victim counter
            }
            num_faults++;
        }
        time++;
    }
    return num_faults;
}