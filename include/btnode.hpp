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

#ifndef BTNODE_HPP
#define BTNODE_HPP

#include <memory>

template <typename T>
class BTNode{
    private: 
        T value;
    public:
        BTNode();
        explicit BTNode(const T&);
        std::shared_ptr<BTNode<T>> left;
        std::shared_ptr<BTNode<T>> right;
        T getValue() const;
        void setValue(const T& val);
        void insert(const BTNode<T>&) ;
        size_t size() const;
};

template <typename T>
BTNode<T>::BTNode(){
    left.reset();
    right.reset();
}

template <typename T>
BTNode<T>::BTNode(const T& val): BTNode(){
    this->value = val; 
}

template <typename T>
T BTNode<T>::getValue() const{
    return this->value;
}

template <typename T>
void BTNode<T>::setValue(const T& val){
    this->value = val;
}

template <typename T>
void BTNode<T>::insert(const BTNode<T>& other){
    if(this->value == other.getValue()){
        return;
    }
    if(this->value > other.getValue()){
        if(!left){
            left.reset(new BTNode<T>());
            left->setValue(other.getValue());
        }else{
            left->insert(other);
        }
    }else if(this->value < other.getValue()){
        if(!right){
            right.reset(new BTNode<T>());
            right->setValue(other.getValue());
        }else{
            right->insert(other);
        }
    }
}

template <typename T>
size_t BTNode<T>::size() const{
    return 1 + (right == nullptr ? 0 : right->size()) +
        (left == nullptr ? 0 : left->size());
}
#endif
