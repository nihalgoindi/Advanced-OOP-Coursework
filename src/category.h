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
#include "item.h"

#ifndef CATEGORY_H
#define CATEGORY_H

class Category {
    std::string ident;
    std::vector<Item> itemsVector;

public:
    Category(std::string ident);
    unsigned int size();
    bool empty();
    void setIdent(std::string ident);
    std::string getIdent() const;
    Item& newItem(std::string itemIdent);
    bool addItem(Item item);
    Item& getItem(std::string itemIdent); //could be const - come back to it later
    bool deleteItem(std::string itemIdent);
    friend bool operator==(const Category& lhs, const Category& rhs);
};

#endif // CATEGORY_H
