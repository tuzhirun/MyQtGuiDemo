#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H

#include<QWidget>
#include<QLineEdit>
#include<QLabel>
#include<QPushButton>
#include<QHBoxLayout>
#include<QVBoxLayout>
//#include<QtNetwork/qudpsocket.h>
//#include<QtNetwork/qtcpsocket.h>
#include<QMessageBox>
#include<QApplication>

#include"registerwidget.h"
#include"managegui.h"
#include"choicetoolwidget.h"
class LoginWidget : public QWidget
{
    Q_OBJECT

public:
    LoginWidget(ManageGui *pManageGui,QWidget *parent = nullptr);
    ~LoginWidget();
    void initDlg();
    void initConnect();
private:
    void initSqlConnect();
private:
    QLabel* m_UserIcon = nullptr;
    QPushButton* m_pLoginButton = nullptr;
    QPushButton* m_pRegisterButton = nullptr;
    QPushButton* m_pCancleButton = nullptr;
    QLabel* m_pUserNameLabel = nullptr;
    QLineEdit* m_pUserNameLineEdit = nullptr;
    QLabel* m_pPassWordLabel = nullptr;
    QLineEdit* m_pPassWordLineEdit = nullptr;
private slots:
    void onLoginBtnClicked();
    void onRegisterBtnClicked();
    void onCancleBtnClicked();
private:
    RegisterWidget *m_pRegisterWidget = nullptr;
    ManageGui *m_pManageGui = nullptr;
    ChoiceToolWidget*m_pChoiceToolWidget = nullptr;
};
#endif // LOGINWIDGET_H
