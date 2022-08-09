#ifndef REGISTERWIDGET_H
#define REGISTERWIDGET_H

#include <QObject>
#include <QWidget>
#include<QDialog>
#include<QLabel>
#include<QPushButton>
#include<QLineEdit>
#include<QHBoxLayout>
#include<QVBoxLayout>
#include<QMessageBox>
#include"managegui.h"
class RegisterWidget : public QDialog
{
    Q_OBJECT
public:
    explicit RegisterWidget(ManageGui *pManageGui,QDialog *parent = nullptr);
    ~RegisterWidget();
    void setUpUi();
    void initConnect();
private:
    QLabel *m_pUserNameLabel = nullptr;
    QLabel*m_pPassWordLabel = nullptr;
    QLabel*m_pSurePassWordLabel = nullptr;
    QLineEdit *m_pUserNameLineEdit = nullptr;
    QLineEdit *m_pPassWordLineEdit = nullptr;
    QLineEdit*m_pSurePassWordLineEdit = nullptr;
    QPushButton *m_pRegisterButton = nullptr;
    QPushButton *m_pCancleButton = nullptr;
private slots:
    void onRegisterButtonClicked();
    void onCancleButtonClicked();

signals:

private:
    ManageGui *m_pManageGui = nullptr;
};

#endif // REGISTERWIDGET_H
