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

#ifndef SLLNODE_HPP
#define SLLNODE_HPP

#include <memory>

template <typename T>
class SLLNode{
    private:
        T value;
    public: 
        SLLNode();
        explicit SLLNode(const T&);
        std::shared_ptr<SLLNode<T>> next;
        T getValue() const;
        void setValue(const T& val);
        void insertAfter(std::shared_ptr<SLLNode<T>>);
        void insertAtEnd(std::shared_ptr<SLLNode<T>>);
        size_t size() const;
};

template <typename T>
SLLNode<T>::SLLNode(){
    next.reset();
}

template <typename T>
SLLNode<T>::SLLNode(const T& val): SLLNode(){
    this->value = val;
}

template <typename T>
T SLLNode<T>::getValue() const{
    return this->value;
}

template <typename T>
void SLLNode<T>::setValue(const T& val){
    this->value = val;
}

template <typename T>
void SLLNode<T>::insertAfter(std::shared_ptr<SLLNode<T>> other){
    if(!next){
        next = other;
    }else{
        std::shared_ptr<SLLNode<T>> temp;
        temp = this->next;
        this->next = other;
        other->next = temp;
    }
}

template <typename T>
void SLLNode<T>::insertAtEnd(std::shared_ptr<SLLNode<T>> other){
    if(!next){
        next = other;
    }else{
        next->insertAtEnd(other);
    }
}

template <typename T>
size_t SLLNode<T>::size() const{
    return 1 + next.size();
}

#endif

