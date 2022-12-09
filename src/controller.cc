#include "controller.h"

bool s21::Controller::IsCorrectExpression(const std::string& inputStr) {
  return model->IsNormalInputString(inputStr);
}

void s21::Controller::SetInputString(const std::string& inputStr) {
  model->SetInputString(inputStr);
}

void s21::Controller::SetX(double x) { model->SetX(x); }

double s21::Controller::GetResult() { return model->GetResult(); }

double s21::Controller::GetResultCreditCalc(double totalAmount, double period,
                                            double percentageRate, int mode) {
  return model->CreditCalc(totalAmount, period, percentageRate, mode);
}
