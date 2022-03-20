// -----------------------------------------------------
// CSC371 Advanced Object Oriented Programming (2021/22)
// Department of Computer Science, Swansea University
//
// Author: 976005
//
// Canvas: https://canvas.swansea.ac.uk/courses/24793
// -----------------------------------------------------

#include "category.h"

// TODO Write a constructor that takes one parameter, a string identifier
//  and initialises the object and member data.
//
// Example:
//  Category c{"categoryIdent"};

Category::Category(std::string ident) : ident(ident){}

// TODO Write a function, size, that takes no parameters and returns an unsigned
//  int of the number of Items in the Category contains.
//
// Example:
//  Category c{"categoryIdent"};
//  auto size = c.size();

unsigned int Category::size(){
    return this->itemsVector.size();
}

// TODO Write a function, empty, that takes no parameters and returns true
//  if the number of Items in the Category is zero, false otherwise.
//
// Example:
//  Category c{"categoryIdent"};
//  auto empty = c.empty();

bool Category::empty(){
    return(size() == 0);
}

// TODO Write a function, getIdent, that returns the identifier for the
//  Category.
//
// Example:
//  Category cObj{"categoryIdent"};
//  auto ident = cObj.getIdent();

std::string Category::getIdent() const{
    return ident;
}

// TODO Write a function, setIdent, that takes one parameter, a string for a new
//  Category identifier, and updates the member variable. It returns nothing.
//
// Example:
//  Category cObj{"categoryIdent"};
//  cObj.setIdent("categoryIdent2");

void Category::setIdent(std::string ident){
    this->ident = ident;
}

// TODO Write a function, newItem, that takes one parameter, an Item identifier,
//  (a string) and returns the Item object as a reference. If an object with the
//  same identifier already exists, then the existing object should be returned.
//  Throw a std::runtime_error if the Item object cannot be inserted into the
//  container for whatever reason.
//
// Example:
//  Category cObj{"categoryIdent"};
//  cObj.newItem("itemIdent");

Item& Category::newItem(std::string itemIdent){
    for (size_t i = 0; i < this->itemsVector.size(); i++){
        if(this->itemsVector[i].getIdent() == itemIdent){
            return itemsVector[i];
        }
    }
    try{
        itemsVector.push_back(Item(itemIdent));
        return this->itemsVector[this->itemsVector.size() -1];
    } catch(const std::exception& ex){
        throw std::runtime_error("Runtime Error");
    } 
}

// TODO Write a function, addItem, that takes one parameter, an Item object,
//  and returns true if the object was successfully inserted. If an object with
//  the same identifier already exists, then the contents should be merged and
//  return false.
//
// Example:
//  Category cObj{"categoryIdent"};
//  Item iObj{"itemIdent"};
//  cObj.addItem(iObj);

bool Category::addItem(Item item){
    for (size_t i = 0; i < this->itemsVector.size(); i++){
        if(this->itemsVector[i].getIdent() == item.getIdent()){
            //merge contents;
            std::vector<std::string> keys = item.getKeys();
            for(size_t j = 0; j < item.size(); j++){
                this->itemsVector[i].addEntry(keys.at(j), item.getEntry(keys.at(j)));
            }
            return false;
        }
    }
    //insert new item
    this->itemsVector.push_back(item);
    return true;
}

// TODO Write a function, getItem, that takes one parameter, an Item
//  identifier (a string) and returns the Item as a reference. If no Item
//  exists, throw an appropriate exception.
//
// Hint:
//  See the test scripts for the exception expected.
//
// Example:
//  Category cObj{"categoryIdent"};
//  cObj.newItem("itemIdent");
//  auto iObj = cObj.getItem("itemIdent");

Item& Category::getItem(std::string itemIdent) {
    for (size_t i = 0; i < this->itemsVector.size(); i++){
        if(this->itemsVector[i].getIdent() == itemIdent){
            return this->itemsVector.at(i);
        }
    }
    throw std::out_of_range("Out of Range");
}

// TODO Write a function, deleteItem, that takes one parameter, an Item
//  identifier (a string), deletes it from the container, and returns true if
//  the Item was deleted. If no Item exists, throw an appropriate exception.
//
// Example:
//  Category cObj{"categoryIdent"};
//  cObj.newItem("itemIdent");
//  bool result = cObj.deleteItem("itemIdent");

bool Category::deleteItem(std::string itemIdent){
    for(auto it = this->itemsVector.begin(); it != this->itemsVector.end(); it++){
        if(it->getIdent() == itemIdent){
            this->itemsVector.erase(it); //erase the item
            return true;
        }
    }
    throw std::out_of_range("Out of Range");
}

std::vector<Item> Category::getItems(){
    return this->itemsVector;
}


// TODO Write an == operator overload for the Category class, such that two
//  Category objects are equal only if they have the same identifier and same
//  Items.
//
// Example:
//  Category cObj1{"categoryIdent1"};
//  cObj1.newItem("itemIdent");
//  Category cObj2{"categoryIdent2"};
//  if(cObj1 == cObj2) {
//    ...
//  }
bool operator==(const Category& lhs, const Category& rhs){
    if((lhs.ident == rhs.ident) && (lhs.itemsVector == rhs.itemsVector)){
        return true;
    } else{
        return false;
    }
}


// TODO Write a function, str, that takes no parameters and returns a
//  std::string of the JSON representation of the data in the Category.
//
// See the coursework specification for how this JSON should look.
//
// Example:
//  Category cObj{"categoryIdent"};
//  std::string s = cObj.str();

std::string Category::str(){
    return ((json) *this).dump();
}

void to_json(json& j, const Category& c){
    json items = json::object();
    for(auto it = c.itemsVector.begin(); it != c.itemsVector.end(); it++) {
        //items.push_back(*it);
        json tmp = *it; //load the item in json (returns json::object)
        for(auto it2 = tmp.begin(); it2 != tmp.end(); it2++) {
            items[c.ident][it2.key()] = it2.value();
        }
    }
    //std::string s = items.dump();
    //std::string ns = s.substr(1, s.length() - 2);
    //items = json::parse(ns);
    //j = json{{c.ident,items}}; //adds category
    j = items;  
}
