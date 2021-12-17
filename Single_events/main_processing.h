#ifndef MAIN_PROCESSING_H
#define MAIN_PROCESSING_H

#include <QObject>
#include <QMainWindow>

class Main_processing : public QObject
{
    Q_OBJECT
public:
    explicit Main_processing(QObject *parent = nullptr);

public slots:
    void runRP(QStringList files);

private:
    void read_data(QStringList files);

signals:

};

#endif // MAIN_PROCESSING_H
