#include "Includes.h"
#include <string>

using namespace std;

void KitchNMain::loadSampleData() {
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
  ingredients.emplace_back("Bread", 2);
  ingredients.emplace_back("Cereal", 5);
  ingredients.emplace_back("Carrot", 10);
  ingredients.emplace_back("Chicken Breast", 4);
  ingredients.emplace_back("Tortillas", 50);
  ingredients.emplace_back("Beer", 100);
  ingredients.emplace_back("Tuna", 8);
  
  // Shopping List
  shoppingList.addItem("Milk");
  shoppingList.addItem("Peanut Butter");
  shoppingList.addItem("Pasta");
  shoppingList.addItem("Apple");
  shoppingList.addItem("Steak");
  shoppingList.addItem("Juice");
  shoppingList.addItem("Ketchup");
  shoppingList.addItem("Celery");
  shoppingList.addItem("Lettuce");
}