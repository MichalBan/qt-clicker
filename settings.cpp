#include "settings.h"

settings::settings(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	connect(ui.buttonBack, &QPushButton::clicked, this, &settings::clickedBack);
}

settings::~settings()
{}

void settings::clickedBack()
{
	this->hide();
	static_cast<QMainWindow*>(parent())->show();
}


