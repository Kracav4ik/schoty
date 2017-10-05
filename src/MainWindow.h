#pragma once

#include "Processor.h"
#include "IOManager.h"

#include <QMainWindow>

#include "ui_main.h"

class MainWindow : public QMainWindow, private Ui::MainWindow, private IOManager {
Q_OBJECT
private:
    Processor pro;

    void updateUi();
    RegisterWidget* getReg(int reg);

    void writeOutput(int8_t value) override;

    int8_t readInput() override;

private slots:
    void on_loadButton_clicked();
    void on_stepButton_clicked();

public:
    MainWindow();
};
