// Ingredient.cpp

#include "Includes.h"

using std::string;

Ingredient::Ingredient(string name, int quantity) {
  this->name = name;
  this->quantity = quantity;
}

string Ingredient::getName() {
  return name;
}

int Ingredient::getQuantity() {
  return quantity;
}

void Ingredient::setName(string name) {
  this->name = name;
}

void Ingredient::setQuantity(int quantity) {
  this->quantity = quantity;
}

