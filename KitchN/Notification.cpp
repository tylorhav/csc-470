//Notification.cpp

#include <string>
#include "Includes.h"

using std::string;


    string Notification::getTitle() {
        return title;
    }
    
    string Notification::getDetails() {
        return details;
    }

    void Notification::setTitle(string title) {
        this->title = title;
    }

    void Notification::setDetails(string details) {
        this->details = details;
    }

