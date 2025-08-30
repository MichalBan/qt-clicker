#include "SettingsWindow.h"

SettingsWindow::SettingsWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	connect(ui.buttonBack, &QPushButton::clicked, this, &SettingsWindow::clickedBack);
}

SettingsWindow::~SettingsWindow()
{}

void SettingsWindow::clickedBack()
{
	this->hide();
	static_cast<QMainWindow*>(parent())->show();
}


