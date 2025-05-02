#ifndef QUOTEDISPLAY_H
#define QUOTEDISPLAY_H
#pragma once
#include <QWidget>
#include <QLabel>
#include <QTimer>

class QuoteDisplay : public QWidget {
    Q_OBJECT
public:
    QuoteDisplay();

    void showQuote(const QString &text, int durationMs);

private:
    QLabel *label;
    QTimer *hideTimer;
};

#endif // QUOTEDISPLAY_H
