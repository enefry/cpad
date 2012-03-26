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
#ifndef SYNTAXHIGHLIGHTER_H
#define SYNTAXHIGHLIGHTER_H

#include <QSyntaxHighlighter>
#include <QString>
#include <QTextDocument>
#include <QList>
#include <QColor>
#include "textblockdata.h"

class QTextCharFormat;

class SyntaxHighlighter : public QSyntaxHighlighter
{
    Q_OBJECT
public:
    SyntaxHighlighter(QTextDocument *parent);

public slots:
    void changeColorGroup(QList<QColor> group);
    void turnOnSyntaxHighlight(bool turn);

private:

    // �������������͡��ؼ��ʡ�ע�� ������ɫ
    QStringList dataTypeList;
    QStringList otherKeywordList;
    QTextCharFormat constFormat;  // �������֣��ַ��������ַ�
    QTextCharFormat dataTypeFormat;  // ��������
    QTextCharFormat commentFormat;   // ���кͶ���ע��
    QTextCharFormat otherFormat;  //�����ʣ����� for while return
    QTextCharFormat transferFormat;
    QTextCharFormat macroFormat;
    QTextCharFormat alertFormat;  //��ʾ
    enum { commentFinished = 1, commentNotFinish };
    struct PositionInfo
    {
        int start;
        int count;
        QTextCharFormat format;
    };
    QList<PositionInfo> formatPosition;  //�洢 struct{start, count, format}
    int findNextAvailableChar(const QString & text, char ch, int pos = 0);
    bool turnOn;

protected:
    void setSyntaxFormat();
    //����ʵ�� highlightBlock
    void highlightBlock(const QString &text);
    //�õ�λ����Ϣ������Ϣ�浽 formatPosition ��
    void getPositionInfo(const QString &text); 
    void printList(QList<PositionInfo> &formatPosition);
    //��setFormat��Ҫ����Ϣ�浽 formatPosition ��
    void pushFormat(int start, int count, QTextCharFormat format);
    //�����������͵���д�ɺ������� getPositionInfo ������á�
    void highlightDataType(const QString &text);
    void highlightOtherkeyword(const QString &text);
    void highlightComments(const QString &text);
    void highlightSingleQuote(const QString &text);
    void highlightQuote(const QString &text);
    void highlightTransfer(const QString &text);
    void highlightParentheses(const QString &text);
    //���ĳ�������ڲ���˫������������
    bool inQuote(const QString &text, int pos);
    QTextCharFormat categoryFormat(int category);

};


#endif // SYNTAXHIGHLIGHTER_H
