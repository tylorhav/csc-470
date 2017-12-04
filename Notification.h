//Notification.h

#ifndef NOTIFICATION_H
#define NOTIFICATION_H

#include <string>

class  {

 private:
    std::string title;
    std::string details;
    
 public:
    std::string getTitle();
    
    std::string getDetails();

    void setTitle(std::string title);

    void setDetails(std::string details);
  
};

#endif
