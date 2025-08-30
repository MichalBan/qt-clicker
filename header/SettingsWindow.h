#pragma once

#include "stdafx.h" 
#include "ui_SettingsWindow.h"

class SettingsWindow : public QMainWindow
{
	Q_OBJECT

public:
	SettingsWindow(QWidget *parent = nullptr);
	~SettingsWindow();

private:
	void clickedBack();

	Ui::settingsClass ui;
};
