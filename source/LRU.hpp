#ifndef LRU_HPP_
#define LRU_HPP_

#include <queue>
#include <vector>
#include <algorithm>
#include <climits> 

int LRU( const int num_pages, const int num_frames, std::deque<int> sequence );

#endif // LRU_HPP_