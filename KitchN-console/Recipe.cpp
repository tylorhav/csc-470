// Recipe.cpp
#include "Includes.h"

using std::vector;
using std::string;

Recipe::Recipe( string title, int prepTime, int cookTime, vector<RecipeIngredient> ingredientsList, vector<string> steps, string cuisineType) {
  this->title = title;
  this->prepTime = prepTime;
  this->cookTime = cookTime;
  this->ingredientsList = ingredientsList;
  this->steps = steps;
  this->cuisineType = cuisineType;
}

string Recipe::getTitle() {
  return title;
}

int Recipe::getPrepTime() {
  return prepTime;
}

int Recipe::getCookTime() {
  return cookTime;
}

vector<RecipeIngredient> Recipe::getIngredientsList() {
  return ingredientsList;
}

vector<string> Recipe::getSteps() {
  return steps;
}

string Recipe::getCuisineType() {
  return cuisineType;
}

void Recipe::setTitle(string title) {
  this->title = title;
}

void Recipe::setPrepTime(int prepTime) {
  this->prepTime = prepTime;
}

void Recipe::setCookTime(int cookTime) {
  this->cookTime = cookTime;
}

void Recipe::setIngredientsList(vector<RecipeIngredient> ingredientsList) {
  this->ingredientsList = ingredientsList;
}

void Recipe::setSteps(vector<string> steps) {
  this->steps = steps;
}

void Recipe::setCuisineType(string cuisineType) {
  this->cuisineType = cuisineType;
}



