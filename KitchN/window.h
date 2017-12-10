
#ifndef WINDOW_H
#define WINDOW_H

#include <Recipe.h>
#include <vector>
#include <QtCore>
#include <QtGui>

class QTextEdit;
class QGroupBox;
class QLabel;
class QGridLayout;
class QListWidget;
class QPushButton;
class QHBoxLayout;
class QScrollArea;
class QSize;
class QWidget;
class QLineEdit;
class QSpinBox;
class QDateEdit;

class Window : public QWidget
{
    Q_OBJECT

public:
    Window();

private slots:
    void removeRecipeItem();
    void removeInventoryItem();
    void removeShoppingItem();
    void displayRecipeOnClick();
    void createRecipePopup();
    void cancelCreateRecipePopup();
    void saveCreateRecipePopup();
    void createInventoryPopup();
    void cancelInventoryPopup();
    void saveInventoryPopup();
    void saveShoppingPopup();
    void cancelShoppingPopup();
    void createShoppingPopup();


private:
    void createRecipeGroupBox();
    void createInventoryGroupBox();
    void createShoppingGroupBox();
    void createCommonLabels();
    void testFillRecipe();
    void testFillInventory();
    void testFillShopping();
    void testRealRecipeList();
    
    QSize *largeList; //Shared between Inventory and Shopping lists

//components of recipeGroupBox
    QTextEdit *recipeText;
    QGridLayout *recipeLayout;
    QGroupBox *recipeGroupBox;
    QListWidget *recipeList;
    QScrollArea *recipeListScroll;
    
    QPushButton *addToShopping;
    QGroupBox *recipeButtonBox;
    QHBoxLayout *recipeHButtons;//This box holds the multiple buttons in horizontal order
    QPushButton *addRecipe;
    QPushButton *editRecipe;
    QPushButton *removeRecipe;
    
//components of inventoryGroupBox
    QGroupBox *inventoryGroupBox;
    QListWidget *inventoryList;
    QGridLayout *inventoryLayout;
    QScrollArea *inventoryListScroll;
    
    QGroupBox *inventoryButtonBox;
    QHBoxLayout *inventoryHButtons;//This box holds the multiple buttons in horizontal order
    QPushButton *addInventory;
    QPushButton *editInventory;
    QPushButton *removeInventory;    
    
//components of inventoryGroupBox
    QGroupBox *shoppingGroupBox;
    QListWidget *shoppingList;
    QGridLayout *shoppingLayout;
    QScrollArea *shoppingListScroll;
    
    QGroupBox *shoppingButtonBox;
    QHBoxLayout *shoppingHButtons;//This box holds the multiple buttons in horizontal order
    QPushButton *addShopping;
    QPushButton *editShopping;
    QPushButton *removeShopping;   

// components of createRecipePopup
    QWidget *recipePopupWidget;
    QPushButton *saveNewRecipe;
    QPushButton *cancelNewRecipe;
    QGridLayout *recipePopupLayout;
    QLineEdit *newRecipeTitleInput;
    QLineEdit *newRecipeCuisineTypeInput;
    QTextEdit *newRecipeStepsInput;
    QSpinBox *newRecipePrepInput;
    QSpinBox *newRecipeCookInput;
    QListWidget *newRecipeIngredientList;
    QPushButton *newRecipeAddIngredient;
    
//components of createCommonLabels
    QLabel* recipeTitleLabel;
    QLabel* cuisineTypeLabel;
    QLabel* prepTimeLabel;
    QLabel* cookTimeLabel;
    QLabel* ingredientNameLabel;
    QLabel* expirationDateLabel;
    
//components of createInventoryPopup
    QWidget *inventoryPopupWidget;
    QPushButton *saveNewInventory;
    QPushButton *cancelNewInventory;
    QGridLayout *inventoryPopupLayout;
    QLineEdit *newInventoryNameInput;
    QDateEdit *newInventoryExpirationInput;

//components of createShoppingPopup
    QWidget *shoppingPopupWidget;
    QPushButton *saveNewShopping;
    QPushButton *cancelNewShopping;
    QGridLayout *shoppingPopupLayout;
    QLineEdit *newShoppingNameInput;
    
//test recipe list stuff
    std::vector<Recipe> recipeTestList;




};

#endif
