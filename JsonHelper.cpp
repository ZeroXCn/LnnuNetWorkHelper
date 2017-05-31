#include "JsonHelper.h"

QVariantMap JsonHelper::fromJson(QString content)
{
	QVariantMap resultmap;
	QJsonParseError error;
	QJsonDocument jsonDocument = QJsonDocument::fromJson(content.toUtf8(), &error);
	if (error.error == QJsonParseError::NoError) {
		if (!(jsonDocument.isNull() || jsonDocument.isEmpty())) {
			if (jsonDocument.isObject()) {
				resultmap = jsonDocument.toVariant().toMap();
			}
			else if (jsonDocument.isArray()) {
				resultmap = jsonDocument.toVariant().toMap();
			}
		}
	}
	else {
//		qFatal(error.errorString().toUtf8().constData());
		return resultmap;
	}
	return resultmap;
}
