#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSettings>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Load settings
    QSettings settings("settings.ini", QSettings::IniFormat);
    ui->ipLineEdit->setText(settings.value("Xbox/IP").toString());
    ui->usernameLineEdit->setText(settings.value("Xbox/Username").toString());
    ui->passwordLineEdit->setText(settings.value("Xbox/Password").toString());

    // Connect save settings button signal
    connect(ui->saveSettingsButton, &QPushButton::clicked, this, &MainWindow::onSaveSettingsButtonClicked);

    // Connect connect button signal using the new slot name
    connect(ui->connectButton, &QPushButton::clicked, this, &MainWindow::handleConnectButtonClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onSaveSettingsButtonClicked()
{
    // Save settings
    QSettings settings("settings.ini", QSettings::IniFormat);
    settings.setValue("Xbox/IP", ui->ipLineEdit->text());
    settings.setValue("Xbox/Username", ui->usernameLineEdit->text());
    settings.setValue("Xbox/Password", ui->passwordLineEdit->text());

    QMessageBox::information(this, "Settings Saved", "Your settings have been saved successfully.");
}

void MainWindow::handleConnectButtonClicked()
{
    // Example: Display a message box or handle a network connection
    QMessageBox::information(this, "Connection Attempt", "Attempting to connect...");
    // Add your actual connection logic here
}
