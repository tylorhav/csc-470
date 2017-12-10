// Ingredient.cpp

#include "Includes.h"

using std::string;
using std::vector;

Ingredient::Ingredient(string name, int quantity, vector<Date> expirationDates) {
  this->name = name;
  this->quantity = quantity;
  this->expirationDates = expirationDates;
}

string Ingredient::getName() {
  return name;
}

int Ingredient::getQuantity() {
  return quantity;
}

vector<Date> Ingredient::getExpirationDates() {
  return expirationDates;
}

void Ingredient::setName(string name) {
  this->name = name;
}

void Ingredient::setQuantity(int quantity) {
  this->quantity = quantity;
}

void Ingredient::addExpirationDate(int month, int day, int year) {
  //this->expirationDates = expirationDates;
	this->expirationDates.emplace_back(day, month, year);
	//this->expirationDates.push_back(Date(day, month, year));
	//Date* date = new Date(day, month, year);
}
