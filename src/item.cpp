// -----------------------------------------------------
// CSC371 Advanced Object Oriented Programming (2021/22)
// Department of Computer Science, Swansea University
//
// Author: 976005
//
// Canvas: https://canvas.swansea.ac.uk/courses/24793
// -----------------------------------------------------
#include <stdexcept>
#include <vector>
#include "item.h"


// TODO Write a constructor that takes one parameter, a string identifier
//  and initialises the object and member data.
Item::Item(std::string ident) : ident(ident){}
//
// Example:
//  Item iObj{"identIdent"};

// TODO Write a function, size, that takes no parameters and returns an unsigned
//  int of the number of entries in the Item contains.
//
// Example:
//  Item iObj{"identIdent"};
//  auto size = iObj.size();

unsigned int Item::size(){
    return this->entries.size();
}

// TODO Write a function, empty, that takes no parameters and returns true
//  if the number of entries in the Item is zero, false otherwise.
//
// Example:
//  Item iObj{"identIdent"};
//  auto empty = iObj.empty();

bool Item::empty(){
    return(size() == 0);
}

// TODO Write a function, setIdent, that takes one parameter, a string for a new
//  Item identifier, and updates the member variable. It returns nothing.
//
// Example:
//  Item iObj{"identIdent"};
//  iObj.setIdent("identIdent2");

void Item::setIdent(std::string ident){
    this->ident = ident;
}

// TODO Write a function, getIdent, that returns the identifier for the Item.
//
// Example:
//  Item iObj{"identIdent"};
//  auto ident = iObj.getIdent();

std::string Item::getIdent() const{
    return ident;
}


// TODO Write a function, addEntry, that takes two parameters, an entry
//  key and value and returns true if the entry was inserted into the
//  container or false if the entry already existed and was replaced.
//
// Example:
//  Item iObj{"identIdent"};
//  iObj.addEntry("key", "value");

bool Item::addEntry(std::string key, std::string value) {
    if(this->entries.find(key) == this->entries.end()){ //if the key does not exist
        this->entries.insert(std::pair<std::string, std::string>(key, value));
        return true;
    } else {
        this->entries.erase(key);
        this->entries.insert(std::pair<std::string, std::string>(key, value));
        return false;
    }

}

// TODO Write a function, getEntry, that takes one parameter, an entry
//  key and returns it's value. If no entry exists, throw an appropriate
//  exception.
//
// Example:
//  Item iObj{"identIdent"};
//  iObj.addEntry("key", "value");
//  auto value = iObj.getEntry("key");

std::string Item::getEntry(std::string key) const{
    if(this->entries.find(key) == this->entries.end()){
        throw std::out_of_range("Out of Range");
    } else{
        return this->entries.at(key);
    }
}

// TODO Write a function, deleteEntry, that takes one parameter, an entry
//  key, deletes it from the container, and returns true if the Item was
//  deleted. If no entry exists, throw an appropriate exception.
//
// Example:
//  Item iObj{"identIdent"};
//  iObj.addEntry("key", "value");
//  iObj.deleteEntry("key");

bool Item::deleteEntry(std::string key){
     if(this->entries.find(key) == this->entries.end()){
        return false;
    } else{
        this->entries.erase(key);
        return true;
    }
}

std::vector<std::string> Item::getKeys() const{
    std::vector<std::string> keys;
    for(auto it: entries){
        keys.push_back(it.first);
    }
    return keys;
}

// TODO Write an == operator overload for the Item class, such that two
//  Item objects are equal only if they have the same identifier and same
//  entries.
//
// Example:
//  Item iObj1{"identIdent"};
//  iObj1.addEntry("key", "value");
//  Item iObj2{"identIdent2"};
//  if(iObj1 == iObj2) {
//    ...
//  }
bool operator==(const Item& lhs, const Item& rhs){
    if((lhs.ident == rhs.ident) && (lhs.entries == rhs.entries)){
        return true;
    } else{
        return false;
    }
}


// TODO Write a function, str, that takes no parameters and returns a
//  std::string of the JSON representation of the data in the Item.
//
// See the coursework specification for how this JSON should look.
//
// Example:
//  Item iObj{"itemIdent"};
//  std::string s = iObj.str();
