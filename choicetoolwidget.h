#ifndef CHOICETOOLWIDGET_H
#define CHOICETOOLWIDGET_H

#include <QDialog>
#include<QPushButton>
#include<QHBoxLayout>
#include<QVBoxLayout>
#include <QListWidget>
#include <QStackedWidget>
#include"calculatorwidget.h"
#include"tetriswidget.h"
#include"communicatewidget.h"
#include"minesweeperwidget.h"
class ChoiceToolWidget : public QDialog
{
    Q_OBJECT
public:
    explicit ChoiceToolWidget(QWidget *parent = nullptr);
    ~ChoiceToolWidget();
    void setUpUi();
    void initConnect();

private:
    QListWidget *m_pListWidget = nullptr;
    QStackedWidget *m_pStackedWidget = nullptr;

    CalculatorWidget*m_pCalculatorWidget = nullptr;
    TetrisWidget*m_pTetrisWidget = nullptr;
    CommunicateWidget*m_pCommunicateWidget = nullptr;
    MineSweeperWidget*m_pMineSweeperWidget = nullptr;
private slots:
void showWidget();
signals:

};

#endif // CHOICETOOLWIDGET_H
