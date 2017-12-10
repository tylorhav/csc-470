#include <QtCore>
#include <QtGui>


#include "Includes.h"

KitchNMain *KitchNMainObJ;
ShoppingList *ShoppingListObj;


int main(int argv, char *args[])
{

    KitchNMainObJ = new KitchNMain;
    ShoppingListObj = new ShoppingList;
    QApplication app(argv, args);
    Window window;
    window.show();
    return app.exec();
}
