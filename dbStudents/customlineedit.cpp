#include "customlineedit.h"

CustomLineEdit::CustomLineEdit(QWidget *parent) : QLineEdit(parent)
{
    setInputMask("+375-00-000-00-00");
}

void CustomLineEdit::mousePressEvent(QMouseEvent *event)
{
    QLineEdit::mousePressEvent(event);
    setCursorPosition(5);
}
