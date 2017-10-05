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
        QString text = QString("%1").arg(static_cast<uint8_t>(pro.memory[address]), 2, 16, QLatin1Char('0'));
        memoryTable->setItem(row, col, new QTableWidgetItem(text));
    }
    for (int reg = 0; reg < Processor::REG_COUNT; ++reg) {
        getReg(reg)->setValue(static_cast<uint8_t>(pro.registers[reg]));
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
        textOutput->appendPlainText(QString("%1").arg(c));
    }
}

int8_t MainWindow::readInput() {
    // TODO
    return ' ';
}
