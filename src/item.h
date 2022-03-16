// -----------------------------------------------------
// CSC371 Advanced Object Oriented Programming (2021/22)
// Department of Computer Science, Swansea University
//
// Author: 976005
//
// Canvas: https://canvas.swansea.ac.uk/courses/24793
// -----------------------------------------------------
// An Item class contains multiple 'entries' as
// key/value pairs (e.g., a key might be 'username'
// and a value would be the username, another might be
// 'url' and the value is the website address the
// username is for.
// -----------------------------------------------------
#include <string>
#include <unordered_map>

#ifndef ITEM_H
#define ITEM_H

class Item {

   std::string ident;
   std::unordered_map<std::string, std::string> entries;
   unsigned int count;
   //std::string key;
   //std::string value;

public:
    Item(std::string ident);


    unsigned int size();
    bool empty();
    void setIdent(std::string ident);
    std::string getIdent() const;
    bool addEntry(std::string key, std::string value);
    std::string getEntry(std::string key) const;
    bool deleteEntry(std::string key);

};

#endif // ITEM_H
