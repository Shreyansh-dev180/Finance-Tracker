#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDate>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(1);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->Date_bar->setText(QDate::currentDate().toString("dd-MM-yyyy"));
}


void MainWindow::on_pushButton_7_clicked()
{
    if(ui->Expense_rbar->text().isEmpty() || ui->Amount_bar->text().isEmpty()){
        return;
    }

    current_expense.reason = ui->Expense_rbar->text();
    current_expense.date = ui->Date_bar->text();
    current_expense.amount = ui->Amount_bar->text().toInt();

    History.push_back(current_expense);
}


void MainWindow::on_pushButton_8_clicked()
{
    ui->Expense_rbar->clear();
    ui->Amount_bar->clear();
}

