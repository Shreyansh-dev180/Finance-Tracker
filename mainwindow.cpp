#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDate>
#include<QTimer>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //open app with the dashboard page by default
    ui->stackedWidget->setCurrentIndex(1);

    //keep both done labels hidden all time by default
    ui->Done_label_ep->hide();
    ui->Done_label_setting_page->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}
//redirect to homepage or default page
void MainWindow::on_pushButton_3_clicked() //home button
{
    ui->stackedWidget->setCurrentIndex(1);
}

//automatically redirect to expense page and time bar filled automatically
void MainWindow::on_pushButton_clicked() //Add expense button
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->Date_bar->setText(QDate::currentDate().toString("dd-MM-yyyy"));
}


void MainWindow::on_pushButton_7_clicked() //add button
{   //checking if all data is filled
    if(ui->Expense_rbar->text().isEmpty() || ui->Amount_bar->text().isEmpty()){
        return;
    }
    //storing the data in our struct Expense;
    current_expense.reason = ui->Expense_rbar->text();
    current_expense.date = ui->Date_bar->text();
    current_expense.amount = ui->Amount_bar->text().toInt();

    History.push_back(current_expense);
    ui->Done_label_ep->show();

    //clearing all bars for next input after add button clicked and data saved;
    ui->Expense_rbar->clear();
    ui->Amount_bar->clear();

    //a five second timer after that the done label hides automatically
    QTimer::singleShot(5000, this,[this](){
        ui->Done_label_ep->hide();
    });
}

//after pressing cancel clear the filled data in bars at expense page
void MainWindow::on_pushButton_8_clicked() //cancel button
{
    ui->Expense_rbar->clear();
    ui->Amount_bar->clear();
}

//upper bar delete section button clicked then redirect there
void MainWindow::on_pushButton_4_clicked() //delete button
{
    ui->stackedWidget->setCurrentIndex(3);
}


void MainWindow::on_pushButton_6_clicked() //confirm button in warning page
{
    History.clear();
    ui->Done_label_setting_page->show();

    QTimer::singleShot(5000, this,[this](){
        ui->Done_label_setting_page->show();
    });


}

//warining page(settingpage)
void MainWindow::on_pushButton_5_clicked() //(delete,clearing data) cancel button then send to homepage
{
    ui->stackedWidget->setCurrentIndex(1);
}

//add a indicator for pressing cancel button in expense page also and then graph page work start;