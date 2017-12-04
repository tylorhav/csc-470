// Recipe.h

#ifndef RECIPE_H
#define RECIPE_H

#include <vector>
#include <string>
#include "RecipeIngredient.h"

class Recipe {

 private:
  std::string title;
  int prepTime;
  int cookTime;
  std::vector<RecipeIngredient> ingredientsList;
  std::vector<std::string> steps;
  std::string cuisineType;
  
  void setTitle(std::string title);
  void setPrepTime(int prepTime);
  void setCookTime(int cookTime);
  void setIngredientsList(std::vector<RecipeIngredient> ingredientsList);
  void setSteps(std::vector<std::string> steps);
  void setCuisineType(std::string cuisineType);
  
 public:
  Recipe( std::string title,
	       int prepTime,
	       int cookTime,
	       std::vector<RecipeIngredient> ingredientsList,
	       std::vector<std::string> steps,
	       std::string cuisineType);
  std::string getTitle();
  int getPrepTime();
  int getCookTime();
  std::vector<RecipeIngredient> getIngredientsList();
  std::vector<std::string> getSteps();
  std::string getCuisineType();


  
};

#endif
