#include "MainWindow.h"

MainWindow::MainWindow() {
    setupUi(this);

    updateUi();

    show();
}

void MainWindow::updateUi() {
    for (int address = 0; address < Processor::MEM_SIZE; ++address) {
        int row = address >> 5;
        int col = address & ((1 << 5) - 1);
        QString text = QString("%1").arg(pro.memory[address], 2, 16, QLatin1Char('0'));
        memoryTable->setItem(row, col, new QTableWidgetItem(text));
    }
}
