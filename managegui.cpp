#include "managegui.h"

ManageGui::ManageGui()
{

}

ManageGui::~ManageGui()
{

}

int ManageGui::getUserInfo(const QString &strUserName, userinfo &stUserInfo)
{
    bool bRes = false;
    QString sql = QString("select * from userinfo where username='%1'").arg(strUserName);
    QSqlQuery query;
    query.prepare(sql);
    bRes = query.exec(sql);
    if(!bRes)
    {
        return -1;
    }
    QSqlRecord rec = query.record();
    while(query.next())
    {
        rec = query.record();
        int usernamecol = rec.indexOf("username");
        int pwdcol = rec.indexOf("password");
        QString username = query.value(usernamecol).toString();
        QString password = query.value(pwdcol).toString();
        stUserInfo.m_strName = username;
        stUserInfo.m_strPassword = password;
        stUserInfo.m_bExist = true;
    }
    if(!stUserInfo.m_bExist)
    {
        return -1;
    }
    return 0;
}

int ManageGui::addUserInfo(const QString &strUserName, const QString &strPassWord)
{
    QString sql = QString("insert into userinfo(username,password) values('%1','%2')").arg(strUserName).arg(strPassWord);
    QSqlQuery query;
    bool bRes = query.exec(sql);
    if(!bRes)
    {
        return -1;
    }
    return 0;
}
