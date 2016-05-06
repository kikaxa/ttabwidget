#ifndef TTABBAR_H
#define TTABBAR_H

#include <QTabWidget>
#include <QTabBar>
#include <QVector>

class TTabWidget : public QTabWidget
{ //vertical, can temporarily hide tabs. unreserves tabbar space when not visible
public:
    TTabWidget(QWidget *parent = 0) : QTabWidget(parent), doing_stuff(false) { }

    void setTabVisible(int idx, bool visible); //index, including hidden
    int totalCount() { return count() + hidden_idx.size(); }

    QSize minimumSizeHint() const { return QTabWidget::minimumSizeHint() - QSize(0, tabBar()->isVisible() ? 0 : tabBar()->sizeHint().height()); }
    QSize sizeHint() const { return QTabWidget::sizeHint() - QSize(0, tabBar()->isVisible() ? 0 : tabBar()->sizeHint().height()); }

protected:
    void tabInserted(int index);
    void tabRemoved(int index);

    bool doing_stuff;
    QVector<int> hidden_idx;
    QVector<QWidget *> hidden_wid;
    QVector<QPair<QIcon, QString> > hidden_data;
};

#endif
