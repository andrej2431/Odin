#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "devicelabel.h"
#include <AudioManager.hpp>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    AudioManager audioManager = AudioManager();
    for(Device& device : audioManager.getDevices()){
        if(device.isInputDevice()){
            ui->inputDeviceLayout->addWidget(new DeviceLabel(device.name()));
        }

        if(device.isOutputDevice()){
            ui->outputDeviceLayout->addWidget(new DeviceLabel(device.name()));
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

