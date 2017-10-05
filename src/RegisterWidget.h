#pragma once

#include "ui_register.h"
#include <QFrame>

class RegisterWidget : public QFrame, private Ui::RegisterWidget {
Q_OBJECT
public:
    explicit RegisterWidget(QWidget* parent);

    void setName(const QString& name);
    void setValue(uint8_t val, const QColor& color);
};
