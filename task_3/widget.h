#ifndef WIDGET_H
#define WIDGET_H

#include "deque_linkedlist.h"
#include "deque_vector.h"
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget {
    Q_OBJECT

public:
    Widget(QWidget* parent = nullptr);
    ~Widget();

    static QRegularExpression separator;

private:
    Ui::Widget* ui;

    void loadFile();
    void onTestingOptionChanged();
    void confirmData();
    void reset();
    void exit();
    void popDeque();
    void pushDeque();

    Deque_linkedList<unsigned int> uintDeque_linkedList;
    Deque_linkedList<char> charDeque_linkedList;
    Deque_vector<unsigned int> uintDeque_vector;
    Deque_vector<char> charDeque_vector;

    enum DataVariant {
        UINT_LINKEDLIST,
        CHAR_LINKEDLIST,
        UINT_VECTOR,
        CHAR_VECTOR
    };

    DataVariant dataVariant;
    QString dataString;
};
#endif // WIDGET_H
