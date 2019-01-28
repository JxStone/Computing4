// Copyright 2015 fredm@cs.uml.edu for 91.204 Computing IV
// Wed Mar 25 06:32:17 2015

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>

#include <stdint.h>
#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>

#include "RingBuffer.hpp"

BOOST_AUTO_TEST_CASE(RBcontructor) {
    // normal constructor
    BOOST_REQUIRE_NO_THROW(RingBuffer(100));
    // this should fail
    BOOST_REQUIRE_THROW(RingBuffer(0), std::exception);
    BOOST_REQUIRE_THROW(RingBuffer(0), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(RBenque_dequeue) {
    RingBuffer rb(100);
    rb.enqueue(2);
    rb.enqueue(1);
    rb.enqueue(0);
    BOOST_REQUIRE(rb.dequeue() == 2);
    BOOST_REQUIRE(rb.dequeue() == 1);
    BOOST_REQUIRE(rb.dequeue() == 0);
    // this should throw an exception when dequeue an empty buffer
    BOOST_REQUIRE_THROW(rb.dequeue(), std::runtime_error);
    RingBuffer rb1(1);
    rb1.enqueue(1);
    // this should throw an exception when enqueue a full buffer
    BOOST_REQUIRE_THROW(rb1.enqueue(1), std::runtime_error);
}

BOOST_AUTO_TEST_CASE(RBpeek) {
    RingBuffer rb(10);
    // throw exception when peek into empty Ringbuffer
    BOOST_REQUIRE_THROW(rb.peek(), std::runtime_error);
    rb.enqueue(654);
    rb.enqueue(2);
    BOOST_REQUIRE_NO_THROW(rb.peek());
    BOOST_REQUIRE(rb.peek() == 654);
    rb.dequeue();
    BOOST_REQUIRE(rb.peek() == 2);
}
