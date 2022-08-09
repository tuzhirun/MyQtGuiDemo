#include "loginwidget.h"

//#if defined(_MSC_VER) && (_MSC_VER >= 1600)
//# pragma execution_character_set("utf-8")
//#endif

LoginWidget::LoginWidget(ManageGui *pManageGui,QWidget *parent)
    : QWidget(parent)
{
    m_pManageGui = pManageGui;
    initSqlConnect();
    initDlg();
    initConnect();
}

LoginWidget::~LoginWidget()
{

}

void LoginWidget::initDlg()
{
    QString strExePath = QApplication::applicationDirPath();
    QFont font;
    font.setFamily("Arial");
    font.setPointSize(14);//字体大小

    this->setMinimumSize(600, 480);
    this->setWindowTitle(QString::fromLocal8Bit("登录界面"));

    QHBoxLayout* userlayout = new QHBoxLayout();
    QHBoxLayout* pwdlayout = new QHBoxLayout();
    QVBoxLayout* userpwdlayout = new QVBoxLayout(this);

    QImage* img = new QImage;
    img->load(strExePath+"/333.jpg");
    img->scaled(250, 250, Qt::KeepAspectRatio);

    m_UserIcon = new QLabel(this);
    //m_UserIcon->setFixedSize(200, 200);
    m_UserIcon->setPixmap(QPixmap::fromImage(*img));

    m_pUserNameLabel = new QLabel(QString::fromLocal8Bit("用户名："), this);
    m_pUserNameLabel->setFont(font);
    m_pUserNameLabel->setFixedWidth(100);

    m_pUserNameLineEdit = new QLineEdit(this);
    m_pUserNameLineEdit->setFont(font);
    m_pUserNameLineEdit->setFixedWidth(200);
    m_pUserNameLineEdit->setAttribute(Qt::WA_InputMethodEnabled, false);

    userlayout->addWidget(m_pUserNameLabel);
    userlayout->addWidget(m_pUserNameLineEdit);
    userlayout->setAlignment(Qt::AlignCenter);

    m_pPassWordLabel = new QLabel(QString::fromLocal8Bit("密    码："), this);
    m_pPassWordLabel->setFont(font);
    m_pPassWordLabel->setFixedWidth(100);

    m_pPassWordLineEdit = new QLineEdit(this);
    m_pPassWordLineEdit->setFont(font);
    m_pPassWordLineEdit->setEchoMode(QLineEdit::Password);
    m_pPassWordLineEdit->setFixedWidth(200);
    //m_pPassWordLineEdit->setFixedSize(200, 50);
    //m_pPassWordLineEdit->setInputMask(QString::fromLocal8Bit("请输入密码"));

    pwdlayout->addWidget(m_pPassWordLabel);
    pwdlayout->addWidget(m_pPassWordLineEdit);
    pwdlayout->setAlignment(Qt::AlignCenter);

    m_pLoginButton = new QPushButton(QString::fromLocal8Bit("登录"), this);
    m_pLoginButton->setFont(font);
    m_pLoginButton->setFixedWidth(100);

    m_pRegisterButton = new QPushButton(QString::fromLocal8Bit("注册"),this);
    m_pRegisterButton->setFont(font);
    m_pRegisterButton->setFixedWidth(100);

    m_pCancleButton = new QPushButton(QString::fromLocal8Bit("取消"), this);
    m_pCancleButton->setFont(font);
    m_pCancleButton->setFixedWidth(100);

    QHBoxLayout* btnlayout = new QHBoxLayout();
    btnlayout->addWidget(m_pLoginButton);
    btnlayout->addWidget(m_pRegisterButton);
    btnlayout->addWidget(m_pCancleButton);
    btnlayout->setAlignment(Qt::AlignCenter);

    userpwdlayout->addStretch(1);
    userpwdlayout->addWidget(m_UserIcon,0, Qt::AlignCenter);
    userpwdlayout->addStretch(1);
    userpwdlayout->addLayout(userlayout);
    userpwdlayout->addStretch(1);
    userpwdlayout->addLayout(pwdlayout);
    userpwdlayout->addStretch(1);
    userpwdlayout->addLayout(btnlayout);
    userpwdlayout->addStretch(1);
    userpwdlayout->setAlignment(Qt::AlignCenter);
}

void LoginWidget::initConnect()
{
    connect(m_pLoginButton, &QPushButton::clicked, this, &LoginWidget::onLoginBtnClicked);
    connect(m_pRegisterButton,&QPushButton::clicked, this, &LoginWidget::onRegisterBtnClicked);
    connect(m_pCancleButton, &QPushButton::clicked, this, &LoginWidget::onCancleBtnClicked);
}

void LoginWidget::initSqlConnect()
{
    QStringList drivers = QSqlDatabase::drivers();
    foreach(QString driver, drivers)
    {
        //qDebug() << "/t" << driver;
    }
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setPort(3306);
    db.setDatabaseName("myqtdb");
    db.setUserName("root");
    db.setPassword("1996Tuzhirun.");
    bool ok = db.open();
    if (ok)
    {
        //QMessageBox::information(this, "infor", "success");
        qDebug()<<QString::fromLocal8Bit("加载数据库成功！");
    }
    else
    {
        //QMessageBox::information(this, "infor", "open failed");
        qDebug()<<QString::fromLocal8Bit("加载数据库失败：")<<db.lastError().text();
    }
}

void LoginWidget::onLoginBtnClicked()
{
    QString strUser = m_pUserNameLineEdit->text();
    if (strUser.isEmpty())
    {
        QMessageBox::warning(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("用户名为空！"), QMessageBox::Ok);
        return;
    }
    QString strPwd = m_pPassWordLineEdit->text();
    if (strPwd.isEmpty())
    {
        QMessageBox::warning(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("密码为空！"), QMessageBox::Ok);
        return;
    }
    userinfo stUserInfo;
    int nRes = m_pManageGui->getUserInfo(strUser,stUserInfo);
    if(0!=nRes)
    {
        QMessageBox::warning(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("用户不存在！"), QMessageBox::Ok);
        return;
    }
    if(stUserInfo.m_strPassword!=strPwd)
    {
        QMessageBox::warning(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("密码错误！"), QMessageBox::Ok);
        return;
    }
    else
    {
        int msgboxRes = QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("登录成功！"), QMessageBox::Ok);
        if(msgboxRes==QMessageBox::Ok)
        {
            close();
            m_pChoiceToolWidget = new ChoiceToolWidget();
            m_pChoiceToolWidget->setAttribute(Qt::WA_DeleteOnClose,true);
            m_pChoiceToolWidget->show();
        }
    }
}

void LoginWidget::onRegisterBtnClicked()
{
    m_pRegisterWidget = new RegisterWidget(m_pManageGui);
    m_pRegisterWidget->setAttribute(Qt::WA_DeleteOnClose,true);
    m_pRegisterWidget->setModal(true);
    m_pRegisterWidget->show();
}

void LoginWidget::onCancleBtnClicked()
{
    close();
}


