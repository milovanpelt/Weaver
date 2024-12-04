#include "fileio.h"
#include "qdebug.h"

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
