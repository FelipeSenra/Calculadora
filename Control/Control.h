#ifndef CONTROL_H
#define CONTROLR_H
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
