//
//  test.cpp
//  ps2
//
//  Created by Jingxian Shi on 2/5/18.
//  Copyright © 2018 Jingxian Shi. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>

#include "LFSR.hpp"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(fiveBitsTapAtTwo)
{
    
    LFSR l("00111", 2);
    BOOST_REQUIRE(l.step() == 1);
    BOOST_REQUIRE(l.step() == 1);
    BOOST_REQUIRE(l.step() == 0);
    BOOST_REQUIRE(l.step() == 0);
    BOOST_REQUIRE(l.step() == 0);
    BOOST_REQUIRE(l.step() == 1);
    BOOST_REQUIRE(l.step() == 1);
    BOOST_REQUIRE(l.step() == 0);
    
    LFSR l2("00111", 2);
    BOOST_REQUIRE(l2.generate(8) == 198);
}

BOOST_AUTO_TEST_CASE(longSeedString)
{
    LFSR l("00110101010000011011111101011011", 22);
    
    BOOST_REQUIRE(l.step() == 1);
    BOOST_REQUIRE(l.step() == 0);
    BOOST_REQUIRE(l.step() == 1);
    BOOST_REQUIRE(l.step() == 1);
    BOOST_REQUIRE(l.step() == 0);
    
    LFSR l2("00110101010000011011111101011011", 22);
    BOOST_REQUIRE(l2.generate(32) == -1);
    BOOST_REQUIRE(l2.generate(5) == 22);
}

BOOST_AUTO_TEST_CASE(generateZeroBitInteger)
{
    LFSR l("10110010", 3);
    BOOST_REQUIRE(l.generate(0) == 0);
    
    LFSR l2("1", 0);
    BOOST_REQUIRE(l2.generate(0) == 0);
    
    LFSR l3("01", 0);
    BOOST_REQUIRE(l3.generate(0) == 0);
    BOOST_REQUIRE(l3.generate(5) == 22);
}

