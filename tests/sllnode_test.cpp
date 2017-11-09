#include <iostream>
#include "doctest.h"
#include "sllnode.hpp"

TEST_CASE("Singly Linked List class tests"){
    {
        SLLNode<int> head(0);
        REQUIRE(head.getValue() == 0);
    }
    {
        std::shared_ptr<SLLNode<int>> head(new SLLNode<int>(0));
        for(int i=1; i<20; ++i){
            std::shared_ptr<SLLNode<int>> temp(new SLLNode<int>());
            temp->setValue(i);
            head->insertAtEnd(temp);
        }
        std::shared_ptr<SLLNode<int>> current(head);
        for(int i=0; i<20; ++i){
            REQUIRE(current->getValue() == i);
            current = current->next;
        }

        std::shared_ptr<SLLNode<int>> node(new SLLNode<int>(999));
        head->insertAfter(node);
        REQUIRE(head->next->getValue() == 999);
        
    }
    
    
}
