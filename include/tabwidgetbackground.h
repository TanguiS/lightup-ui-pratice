#ifndef TABWIDGETBACKGROUND_H
#define TABWIDGETBACKGROUND_H

#include <QTabWidget>

class TabWidgetBackground : public QTabWidget {
public:
    TabWidgetBackground(QWidget *parent = nullptr);

    // QWidget interface
protected:
    void paintEvent(QPaintEvent *event) override;
};

#endif // TABWIDGETBACKGROUND_H
