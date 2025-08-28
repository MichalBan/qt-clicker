#include "stdafx.h"
#include "qtclicker.h"

qtclicker::qtclicker(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	ui.frameScore->setVisible(false);
	ui.frameReturn->setVisible(false);
	connect(ui.buttonExit, &QPushButton::clicked, this, &qtclicker::clickedExit);
	connect(ui.buttonGo1, &QPushButton::clicked, this, &qtclicker::clickedGo1);
	connect(ui.buttonReturn, &QPushButton::clicked, this, &qtclicker::clickedReturn);
}

qtclicker::~qtclicker() = default;

void qtclicker::clickedExit()
{
	exit(0);
}

void qtclicker::clickedGo1()
{
	ui.frameButtons->setVisible(false);
	ui.frameScore->setVisible(true);
	ui.progressBarTime->setValue(0);
	ui.labelScore->setText("0");

	tickCounter = 0;
	score = 0;
	timerClicker.setInterval(1000);
	connect(&timerClicker, &QTimer::timeout, this, &qtclicker::timerTimeout);
	timerClicker.start();
}

void qtclicker::clickedReturn()
{
	ui.frameReturn->setVisible(false);
	ui.frameButtons->setVisible(true);
}

void qtclicker::timerTimeout()
{
	++tickCounter;
	if (tickCounter >= maxTick)
	{
		endClicker();
		return;
	}

	if (QRandomGenerator::global()->generate())
	{
		++score;
	}
	ui.progressBarTime->setValue(tickCounter * 100 / maxTick);
	ui.labelScore->setText(QString::number(score));
}

void qtclicker::endClicker()
{
	ui.frameScore->setVisible(false);
	ui.frameReturn->setVisible(true);
	timerClicker.stop();
}
