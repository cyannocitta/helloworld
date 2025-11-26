#define BOOST_TEST_MODULE VersionTest
#include <boost/test/included/unit_test.hpp>
#include "lib.h"

BOOST_AUTO_TEST_CASE(build_number_is_positive)
{
    BOOST_CHECK(version() > 0);
}