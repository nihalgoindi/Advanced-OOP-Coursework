// -----------------------------------------------------
// CSC371 Advanced Object Oriented Programming (2021/22)
// Department of Computer Science, Swansea University
//
// Author: 976005
//
// Canvas: https://canvas.swansea.ac.uk/courses/24793
// -----------------------------------------------------
// A category contains one or more Items, each with
// their own identifier ('ident').
// -----------------------------------------------------
#include <string>
#include <vector>

#include "lib_json.hpp"

#include "item.h"


using json = nlohmann::json;

#ifndef CATEGORY_H
#define CATEGORY_H

class Category
{
    std::string ident;
    std::vector<Item> itemsVector;

public:
    Category(std::string ident);
    unsigned int size();
    bool empty();
    std::string getIdent() const;
    void setIdent(std::string ident);
    Item &newItem(std::string itemIdent);
    bool addItem(Item item);
    Item &getItem(std::string itemIdent);
    bool deleteItem(std::string itemIdent);
    std::vector<Item> getItems();
    friend bool operator==(const Category &lhs, const Category &rhs);
    std::string str();
    friend void to_json(json &j, const Category &c);
};

#endif // CATEGORY_H
