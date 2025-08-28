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
	// button events
    void clickedExit();
    void clickedGo1();
    void clickedReturn();
    void clickedDot();
    // timer events
    void timerTimeout();
    // helper methods
    void endClicker();
    void spawnDot();

    int tickCounter;
    int score;
    QTimer timerClicker;
    Ui::qtclickerClass ui;

    int dotSize = 20;
    int tickInterval = 500;
    static constexpr int maxTick = 10;
};

