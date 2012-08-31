#ifndef CONTROL_H
#define CONTROL_H
#include <string>



namespace controlens{



class Control{
 public:
  static Control* getInstance();
  void enablePrint();
  void disablePrint();
  bool ToPrint();
  Control();
  ~Control();
 private:
  static Control *instance;
  bool toPrint;
  static bool instanceFlag;

};

enum ERROCT{
STRING,
CORE
};
}
#endif
