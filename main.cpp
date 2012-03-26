/*
    This file is part of cPad Project.

    cPad is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    cPad is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with cPad.  If not, see <http://www.gnu.org/licenses/>.
*/
#include <QtGui/QApplication>
#include "mainwindow.h"
#include <QTextCodec>
#include <QSplashScreen>
#include <QDesktopWidget>

int main(int argc, char *argv[])
{
    QApplication cpad(argc, argv);

    //����translation����Ϊwindows���ر���
    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());

    //�������������ͼƬ
    QPixmap pixmap(":/resources/splash.png");

    //������������
    QSplashScreen splash(pixmap);
    for(qint64 i=5555555*9;i>0;i--)
        splash.show();

    //���ó������֯����
    cpad.setOrganizationName("5-up");
    //���ó��������
    cpad.setApplicationName("cPad");

    //�����岢��ʾ
    MainWindow mainWindow;
    mainWindow.show();
    //�����������
    splash.finish(&mainWindow);

    //������ļ���Ϊ���� ���ļ�
    if (argc > 1) {
        mainWindow.openArgvFile(argv[1]);
    }

    //����ִ�� �ȴ���Ӧ
    return cpad.exec();
}
