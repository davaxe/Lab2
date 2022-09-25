#include "catch.hpp"
#include "list.h"
#include <utility>
#include <iostream>

TEST_CASE("Constructors and getters")
{
    SECTION("Default constructor")
    {
        List list{};

        CHECK_THROWS(list.get(0));
        CHECK_THROWS(list.front());
        CHECK_THROWS(list.back());
    }
    SECTION("Integer constructor")
    {
        List list{1, 2, 3};

        CHECK_THROWS(list.get(-1));
        CHECK_THROWS(list.get(3));

        CHECK(list.get(0) == 1);
        CHECK(list.get(1) == 2);
        CHECK(list.get(2) == 3);

        CHECK(list.front() == 1);
        CHECK(list.back() == 3);
    }
    SECTION("Copy constructor")
    {
        List l1{1, 2, 3};
        List l2{l1};
        l2.push_back(4);

        CHECK(l1.to_string() == "[1, 2, 3]");
        CHECK(l2.to_string() == "[1, 2, 3, 4]");
    }
    SECTION("Assignment operator")
    {
        List l1{1, 2, 3};
        List l2{};
        l2 = l1;
        l2.push_back(4);
        CHECK(l1.to_string() == "[1, 2, 3]");
        CHECK(l2.to_string() == "[1, 2, 3, 4]");
    }
    SECTION("MOVE")
    {
        List l1{1, 2, 3};
        List l2{std::move(l1)};
        CHECK(l2.to_string() == "[1, 2, 3]");

        List l3 {1, 2, 3};
        List l4{3, 1, 2};
        l4 = std::move(l3);
        
        CHECK(l4.to_string() == "[1, 2, 3]");
    }
}
TEST_CASE("to_string method")
{
    SECTION("To string")
    {
        List empty{};
        List non_empty{1, 2, 3};
        CHECK(empty.to_string() == "[]");
        CHECK(non_empty.to_string() == "[1, 2, 3]");
    }
}
TEST_CASE("Add/remove values")
{
    SECTION("Add, push_back, push_front")
    {
        List l1{};
        l1.push_back(1);
        CHECK(l1.to_string() == "[1]");
        l1.push_front(2);
        CHECK(l1.to_string() == "[2, 1]");
        l1.push_back(3);
        CHECK(l1.to_string() == "[2, 1, 3]");
    }
    SECTION("Remove, pop_back, pop_front")
    {
        List l1{1, 2, 3};
        List l2{1, 2, 3};
        List l3{};

        CHECK_THROWS(l3.pop_back());
        CHECK_THROWS(l3.pop_front());

        CHECK(l1.pop_back() == 3);
        CHECK(l1.to_string() == "[1, 2]");

        CHECK(l2.pop_front() == 1);
        CHECK(l2.to_string() == "[2, 3]");
    }
    SECTION("Empty, length")
    {
        List l1{};
        List l2{1};
        CHECK(l2.length() == 1);

        CHECK_FALSE(l2.empty());
        CHECK(l1.empty());

        l2.pop_front();
        l1.push_back(1);
        CHECK_FALSE(l1.empty());
        CHECK(l2.empty());

        CHECK(l2.length() == 0);
        CHECK(l1.length() == 1);
    }
    SECTION("Clear list, clear")
    {
        List l1{1, 2, 3, 4};
        l1.clear();
        CHECK(l1.to_string() == "[]");
        CHECK(l1.empty());
    }
}
TEST_CASE("Sorting")
{
    SECTION("Merge sort")
    {
        List l1{66, 5, 3, 43};
        List l2{9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
        l1.sort();
        l2.sort();
        CHECK(l2.to_string() == "[0, 1, 2, 3, 4, 5, 6, 7, 8, 9]");
        CHECK(l1.to_string() == "[3, 5, 43, 66]");
    }
}