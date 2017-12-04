//ShoppingList.h

#ifndef SHOPPINGLIST_H
#define SHOPPINGLIST_H

#include <vector>
#include <string>
#include <algorithm>

class ShoppingList {

 private:
  std::vector<std::string> items;
  
 public:
    std::vector<std::string> getItems();

    void addItem(std::string item);

    void removeItem(std::string item);
  
};

#endif
