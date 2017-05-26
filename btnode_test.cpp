#include <iostream>

#include "doctest.h"
#include "btnode.hpp"


TEST_CASE("Binary Tree class tests"){

  BTNode root;
    root.left = new BTNode();


    std::cout << "test " << root.left << root.right << std::endl;
}
