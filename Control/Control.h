#ifndef CONTROL_H
#define CONTROL_H "Control.h"
#include <string>



namespace controlens{



class Control{
 public:
  static Control getInstance();
  void enablePrint();
  void disablePrint();
  bool ToPrint();
  Control();
 private:
  static Control *instance;
  bool toPrint;

};

enum ERROCT{
STRING,
CORE
};
}
#endif
