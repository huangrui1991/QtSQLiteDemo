#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QFileDialog>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QStringListModel>
#include <QTableView>
#include <QListView>
#include <QModelIndex>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString dbFilePath = QFileDialog::getOpenFileName(this,"select a db file");
    if(!dbFilePath.isEmpty())
        LoadSqlFile(dbFilePath);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::LoadSqlFile(QString &dbFile)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dbFile);
    bool isopen = db.open();
    if (!isopen)
    {
        std::cout <<"open database failed!"<<std::endl;
        return;
    }
    QStringListModel* lModel = new QStringListModel(db.tables());
    ui->listView->setModel(lModel);

    QSqlTableModel* TModel = new QSqlTableModel(this,db);
    ui->tableView->setModel(TModel);

}

void MainWindow::on_listView_clicked(const QModelIndex &index)
{
        qobject_cast<QSqlTableModel *>(ui->tableView->model())->setTable(ui->listView->model()->data(index).toString());
        qobject_cast<QSqlTableModel *>(ui->tableView->model())->select();
}
