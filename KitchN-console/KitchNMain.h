// KitchNMain.h

#ifndef KITCHNMAIN_H
#define KITCHNMAIN_H

#include <vector>
/*
#include <Notification.h>
#include <Recipe.h>
*/
#include "ShoppingList.h"
#include "Ingredient.h"
#include "Recipe.h"
#include "Notification.h"

class ShoppingList;

class KitchNMain {

 private:
  ShoppingList shoppingList;
  std::vector<Ingredient> ingredients;
  std::vector<Recipe> recipes;
  std::vector<Notification> notifications;
  
 public:
  void checkForExpiredIngredients();
  void checkNotifications();
  
  ShoppingList getShoppingList();
  std::vector<Recipe> getRecipes();
  std::vector<Recipe> getRecipesByTitle(std::string term);
  std::vector<Recipe> getRecipesByIngredient(Ingredient ingredient);
  std::vector<Recipe> getRecipesByCuisineType(std::string cuisineType);
  std::vector<Recipe> getMakeableRecipes();
  std::vector<Ingredient> getIngredients();
  Ingredient* getIngredientByName(std::string name);

  void addIngredient(Ingredient ingredient);
  void removeIngredient(std::string name);
  void addRecipe(Recipe recipe);
  void removeRecipe(std::string title);
  
  void getIngredientsConsoleWrapper();
  void addIngredientConsoleWrapper();
  void removeIngredientConsoleWrapper();
  void getRecipesConsoleWrapper();
  void getRecipesByTitleConsoleWrapper();
  void getRecipesByIngredientConsoleWrapper();
  void getRecipesByCuisineTypeConsoleWrapper();
  void addRecipeConsoleWrapper();
  void removeRecipeConsoleWrapper();
  void getShoppingListConsoleWrapper();
  void addIngredientToShoppingList();
  void removeIngredientFromShoppingList();
  void clearShoppingListConsoleWrapper();
  void clearShoppingList();


  void exitSystem();
  void clearScreen();
  int displayMenu();
  void displayRecipe(std::string title);

  int main();

};

#endif
