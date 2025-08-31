#include "MainWindow.h"

#include "SettingsHandler.h"

MainWindow::MainWindow(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	ui.frameScore->setVisible(false);
	ui.frameReturn->setVisible(false);
	ui.frameDots->setVisible(false);
	connect(ui.buttonPlay, &QPushButton::clicked, this, &MainWindow::clickedPlay);
	connect(ui.buttonSettings, &QPushButton::clicked, this, &MainWindow::clickedSettings);
	connect(ui.buttonExit, &QPushButton::clicked, this, &MainWindow::clickedExit);
	connect(ui.buttonReturn, &QPushButton::clicked, this, &MainWindow::clickedReturn);
	connect(&timerClicker, &QTimer::timeout, this, &MainWindow::timerTimeout);

	set = new SettingsWindow(this);
}

MainWindow::~MainWindow()
{
	delete set;
}

void MainWindow::clickedExit()
{
	QApplication::quit();
}

void MainWindow::clickedPlay()
{
	ui.frameButtons->setVisible(false);
	ui.frameScore->setVisible(true);
	ui.progressBarTime->setValue(0);
	ui.labelScore->setText("0");
	ui.frameDots->setVisible(true);

	dotSize = SettingsHandler::get().getSetting(SettingTypes::dotSize);
	tickInterval = SettingsHandler::get().getSetting(SettingTypes::interval);
	time = SettingsHandler::get().getSetting(SettingTypes::time);
	maxTick = time * 1000 / tickInterval;
	tickCounter = 0;
	score = 0;
	timerClicker.setInterval(tickInterval);
	timerClicker.start();
}

void MainWindow::clickedSettings()
{
	set->show();
	this->hide();
}

void MainWindow::clickedReturn()
{
	ui.frameReturn->setVisible(false);
	ui.frameButtons->setVisible(true);
}

void MainWindow::clickedDot()
{
	++score;
	ui.labelScore->setText(QString::number(score));
	delete sender();
}

void MainWindow::timerTimeout()
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

void MainWindow::endClicker()
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

void MainWindow::spawnDot()
{
	auto dot = new QPushButton(ui.frameDots);
	int X = QRandomGenerator::global()->bounded(dotSize, ui.frameDots->width() - dotSize);
	int Y = QRandomGenerator::global()->bounded(dotSize, ui.frameDots->height() - dotSize);
	dot->setGeometry(X, Y, dotSize, dotSize);
	dot->setStyleSheet(QString("border-radius: %1px; background-color: rgb(217, 2, 255)").arg(dotSize / 2));
	connect(dot, &QPushButton::clicked, this, &MainWindow::clickedDot);
	dot->show();
}
