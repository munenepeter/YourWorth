#pragma once
#include <QMainWindow>
#include <QTimer>
#include "quotedisplay.h"
#include "configdialog.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
private slots:
    void showQuote();
    void openConfig();

private:
    QTimer *timer;
    QuoteDisplay *quoteDisplay;
    ConfigDialog *configDialog;
    int interval = 5000; // 5 seconds
    int duration = 3000; // 3 seconds
};
