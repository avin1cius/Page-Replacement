#include "OTM.hpp"

int OTM( const int num_pages, const int num_frames, std::deque<int> sequence )
{
    int counter, victim, page, num_faults = 0;
    std::vector<int> memory;
    memory.reserve( num_frames );
    std::vector<int> addresses( num_pages + 1, -1 ); //Pages addresses on memory
    std::vector<bool> aux( num_pages + 1, false );

    while ( !sequence.empty() )
    {
        page = sequence.front();
        sequence.pop_front();

        if ( addresses[ page ] == -1 ) //If page is not in memory
        {
            num_faults++;
            counter = 0;
            victim = -1;

            if ( (int)memory.size() < num_frames ) //If memory is not full
            {
                addresses[ page ] = memory.size(); //Index of next frame 
                memory.push_back( page ); //Insert page in memory
            }
            else
            {
                for ( int i = 0; i < (int)sequence.size(); i++ ) //Search victim page
                {
                    if ( !aux[ sequence[i] ] && ( addresses[ sequence[i] ] != -1 ) )
                    {
                        counter++;
                        aux[ sequence[i] ] = true;
                        victim = sequence[i];
                    }
                }
                if ( counter < num_frames ) //But if there are pages on memory that will not be used
                {
                    for ( int i = 0; i < (int)memory.size(); i++ ) //Search victim page
                    {
                        if ( !aux[ memory[i] ] )
                        {
                            victim = memory[i];
                            break;
                        }
                    }
                }
                addresses[ page ] = addresses[ victim ];
                addresses[ victim ] = -1; 
                memory[ addresses[ page ] ] = page; //Swap
                aux.assign( aux.size(), false );
            }
        }
    }
    return num_faults;
}
