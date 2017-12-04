// KitchNMain.h

#ifndef KITCHNMAIN_H
#define KITCHNMAIN_H

#include <vector>
#include <Notification.h>

class KitchNMain {

 private:
  ShoppingList shoppingList;
  std::vector<Ingredient> ingredients;
  std::vector<Recipe> recipes;
  std::vector<Notification> notifications;
  
 public:
  void checkForExpiredIngredients();
  void checkNotifications();
  std::vector<Recipe> getRecipes();
  std::vector<Recipe> getRecipesByTitle(std::string term);
  std::vector<Recipe> getRecipesByIngredient(Ingredient ingredient);
  std::vector<Recipe> getRecipesByCuisineType(std::string cuisineType);
  std::vector<Recipe> getMakeableRecipes();
  std::vector<Ingredient> getIngredients();
  Ingredient getIngredientByName(std::string name);
  void removeIngredient(std::string name);
  void removeRecipe(std::string title);
  int main();

};

#endif
