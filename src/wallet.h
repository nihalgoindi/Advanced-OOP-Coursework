// -----------------------------------------------------
// CSC371 Advanced Object Oriented Programming (2021/22)
// Department of Computer Science, Swansea University
//
// Author: 976005
//
// Canvas: https://canvas.swansea.ac.uk/courses/24793
// -----------------------------------------------------
// The root object that holds all data for 371pass. This
// class contains Categories, which in turn hold Items,
// which hold a mapping of entries.
// -----------------------------------------------------
#include <string>
#include <vector>
#include "category.h"

#ifndef WALLET_H
#define WALLET_H

class Wallet {
  std::vector<Category> categories;

public:
  Wallet();
  unsigned int size();
  bool empty();
  Category& newCategory(std::string categoryIdent);
  bool addCategory(Category category);
  Category& getCategory(std::string categoryIdent);
  bool deleteCategory(std::string categoryIdent);
  void load(std::string dbName);
  void save(std::string filePath);
  friend void to_json(json& j, const Wallet& w);
  friend bool operator==(const Wallet& lhs, const Wallet& rhs);
  std::string str();
};

#endif // WALLET_H
