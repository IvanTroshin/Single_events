#ifndef MAIN_PROCESSING_H
#define MAIN_PROCESSING_H

#include <QObject>
#include <QMainWindow>

class Def_of_time//-------------Структура-----------
{
    public:
        int Event;              // Номер события
        double Time_global;     // Время события
        QList<int> Wire;        // Проволока
        QList<int> Channel;     // Камера
        QList<int> Time_drift;  // Передний или задний фронт сигнала
        QList<int> Signal_duration;     // Длительность сигнала
        int accsident[14][4];           // Сколько событий в каждой камере
        QList<double> NumXY[14][4];     // Координаты точек ионизации 4*y
        QList<double> K_B_Sig[14][3];   // K, B и Sig для каждой камеры
};

class Main_processing : public QObject
{
    Q_OBJECT
public:
    explicit Main_processing(QObject *parent = nullptr);

public slots:
    void runRP(QStringList files);  // запуск для потока

private:
    void start_proc(QStringList files); // начало обработки
    void read_data(Def_of_time& data, QString read_str);  // чтение данных из файла
    void loadShow(); // загрузка вращение элемента

signals:
    void text_to_edit_signal(QString text); // запись в текст эдитор
    void text_to_edit_del_delete(); // Удаление элемента
};

#endif // MAIN_PROCESSING_H
