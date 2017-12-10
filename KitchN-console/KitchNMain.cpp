// KitchNMain.cpp

#include "Includes.h"
#include <iostream>
#include <stdio.h>
#include <unistd.h>

using namespace std;

void KitchNMain::loadSampleData() {

  cout << "loading sample data, please wait..." << endl;

  // Recipes
  string title;
  int prepTime;
  int cookTime;
  string cuisineType;
  vector<RecipeIngredient> myIngredients;
  vector<string> mySteps;


  title = "Poppy Seed Chicken Salad";
  prepTime = 5;
  cookTime = 0;
  cuisineType = "Salad";
  myIngredients.emplace_back("2 cups", "Chicken Salad");
  myIngredients.emplace_back("1/4 cup", "Poppy Seed Salad Dressing");
  myIngredients.emplace_back("1/2 cup - roasted","Pecans");
  myIngredients.emplace_back("1/2 cup - halved","Grapes");
  myIngredients.emplace_back("1 package","pita chips");
  mySteps.push_back("Combine first 4 ingredients in a bowl.");
  mySteps.push_back("Cover and chill until ready to serve.");
  mySteps.push_back("Serve with crackers or pita chips.");
  Recipe* rec = new Recipe(title, prepTime, cookTime, myIngredients, mySteps, cuisineType);
  addRecipe(rec);

  // Ingredients
  string name;
  string expDate;


  // Shopping List

}

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

void KitchNMain::addRecipe(Recipe* recipe) {
  recipes.push_back(*recipe);
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
  cout << "in getIngredientsConsoleWrapper()" << endl;
  
  // display list of all ingredients on hand
  std::vector<Ingredient> results = getIngredients();

  // enter to continue
  char temp;
  cin >> temp;
}

void KitchNMain::addIngredientConsoleWrapper() {
  clearScreen();
  cout << "in addIngredientConsoleWrapper()" << endl;
  
  // input:
  //  - name
  //  - exp date
  //  - qty
  string name;
  int month, day, year, qty;
  cout << "Add Ingredient to Inventory" << endl;
  cout << endl;
  cout << "Name: ";
  cin.ignore();
  getline(cin, name);
  cout << endl;
  cout << "Expiration date " << endl;
  cout << "Month: ";
  cin >> month;
  cout << "Day: ";
  cin >> day;
  cout << "Year: ";
  cin >> year;
  cout << endl;
  cout << "Quantity: ";
  cin >> qty;

  // do we already have one or more of this ingredient on-hand?
  bool exists = false;
  int totalqty;
  for (auto &ing : ingredients) {
    if (ing.getName() == name) {
      exists = true;
      ing.setQuantity(ing.getQuantity() + qty);
      totalqty = ing.getQuantity();
      for (int a = 0; a < qty; a++) {
        ing.addExpirationDate(month, day, year);
      }
      break;
    }
  }

  if (exists) {
    //  confirmation
    cout << name << " already exists in inventory." << endl;
    cout << "Added " << qty << " " << name << "(s) with expiration date of " << month << "/" << day << "/" << year << " to inventory." << endl;
    cout << "Total quantity is now " << totalqty << endl; 
  } else {
    //    instantiate Ingredient
    //    add Ingredient to ingredients vector
    vector<Date> expirationDates;
    for (int a = 0; a < qty; a++) {
      expirationDates.emplace_back(day, month, year);
    }

    ingredients.emplace_back(name, qty, expirationDates);
    //    confirmation
    cout << "Added " << qty << " " << name << "(s) with expiration date of " << month << "/" << day << "/" << year << " to inventory." << endl;

  }

  char response;
  cout << "Add another ingredient? (Y/n): ";
  cin >> response;
  response = char(toupper(response));

  if (response == 'Y') {
    addIngredientConsoleWrapper();
  }
}

void KitchNMain::removeIngredientConsoleWrapper() {
  clearScreen();
  cout << "in removeIngredientConsoleWrapper()" << endl;
  // display #'d list of ingredients
  // prompt # to remove
  // prompt qty  
  // remove from inventory (assume oldest exp date for simplicity)
}

void KitchNMain::getRecipesConsoleWrapper() {
  clearScreen();

  int selection;
  int ctr = 1;
  
  cout << "View All Recipes" << endl;
  cout << endl;
  cout << "0) <--Back" << endl;
  
  vector<Recipe> results = getRecipes();
  
  // display #'d list of recipes
  for (auto &rec : results) {
    cout << ctr << ") " << rec.getTitle() << endl;
    ctr++;
  }
  
  // prompt # to view
  cout << "Selection: ";
  cin >> selection;
  if (selection > 0) {
    // display recipe
    displayRecipe(results.at(selection - 1).getTitle());
    getRecipesConsoleWrapper();
  }
}

void KitchNMain::getRecipesByTitleConsoleWrapper() {
  clearScreen();

  string searchTitle;
  int selection;
  int ctr = 1;

  // prompt recipe title
  // show #'d list of matching recipes
  // prompt recipe # to display
  //   - 0 back to main
  // if != 0, displayRecipe(string title)
  //          getRecipesByTitleConsoleWrapper();
  // else displayMenu();
}

void KitchNMain::getRecipesByIngredientConsoleWrapper() {
  clearScreen();
  cout << "in getRecipesByIngredientConsoleWrapper()" << endl;
  // prompt ingredient name
  // show #'d list of matching recipes
  // prompt recipe # to display
  //   - 0 back to main
  // if != 0, displayRecipe(string title)
  //          getRecipesByIngredientConsoleWrapper();
  // else displayMenu();
}

void KitchNMain::getRecipesByCuisineTypeConsoleWrapper() {
  clearScreen();
  cout << "in getRecipesByCuisineTypeConsoleWrapper()" << endl;
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
  clearScreen();
  cout << "in addRecipeConsoleWrapper()" << endl;
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
  clearScreen();
  cout << "in removeRecipeConsoleWrapper()" << endl;
  // display #'d list of all recipes
  // prompt for recipe # to remove
  // remove recipe
  // confirmation
  // enter to continue
}

void KitchNMain::getShoppingListConsoleWrapper() {
  clearScreen();
  cout << "in getShoppingListConsoleWrapper()" << endl;
  // display current shopping list
  // enter to continue
}

void KitchNMain::addIngredientToShoppingList() {
  clearScreen();
  cout << "in addIngredientToShoppingList()" << endl;
  // display #'d list of ingredients
  // prompt for # of ingredient
  // add ingredient to shopping list
  // confirmation
  // enter to continue
}

void KitchNMain::removeIngredientFromShoppingList() {
  clearScreen();
  cout << "in removeIngredientFromShoppingList()" << endl;
  // display current shopping list (#'d)
  // prompt for # of item to remove
  // confirmation
  // enter to continue
}

void KitchNMain::clearShoppingListConsoleWrapper() {
  clearScreen();
  cout << "in clearShoppingList()" << endl;
  // display current shopping list
  // prompt to confirm
  // clearShoppingList();
  // confirmation
  // enter to continue
}

void KitchNMain::clearShoppingList() {
  // empty shopping list
}

void KitchNMain::exitSystem() {
  cout << "Thank you for using KitchN. Goodbye.\n";
  sleep(3);
  exit(0);
}



int KitchNMain::displayMenu() {

  int menuResponse;

  // clear screen
  clearScreen();

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
  clearScreen();

  // show the recipe
  cout << "Recipe Selected: " << title << endl;
  
  // enter to continue
  cout << "0->Enter to exit.";
  char temp;
  cin >> temp;
}



int main() {

  KitchNMain kmain;

  kmain.loadSampleData();

  int menuResponse = 0;
  char temp;

  menuResponse = kmain.displayMenu();

  while (menuResponse != 0) {
    // switch case for menuResponse
    
    cout << "You entered " << menuResponse << endl;

    switch (menuResponse) {

      case 1: kmain.getIngredientsConsoleWrapper();
              break;
      case 2: kmain.addIngredientConsoleWrapper();
              break;
      case 3: kmain.removeIngredientConsoleWrapper();
              break;
      case 4: kmain.getRecipesConsoleWrapper();
              break;
      case 5: kmain.getRecipesByTitleConsoleWrapper();
              break;
      case 6: kmain.getRecipesByIngredientConsoleWrapper();
              break;
      case 7: kmain.getRecipesByCuisineTypeConsoleWrapper();
              break;
      case 8: kmain.addRecipeConsoleWrapper();
              break;
      case 9: kmain.removeRecipeConsoleWrapper();
              break;
      case 10: kmain.getShoppingListConsoleWrapper();
              break;              
      case 11: kmain.addIngredientToShoppingList();
              break;
      case 12: kmain.removeIngredientFromShoppingList();
              break;
      case 13: kmain.clearShoppingListConsoleWrapper();
              break;
      case 0: kmain.exitSystem();
              break;
      

    }

    //cin >> temp;

    menuResponse = kmain.displayMenu();
  

  }

  cout << "exited loop with menuResponse = " << menuResponse << endl;
  kmain.exitSystem();



  return 0;
}
