#include <iostream>
#include "doctest.h"
#include "btnode.hpp"


TEST_CASE("Binary Tree class tests"){
    {
        BTNode<int> root(0);
        REQUIRE(root.getValue() == 0);
    }
    {
        BTNode<std::string> root;
        REQUIRE(root.getValue() == "");
    }
    {
        BTNode<uint8_t> root(5);
        for(auto i=0; i<10; ++i){
            root.insert(BTNode<uint8_t>(i));
        }

        REQUIRE(root.size() == 10);

    }
    {
        BTNode<uint32_t> root(1000);
        for(auto i=0; i<2000; ++i){
            root.insert(BTNode<uint32_t>(i));
        }
        for(auto i=1999; i>=0; --i){
            root.insert(BTNode<uint32_t>(i));
        }
        REQUIRE(root.size() == 2000);
    }
}
