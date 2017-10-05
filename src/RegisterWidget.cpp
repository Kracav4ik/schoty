#include "RegisterWidget.h"

RegisterWidget::RegisterWidget(QWidget* parent)
    : QFrame(parent)
{
    setupUi(this);
}

void RegisterWidget::setName(const QString& name) {
    nameLabel->setText(name);
}

void RegisterWidget::setValue(uint8_t val) {
    valueLabel->setText(QString("%1").arg(val, 2, 16, QLatin1Char('0')));
}
