#include "main.hpp"

int main( int argc, char *argv[ ] )
{
    int num_frames;
    std::string filename;
    std::deque<int> reference_sequence;

    if ( argc == 1 )
    {
        filename = "input.txt";
    }
    else
    {
        filename = argv[1];
    }

    std::ifstream file( filename );

    if ( file.is_open() )
    {
        int i;       

        file >> num_frames;        
        
        while ( file >> i )
        {
            reference_sequence.push_back( i );
        }
        file.close();
    }
    else
    {
        std::cout << filename << " não encontrado" << std::endl;
        return 0;
    }

    int num_pages = *std::max_element( reference_sequence.begin(), reference_sequence.end() );

    std::cout << "FIFO " << FIFO( num_pages, num_frames, reference_sequence ) << std::endl;
    std::cout << "OTM " << OTM( num_pages, num_frames, reference_sequence ) << std::endl;
    std::cout << "LRU " << LRU( num_pages, num_frames, reference_sequence ) << std::endl;

    return 0;
}