#pragma once

#include <iostream>

struct memory_profiler_t
{
	std::size_t all_reservation_count;
	std::size_t all_releasing_count;

	std::size_t current_reservated_size;
	std::size_t current_reservated_count;
};

inline memory_profiler_t memory_profiler;

inline void * operator new(std::size_t size)
{
	++memory_profiler.current_reservated_count;
	memory_profiler.current_reservated_size += size;

	++memory_profiler.all_reservation_count;

	return malloc(size);
}

inline void operator delete(void * obj, std::size_t size)
{
	--memory_profiler.current_reservated_count;
	memory_profiler.current_reservated_size -= size;

	++memory_profiler.all_releasing_count;

	free(obj);

}
