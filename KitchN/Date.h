// Date.h

#ifndef DATE_H
#define DATE_H


class Date {

 private:
  int day;
  int month;
  int year;

 public:
  void setDay(int day);
  void setMonth(int month);
  void setYear(int year);

  Date(int day, int month, int year);
  int getDay();
  int getMonth();
  int getYear();

 
};

#endif
