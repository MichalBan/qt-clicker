#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_qtclicker.h"

class qtclicker : public QMainWindow
{
    Q_OBJECT

public:
    qtclicker(QWidget *parent = nullptr);
    ~qtclicker();

private:
    void clickedExit();
    void clickedGo1();
    void clickedReturn();
    void timerTimeout();
    void endClicker();

    int tickCounter;
    int score;
    QTimer timerClicker;
    Ui::qtclickerClass ui;

    static constexpr int maxTick = 10;
};

