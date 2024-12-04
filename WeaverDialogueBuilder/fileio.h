#ifndef FILEIO_H
#define FILEIO_H

#include <QFile>

class FileIO
{
public:
    FileIO();
    bool WriteToFile(QString filename, QString data, bool clearFile = false);
};

#endif // FILEIO_H
