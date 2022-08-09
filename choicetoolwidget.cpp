#include "choicetoolwidget.h"

ChoiceToolWidget::ChoiceToolWidget(QWidget *parent) : QDialog(parent)
{
    setUpUi();
    initConnect();
}

ChoiceToolWidget::~ChoiceToolWidget()
{

}

void ChoiceToolWidget::setUpUi()
{
    setWindowTitle(QString::fromLocal8Bit("工具窗口"));
    //setFixedSize(800,600);
    setMinimumSize(800,600);
    m_pListWidget = new QListWidget(this);
    m_pListWidget->insertItem(0,QString::fromLocal8Bit("计算器"));
    m_pListWidget->insertItem(1,QString::fromLocal8Bit("俄罗斯方块"));
    m_pListWidget->insertItem(2,QString::fromLocal8Bit("通讯录"));
    m_pListWidget->insertItem(3,QString::fromLocal8Bit("扫雷"));

    m_pCalculatorWidget = new CalculatorWidget();
    m_pCalculatorWidget->setWindowTitle(QString::fromLocal8Bit("计算器"));

    m_pTetrisWidget = new TetrisWidget();
    m_pTetrisWidget->setWindowTitle(QString::fromLocal8Bit("俄罗斯方块"));

    m_pCommunicateWidget = new CommunicateWidget();
    m_pCommunicateWidget->setWindowTitle(QString::fromLocal8Bit("通讯录"));

    m_pMineSweeperWidget = new MineSweeperWidget();
    m_pMineSweeperWidget->setWindowTitle(QString::fromLocal8Bit("扫雷"));

    m_pStackedWidget = new QStackedWidget(this);
    m_pStackedWidget->addWidget(m_pCalculatorWidget);
    m_pStackedWidget->addWidget(m_pTetrisWidget);
    m_pStackedWidget->addWidget(m_pCommunicateWidget);
    m_pStackedWidget->addWidget(m_pMineSweeperWidget);
    m_pStackedWidget->setCurrentIndex(0);

    QHBoxLayout *mainLayout = new QHBoxLayout(this); //对整个对话框进行布局
    mainLayout->setMargin(5); //设置对话框的边距为5
    mainLayout->setSpacing(5); //设置各个控件之间的间距为5
    mainLayout->addWidget(m_pListWidget);
    mainLayout->addWidget(m_pStackedWidget);
    mainLayout->setStretchFactor(m_pListWidget, 1);  //设置list为可伸缩控件
    mainLayout->setStretchFactor(m_pStackedWidget,3);

}

void ChoiceToolWidget::initConnect()
{
    connect(m_pListWidget,SIGNAL(currentRowChanged(int)),m_pStackedWidget,SLOT(setCurrentIndex(int)));
    connect(m_pListWidget,&QListWidget::currentRowChanged,this,&ChoiceToolWidget::showWidget);
}

void ChoiceToolWidget::showWidget()
{
    int nCurrentIndex = m_pStackedWidget->currentIndex();
    switch (nCurrentIndex)
    {
    case 0:
        m_pCalculatorWidget->show();
        break;
    case 1:
        m_pTetrisWidget->show();
        break;
    case 2:
        m_pCommunicateWidget->show();
        break;
    case 3:
        m_pMineSweeperWidget->show();
        break;
    }
}
