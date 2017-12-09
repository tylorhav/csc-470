// RecipeIngredient.cpp
#include "Includes.h"

using std::string;

RecipeIngredient::RecipeIngredient( string measurement, string name) {
  this->measurement = measurement;
  this->name = name;
}

string RecipeIngredient::getMeasurement() {
  return measurement;
}

string RecipeIngredient::getName() {
  return name;
}

void RecipeIngredient::setMeasurement(string measurement) {
  this->measurement = measurement;
}

void RecipeIngredient::setName(string name) {
  this->name = name;
}
