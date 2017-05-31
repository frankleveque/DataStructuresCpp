#include <iostream>

#include "doctest.h"
#include "btnode.hpp"
#include <cstdint>


TEST_CASE("Binary Tree class tests"){
    {
    BTNode<int> root;
    REQUIRE(root.value == 0);
    }
    {
    BTNode<std::string> root;
    REQUIRE(root.value == "");
    }   
}
