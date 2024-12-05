#ifndef FILEIO_H
#define FILEIO_H

#include <QFile>

class FileIO
{
public:
    FileIO();
    bool WriteToFile(QString filename, QString data, bool clearFile = false);
    bool ReadFromFile(QString filename);

    bool WriteToJSONFile(QString filename, QJsonObject json_object);
    bool ReadFromJSONFile(QString filename);

    bool SaveDialogueToJSON(QString filename, QStringList dialogueList);

};

#endif // FILEIO_H
