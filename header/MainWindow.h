#pragma once

#include "ui_MainWindow.h"
#include "SettingsWindow.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

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
    int dotSize;
    int tickInterval;
    int time;
    int tickCounter;
    int maxTick;
    int score;
    QTimer timerClicker;
    // UI
    SettingsWindow* set;
    Ui::qtclickerClass ui;
};

