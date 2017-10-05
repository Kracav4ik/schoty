#pragma once

#include "Processor.h"

#include <QMainWindow>

#include "ui_main.h"

class MainWindow : public QMainWindow, private Ui::MainWindow {
Q_OBJECT
private:
    Processor pro;

    void updateUi();
    RegisterWidget* getReg(int reg);

public:
    MainWindow();
};
