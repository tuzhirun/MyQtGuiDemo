#include "registerwidget.h"

/**
* @函数名称：
* @函数功能：
* @创建作者：tuzhirun
* @创建日期：2022-07-30
*/
RegisterWidget::RegisterWidget(ManageGui *pManageGui,QDialog *parent) : QDialog(parent)
{
    m_pManageGui = pManageGui;
    setUpUi();
    initConnect();
}

/**
* @函数名称：
* @函数功能：
* @创建作者：tuzhirun
* @创建日期：2022-07-30
*/
RegisterWidget::~RegisterWidget()
{

}

/**
* @函数名称：
* @函数功能：
* @创建作者：tuzhirun
* @创建日期：2022-07-30
*/
void RegisterWidget::setUpUi()
{
    QFont font;
    font.setFamily("Arial");
    font.setPointSize(14);//字体大小

    //this->setMinimumSize(600, 480);
    this->setWindowTitle(QString::fromLocal8Bit("注册"));

    m_pUserNameLabel = new QLabel(QString::fromLocal8Bit("用户名："), this);
    m_pUserNameLabel->setFixedWidth(100);
    m_pUserNameLabel->setFont(font);

    m_pPassWordLabel = new QLabel(QString::fromLocal8Bit("密码："), this);
    m_pPassWordLabel->setFixedWidth(100);
    m_pPassWordLabel->setFont(font);

    m_pSurePassWordLabel = new QLabel(QString::fromLocal8Bit("确认密码："), this);
    m_pSurePassWordLabel->setFixedWidth(100);
    m_pSurePassWordLabel->setFont(font);

    m_pUserNameLineEdit = new QLineEdit(this);
    m_pUserNameLineEdit->setFixedWidth(200);
    m_pUserNameLineEdit->setFont(font);
    m_pUserNameLineEdit->setAttribute(Qt::WA_InputMethodEnabled, false);

    m_pPassWordLineEdit = new QLineEdit(this);
    m_pPassWordLineEdit->setFixedWidth(200);
    m_pPassWordLineEdit->setFont(font);
    m_pPassWordLineEdit->setEchoMode(QLineEdit::Password);
    m_pPassWordLineEdit->setMaxLength(16);

    m_pSurePassWordLineEdit = new QLineEdit(this);
    m_pSurePassWordLineEdit->setFixedWidth(200);
    m_pSurePassWordLineEdit->setFont(font);
    m_pSurePassWordLineEdit->setMaxLength(16);
    m_pSurePassWordLineEdit->setEchoMode(QLineEdit::Password);

    m_pRegisterButton = new QPushButton(QString::fromLocal8Bit("注册"),this);
    m_pRegisterButton->setFixedWidth(150);
    m_pRegisterButton->setFont(font);

    m_pCancleButton = new QPushButton(QString::fromLocal8Bit("取消"),this);
    m_pCancleButton->setFixedWidth(150);
    m_pCancleButton->setFont(font);

    QHBoxLayout *pHBoxLayout_1 = new QHBoxLayout();
    pHBoxLayout_1->addWidget(m_pUserNameLabel);
    pHBoxLayout_1->addWidget(m_pUserNameLineEdit);

    QHBoxLayout *pHBoxLayout_2 = new QHBoxLayout();
    pHBoxLayout_2->addWidget(m_pPassWordLabel);
    pHBoxLayout_2->addWidget(m_pPassWordLineEdit);

    QHBoxLayout *pHBoxLayout_3 = new QHBoxLayout();
    pHBoxLayout_3->addWidget(m_pSurePassWordLabel);
    pHBoxLayout_3->addWidget(m_pSurePassWordLineEdit);

    QHBoxLayout *pHBoxLayout_4 = new QHBoxLayout();
    pHBoxLayout_4->addWidget(m_pRegisterButton);
    pHBoxLayout_4->addWidget(m_pCancleButton);

    QVBoxLayout *pVBoxLayout = new QVBoxLayout(this);
    pVBoxLayout->addLayout(pHBoxLayout_1);
    pVBoxLayout->addLayout(pHBoxLayout_2);
    pVBoxLayout->addLayout(pHBoxLayout_3);
    pVBoxLayout->addLayout(pHBoxLayout_4);

}

/**
* @函数名称：
* @函数功能：
* @创建作者：tuzhirun
* @创建日期：2022-07-30
*/
void RegisterWidget::initConnect()
{
    connect(m_pRegisterButton,&QPushButton::clicked,this,&RegisterWidget::onRegisterButtonClicked);
    connect(m_pCancleButton,&QPushButton::clicked,this,&RegisterWidget::onCancleButtonClicked);
}

/**
* @函数名称：
* @函数功能：
* @创建作者：tuzhirun
* @创建日期：2022-07-30
*/
void RegisterWidget::onRegisterButtonClicked()
{
    int nRes = 0;
    userinfo stUserInfo;
    QString strUserName = m_pUserNameLineEdit->text();
    QString strUserPassWord = m_pPassWordLineEdit->text();
    QString strSurePassWord = m_pSurePassWordLineEdit->text();
    if(strUserName.isEmpty())
    {
        QMessageBox::warning(this, QString::fromLocal8Bit("警告"), QString::fromLocal8Bit("用户名为空！"), QMessageBox::Ok);
        return;
    }
    if(strUserPassWord.isEmpty())
    {
        QMessageBox::warning(this, QString::fromLocal8Bit("警告"), QString::fromLocal8Bit("密码为空！"), QMessageBox::Ok);
        return;
    }
    if(strSurePassWord!=strUserPassWord)
    {
        QMessageBox::warning(this, QString::fromLocal8Bit("警告"), QString::fromLocal8Bit("密码不一致！"), QMessageBox::Ok);
        return;
    }

    nRes = m_pManageGui->getUserInfo(strUserName,stUserInfo);
    if(nRes==0)
    {
        QMessageBox::warning(this, QString::fromLocal8Bit("警告"), QString::fromLocal8Bit("用户已存在！"), QMessageBox::Ok);
        m_pPassWordLineEdit->clear();
        m_pSurePassWordLineEdit->clear();
        return;
    }
    nRes = m_pManageGui->addUserInfo(strUserName,strSurePassWord);
    if(nRes==0)
    {
        QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("注册成功！"), QMessageBox::Ok);
        close();
        return;
    }
    else
    {
        QMessageBox::warning(this, QString::fromLocal8Bit("警告"), QString::fromLocal8Bit("注册失败！"), QMessageBox::Ok);
        return;
    }

}

/**
* @函数名称：
* @函数功能：
* @创建作者：tuzhirun
* @创建日期：2022-07-30
*/
void RegisterWidget::onCancleButtonClicked()
{
    close();
}
