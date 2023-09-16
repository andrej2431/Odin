#ifndef DEVICELABEL_H
#define DEVICELABEL_H

#include <QLabel>
#include <QMouseEvent>

class DeviceLabel : public QLabel
{
    Q_OBJECT
public:
    explicit DeviceLabel(QWidget *parent = nullptr);

    explicit DeviceLabel(std::string text = "", QWidget *parent = nullptr);


protected:
    void paintEvent(QPaintEvent *event) override;

signals:
    void labelClicked();

protected:
    void mousePressEvent(QMouseEvent* event) override;
};

Q_DECLARE_METATYPE(DeviceLabel*)
Q_DECLARE_METATYPE(const DeviceLabel*)

#endif // DEVICELABEL_H
