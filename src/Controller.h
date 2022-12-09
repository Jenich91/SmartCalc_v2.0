#ifndef SRC_CONTROLLER_H_
#define SRC_CONTROLLER_H_
#include "model.h"

namespace s21 {
class Controller {
 private:
    Model* model;

 public:
    explicit Controller(Model* m) : model(m) {}

    bool IsCorrectExpression(const std::string& inputStr);
    void SetInputString(const std::string& inputStr);
    void SetX(double x);
    double GetResult();
    double GetResultCreditCalc(double totalAmount, double period, double percentageRate, int mode);
    void Reset() { model->ResetValues(); }
};
}  // namespace s21
// #include "controller.cc"
#endif  // SRC_CONTROLLER_H_
