/*
 *	File: gui_wallet_centralwigdet.h
 *
 *	Created on: Nov 11, 2016
 *	Created by: Davit Kalantaryan (Email: davit.kalantaryan@desy.de)
 *
 *  This file implements ...
 *
 */
#ifndef CENTRALWIGDET_GUI_WALLET_H
#define CENTRALWIGDET_GUI_WALLET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QTabWidget>
#include "browse_content_tab.hpp"
#include "transactions_tab.hpp"
#include "upload_tab.hpp"
#include "overview_tab.hpp"
#include <stdio.h>

extern int g_nDebugApplication;

class qtWidget_test : public QWidget
{
public:
    ~qtWidget_test()
    {
        if(g_nDebugApplication){printf("qtWidget_test::~qtWidget_test();\n");}
    }
};

#define tmpWidget  qtWidget_test

namespace gui_wallet
{
    class CentralWigdet : public QWidget
    {
        Q_OBJECT
    public:
        CentralWigdet();
        virtual ~CentralWigdet(); // virtual because may be this class will be
                                  // used by inheritance

    protected:
        virtual void showEvent ( QShowEvent * event ) ;
        virtual void makeWarningImediatly(const QString& waringTitle, const QString& waringText, const QString& details );

    private slots:
        void make_deleyed_warning();

    private:
        QVBoxLayout         m_main_layout;
        tmpWidget           m_first_line_widget;
        QHBoxLayout         m_first_line_layout;
        QLineEdit           m_search_box;
        QTabWidget          m_main_tabs;
        Browse_content_tab  m_browse_cont_tab;
        Transactions_tab    m_trans_tab;
        Upload_tab          m_Upload_tab;
        Overview_tab        m_Overview_tab;
        QString             m_DelayedWaringTitle;
        QString             m_DelayedWaringText;
        QString             m_DelayedWaringDetails;

    };
}



#endif // CENTRALWIGDET_GUI_WALLET_H
