#include "helper_func.h"
helper_func::helper_func()
{

}

QString helper(int x){
    QString ans{};
    if(!x)return "0";
    while(x>0){
        ans=(QChar)(x%10+'0')+ans;
        x/=10;
    }
    return ans;
}


bool cin_check(QString s){
    QString standard{"0123456789"};
    for(int i{};i<s.length();i++){
        bool p{true};
        for(int j{};j<10;j++){
            if(s[i]==standard[j])p=false;
        }
        if(p)return false;
    }
    if(s[0]=='0')return false;
    return true;
}

bool cin_check2(QString s){
    if(s.length()==0)return false;
    QString standard{"0123456789"};
    for(int i{};i<s.length();i++){
        bool p{true};
        for(int j{};j<10;j++){
            if(s[i]==standard[j])p=false;
        }
        if(p)return false;
    }
    if(s[0]=='0'&&s.length()>1)return false;
    return true;
}


void dial(QString words)
{
    QDialog dialog;
    dialog.setGeometry(730,400,500,200);
    QLabel* s=new QLabel(words,&dialog);
    s->setGeometry(50,50,400,50);
    QFont f("黑体",18);
    s->setFont(f);
    dialog.exec();
}


