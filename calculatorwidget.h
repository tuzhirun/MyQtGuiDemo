#ifndef CALCULATORWIDGET_H
#define CALCULATORWIDGET_H

#include <QObject>
#include <QWidget>
#include<QLabel>
#include<QLineEdit>
#include<QPushButton>
#include<QGridLayout>
#include<QVBoxLayout>
class CalculatorWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CalculatorWidget(QWidget *parent = nullptr);
    void setUpUi();
    void initConnect();
private:
    QLineEdit *m_pExpressLineEdit = nullptr;
    QLineEdit *m_pResultLineEdit = nullptr;

    QPushButton *m_pReciprocalPushButton = nullptr;
    QPushButton *m_pBinaryPushButton = nullptr;
    QPushButton *m_pDecimalPushButton = nullptr;
    QPushButton *m_pBackSpacePushButton = nullptr;
    QPushButton *m_pClearPushButton = nullptr;

    QPushButton *m_pSinPushButton = nullptr;
    QPushButton *m_pSevenPushButton = nullptr;
    QPushButton *m_pEightPushButton = nullptr;
    QPushButton *m_pNinePushButton = nullptr;
    QPushButton *m_pPlusPushButton = nullptr;

    QPushButton *m_pCosPushButton = nullptr;
    QPushButton *m_pFourPushButton = nullptr;
    QPushButton *m_pFivePushButton = nullptr;
    QPushButton *m_pSixPushButton = nullptr;
    QPushButton *m_pMinusPushButton = nullptr;

    QPushButton *m_pTanPushButton = nullptr;
    QPushButton *m_pOnePushButton = nullptr;
    QPushButton *m_pTwoPushButton = nullptr;
    QPushButton *m_pThreePushButton = nullptr;
    QPushButton *m_pMulPushButton = nullptr;

    QPushButton *m_pCotPushButton = nullptr;
    QPushButton *m_pPiePushButton = nullptr;
    QPushButton *m_pZeroPushButton = nullptr;
    QPushButton *m_pPointPushButton = nullptr;
    QPushButton *m_pDivPushButton = nullptr;

    QPushButton *m_pReversePushButton = nullptr;
    QPushButton *m_pSquarePushButton = nullptr;
    QPushButton *m_pSqrtPushButton = nullptr;
    QPushButton *m_pFactorialPushButton = nullptr;
    QPushButton *m_pModPushButton = nullptr;

    QPushButton *m_pLeftBracketsPushButton = nullptr;
    QPushButton *m_pRightBracketsPushButton = nullptr;
    QPushButton *m_pAbsPushButton = nullptr;
    QPushButton *m_pIndexPushButton = nullptr;
    QPushButton *m_pEqualPushButton = nullptr;
private slots:
    void onClearBtnClicked();

    void onOneBtnClicked();










    void onAddBtnClicked();
    void onMinusBtnClicked();
    void onMulBtnClicked();
    void onDivBtnClicked();
    
    void onBackSpaceBtnClicked();
    void onEqualBtnClicked();
signals:

};

#endif // CALCULATORWIDGET_H
