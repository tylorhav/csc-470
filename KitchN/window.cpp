

#include <QtCore>
#include <QtGui>
#include <string>
#include <iostream>

#include "Includes.h"

extern ShoppingList *ShoppingListObj;
extern KitchNMain *KitchnMainObj;

Window::Window()
{
    createCommonLabels();
    createRecipeGroupBox();
    createInventoryGroupBox();
    createShoppingGroupBox();


// these only fill the UI not the Database
//    testFillRecipe();
//    testFillInventory();
//    testFillShopping();
    
    QGridLayout *layout = new QGridLayout;
    layout->addWidget(recipeGroupBox, 0, 0);
    layout->addWidget(inventoryGroupBox, 0, 1);
    layout->addWidget(shoppingGroupBox, 0, 2);
    
    layout->setSizeConstraint(QLayout::SetFixedSize);
    setLayout(layout);
    
    setWindowTitle(tr("Kitchenator 9001"));
    
}

//the "Create" series of methods create and establish each individual section in the main window
void Window::createCommonLabels()
{
//these labels can get used in any UI part
    recipeTitleLabel = new QLabel;
        recipeTitleLabel->setText("Recipe Title:");
    cuisineTypeLabel = new QLabel;
        cuisineTypeLabel->setText("Cuisine Type:");
    prepTimeLabel = new QLabel;
        prepTimeLabel->setText("Prep Time (Min):");
    cookTimeLabel = new QLabel;
        cookTimeLabel->setText("Cook Time (Min):");
    ingredientNameLabel = new QLabel;
        ingredientNameLabel->setText("Ingredient Name");
    expirationDateLabel = new QLabel;
        expirationDateLabel->setText("Expiration Date");
}

void Window::createShoppingPopup()
{
    shoppingPopupWidget = new QWidget;
    saveNewShopping = new QPushButton;
        saveNewShopping->setText("Save");
    cancelNewShopping = new QPushButton;
        cancelNewShopping->setText("Cancel");
    shoppingPopupLayout = new QGridLayout;
    newShoppingNameInput = new QLineEdit;
        newShoppingNameInput->setPlaceholderText("Ingredient Name");
    
    //connect up those buttons
    connect(cancelNewShopping, SIGNAL (released()),this, SLOT (cancelShoppingPopup()));
    connect(saveNewShopping, SIGNAL (released()),this, SLOT (saveShoppingPopup()));
        
    //add to layout
    shoppingPopupLayout->addWidget(ingredientNameLabel, 0, 0, Qt::AlignCenter);
    shoppingPopupLayout->addWidget(newShoppingNameInput, 0, 1, Qt::AlignCenter);
    shoppingPopupLayout->addWidget(saveNewShopping, 1, 0, Qt::AlignCenter);
    shoppingPopupLayout->addWidget(cancelNewShopping, 1, 1, Qt::AlignCenter);
    shoppingPopupWidget->setLayout(shoppingPopupLayout);
    shoppingPopupWidget->setWindowTitle(tr("Add to Shopping List"));
    shoppingPopupWidget->show();
}

void Window::cancelShoppingPopup()
{
    shoppingPopupWidget->close();
}

void Window::saveShoppingPopup()
{
    std::string temp = (newShoppingNameInput->text()).toUtf8().constData();
    ShoppingListObj->addItem(temp);//adds to database
    shoppingList->addItem(newShoppingNameInput->text());//adds to UI
    shoppingPopupWidget->close();
}

void Window::createInventoryPopup()
{
    inventoryPopupWidget = new QWidget;
    saveNewInventory = new QPushButton;
        saveNewInventory->setText("Save");
    cancelNewInventory = new QPushButton;
        cancelNewInventory->setText("Cancel");
    inventoryPopupLayout = new QGridLayout;
    newInventoryNameInput = new QLineEdit;
        newInventoryNameInput->setPlaceholderText("Ingredient Name");
    newInventoryExpirationInput = new QDateEdit;
    
    //connect up those buttons
    connect(cancelNewInventory, SIGNAL (released()),this, SLOT (cancelInventoryPopup()));
    connect(saveNewInventory, SIGNAL (released()),this, SLOT (saveInventoryPopup()));
        
    //add to layout
    inventoryPopupLayout->addWidget(ingredientNameLabel, 0, 0, Qt::AlignCenter);
    inventoryPopupLayout->addWidget(newInventoryNameInput, 0, 1, Qt::AlignCenter);
    inventoryPopupLayout->addWidget(expirationDateLabel, 1, 0, Qt::AlignCenter);
    inventoryPopupLayout->addWidget(newInventoryExpirationInput, 1, 1, Qt::AlignCenter);
    inventoryPopupLayout->addWidget(saveNewInventory, 2, 0, Qt::AlignCenter);
    inventoryPopupLayout->addWidget(cancelNewInventory, 2, 1, Qt::AlignCenter);
    inventoryPopupWidget->setLayout(inventoryPopupLayout);
    inventoryPopupWidget->setWindowTitle(tr("Add Ingredient to Inventory"));
    inventoryPopupWidget->show();
}

void Window::cancelInventoryPopup()
{
    inventoryPopupWidget->close();
}

void Window::saveInventoryPopup()
{
    //add to DB
    
    inventoryList->addItem(newInventoryNameInput->text());//adds to UI
    inventoryPopupWidget->close();
}

void Window::createRecipePopup()
{
    recipePopupWidget = new QWidget;
    saveNewRecipe = new QPushButton;
        saveNewRecipe->setText("Save");
    cancelNewRecipe = new QPushButton;
        cancelNewRecipe->setText("Cancel");
    recipePopupLayout = new QGridLayout;
    newRecipeTitleInput = new QLineEdit;
        newRecipeTitleInput->setPlaceholderText("Recipe Title");
    newRecipeCuisineTypeInput = new QLineEdit;
        newRecipeCuisineTypeInput->setPlaceholderText("Cuisine Type");
    newRecipeStepsInput = new QTextEdit;
        newRecipeStepsInput->setPlainText("Recipe Instuctions");
    newRecipePrepInput = new QSpinBox;
    newRecipeCookInput = new QSpinBox;
    
    //connect up those buttons
    connect(cancelNewRecipe, SIGNAL (released()),this, SLOT (cancelCreateRecipePopup()));
    connect(saveNewRecipe, SIGNAL (released()),this, SLOT (saveCreateRecipePopup()));
        
    //add to layout
    recipePopupLayout->addWidget(recipeTitleLabel, 0, 0, Qt::AlignCenter);
    recipePopupLayout->addWidget(newRecipeTitleInput, 0, 1, Qt::AlignCenter);
    recipePopupLayout->addWidget(cuisineTypeLabel, 1, 0, Qt::AlignCenter);
    recipePopupLayout->addWidget(newRecipeCuisineTypeInput, 1, 1, Qt::AlignCenter);
    recipePopupLayout->addWidget(prepTimeLabel, 2, 0, Qt::AlignCenter);
    recipePopupLayout->addWidget(newRecipePrepInput, 2, 1, Qt::AlignCenter);
    recipePopupLayout->addWidget(newRecipeCookInput, 3, 1, Qt::AlignCenter);
    recipePopupLayout->addWidget(cookTimeLabel, 3, 0, Qt::AlignCenter);
    recipePopupLayout->addWidget(newRecipeStepsInput, 4, 1, Qt::AlignCenter);
    recipePopupLayout->addWidget(saveNewRecipe, 5, 0, Qt::AlignCenter);
    recipePopupLayout->addWidget(cancelNewRecipe, 5, 1, Qt::AlignCenter);
    recipePopupWidget->setLayout(recipePopupLayout);
    recipePopupWidget->setWindowTitle(tr("Add New Recipe"));
    recipePopupWidget->show();
}

    
void Window::cancelCreateRecipePopup()
{
    recipePopupWidget->close();
}

void Window::saveCreateRecipePopup()
{
    //parse data from input to create a recipe to pass in to storage
    std::string title = (newRecipeTitleInput->text()).toUtf8().constData();
    int preptime = newRecipePrepInput->value();
    int cooktime = newRecipeCookInput->value();
    std::vector <std::string>steps;
    steps.push_back((newRecipeStepsInput->toPlainText()).toUtf8().constData());
    std::string cuisineType = (newRecipeCuisineTypeInput->text()).toUtf8().constData();
    std::vector <RecipeIngredient>ingredientsList;
    Recipe temp( title, preptime, cooktime, ingredientsList, steps, cuisineType);

    recipeList->addItem(newRecipeTitleInput->text()); //this adds it to the recipe list ONLY
    recipeTestList.push_back(temp); //push back to local for testing in prod this passes it to real storage
    recipePopupWidget->close();
}
    

void Window::createRecipeGroupBox()
{
    recipeGroupBox = new QGroupBox(tr("Recipes"));
//create widgets
    recipeListScroll = new QScrollArea;
    recipeList = new QListWidget;
    recipeText = new QTextEdit;
    recipeLayout = new QGridLayout;
    recipeList->setSelectionMode(QAbstractItemView::SingleSelection);

    recipeListScroll->setWidget(recipeList);
    recipeButtonBox = new QGroupBox();
    recipeHButtons = new QHBoxLayout;
    addRecipe = new QPushButton;
        addRecipe->setText("Add");
    editRecipe = new QPushButton;
        editRecipe->setText("Edit");
    removeRecipe = new QPushButton;
        removeRecipe->setText("Remove");

    addToShopping = new QPushButton;
        addToShopping->setText("Add To Shopping List");

        
//connect buttons to their slots
    connect(removeRecipe, SIGNAL (released()),this, SLOT (removeRecipeItem()));
    connect(addRecipe, SIGNAL (released()),this, SLOT (createRecipePopup()));
    
// connects the recipe list to perform an action when you click on a particular recipe
     
    connect(recipeList, SIGNAL(itemSelectionChanged()), this, SLOT(displayRecipeOnClick())); 
    
//add widgets to layouts
    recipeHButtons->addWidget(addRecipe);
    recipeHButtons->addWidget(editRecipe);
    recipeHButtons->addWidget(removeRecipe);
    recipeButtonBox->setLayout(recipeHButtons);
    
    
    recipeLayout->addWidget(recipeText, 2, 0, Qt::AlignCenter);
    recipeLayout->addWidget(recipeButtonBox, 1, 0, Qt::AlignCenter);
    recipeLayout->addWidget(recipeList, 0, 0, Qt::AlignCenter);
    recipeLayout->addWidget(addToShopping, 3, 0, Qt::AlignCenter);
    recipeGroupBox->setLayout(recipeLayout);
}

void Window::createInventoryGroupBox()
{
    int inventoryListHeight = 400;
    int inventoryListWidth = 350;
    
    inventoryGroupBox = new QGroupBox(tr("Kitchen Inventory"));
    inventoryList = new QListWidget;
    inventoryList->setSelectionMode(QAbstractItemView::SingleSelection);
    inventoryListScroll = new QScrollArea;

    inventoryListScroll->setWidget(inventoryList);
    inventoryButtonBox = new QGroupBox();
    inventoryHButtons = new QHBoxLayout;
    addInventory = new QPushButton;
        addInventory->setText("Add");
    editInventory = new QPushButton;
        editInventory->setText("Edit");
    removeInventory = new QPushButton;
        removeInventory->setText("Remove");

//connect buttons to their slots
    connect(removeInventory, SIGNAL (released()),this, SLOT (removeInventoryItem()));
    connect(addInventory, SIGNAL (released()),this, SLOT (createInventoryPopup()));
    
    inventoryHButtons->addWidget(addInventory);
    inventoryHButtons->addWidget(editInventory);
    inventoryHButtons->addWidget(removeInventory);
    inventoryButtonBox->setLayout(inventoryHButtons);
    inventoryList->setMinimumSize(inventoryListWidth,inventoryListHeight);
    
    inventoryLayout = new QGridLayout;
    inventoryLayout->addWidget(inventoryList, 0, 0, Qt::AlignCenter);
    inventoryLayout->addWidget(inventoryButtonBox, 1, 0, Qt::AlignCenter);
    inventoryGroupBox->setLayout(inventoryLayout);
}

void Window::createShoppingGroupBox()
{
    int shoppingListHeight = 400;
    int shoppingListWidth = 350;
    
    shoppingGroupBox = new QGroupBox(tr("Shopping List"));
    shoppingList = new QListWidget;
    shoppingListScroll = new QScrollArea;
    shoppingList->setSelectionMode(QAbstractItemView::SingleSelection);

    shoppingListScroll->setWidget(shoppingList);
    shoppingButtonBox = new QGroupBox();
    shoppingHButtons = new QHBoxLayout;
    addShopping = new QPushButton;
        addShopping->setText("Add");
    editShopping = new QPushButton;
        editShopping->setText("Edit");
    removeShopping = new QPushButton;
        removeShopping->setText("Remove");
        
//connect buttons to their slots
    connect(removeShopping, SIGNAL (released()),this, SLOT (removeShoppingItem()));
    connect(addShopping, SIGNAL (released()),this, SLOT (createShoppingPopup()));
        
    shoppingHButtons->addWidget(addShopping);
    shoppingHButtons->addWidget(editShopping);
    shoppingHButtons->addWidget(removeShopping);
    shoppingButtonBox->setLayout(shoppingHButtons);
    shoppingList->setMinimumSize(shoppingListWidth,shoppingListHeight);

    shoppingLayout = new QGridLayout;
    shoppingLayout->addWidget(shoppingList, 0, 0, Qt::AlignCenter);
    shoppingLayout->addWidget(shoppingButtonBox, 1, 0, Qt::AlignCenter);
    shoppingGroupBox->setLayout(shoppingLayout);
}

    void Window::removeRecipeItem()
    {
//        KitchNMain::removeRecipe(recipeList->currentItem());
       delete (recipeList->currentItem());
    }
    
    void Window::removeInventoryItem()
    {
//       KitchNMain::removeIngredient(inventoryList->currentItem());
       delete (inventoryList->currentItem());
    }
    
    void Window::removeShoppingItem()
    {
    std::string temp = ((shoppingList->currentItem())->text()).toUtf8().constData();
    ShoppingListObj->removeItem(temp);//removes from database
    shoppingPopupWidget->close();//removes from UI
       delete (shoppingList->currentItem());
    }

void Window::displayRecipeOnClick()
{
// This method will pass the name of the recipe out, and get in the recipe itself for display
//Not Yet Implimented
//        (recipeList->currentItem())->setBackground(Qt::green); //this is just example
    std::string term = ((recipeList->currentItem())->text()).toUtf8().constData();
    std::vector<Recipe> results;
    std::string textConcat;
    for (unsigned int a = 0; a < recipeTestList.size(); a++)
    {
        if (recipeTestList[a].getTitle().find(term) != std::string::npos)
        {
            textConcat += "Recipe Name: ";
            textConcat += recipeTestList[a].getTitle();
            textConcat += "\nCuisine Type: ";
            textConcat += recipeTestList[a].getCuisineType();
            textConcat += "\nPrep Time: ";
            textConcat += std::to_string(recipeTestList[a].getPrepTime());
            textConcat += "\nCook Time: ";
            textConcat += std::to_string(recipeTestList[a].getCookTime());
            recipeText->setPlainText(QString::fromStdString(textConcat));
        }
    }
//    recipeText->setPlainText((results.front()).getTitle());
    
}


//Reserved for testing functions*******************************************************

void Window::testFillRecipe()
{
    for(int i = 0; i != 40; i++)
    {
        recipeList->addItem("Recipe " + QString::number(i));
    }
}

void Window::testFillInventory()
{
    for(int i = 0; i != 40; i++)
    {
        inventoryList->addItem("Item " + QString::number(i));
    }
}

void Window::testFillShopping()
{
    for(int i = 0; i != 40; i++)
    {
        shoppingList->addItem("Shopping Item " + QString::number(i));
    }
}

void Window::testRealRecipeList()
{
//    recipeTestList = new std::vector<Recipe>;
        
}
