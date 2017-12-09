//ShoppingList.cpp
#include "Includes.h"

using std::vector;
using std::string;
//using std::algorithm;

vector<string> items;

vector<string> ShoppingList::getItems() {
	return items;
}

void ShoppingList::addItem(string item) {
	items.push_back(item);
}

void ShoppingList::removeItem(string item) {
	items.erase(std::remove(items.begin(), items.end(), item), items.end());
}
