#include "configdialog.h"
#include <QVBoxLayout>
#include <QSpinBox>
#include <QPushButton>
#include <QLabel>

ConfigDialog::ConfigDialog(QWidget *parent) : QDialog(parent) {
    auto layout = new QVBoxLayout(this);

    intervalBox = new QSpinBox;
    intervalBox->setRange(1000, 60000);
    intervalBox->setValue(45000);

    durationBox = new QSpinBox;
    durationBox->setRange(1000, 30000);
    durationBox->setValue(3000);

    auto saveBtn = new QPushButton("Save");

    layout->addWidget(new QLabel("Interval (ms):"));
    layout->addWidget(intervalBox);
    layout->addWidget(new QLabel("Duration (ms):"));
    layout->addWidget(durationBox);
    layout->addWidget(saveBtn);

    connect(saveBtn, &QPushButton::clicked, this, [=]() {
        emit settingsChanged(intervalBox->value(), durationBox->value());
        close();
    });
}
