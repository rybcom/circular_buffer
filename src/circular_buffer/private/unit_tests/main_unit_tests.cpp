#include "project_config.h"
#if RUN_AS_UNIT_TESTING() == true

#define CATCH_CONFIG_RUNNER
#include "catch.hpp"


struct Point
{
	float x{ 0 };
	float y{ 0 };
};

static bool operator==(Point const& point, Point const& point_b)
{
	return (point.x == point_b.x) && (point.y == point_b.y);
}

static bool operator!=(Point const& point, Point const& point_b)
{
	return !(point == point);
}

#include "unit_tests/push_back_unit_tests.h"
#include "unit_tests/iterator_unit_tests.h"

int main(int argc, char* argv[]) 
{
	char* xxx[2];
	xxx[0] = (char*)"xxx";
	xxx[1] =(char*) "-s";
	int result = Catch::Session().run(2, xxx);
	return result;
}


#endif
