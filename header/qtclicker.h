#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_qtclicker.h"
#include "settings.h"

class qtclicker : public QMainWindow
{
    Q_OBJECT

public:
    qtclicker(QWidget *parent = nullptr);
    ~qtclicker();

private:
	// button events
    void clickedPlay();
    void clickedSettings();
    void clickedExit();
    void clickedReturn();
    void clickedDot();
    // timer events
    void timerTimeout();
    // helper methods
    void endClicker();
    void spawnDot();

	// variables
    int tickCounter;
    int maxTick;
    int score;
    QTimer timerClicker;
    //options
    int dotSize = 20;
    int tickInterval = 500;
    int time = 10;
    // UI
    settings* set;
    Ui::qtclickerClass ui;
};

