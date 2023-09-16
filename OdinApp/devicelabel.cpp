#include "devicelabel.h"

#include <QPainter>

DeviceLabel::DeviceLabel(QWidget *parent)
    : QLabel(parent)
{
    setText("RANDOM LABEL");
}

DeviceLabel::DeviceLabel(std::string text, QWidget *parent)
    : QLabel(parent)
{
    setText(QString::fromStdString(text));
    setFixedHeight(75);
    setStyleSheet("padding-left: 20px; padding-right: 20px;");
}

void DeviceLabel::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    painter.fillRect(rect(), Qt::lightGray);

    QLabel::paintEvent(event);
}

void DeviceLabel::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        emit labelClicked(); // Emit the custom signal when left-clicked
    }
}

//void DeviceLabel::clicked(int x, int y){

//}

//void DeviceLabel::mousePressEvent(QMouseEvent* event){

//}
