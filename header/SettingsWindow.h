#pragma once

#include "SettingsHandler.h"
#include "stdafx.h" 
#include "ui_SettingsWindow.h"

class SettingsWindow : public QMainWindow
{
	Q_OBJECT

public:
	SettingsWindow(QWidget *parent = nullptr);

private:
	// events
	void showEvent(QShowEvent* event) override;
	void clickedBack();
	// helper methods
	void updateLabel(SettingTypes setting, int value);
	void updateSlider(SettingTypes setting, int value);

	Ui::settingsClass ui;
};
