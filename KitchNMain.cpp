// KitchNMain.cpp

#include "KitchNMain.h"
#include <iostream>

using std::string;
using std::vector;
using std::cout;

void KitchNMain::checkForExpiredIngredients() {
  // awaiting implementation
}

void KitchNMain::checkNotifications() {
  if (notifications.size() > 0) {
    for (unsigned int a = 0; a < notifications.size(); a++) {
      cout << notifications[a].getTitle() << "\n" << "   -- " << notifications[a].getDetails() << "\n";
    }
  }
}

vector<Recipe> KitchNMain::getRecipes() {
  return recipes;
}

vector<Recipe> KitchNMain::getRecipesByTitle(string term) {
  vector<Recipe> results;
  for (unsigned int a = 0; a < recipes.size(); a++) {
    if (recipes[a].getTitle().find(term) != std::string::npos) {
      results.push_back(recipes[a]);
    }
  }
  return results;
}

vector<Recipe> KitchNMain::getRecipesByIngredient(Ingredient ingredient) {
  vector<Recipe> results;
  for (unsigned int a = 0; a < recipes.size(); a++) {
    for (unsigned int b = 0; b < recipes[a].getIngredientsList().size(); b++) {
      if (recipes[a].getIngredientsList()[b].getName() == ingredient.getName()) {
	results.push_back(recipes[a]);
      }
    }
  }
  return results;
}

vector<Recipe> KitchNMain::getRecipesByCuisineType(string cuisineType) {
  vector<Recipe> results;
  for (unsigned int a = 0; a < recipes.size(); a++) {
    if (recipes[a].getCuisineType() == cuisineType) {
      results.push_back(recipes[a]);
    }
  }
  return results;
}

/*
vector<Recipe> KitchNMain::getMakeableRecipes() {
  // awaiting implementation
}
*/

vector<Ingredient> KitchNMain::getIngredients() {
  return ingredients;
}

Ingredient KitchNMain::getIngredientByName(string name) {
  for (unsigned int a = 0; a < ingredients.size(); a++) {
    if (ingredients[a].getName() == name) {
      return ingredients[a];
    }
    else {
      return NULL;
    }
  }
}

void KitchNMain::removeIngredient(string name) {
  bool removed = false;
  for (unsigned int a = 0; a < ingredients.size(); a++) {
    if (ingredients[a].getName() == name) {
      ingredients.erase(ingredients.begin() + a);
      removed = true;
    }
  }
  if (removed) {
    cout << "Removed " << name << " from ingredients list.\n";
  }
  else {
    cout << name << " does not exist.\n";
  }
}

void KitchNMain::removeRecipe(string title) {
  bool removed = false;
  for (unsigned int a = 0; a < recipes.size(); a++) {
    if (recipes[a].getTitle() == title) {
      recipes.erase(recipes.begin() + a);
      removed = true;
    }
  }
  if (removed) {
    cout << "Removed " << title << " from recipes list.\n";
  }
  else {
    cout << title << " does not exist.\n";
  }
}

int KitchNMain::main() {


  return 0;
}
