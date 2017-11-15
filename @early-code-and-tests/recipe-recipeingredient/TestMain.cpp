// TestMain.cpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include "Recipe.h"
#include "RecipeIngredient.h"

using std::vector;
using std::string;

int main() {

  vector<RecipeIngredient> ingredientsList;
  vector<string> steps;

  std::cout << "Initializing recipe details...";
  
  string title = "Garlic Chicken";
  int prepTime = 20;
  int cookTime = 30;
  string cuisineType = "Italian";
  
  ingredientsList.push_back(RecipeIngredient("1/4 cup", "Olive Oil"));
  ingredientsList.push_back(RecipeIngredient("2 cloves, crushed", "Garlic"));
  ingredientsList.push_back(RecipeIngredient("1/4 cup", "Italian Seasoned Bread Crumbs"));
  ingredientsList.push_back(RecipeIngredient("1/4 cup, greated", "Parmesan Cheese"));
  ingredientsList.push_back(RecipeIngredient("4 halves", "Chicken Breast"));
  
  steps.push_back("Preheat oven to 425 degrees F.");
  steps.push_back("Heat olive oil and garlic in a small saucepan over low heat until warmed, 1 to 2 minutes. Transfer garlic and oil to a shallow bowl.");
  steps.push_back("Combine bread crumbs and parmesan cheese in a separate shallow bowl.");
  steps.push_back("Dip chicken breast in the olive oil - garlic mixture using tongs; transfer to bread crumb mixture and turn to evenly coat. Transfer coated chicken to a shallow baking dish.");
  steps.push_back("Bake in the preheated oven until no longer pink and juices run clear, 30 to 35 minutes. An instant-read thermometer inserted into the center should read at least 165 degrees F.");

  std::cout << "complete\n";

  std::cout << "Building Recipe object...";
  Recipe myRecipe = Recipe(title, prepTime, cookTime, ingredientsList, steps, cuisineType);
  std::cout << "complete\n";
  
  // print recipe
  std::cout << "Printing recipe...\n\n\n";
  
  std::cout << title << "\n\n";
  std::cout << "Prep Time: " << myRecipe.getPrepTime() << " minutes\n";
  std::cout << "Cook Time: " << myRecipe.getCookTime() << " minutes\n";
  std::cout << "Cuisine Type: " << myRecipe.getCuisineType() << "\n\n";
  std::cout << "Ingredients:\n------------\n";

  for (int a = 0; a < myRecipe.getIngredientsList().size(); a++) {
    std::cout << myRecipe.getIngredientsList()[a].getMeasurement() << " " << myRecipe.getIngredientsList()[a].getName() << "\n";
  }

  std::cout << "\nSteps:\n------\n";

  for (int a = 0; a < myRecipe.getSteps().size(); a++) {
    std::cout << a+1 << ". " << myRecipe.getSteps()[a] << "\n";
  }
  
  
  return 0;
}
