#include "project_config.h"
#include "catch.hpp"
#include "circular_buffer.h"



TEST_CASE("circular buffer of size 10 -  push_back")
{
	circular_buffer<Point, 10> buffer;

	SECTION("push back 0 items")
	{
		REQUIRE(buffer.size() == 0);
		REQUIRE(buffer.capacity() == 10);
		REQUIRE(buffer.remaining_capacity() == 10);
	}

	SECTION("push back 5 items")
	{
		for (std::size_t i{ 0 }; i < 5; ++i)
		{
			buffer.push_back({ 1, static_cast<float>(i) });
		}
		REQUIRE(buffer.size() == 5);
		REQUIRE(buffer.capacity() == 10);
		REQUIRE(buffer.remaining_capacity() == 5);
		REQUIRE(buffer[4] == Point{1,4});
	}

	SECTION("push back 10 items")
	{
		for (std::size_t i{ 0 }; i < 10; ++i)
		{
			buffer.push_back({ 1, static_cast<float>(i) });
		}
		REQUIRE(buffer.size() == 10);
		REQUIRE(buffer.capacity() == 10);
		REQUIRE(buffer.remaining_capacity() == 0);
		REQUIRE(buffer[9] == Point{1, 9});

	}

	SECTION("push back 11 items")
	{
		for (std::size_t i{ 0 }; i < 11; ++i)
		{
			buffer.push_back({ 1, static_cast<float>(i) });
		}
		REQUIRE(buffer.size() == 10);
		REQUIRE(buffer.capacity() == 10);
		REQUIRE(buffer.remaining_capacity() == 0);
		REQUIRE(buffer[9] == Point{1, 10});
		REQUIRE(buffer[0] == Point{1, 1});

	}

	SECTION("push back 27 items")
	{
		for (std::size_t i{ 0 }; i < 27; ++i)
		{
			buffer.push_back({ 1, static_cast<float>(i) });
		}
		REQUIRE(buffer.size() == 10);
		REQUIRE(buffer.capacity() == 10);
		REQUIRE(buffer.remaining_capacity() == 0);
		REQUIRE(buffer[9] == Point{ 1, 26 });
		REQUIRE(buffer[8] == Point{ 1, 25 });
		REQUIRE(buffer[7] == Point{ 1, 24 });
		REQUIRE(buffer[6] == Point{ 1, 23 });
		REQUIRE(buffer[5] == Point{ 1, 22 });
		REQUIRE(buffer[4] == Point{ 1, 21 });
		REQUIRE(buffer[3] == Point{ 1, 20 });
		REQUIRE(buffer[2] == Point{ 1, 19 });
		REQUIRE(buffer[1] == Point{ 1, 18 });
		REQUIRE(buffer[0] == Point{ 1, 17 });

	}

}
