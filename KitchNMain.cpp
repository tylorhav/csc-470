// KitchNMain.cpp

#include "KitchNMain.h"

using std::string;
using std::vector;

void KitchNMain::checkForExpiredIngredients() {
  // awaiting implementation
}

void KitchNMain::checkNotifications() {
  if (notifications.size() > 0) {
    for (int a = 0; a < notifications.size(); a++) {
      cout << notications[a] << "\n";
    }
  }
}

vector<Recipe> KitchNMain::getRecipes() {
  return recipes;
}

vector<Recipe> KitchNMain::getRecipesByTitle(string term) {
  vector<Recipe> results;
  for (int a = 0; a < recipes.size(); a++) {
    if (recipes[a].getTitle().find(term) != std::string::npos) {
      results.push_back(recipes[a]);
    }
  }
  return results;
}

vector<Recipe> KitchNMain::getRecipesByIngredient(Ingredient ingredient) {
  vector<Recipe> results;
  for (int a = 0; a < recipes.size(); a++) {
    for (int b = 0; b < recipes[a].getIngredients().size(); b++) {
      if (recipes[a].getIngredients()[b].getName() == ingredient.getName()) {
	results.push_back(recipes[a]);
      }
    }
  }
  return results;
}

vector<Recipe> KitchNMain::getRecipesByCuisineType(string cuisineType) {
  vector<Recipe> results;
  for (int a = 0; a < recipes.size(); a++) {
    if (recipes[a].getCuisineType() == cuisineType) {
      results.push_back(recipes[a]);
    }
  }
  return results;
}

vector<Recipe> KitchNMain::getMakeableRecipes() {
  // awaiting implementation
}

vector<Ingredient> KitchNMain::getIngredients() {
  return ingredients;
}

Ingredient KitchNMain::getIngredientByName(string name) {
  for (int a = 0; a < ingredients.size(); a++) {
    if (ingredients[a].getName() == name) {
      return ingredients[a];
    }
  }
}

void KitchNMain::removeIngredient(string name) {
  bool removed = false;
  for (int a = 0; a < ingredients.size(); a++) {
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
  for (int a = 0; a < recipes.size(); a++) {
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
