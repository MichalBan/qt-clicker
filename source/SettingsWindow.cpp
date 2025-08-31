#include "SettingsWindow.h"
#include "SettingsHandler.h"

SettingsWindow::SettingsWindow(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	connect(ui.buttonBack, &QPushButton::clicked, this, &SettingsWindow::clickedBack);
	connect(ui.sliderDotSize, &QSlider::sliderMoved, this, [this](int value)
	{
		updateLabel(SettingTypes::dotSize, value);
	});
	connect(ui.sliderDotSize, &QSlider::sliderReleased, this, [this]
	{
		SettingsHandler::get().setSetting(SettingTypes::dotSize, ui.sliderDotSize->value());
	});
	connect(ui.sliderInterval, &QSlider::sliderMoved, this, [this](int value)
	{
		updateLabel(SettingTypes::interval, value);
	});
	connect(ui.sliderInterval, &QSlider::sliderReleased, this, [this]
	{
		SettingsHandler::get().setSetting(SettingTypes::interval, ui.sliderInterval->value());
	});
	connect(ui.sliderTime, &QSlider::sliderMoved, this, [this](int value)
	{
		updateLabel(SettingTypes::time, value);
	});
	connect(ui.sliderTime, &QSlider::sliderReleased, this, [this]
	{
		SettingsHandler::get().setSetting(SettingTypes::time, ui.sliderTime->value());
	});
}

void SettingsWindow::showEvent(QShowEvent* event)
{
	QMainWindow::showEvent(event);

	for (int i = 0; i < int(SettingTypes::num); ++i)
	{
		updateLabel(SettingTypes(i), SettingsHandler::get().getSetting(SettingTypes(i)));
		updateSlider(SettingTypes(i), SettingsHandler::get().getSetting(SettingTypes(i)));
	}
}

void SettingsWindow::clickedBack()
{
	this->hide();
	static_cast<QMainWindow*>(parent())->show();
}

void SettingsWindow::updateLabel(SettingTypes setting, int value)
{
	QLabel* label;
	QString format;
	switch (setting)
	{
	case SettingTypes::dotSize:
		label = ui.labelDotSize;
		format = "%1px";
		break;
	case SettingTypes::interval:
		label = ui.labelInterval;
		format = "%1ms";
		break;
	default:
		label = ui.labelTime;
		format = "%1s";
		break;
	}
	label->setText(format.arg(value));
}

void SettingsWindow::updateSlider(SettingTypes setting, int value)
{
	QSlider* slider;
	switch (setting)
	{
	case SettingTypes::dotSize:
		slider = ui.sliderDotSize;
		break;
	case SettingTypes::interval:
		slider = ui.sliderInterval;
		break;
	default:
		slider = ui.sliderTime;
		break;
	}
	slider->setValue(value);
}
