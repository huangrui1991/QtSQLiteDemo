#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}
class QModelIndex;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
//    void tableChanged(QModelIndex index);

    void on_listView_clicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    void LoadSqlFile(QString &dbFile);
};

#endif // MAINWINDOW_H
