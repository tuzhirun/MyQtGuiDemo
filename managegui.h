#ifndef MANAGEGUI_H
#define MANAGEGUI_H
#include<QString>
#include<QSql>
#include<QSqlRecord>
#include<QSqlDatabase>
#include<QSqlError>
#include<QSqlQuery>
#include <QStringList>
#include<QtAlgorithms>
#include<QDebug>
struct userinfo
{
    bool m_bExist = false;
    QString m_strName = QString();
    QString m_strPassword = QString();
};

class ManageGui
{
public:
    ManageGui();
    ~ManageGui();
    int getUserInfo(const QString& strUserName,userinfo &stUserInfo);
    int addUserInfo(const QString& strUserName,const QString& strPassWord);
};

#endif // MANAGEGUI_H
