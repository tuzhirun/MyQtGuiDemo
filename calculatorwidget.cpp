#include "calculatorwidget.h"

CalculatorWidget::CalculatorWidget(QWidget *parent) : QWidget(parent)
{
    setUpUi();
    initConnect();
}

void CalculatorWidget::setUpUi()
{
    QFont font;
    font.setPointSize(16);
    this->setStyleSheet("QPushButton{font-size :16px;font-family:'Microsoft YaHei UI';}QLineEdit{font-size :16px;font-family:'Microsoft YaHei UI';}");
    setStyleSheet(
                     //正常状态样式
                     "QPushButton{"
                     "background-color:rgba(100,225,100,30);"//背景色（也可以设置图片）
                     "border-style:outset;"                  //边框样式（inset/outset）
                     "border-width:4px;"                     //边框宽度像素
                     "border-radius:10px;"                   //边框圆角半径像素
                     "border-color:rgba(255,255,255,30);"    //边框颜色
                     "font:bold 16px;"                       //字体，字体大小
                     "color:rgba(0,0,0,100);"                //字体颜色
                     "padding:6px;"                          //填衬
                     "}"
                     //鼠标按下样式
                     "QPushButton:pressed{"
                     "background-color:rgba(100,255,100,200);"
                     "border-color:rgba(255,255,255,30);"
                     "border-style:inset;"
                     "color:rgba(0,0,0,100);"
                     "}"
                     //鼠标悬停样式
                     "QPushButton:hover{"
                     "background-color:rgba(100,255,100,100);"
                     "border-color:rgba(255,255,255,200);"
                     "color:rgba(0,0,0,200);"
                     "}");
    QVBoxLayout *verticalLayout = new QVBoxLayout(this);

    QGridLayout *gridLayout = new QGridLayout();

    m_pExpressLineEdit = new QLineEdit(this);
    m_pExpressLineEdit->setReadOnly(true);
    m_pExpressLineEdit->setFixedHeight(50);
    m_pExpressLineEdit->setText("0");
    m_pExpressLineEdit->setAlignment(Qt::AlignRight);
    m_pExpressLineEdit->setFont(font);
    verticalLayout->addWidget(m_pExpressLineEdit);
    //verticalLayout->addStretch(1);

    m_pResultLineEdit = new QLineEdit(this);
    m_pResultLineEdit->setReadOnly(true);
    m_pResultLineEdit->setFixedHeight(50);
    m_pResultLineEdit->setText("0");
    m_pResultLineEdit->setAlignment(Qt::AlignRight);
    m_pResultLineEdit->setFont(font);
    verticalLayout->addWidget(m_pResultLineEdit);
    //verticalLayout->addStretch(1);

    m_pReciprocalPushButton = new QPushButton(this);
    m_pReciprocalPushButton->setText(QString::fromLocal8Bit("倒数"));
    gridLayout->addWidget(m_pReciprocalPushButton,0,0);

    m_pBinaryPushButton = new QPushButton(this);
    m_pBinaryPushButton->setText(QString::fromLocal8Bit("二进制"));
    gridLayout->addWidget(m_pBinaryPushButton,0,1);

    m_pDecimalPushButton = new QPushButton(this);
    m_pDecimalPushButton->setText(QString::fromLocal8Bit("十进制"));
    gridLayout->addWidget(m_pDecimalPushButton,0,2);

    m_pBackSpacePushButton = new QPushButton(this);
    m_pBackSpacePushButton->setText(QString::fromLocal8Bit("BackSpace"));
    gridLayout->addWidget(m_pBackSpacePushButton,0,3);

    m_pClearPushButton = new QPushButton(this);
    m_pClearPushButton->setText(QString::fromLocal8Bit("Clear"));
    gridLayout->addWidget(m_pClearPushButton,0,4);

    m_pSinPushButton = new QPushButton(this);
    m_pSinPushButton->setText(QString::fromLocal8Bit("Sin"));
    gridLayout->addWidget(m_pSinPushButton,1,0);

    m_pSevenPushButton = new QPushButton(this);
    m_pSevenPushButton->setText(QString::fromLocal8Bit("7"));
    gridLayout->addWidget(m_pSevenPushButton,1,1);

    m_pEightPushButton = new QPushButton(this);
    m_pEightPushButton->setText(QString::fromLocal8Bit("8"));
    gridLayout->addWidget(m_pEightPushButton,1,2);

    m_pNinePushButton = new QPushButton(this);
    m_pNinePushButton->setText(QString::fromLocal8Bit("9"));
    gridLayout->addWidget(m_pNinePushButton,1,3);

    m_pPlusPushButton = new QPushButton(this);
    m_pPlusPushButton->setText(QString::fromLocal8Bit("+"));
    gridLayout->addWidget(m_pPlusPushButton,1,4);

    m_pCosPushButton = new QPushButton(this);
    m_pCosPushButton->setText(QString::fromLocal8Bit("Cos"));
    gridLayout->addWidget(m_pCosPushButton,2,0);

    m_pFourPushButton = new QPushButton(this);
    m_pFourPushButton->setText(QString::fromLocal8Bit("4"));
    gridLayout->addWidget(m_pFourPushButton,2,1);

    m_pFivePushButton = new QPushButton(this);
    m_pFivePushButton->setText(QString::fromLocal8Bit("5"));
    gridLayout->addWidget(m_pFivePushButton,2,2);

    m_pSixPushButton = new QPushButton(this);
    m_pSixPushButton->setText(QString::fromLocal8Bit("6"));
    gridLayout->addWidget(m_pSixPushButton,2,3);

    m_pMinusPushButton = new QPushButton(this);
    m_pMinusPushButton->setText(QString::fromLocal8Bit("-"));
    gridLayout->addWidget(m_pMinusPushButton,2,4);

    m_pTanPushButton = new QPushButton(this);
    m_pTanPushButton->setText(QString::fromLocal8Bit("tan"));
    gridLayout->addWidget(m_pTanPushButton,3,0);

    m_pOnePushButton = new QPushButton(this);
    m_pOnePushButton->setText(QString::fromLocal8Bit("1"));
    gridLayout->addWidget(m_pOnePushButton,3,1);

    m_pTwoPushButton = new QPushButton(this);
    m_pTwoPushButton->setText(QString::fromLocal8Bit("2"));
    gridLayout->addWidget(m_pTwoPushButton,3,2);

    m_pThreePushButton = new QPushButton(this);
    m_pThreePushButton->setText(QString::fromLocal8Bit("3"));
    gridLayout->addWidget(m_pThreePushButton,3,3);

    m_pMulPushButton = new QPushButton(this);
    m_pMulPushButton->setText(QString::fromLocal8Bit("*"));
    gridLayout->addWidget(m_pMulPushButton,3,4);

    m_pCotPushButton = new QPushButton(this);
    m_pCotPushButton->setText(QString::fromLocal8Bit("Cot"));
    gridLayout->addWidget(m_pCotPushButton,4,0);

    m_pPiePushButton = new QPushButton(this);
    m_pPiePushButton->setText(QString::fromLocal8Bit("Π"));
    gridLayout->addWidget(m_pPiePushButton,4,1);

    m_pZeroPushButton = new QPushButton(this);
    m_pZeroPushButton->setText(QString::fromLocal8Bit("0"));
    gridLayout->addWidget(m_pZeroPushButton,4,2);

    m_pPointPushButton = new QPushButton(this);
    m_pPointPushButton->setText(QString::fromLocal8Bit("."));
    gridLayout->addWidget(m_pPointPushButton,4,3);

    m_pDivPushButton = new QPushButton(this);
    m_pDivPushButton->setText(QString::fromLocal8Bit("/"));
    gridLayout->addWidget(m_pDivPushButton,4,4);

    m_pReversePushButton = new QPushButton(this);
    m_pReversePushButton->setText(QString::fromLocal8Bit("取反"));
    gridLayout->addWidget(m_pReversePushButton,5,0);

    m_pSquarePushButton = new QPushButton(this);
    m_pSquarePushButton->setText(QString::fromLocal8Bit("平方"));
    gridLayout->addWidget(m_pSquarePushButton,5,1);

    m_pSqrtPushButton = new QPushButton(this);
    m_pSqrtPushButton->setText(QString::fromLocal8Bit("开方"));
    gridLayout->addWidget(m_pSqrtPushButton,5,2);

    m_pFactorialPushButton = new QPushButton(this);
    m_pFactorialPushButton->setText(QString::fromLocal8Bit("阶乘"));
    gridLayout->addWidget(m_pFactorialPushButton,5,3);

    m_pModPushButton = new QPushButton(this);
    m_pModPushButton->setText(QString::fromLocal8Bit("取余"));
    gridLayout->addWidget(m_pModPushButton,5,4);

    m_pLeftBracketsPushButton = new QPushButton(this);
    m_pLeftBracketsPushButton->setText(QString::fromLocal8Bit("("));
    gridLayout->addWidget(m_pLeftBracketsPushButton,6,0);

    m_pRightBracketsPushButton = new QPushButton(this);
    m_pRightBracketsPushButton->setText(QString::fromLocal8Bit(")"));
    gridLayout->addWidget(m_pRightBracketsPushButton,6,1);

    m_pAbsPushButton = new QPushButton(this);
    m_pAbsPushButton->setText(QString::fromLocal8Bit("|x|"));
    gridLayout->addWidget(m_pAbsPushButton,6,2);

    m_pIndexPushButton = new QPushButton(this);
    m_pIndexPushButton->setText(QString::fromLocal8Bit("^"));
    gridLayout->addWidget(m_pIndexPushButton,6,3);

    m_pEqualPushButton = new QPushButton(this);
    m_pEqualPushButton->setText(QString::fromLocal8Bit("="));
    gridLayout->addWidget(m_pEqualPushButton,6,4);

    verticalLayout->addLayout(gridLayout);
    verticalLayout->setAlignment(Qt::AlignTop|Qt::AlignCenter);
}

void CalculatorWidget::initConnect()
{
    connect(m_pBackSpacePushButton,&QPushButton::clicked,this,&CalculatorWidget::onBackSpaceBtnClicked);
    connect(m_pClearPushButton,&QPushButton::clicked,this,&CalculatorWidget::onClearBtnClicked);
    connect(m_pOnePushButton,&QPushButton::clicked,this,&CalculatorWidget::onOneBtnClicked);
    connect(m_pPlusPushButton,&QPushButton::clicked,this,&CalculatorWidget::onAddBtnClicked);
}

void CalculatorWidget::onClearBtnClicked()
{
    m_pExpressLineEdit->clear();
    m_pExpressLineEdit->setText("0");
}

void CalculatorWidget::onOneBtnClicked()
{
    if(m_pExpressLineEdit->text()=="0")
    {
        m_pExpressLineEdit->setText("1");
    }
    else
    {
        m_pExpressLineEdit->insert("1");
    }

}

void CalculatorWidget::onAddBtnClicked()
{
    m_pExpressLineEdit->insert("+");
}

void CalculatorWidget::onMinusBtnClicked()
{

}

void CalculatorWidget::onMulBtnClicked()
{

}

void CalculatorWidget::onDivBtnClicked()
{
    
}

void CalculatorWidget::onBackSpaceBtnClicked()
{
    QString res = m_pExpressLineEdit->text();
    if(res.length()==1)
    {
        m_pExpressLineEdit->setText("0");
    }
    else
    {
        res = res.left(res.length()-1);
        m_pExpressLineEdit->setText(res);
    }
}

void CalculatorWidget::onEqualBtnClicked()
{

    QString strExpress = m_pExpressLineEdit->text();
}
