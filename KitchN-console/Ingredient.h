// Ingredient.h

#ifndef INGREDIENT_H
#define INGREDIENT_H

#include <string>

class Ingredient {

 private:
  std::string name;
  int quantity;

 public:
  Ingredient( std::string name, int quantity);

  void setName(std::string name);
  void setQuantity(int quantity);

  std::string getName();
  int getQuantity();  
};

#endif
