#include "quotedisplay.h"
#include <QVBoxLayout>
#include <QPalette>

QuoteDisplay::QuoteDisplay() {
    setWindowFlags(Qt::FramelessWindowHint | Qt::Window);
    setAttribute(Qt::WA_DeleteOnClose, false);
    label = new QLabel("", this);
    label->setAlignment(Qt::AlignCenter);
    label->setStyleSheet("font-size: 32px; color: white;");

    auto layout = new QVBoxLayout(this);
    layout->addWidget(label);

    hideTimer = new QTimer(this);
    connect(hideTimer, &QTimer::timeout, this, &QuoteDisplay::hide);
}

void QuoteDisplay::showQuote(const QString &text, int durationMs) {
    label->setText(text);
    QPalette pal;
    pal.setColor(QPalette::Window, Qt::black);
    setPalette(pal);
    setAutoFillBackground(true);

    showFullScreen();
    hideTimer->start(durationMs);
}
