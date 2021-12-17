#include "main_processing.h"

Main_processing::Main_processing(QObject *parent) : QObject(parent)
{

}

void Main_processing::runRP(QStringList files)
{

    read_data(files); // Чтение файлов

}

void Main_processing::read_data(QStringList files)
{

}
