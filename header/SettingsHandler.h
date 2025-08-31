#pragma once

#include <QObject>

enum class SettingTypes : uint8_t
{
	dotSize,
	interval,
	time,
	num
};

class SettingsHandler  : public QObject
{
	Q_OBJECT

public:
	// singleton pattern
	static SettingsHandler& get();
	SettingsHandler(SettingsHandler const&) = delete;
	void operator=(SettingsHandler const&) = delete;
	// settings handling
	void setSetting(SettingTypes type, int value);
	int getSetting(SettingTypes type);

private:
	// helper methods
	int getDefaultValue(SettingTypes type);
	QString getSettingName(SettingTypes type);
	QSettings getSettings();
	// singleton pattern
	SettingsHandler(QObject *parent = nullptr);
};

