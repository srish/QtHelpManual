#include <QSplitter>
#include <QMainWindow>
#include <QtGui/QApplication>
#include <QtHelp/QHelpEngine>
#include <QtHelp/QHelpEngineCore>
#include <QtHelp/QHelpContentItem>
#include <QtHelp/QHelpContentModel>
#include <QtHelp/QHelpContentWidget>
#include <QtHelp/QHelpIndexModel>
#include <QtHelp/QHelpIndexWidget>

#include "helpbrowser.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QMainWindow window;

    QHelpEngine* helpEngine = new QHelpEngine("/home/arun/QtSDK/Examples/4.7/help/simpletextviewer/documentation/simpletextviewer.qhc");
    helpEngine->setupData();

    QHelpContentWidget *contentWidget = helpEngine->contentWidget();
    HelpBrowser *helpBrowser = new HelpBrowser(helpEngine);

    QSplitter* splitter = new QSplitter(Qt::Horizontal);
    splitter->setFixedSize(1000, 800);

    splitter->addWidget(contentWidget);

    splitter->insertWidget(0, contentWidget);
    splitter->insertWidget(1, helpBrowser);

    QObject::connect(helpEngine->contentWidget(), SIGNAL(linkActivated(const QUrl &)),
                    helpBrowser, SLOT(setSource(const QUrl &)));

    splitter->show();

    window.setFixedSize(1000, 800);
    return a.exec();
}
