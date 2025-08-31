#include "SettingsHandler.h"

SettingsHandler::SettingsHandler(QObject* parent)
	: QObject(parent)
{
}

SettingsHandler& SettingsHandler::get()
{
	static SettingsHandler instance;
	return instance;
}

void SettingsHandler::setSetting(SettingTypes type, int value)
{
	getSettings().setValue(getSettingName(type), value);
}

int SettingsHandler::getSetting(SettingTypes type)
{
	return getSettings().value(getSettingName(type), getDefaultValue(type)).toInt();
}

int SettingsHandler::getDefaultValue(SettingTypes type)
{
	switch (type)
	{
	case SettingTypes::dotSize:
		return 20;
	case SettingTypes::interval:
		return 500;
	default:
		return 10;
	}
}

QString SettingsHandler::getSettingName(SettingTypes type)
{
	switch (type)
	{
	case SettingTypes::dotSize:
		return "dotSize";
	case SettingTypes::interval:
		return "tickInterval";
	default:
		return "time";
	}
}

QSettings SettingsHandler::getSettings()
{
	return QSettings("MichalBan", "qt-clicker");
}
