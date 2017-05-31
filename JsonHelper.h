#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonValue>
#include <QVariantMap>

#ifndef JSONHELPER_H
#define JSONHELPER_H

class JsonHelper{

public:
	static QVariantMap fromJson(QString);

};

#endif