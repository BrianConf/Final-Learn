#include "Group.h"
#include <iostream>
using namespace std;
bool Group::insert_left(Cards& card){

    auto _card = group.at(0);
    if(card.index() < _card.index()){
        group.push_back(card);
        return true;
    }
    return false;
}
bool Group::insert_right(Cards& card){

    auto iter = end(group);
    auto _card = *(--iter);
    if(card.index() > _card.index()){
        group.push_back(card);
        return true;
    }
    return false;
}
bool Group::remove_left(){

    if(group.size() > 3){
       group.erase(begin(group));
       return true;
    }
    return false;
}
bool Group::remove_right(){

    if(group.size() > 3){
        group.pop_back();
        return true;
    }
    return false;
}
vectorOfCards Group::separate(){

    vectorOfCards cards;
    auto size = group.size();
    if( size > 3){

        for( auto i = 0; i < size/2; i++){
            auto it = begin(group);
            cards.push_back(*it);
            group.erase(it);
        }
    }
    return cards;
}
