//Notification.h

#ifndef NOTIFICATION_H
#define NOTIFICATION_H

#include <string>

class  {

 private:
    std::string title;
    std::string details;
    
 public:
    std::string Notification::getTitle();
    
    std::string Notification::getDetails();

    void Notification::setTitle(std::string title);

    void Notification::setDetails(std::string details);
  
};

#endif
