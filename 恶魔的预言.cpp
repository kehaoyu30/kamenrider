#include<stdio.h>
#include<stdlib.h>
#include <string>
#include <iostream>
using namespace std;

void detective(string std)//用于识别是基本字或标识符
{ //用于识别基本的字
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
    else//用于识别标识符
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

        //读入代码（字符串形式）
        if (strs.length() == 0)
        {
            getline(cin, strs);
            continue;
        }
        else

            stw = stw + '\n' + strs;
        getline(cin, strs);


    }
    //开始处理写入的代码
    int length_stw = stw.length();
    for (int m = 0; m < length_stw; m++)
    {
        //当遇到空格或换行时，跳过后继续执行
        if (stw[m] == ' ') { continue; }
        if (stw[m] == '\n') {
            cout << endl;
            j++; continue;
        }
        //识别是否有常数
        else if (isdigit(stw[m]) && !isalpha(stw[m + 1]))
        {
            string digit;
            //以字符串形式表示此常数
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
        //识别基本字符或标识符
        else if (isalpha(stw[m]))
        {
            string rough;
            //以字符串形式表示这个基本字符或者标识符
            while (isdigit(stw[m]) || isalpha(stw[m]))
            {
                rough += stw[m];
                m++;
            }
            m--;
            detective(rough);
        }
        //识别运算符
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
                
            case '&'://识别边界符
                m++;
                if (stw[m] == '&')
                {
                    cout << "<25,->" << ",";
                }
                break;
            case '|'://识别边界符
                m++;
                if (stw[m] == '|')
                {
                    cout << "<26,->" << ",";
                }
                break;
            case '('://识别边界符
                cout << "<28,->" << ",";
                break;
            case ')'://识别边界符
                cout << "<29,->" << ",";
                break;
            case '['://识别边界符
                cout << "<30,->" << ",";
                break;
            case ']'://识别边界符
                cout << "<31,->" << ",";
                break;
            case '{'://识别边界符
                cout << "<32,->" << ",";
                break;
            case '}'://识别边界符
                cout << "<33,->" << ",";
                break;
            case ';'://识别边界符
                cout << "<34,->" << ",";
                break;
            case ','://识别边界符
                cout << "<35,->" << ",";
                break;
            case '`'://识别边界符
                cout << "<36,->" << ",";
                break;
            default: //错误处理
                cout << "出错了雅洛" << ",";
                break;
            }
        }
    }

    if (OP == 1) {

        printf(" \nLexicalError(s) on line(s) %d,%d,", x[0], x[1]);

    }
    return 0;
}