#include "project_config.h"
#include "catch.hpp"
#include "circular_buffer.h"



TEST_CASE("circular buffer of size 10 -  iterator")
{
	circular_buffer<Point, 10> buffer;

	SECTION("empty iterator")
	{
		auto iterator = buffer.cbegin();
		auto iterator_end = buffer.cend();
		REQUIRE(iterator.operator==(iterator_end));

	}

	SECTION("iterator 5 items")
	{
		for (std::size_t i{ 0 }; i < 5; ++i)
		{
			buffer.push_back({ 1, static_cast<float>(i) });
		}

		auto iterator = buffer.cbegin();
		auto iterator_end = buffer.cend();

		REQUIRE(*iterator == Point{ 1,0 });
		iterator++;
		iterator++;
		iterator++;
		REQUIRE(*iterator == Point{ 1,3 });

		++iterator;

		REQUIRE(*iterator == Point{ 1,4 });

		++iterator;

		REQUIRE(iterator.operator==(iterator_end));

	}

	SECTION("iterator 10 items")
	{
		for (std::size_t i{ 0 }; i < 10; ++i)
		{
			buffer.push_back({ 1, static_cast<float>(i) });
		}

		auto iterator = buffer.cbegin();
		auto iterator_end = buffer.cend();

		REQUIRE(*iterator == Point{ 1,0 });

		++iterator;
		++iterator;
		++iterator;
		++iterator;
		++iterator;
		++iterator;
		++iterator;
		++iterator;
		++iterator;

		REQUIRE(*iterator == Point{ 1,9 });
		++iterator;

		REQUIRE(iterator.operator==(iterator_end));

	}

	SECTION("iterator 11 items")
	{
		for (std::size_t i{ 0 }; i < 11; ++i)
		{
			buffer.push_back({ 1, static_cast<float>(i) });
		}

		auto iterator = buffer.cbegin();
		auto iterator_end = buffer.cend();

		REQUIRE(*iterator == Point{ 1,1 });

		++iterator;
		++iterator;
		++iterator;
		++iterator;
		++iterator;
		++iterator;
		++iterator;
		++iterator;
		++iterator;

		REQUIRE(*iterator == Point{ 1,10 });
		++iterator;

		REQUIRE(iterator.operator==(iterator_end));

	}

	SECTION("iterator 27 items")
	{
		for (std::size_t i{ 0 }; i < 27; ++i)
		{
			buffer.push_back({ 1, static_cast<float>(i) });
		}

		auto iterator = buffer.cbegin();
		auto iterator_end = buffer.cend();

		REQUIRE(*iterator == Point{ 1,17 });

		++iterator;
		++iterator;
		++iterator;
		++iterator;
		++iterator;
		++iterator;
		++iterator;
		++iterator;
		++iterator;

		REQUIRE(*iterator == Point{ 1,26 });
		++iterator;

		REQUIRE(iterator.operator==(iterator_end));
	}

}
