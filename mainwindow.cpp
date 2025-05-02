#include "mainwindow.h"
#include <QMenuBar>
#include <QAction>
#include <cstdlib>
#include <ctime>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    quoteDisplay = new QuoteDisplay();
    configDialog = new ConfigDialog(this);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::showQuote);
    timer->start(interval);

    auto configAction = new QAction("Settings", this);
    menuBar()->addAction(configAction);
    connect(configAction, &QAction::triggered, this, &MainWindow::openConfig);

    connect(configDialog, &ConfigDialog::settingsChanged, this, [&](int newInterval, int newDuration){
        interval = newInterval;
        duration = newDuration;
        timer->start(interval);
    });

    setWindowTitle("WorthRunner");
    resize(400, 200);

    std::srand(static_cast<unsigned int>(std::time(nullptr)));
}

void MainWindow::showQuote() {
    static const char* const quotes[] = {
        "Stay hungry, stay foolish.",
        "If you're a guy and you're having a bad day just remember no one really cares",
        "Life is so damn short. For f***’s sake, just do what makes you happy.",
        "Waste no more time arguing what a good man should be. Be one.",
        "You aren’t nervous about the performance, you’re nervous about the results.",
        "A young man without ambition is an old man waiting to be.",
        "Don't pursue love, affection, or attention that isn't freely given.",
        "Don’t prioritize someone who sees you as an option.",
        "If you know yourself better, you’re lucky enough to face disappointment.",
        "All sins are attempts to fill voids."
    };

    int count = sizeof(quotes) / sizeof(quotes[0]);
    int index = std::rand() % count;
    quoteDisplay->showQuote(quotes[index], duration);
}

void MainWindow::openConfig() {
    configDialog->show();
}
