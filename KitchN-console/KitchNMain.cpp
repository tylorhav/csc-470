// KitchNMain.cpp

#include "Includes.h"
#include <iostream>
#include <stdio.h>
#include <unistd.h>

using namespace std;

void KitchNMain::clearScreen() {
  if(system("CLS")) system("clear");
}

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

ShoppingList KitchNMain::getShoppingList() {
  return shoppingList;
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

Ingredient* KitchNMain::getIngredientByName(string name) {
  for (unsigned int a = 0; a < ingredients.size(); a++) {
    if (ingredients[a].getName() == name) {
      return &ingredients[a];
    }
  }
  return NULL;
}

void KitchNMain::addIngredient(Ingredient ingredient) {
  
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

void KitchNMain::addRecipe(Recipe recipe) {

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

void KitchNMain::getIngredientsConsoleWrapper() {
  clearScreen();

  // display list of all ingredients on hand
  // enter to continue
}

void KitchNMain::addIngredientConsoleWrapper() {
  clearScreen();
  // input:
  //  - name
  //  - exp date
  //  - qty

  // instantiate ingredient
  // add to ingredients vector

  // confirmation
  // view ingredients list? 
  //      y - getIngredientsConsoleWrapper() 
  //      else proceed
}

void KitchNMain::removeIngredientConsoleWrapper() {
  clearScreen();
  // display #'d list of ingredients
  // prompt # to remove
  // prompt qty  
  // remove from inventory (assume oldest exp date for simplicity)
}

void KitchNMain::getRecipesConsoleWrapper() {
  clearScreen();
  // display #'d list of recipes
  // prompt # to view
  //   - 0 back to main
  //   - !=0 displayRecipe(string title) | getRecipesConsoleWrapper();
  // 
}

void KitchNMain::getRecipesByTitleConsoleWrapper() {
  clearScreen();
  // prompt recipe title
  // show #'d list of matching recipes
  // prompt recipe # to display
  //   - 0 back to main
  // if != 0, displayRecipe(string title)
  //          getRecipesByTitleConsoleWrapper();
  // else displayMenu();
}

void KitchNMain::getRecipesByIngredientConsoleWrapper() {
  // prompt ingredient name
  // show #'d list of matching recipes
  // prompt recipe # to display
  //   - 0 back to main
  // if != 0, displayRecipe(string title)
  //          getRecipesByIngredientConsoleWrapper();
  // else displayMenu();
}

void KitchNMain::getRecipesByCuisineTypeConsoleWrapper() {
  //clearScreen();
  // display #'d list of current cuisine types
  // prompt cuisine type #
  //clearScreen();
  // show #'d list of matching recipes
  // prompt recipe # to display
  //   - 0 back to main
  // if != 0, displayRecipe(string title)
  //          getRecipesByCuisineTypeConsoleWrapper();
  // else displayMenu();
}

void KitchNMain::addRecipeConsoleWrapper() {
 // clearScreen();
  // prompt recipe title
  // prompt prep time
  // prompt cook time
  // prompt cuisine type
  // loop prompt ingredients name and quantity
  // loop prompt steps
  // instantiate recipe
  // addRecipe(recipe)
  // displayRecipe(string title)
}

void KitchNMain::removeRecipeConsoleWrapper() {
  //clearScreen();
  // display #'d list of all recipes
  // prompt for recipe # to remove
  // remove recipe
  // confirmation
  // enter to continue
}

void KitchNMain::getShoppingListConsoleWrapper() {
  //clearScreen();
  // display current shopping list
  // enter to continue
}

void KitchNMain::addIngredientToShoppingList() {
  //clearScreen();
  // display #'d list of ingredients
  // prompt for # of ingredient
  // add ingredient to shopping list
  // confirmation
  // enter to continue
}

void KitchNMain::removeIngredientFromShoppingList() {
  //clearScreen();
  // display current shopping list (#'d)
  // prompt for # of item to remove
  // confirmation
  // enter to continue
}

void KitchNMain::clearShoppingList() {
  //clearScreen();
  // display current shopping list
  // prompt to confirm
  // empty list
  // confirmation
  // enter to continue
}


void exitSystem() {
  cout << "Thank you for using KitchN. Goodbye.\n";
  sleep(3);
  exit(0);
}



int displayMenu() {

  int menuResponse;

  // clear screen
  //clearScreen();

  // display menu
  cout << endl;
  cout << "----------------------------+ Welcome to KitchN! +---------------------------" << endl;
  cout << endl;
  
  // checkNotifications()

  cout << "  You currently have X items on your shopping list" << endl;
  cout << "  You currently have X items in your kitch inventory" << endl;
  cout << endl;
  cout << endl;
  cout << "  --+ MAIN MENU +--" << endl;
  cout << endl;
  cout << "  - Kitchen Inventory" << endl;
  cout << "  1) View all on-hand ingredients" << endl;
  cout << "  2) Add ingredient to inventory" << endl;
  cout << "  3) Remove ingredient from inventory" << endl;
  cout << endl;
  cout << "  - Recipes" << endl;
  cout << "  4) View all recipes" << endl;
  cout << "  5) Search by title" << endl;
  cout << "  6) Search by ingredient name" << endl;
  cout << "  7) Search by cuisine type" << endl;
  cout << "  8) Add recipe" << endl;
  cout << "  9) Remove recipe" << endl;
  cout << endl;
  cout << "  - Shopping List" << endl;
  cout << "  10) View shopping list" << endl;
  cout << "  11) Add ingredient to shopping list" << endl;
  cout << "  12) Remove ingredient from shopping list" << endl;
  cout << "  13) Clear shopping list" << endl;
  cout << endl;
  cout << "  0) Exit" << endl;
  cout << endl;
  cout << "------------------------------------------------------------------------------" << endl;
  cout << "Please enter your selection: ";
  


  // collect input #
  cin >> menuResponse;

  // return response
  return menuResponse;
}

void KitchNMain::displayRecipe(string title) {
  // show the recipe
  // enter to continue
}



int main() {

  printf("Welcome to KitchNMain\n");

  int menuResponse = 0;
  char temp;

  menuResponse = displayMenu();

  while (menuResponse != 0) {
    // switch case for menuResponse
    
    cout << "You entered " << menuResponse << endl;

    switch (menuResponse) {

      case 1: // getIngredientsConsoleWrapper()
              break;
      case 2: // addIngredientConsoleWrapper()
              break;
      case 3: // removeIngredientFromInventory()
              break;
      case 4: // printRecipes()
              break;
      case 5: // printRecipesByTitle()
              break;
      case 6: // printRecipesByIngredient()
              break;
      case 7: // printRecipesByCuisineType()
              break;
      case 8: // addNewRecipe()
              break;
      case 9: // removeRecipe()
              break;
      case 10: // printShoppingList()
              break;              
      case 11: // addToShoppingList()
              break;
      case 12: // removeFromShoppingList()
              break;
      case 13: // clearShoppingList()
              break;
      case 0: exitSystem();
              break;
      

    }

    cin >> temp;

    menuResponse = displayMenu();
  

  }

  cout << "exited loop with menuResponse = " << menuResponse << endl;
  exitSystem();



  return 0;
}
