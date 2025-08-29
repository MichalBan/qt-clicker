#include "stdafx.h"
#include "qtclicker.h"

qtclicker::qtclicker(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	ui.frameScore->setVisible(false);
	ui.frameReturn->setVisible(false);
	ui.frameDots->setVisible(false);
	connect(ui.buttonPlay, &QPushButton::clicked, this, &qtclicker::clickedPlay);
	connect(ui.buttonSettings, &QPushButton::clicked, this, &qtclicker::clickedSettings);
	connect(ui.buttonExit, &QPushButton::clicked, this, &qtclicker::clickedExit);
	connect(ui.buttonReturn, &QPushButton::clicked, this, &qtclicker::clickedReturn);
	connect(&timerClicker, &QTimer::timeout, this, &qtclicker::timerTimeout);

	set = new settings(this);
}

qtclicker::~qtclicker()
{
	delete set;
}

void qtclicker::clickedExit()
{
	QApplication::quit();
}

void qtclicker::clickedPlay()
{
	ui.frameButtons->setVisible(false);
	ui.frameScore->setVisible(true);
	ui.progressBarTime->setValue(0);
	ui.labelScore->setText("0");
	ui.frameDots->setVisible(true);

	maxTick = time * 1000 / tickInterval;
	tickCounter = 0;
	score = 0;
	timerClicker.setInterval(tickInterval);
	timerClicker.start();
}

void qtclicker::clickedSettings()
{
	set->show();
	this->hide();
}

void qtclicker::clickedReturn()
{
	ui.frameReturn->setVisible(false);
	ui.frameButtons->setVisible(true);
}

void qtclicker::clickedDot()
{
	++score;
	ui.labelScore->setText(QString::number(score));
	delete sender();
}

void qtclicker::timerTimeout()
{
	++tickCounter;
	if (tickCounter > maxTick)
	{
		endClicker();
		return;
	}

	spawnDot();
	ui.progressBarTime->setValue(tickCounter * 100 / maxTick);
}

void qtclicker::endClicker()
{
	ui.frameScore->setVisible(false);
	ui.frameReturn->setVisible(true);
	ui.frameDots->setVisible(true);
	for (auto& child : ui.frameDots->children())
	{
		delete child;
	}
	timerClicker.stop();
	ui.labelLastScore->
	   setText(QString("Your Score: %1 / %2").arg(QString::number(score), QString::number(maxTick)));
}

void qtclicker::spawnDot()
{
	auto dot = new QPushButton(ui.frameDots);
	int X = QRandomGenerator::global()->bounded(dotSize, ui.frameDots->width() - dotSize);
	int Y = QRandomGenerator::global()->bounded(dotSize, ui.frameDots->height() - dotSize);
	dot->setGeometry(X, Y, dotSize, dotSize);
	dot->setStyleSheet(QString("border-radius: %1px; background-color: rgb(217, 2, 255)").arg(dotSize / 2));
	connect(dot, &QPushButton::clicked, this, &qtclicker::clickedDot);
	dot->show();
}
