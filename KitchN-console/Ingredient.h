// Ingredient.h

#ifndef INGREDIENT_H
#define INGREDIENT_H

#include <string>
#include <vector>
#include "Date.h"


class Ingredient {

 private:
  std::string name;
  int quantity;
  std::vector<Date> expirationDates;

 public:
  void setName(std::string name);
  void setQuantity(int quantity);
  //void addExpirationDate(std::vector<Date> expirationDates);
  //void addExpirationDate(Date date);
  void addExpirationDate(int month, int day, int year);

  Ingredient( std::string name, int quantity, std::vector<Date> expirationDates);
  std::string getName();
  int getQuantity();
  std::vector<Date> getExpirationDates();
  
};

#endif
