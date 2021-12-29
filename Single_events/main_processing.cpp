#include "main_processing.h"
#include <QWidget>
#include <QObject>
#include <dos.h>
#include <time.h>
#include <QFileInfo>

int read_list = 0;


Main_processing::Main_processing(QObject *parent) : QObject(parent)
{

}

void Main_processing::runRP(QStringList files)
{

//    emit text_to_edit_signal("505");
    start_proc(files); // Чтение файлов

}

void Main_processing::start_proc(QStringList files)
{
    time_t timer1 = time(NULL);

//    emit text_to_edit_signal("X");
//    emit text_to_edit_signal("X");

    for (int i_F = 0; i_F < files.size(); i_F++)
    {

        QString fileway = QFileInfo(files[i_F]).absolutePath();

        QString base_buff = QFileInfo(files[i_F]).baseName();

//        if (file_already_read.contains(base_buff)) // пропустить что уже прочитал
//        {
//            continue;
//        }

//        emit text_to_edit_del_delete();
//        emit text_to_edit_del_delete();
//        if (i_F+1 > 10)
//            emit text_to_edit_del_delete();

//        if (i_F+1 > 100)
//            emit text_to_edit_del_delete();

//        emit text_to_edit_signal(QString::number(i_F+1));
        emit text_to_edit_signal(" ");

        QFile file(files[i_F]);
        if ((file.exists())&&(file.open(QIODevice::ReadOnly)))
        {

            int i_test = 0;
            while(!file.atEnd())
            {
//                if(time(NULL) - timer1 > 0.5)
//                {
//                    loadShow(); // Загрузка
//                    timer1 = time(NULL);
//                }

                Def_of_time data;       // Структура для всех точек ионизации

                // Чтение строки
                QString read_str = QString::fromUtf8(file.readLine());

                if(read_list == i_test)
                {
                    read_list = i_test;
                    read_data(data, read_str);  // Чтение данных

                    emit text_to_edit_signal("\n");

                    QString s = QString::number(data.Event);
                    emit text_to_edit_signal(s);

                    emit text_to_edit_signal("\n");

                    read_list++;
                    break;
                }

                i_test++;

            }

            file.close();
        }
    }

//    emit text_to_edit_signal("\n");
    emit text_to_edit_signal("Finished");

}

int loadShow_n = 0;
void Main_processing::loadShow()
{
    emit text_to_edit_del_delete();
    if (loadShow_n == 0)
    {
        emit text_to_edit_signal("┛");
        loadShow_n++;
    }
    else if (loadShow_n == 1)
    {
        emit text_to_edit_signal("┗");
        loadShow_n++;
    }
    else if (loadShow_n == 2)
    {
        emit text_to_edit_signal("┏");
        loadShow_n++;
    }
    else if (loadShow_n == 3)
    {
        emit text_to_edit_signal("┓");
        loadShow_n = 0;
    }
}

void Main_processing::read_data(Def_of_time& data, QString read_str)
{
    QString numb_str="";                        // Чтение числа
    int i_way = -2;
    int chamber, wire, time_to_front, time_signal; // Камера, проволока, время до заднего фронта, длительность сигнала

//                //------Проверка--------
//                FILE * fi;
//                char nameT[1200] = "";

//                QByteArray ba = fileway.toLocal8Bit();
//                const char *c_str2 = ba.data();

//                strcat(nameT, c_str2);
//                strcat(nameT, "/time_test.txt");

    for (int i_r = 0; i_r < read_str.size(); i_r++)
    {

        if (read_str[i_r] != '\t' && read_str[i_r] != '\n' && read_str[i_r] != '\r')
        {
            numb_str = numb_str + read_str[i_r];
        }
        else if (read_str[i_r] == '\r')
        {
            break;
        }
        else
        {

            if (i_way == -2)
            {
                data.Event = numb_str.toInt();
//                            fi = fopen(nameT, "at");                    //------Проверка--------
//                            fprintf(fi, "\nw%d\t", numb_str.toInt());   //------Проверка--------
//                            fclose(fi);                                 //------Проверка--------
            }

            if (i_way == -1)
            {
                data.Time_global = numb_str.toDouble();
//                            fi = fopen(nameT, "at");                    //------Проверка--------
//                            fprintf(fi, "q%f\t", numb_str.toDouble());  //------Проверка--------
//                            fclose(fi);                                 //------Проверка--------
            }
            if (i_way == 0)
            {
//                            fi = fopen(nameT, "at");                    //------Проверка--------
//                            fprintf(fi, "a%d\t", numb_str.toInt());     //------Проверка--------
//                            fclose(fi);                                 //------Проверка--------
                data.Channel.push_back(numb_str.toInt()/4);                         // Проволока
                data.Wire.push_back(numb_str.toInt()-numb_str.toInt()/4*4);         // Канал
                chamber = numb_str.toInt()/4;
                wire = numb_str.toInt()-numb_str.toInt()/4*4;

            }

            if (i_way == 1)
            {
//                            fi = fopen(nameT, "at");                    //------Проверка--------
//                            fprintf(fi, "b%d\t", numb_str.toInt());     //------Проверка--------
//                            fclose(fi);                                 //------Проверка--------
                data.Time_drift.push_back(5*numb_str.toInt());                      // Время до заднего фронта
                time_to_front = 5*numb_str.toInt();
            }
            if (i_way == 2)
            {
//                            fi = fopen(nameT, "at");                    //------Проверка--------
//                            fprintf(fi, "c%d\t", numb_str.toInt());     //------Проверка--------
//                            fclose(fi);                                 //------Проверка--------
                data.Signal_duration.push_back(5*numb_str.toInt());                 // Длительность сигнала
                time_signal = 5*numb_str.toInt();

                if (time_signal > 10)
                {
                    int time_table = time_to_front + time_signal;
                }

            }

            if (i_way == 3)
            {
//                            fi = fopen(nameT, "at");                    //------Проверка--------
//                            fprintf(fi, "d%d\t", numb_str.toInt());     //------Проверка--------
//                            fclose(fi);                                 //------Проверка--------
                i_way = -1;
            }

            i_way++;
            numb_str="";


        }

    }

}

