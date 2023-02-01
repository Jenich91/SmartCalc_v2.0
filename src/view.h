#ifndef SRC_VIEW_H_
#define SRC_VIEW_H_

#include <QKeyEvent>
#include <QMainWindow>
#include <QToolTip>

#include "controller.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainQT;
}
QT_END_NAMESPACE

namespace sfleta_ {
class View : public QMainWindow {
    Q_OBJECT

 private:
    Ui::MainQT *ui;
    sfleta_::Controller *controller;

    inline bool IsEqualDouble(double x, double y) {
        return std::fabs(x - y) <= std::numeric_limits<double>::epsilon();
    }
    inline bool LessOrEqualDouble(double x, double y) { return IsEqualDouble(x, y) || (x <= y); }

 public:
    explicit View(sfleta_::Controller *c, QWidget *parent = nullptr);
    ~View();

 protected:
    void keyPressEvent(QKeyEvent *event);

 private slots:
    void on_Button_reset_clicked();
    void on_Button_result_clicked();
    void push_button_digit();
    void on_Button_dot_clicked();
    void on_Button_sign_clicked();
    void push_button_operator();
    void push_button_func();

    void on_Button_Graphic_clicked();
    void on_Button_ClearGraph_clicked();
    void showToolTipEnterX();

    void on_lineEdit_x_editingFinished();
    void on_button_calc_credit_clicked();
    void on_button_clear_credit_clicked();
};
}  // namespace sfleta_
#endif  // SRC_VIEW_H_
