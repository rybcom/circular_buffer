#include "project_config.h"

#if UNIT_TESTING_MODE() == false

#include <chrono>
#include <iostream>
#include <string>
#include "circular_buffer.h"
#include "SimpleLogger.h"

#define BENCHMARK_MODE() true

namespace
{

	struct Point
	{
		double x{ 0 };
		double y{ 0 };
	};

	std::string to_string(Point const& point)
	{
		return fmt::format("point : {},{}", point.x, point.y);
	}

	void print(Point const& point)
	{
		INFO_LOG("{}", to_string(point));
	}

	template<typename T, std::size_t SIZE>
	void print(circular_buffer<T, SIZE> const& buffer)
	{
		INFO_LOG("buffer :");
		for (auto const& item : buffer)
		{
			print(item);
		}
		INFO_LOG("_____________________");

	}


	template<typename T, std::size_t SIZE>
	void change(circular_buffer<T, SIZE>& buffer)
	{
		for (Point& item : buffer)
		{
			item.x = 99;
		}

	}
}


#if BENCHMARK_MODE() == true
#include "StopWatch.h"

int main(int argc, char* []) {

	StopWatch sw;
	constexpr size_t ITEM_COUNT{1000000000};
	circular_buffer<Point, 300> list{};

	sw.Restart();
	for (size_t i{ 0 }; i < ITEM_COUNT; i++)
	{
		list.push_back({ 1,static_cast<double>(i) });
	}

	auto elapsedtime_ms =  sw.elapsed_ms();
	INFO_LOG("time of inserting {} items : {} ms [avg : {} us ]", ITEM_COUNT, elapsedtime_ms, (elapsedtime_ms*1000.0)/ITEM_COUNT);

	print(list);

}
#else

int main(int argc, char* []) {


	circular_buffer<Point, 6> list{};

	list.push_back({ 1,1 });
	list.push_back({ 1,2 });
	list.push_back({ 1,3 });
	list.push_back({ 1,4 });
	print(list);

	auto front = list.pop_front();
	print(list);

	list.push_back({ 1,5 });
	list.push_back({ 1,6 });
	print(list);

	list.push_back({ 1,7 });
	list.push_back({ 1,8 });

	change(list);


	print(list);

	front = list.pop_front();
	front = list.pop_front();
	front = list.pop_front();
	front = list.pop_front();
	front = list.pop_front();

	print(list);


	INFO_LOG("size {}", list.size());
	INFO_LOG("capacity {}", list.capacity());

}
#endif

#endif

