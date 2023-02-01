#include <QApplication>
#include "view.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    sfleta_::Model model;
    sfleta_::Controller controller(&model);
    sfleta_::View w(&controller);

    w.show();
    return a.exec();
}
