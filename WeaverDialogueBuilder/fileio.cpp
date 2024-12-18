#include "fileio.h"
#include "qdebug.h"

#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>

FileIO::FileIO()
{}

bool FileIO::WriteToFile(QString filename, QString data, bool clearFile)
{
    QFile file(filename);
    if (!file.open(clearFile ? QIODevice::WriteOnly | QIODevice::Text : QIODevice::Append | QIODevice::Text))
    {
        qCritical() << file.errorString();
        return false;
    }

    QTextStream stream(&file);
    stream << data << "\n";

    file.close();
    return true;
}

bool FileIO::ReadFromFile(QString filename)
{
    QFile file(filename);
    if (!file.exists())
    {
        qCritical() << "File not found!";
        return false;
    }

    if (!file.open(QIODevice::ReadOnly))
    {
        qCritical() << file.errorString();
        return false;
    }

    QTextStream stream(&file);
    while(!stream.atEnd())
    {
        QString line = stream.readLine();
        qInfo() << line;
    }

    return true;
}

bool FileIO::WriteToJSONFile(QString filename, QJsonObject json_object)
{
    QJsonDocument jsonDoc(json_object);

    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qCritical() << file.errorString();
        return false;
    }

    file.write(jsonDoc.toJson());
    file.close();
    return true;
}

bool FileIO::ReadFromJSONFile(QString filename)
{
    QFile file(filename);
    if (!file.exists())
    {
        qCritical() << "File not found: " + filename;
        return false;
    }

    if (!file.open(QIODevice::ReadOnly))
    {
        qCritical() << file.errorString();
        return false;
    }

    QTextStream stream(&file);
    QString jsonString;
    jsonString = stream.readAll();
    file.close();

    QByteArray jsonBytes = jsonString.toLocal8Bit();

    auto jsonDoc = QJsonDocument::fromJson(jsonBytes);
    if (jsonDoc.isNull())
    {
        qDebug() << "Failed to create JSON doc";
        return false;
    }

    QJsonObject jsonObj = jsonDoc.object();
    if (jsonObj.isEmpty())
    {
        qDebug() << "JSON object is empty";
        return false;
    }

    QVariantMap jsonMap = jsonObj.toVariantMap();
    return true;
}

bool FileIO::SaveDialogueToJSON(QString filename, QVector<QPair<QString, QVector<QString>>> dialogueList)
{
    QJsonArray jsonArray;


    for (const auto &pair : dialogueList)
    {
        QJsonObject jsonObject;
        jsonObject.insert(pair.first, QJsonArray::fromStringList(QList<QString>::fromVector(pair.second)));
        jsonArray.append(jsonObject);
    }

    QJsonDocument jsonDoc(jsonArray);

    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly))
    {
        qCritical() << "Could not open file for writing: " << file.errorString();
        return false;
    }

    file.write(jsonDoc.toJson());
    file.close();
    return true;
}
