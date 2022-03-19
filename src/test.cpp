#include <fstream>
#include <iostream>
#include <sstream>
#include <typeinfo>
#include "lib_json.hpp"
using json = nlohmann::json;

int main(int argc, char *argv[]) { 
    
    std::ifstream is("database.json");
    json j;
    is >> j;
    //goes through each element, i.e. a category, 
    for(auto &_category : j.items()){ //for category:
        std::cout << _category.key() << "|||||||" << _category.value() << std::endl;
        auto cats = _category.value();
    
        for(auto it = cats.begin(); it != cats.end(); it++){ //for item
            std::cout << *it << std::endl;
            std::cout << "----2----" << std::endl;
           
            auto ents = it.value();
    
            for(auto ent = ents.begin(); ent != ents.end(); ent++){ //for entry
                std::cout << *ent << std::endl;
                std::cout << "----3----" << std::endl;
            }
           
        }
        //std::cout << _category.key() << std::endl;
        //std::cout << _category.value() << std::endl;
        std::cout << "----1----" << std::endl;
    }
    is.close();

    return 0;
}
