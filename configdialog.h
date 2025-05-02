#ifndef CONFIGDIALOG_H
#define CONFIGDIALOG_H

#pragma once
#include <QDialog>

class QSpinBox;

class ConfigDialog : public QDialog {
    Q_OBJECT
public:
    ConfigDialog(QWidget *parent = nullptr);

signals:
    void settingsChanged(int interval, int duration);

private:
    QSpinBox *intervalBox;
    QSpinBox *durationBox;
};

#endif // CONFIGDIALOG_H
