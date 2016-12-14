/*
 *	File: gui_wallet_application.hpp
 *
 *	Created on: 14 Dec 2016
 *	Created by: Davit Kalantaryan (Email: davit.kalantaryan@desy.de)
 *
 *  This file is header file for class application
 *  this class will implement functional part necessary for the application
 *
 */
#ifndef GUI_WALLET_APPLICATION_HPP
#define GUI_WALLET_APPLICATION_HPP

#include <QApplication>
#include "fc_rpc_gui.hpp"


namespace gui_wallet
{

class application : public QApplication
{
public:
    application(int& argc, char** argv);
    virtual ~application();

private:
    fc::rpc::gui    m_gui_app;
};

}

typedef void (*TypeInGuiFnc)(void*);

struct SInGuiThreadCallInfo
{
    void*           data;
    TypeInGuiFnc    fnc;
};

class InGuiThreatCaller : public QObject
{
    Q_OBJECT

public:
    class QWidget*                      m_pParent2;
    int                                 m_nRes;
    decent_tools::UnnamedSemaphoreLite  m_sema;
public:
    void EmitShowMessageBox(const QString& a_str);
    void EmitCallFunc(SInGuiThreadCallInfo a_call_info);

public slots:
    void MakeShowMessageBoxSlot(const QString& a_str);
    void MakeCallFuncSlot(SInGuiThreadCallInfo a_call_info);

private:
signals:
    void ShowMessageBoxSig(const QString& a_str);
    void CallFuncSig(SInGuiThreadCallInfo a_call_info);
};


#endif // GUI_WALLET_APPLICATION_HPP
