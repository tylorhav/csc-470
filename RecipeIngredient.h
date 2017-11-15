// RecipeIngredient.h

#ifndef RECIPEINGREDIENT_H
#define RECIPEINGREDIENT_H

#include <string>


class RecipeIngredient {

 private:
  std::string measurement;
  std::string name;

 public:
  RecipeIngredient( std::string measurement,
		    std::string name);
  std::string getMeasurement();
  std::string getName();
  void setMeasurement(std::string measurement);
  void setName(std::string name);
  
};

#endif


