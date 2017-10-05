#include "MainWindow.h"

#include <QFileDialog>

MainWindow::MainWindow() {
    setupUi(this);

    for (int reg = 0; reg < Processor::REG_COUNT; ++reg) {
        getReg(reg)->setName(QString("R%1").arg(reg, 2, 10, QLatin1Char('0')));
    }

    updateUi();
    IOManager::set(this);

    show();
}

void MainWindow::updateUi() {
    for (int address = 0; address < Processor::MEM_SIZE; ++address) {
        int row = address >> 5;
        int col = address & ((1 << 5) - 1);
        QTableWidgetItem* item = new QTableWidgetItem();
        if (address == pro.commandOffset || address == (pro.commandOffset + 1)%Processor::MEM_SIZE) {
            item->setBackground(QColor(255, 64, 255));
        } else if (pro.memoryRead.contains(address)) {
            item->setBackground(QColor(64, 255, 64));
        } else if (pro.memoryWrite.contains(address)) {
            item->setBackground(QColor(255, 64, 64));
        }
        QString text = QString("%1").arg(static_cast<uint8_t>(pro.getMem(static_cast<uint8_t>(address))), 2, 16, QLatin1Char('0'));
        item->setText(text);
        memoryTable->setItem(row, col, item);
    }
    for (int reg = 0; reg < Processor::REG_COUNT; ++reg) {
        QColor color = Qt::black;
        if (pro.registersRead.contains(reg)) {
            color = QColor(0, 255, 0);
        } else if (pro.registersWrite.contains(reg)) {
            color = QColor(255, 0, 0);
        }
        getReg(reg)->setValue(static_cast<uint8_t>(pro.getReg(static_cast<uint8_t>(reg))), color);
    }
}

RegisterWidget* MainWindow::getReg(int reg) {
    QString name = QString("widgetR%1").arg(reg, 1, 16);
    return findChild<RegisterWidget*>(name);
}

void MainWindow::on_loadButton_clicked() {
    QString path = QFileDialog::getOpenFileName(this, "Load memory contents", QString(), "Text files (*.txt);;All files (*.*)");
    if (path.isNull()) {
        return;
    }
    pro.load(path.toUtf8().data());
    updateUi();
}

void MainWindow::writeOutput(int8_t value) {
    if (value > 0) {
        char c = value;
        textOutput->setPlainText(textOutput->toPlainText() + QString("%1").arg(c));
    }
}

int8_t MainWindow::readInput() {
    // TODO
    return ' ';
}

void MainWindow::on_stepButton_clicked() {
    try {
        pro.step();
    } catch (const DecodeException& e) {
        textOutput->appendPlainText(QString("*** %1\n").arg(e.getMsg()));
    }
    updateUi();
}
