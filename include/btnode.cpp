/*
DataStructuresCpp - Various data structures implemented in c++
===============================================================================
Copyright (C) 2017 Frank Leveque

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
===============================================================================
*/

#include <cassert>
#include "btnode.hpp"

template <typename T>
BTNode<T>::BTNode(){

}

template <typename T>
BTNode<T>::BTNode(T val) {
        this->value=val;
}

template <typename T>
void BTNode<T>::insert(const BTNode<T>& other){

    if(this->value == other.value){
        return;
    }
    if(this->value > other.value){
        if(!left){
            left.reset(new BTNode<T>());
            left->value = other.value;
        }else{
            left->insert(other);
        }
    }else if(this->value < other.value){
        if(!right){
            right.reset(new BTNode<T>());
            right->value = other.value;
        }else{
            right->insert(other);
        }

    }
}

template <typename T>
uint32_t BTNode<T>::size(){
    return 1 +
        (right == nullptr ? 0 : right->size()) +
        (left == nullptr ? 0 : left->size());
}

