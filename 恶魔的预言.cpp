#include<stdio.h>
#include<stdlib.h>
#include <string>
#include <iostream>
using namespace std;

void detective(string std)//����ʶ���ǻ����ֻ��ʶ��
{ //����ʶ���������
    if (std == "main")
    {
        cout << "<13,->" << ",";
    }
    else if (std == "void")
        cout << "<3,->" << ",";
    else if (std == "const")
        cout << "<constsym,const>" << ",";
    else if (std == "end")
        cout << "<endsym,->" << ","; 
    else if (std == "float")
        cout << "<5,->" << ",";
    else if (std == "char")
        cout << "<6,->" << ",";
    else if (std == "if")
        cout << "<7,->" << ",";
    else if (std == "else")
        cout << "<8,->" << ",";
    else if (std == "while")
        cout << "<9,->" << ",";
    else if (std == "do")
        cout << "<10,->" << ",";
    else if (std == "for")
        cout << "<11,->" << ","; 
    else if (std == "return")
        cout << "<12,->" << ",";
    else if (std == "kamenrider")
        cout << "<1971,->" << ",";
    else if (std == "int")
        cout << "<4,->" << ",";
    else//����ʶ���ʶ��
    {
        cout << "<1," << std << ">" << ",";
    }
}
int main()
{
    string stw, strs;
    int j = 0, x[2] = { 0 }, k = 0, OP = 0;
    getline(cin, strs);
    while (strs != "#")
    {

        //������루�ַ�����ʽ��
        if (strs.length() == 0)
        {
            getline(cin, strs);
            continue;
        }
        else

            stw = stw + '\n' + strs;
        getline(cin, strs);


    }
    //��ʼ����д��Ĵ���
    int length_stw = stw.length();
    for (int m = 0; m < length_stw; m++)
    {
        //�������ո����ʱ�����������ִ��
        if (stw[m] == ' ') { continue; }
        if (stw[m] == '\n') {
            cout << endl;
            j++; continue;
        }
        //ʶ���Ƿ��г���
        else if (isdigit(stw[m]) && !isalpha(stw[m + 1]))
        {
            string digit;
            //���ַ�����ʽ��ʾ�˳���
            while (isdigit(stw[m]))
            {
                digit += stw[m];
                m++;
            }
            m--;
            cout << "<2," << digit << ">" << ",";
        }
        else if (isdigit(stw[m]) && isalpha(stw[m + 1])) {
            cout << "LexicalError" << ",";
            while (stw[m + 1] != '=') {
                m++;
            }
            OP = 1;
            x[k] = j;
            k++;
        }
        //ʶ������ַ����ʶ��
        else if (isalpha(stw[m]))
        {
            string rough;
            //���ַ�����ʽ��ʾ��������ַ����߱�ʶ��
            while (isdigit(stw[m]) || isalpha(stw[m]))
            {
                rough += stw[m];
                m++;
            }
            m--;
            detective(rough);
        }
        //ʶ�������
        else
        {
            switch (stw[m])
            {
            case '+':
                cout << "<14,->" << ",";
                break;
            case '-':
                cout << "<15,->" << ",";
                break;
            case '*':
                cout << "<16,->" << ",";
                break;
            case '/':
                m++;
                if (stw[m] == '*') {
                    while (stw[m] != '/')
                        m++;
                }
                else if (stw[m] == '/') {
                    while (stw[m] != '\n')
                        m++;
                }
                else {
                    m--;
                    cout << "<17,->" << ",";
                }
                break;
            case '%':
                cout << "<18,->" << ",";
                break;
            case '=':
                m++;
                if (stw[m] == '=')
                {
                    cout << "<23,->" << ",";
                }
                else
                {
                    m--;
                    cout << "<27,->" << ",";
                }
                break;
            case '<':
                m++;
                if (stw[m] == '>')
                {
                    cout << "<neq,<>>" << ",";
                }
                else if (stw[m] == '=')
                {
                    cout << "<20,->" << ",";
                }
                else
                {
                    m--;
                    cout << "<19,->" << ",";
                }
                break;
            case '>':
                m++;
                if (stw[m] == '=')
                {
                    cout << "<22,->" << ",";
                }
                else
                {
                    m--;
                    cout << "<21,->" << ",";
                }
                break;
            case '!':
                m++;
                if (stw[m] == '=')
                {
                    cout << "<24,->" << ",";
                }
                break;
                
            case '&'://ʶ��߽��
                m++;
                if (stw[m] == '&')
                {
                    cout << "<25,->" << ",";
                }
                break;
            case '|'://ʶ��߽��
                m++;
                if (stw[m] == '|')
                {
                    cout << "<26,->" << ",";
                }
                break;
            case '('://ʶ��߽��
                cout << "<28,->" << ",";
                break;
            case ')'://ʶ��߽��
                cout << "<29,->" << ",";
                break;
            case '['://ʶ��߽��
                cout << "<30,->" << ",";
                break;
            case ']'://ʶ��߽��
                cout << "<31,->" << ",";
                break;
            case '{'://ʶ��߽��
                cout << "<32,->" << ",";
                break;
            case '}'://ʶ��߽��
                cout << "<33,->" << ",";
                break;
            case ';'://ʶ��߽��
                cout << "<34,->" << ",";
                break;
            case ','://ʶ��߽��
                cout << "<35,->" << ",";
                break;
            case '`'://ʶ��߽��
                cout << "<36,->" << ",";
                break;
            default: //������
                cout << "����������" << ",";
                break;
            }
        }
    }

    if (OP == 1) {

        printf(" \nLexicalError(s) on line(s) %d,%d,", x[0], x[1]);

    }
    return 0;
}