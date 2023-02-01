#include "controller.h"

bool sfleta_::Controller::IsCorrectExpression(const std::string& inputStr) {
  return model->IsNormalInputString(inputStr);
}

void sfleta_::Controller::SetInputString(const std::string& inputStr) {
  model->SetInputString(inputStr);
}

void sfleta_::Controller::SetX(double x) { model->SetX(x); }

double sfleta_::Controller::GetResult() { return model->GetResult(); }

double sfleta_::Controller::GetResultCreditCalc(double totalAmount, double period,
                                            double percentageRate, int mode) {
  return model->CreditCalc(totalAmount, period, percentageRate, mode);
}
