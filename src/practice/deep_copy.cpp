//
// Created by 14771 on 2024/9/4.
//
#include <iostream>
#include <string.h>
using namespace std;

class String{
private:
    unsigned int m_size;
    char* m_buffer;
public:
    String(const char* string1){
        m_size = strlen(string1);
        m_buffer = new char[m_size+1];
        memcpy(m_buffer,string1,m_size+1);
    }
    //deep_copy-------without the function,it's a simple copy to ptr of the variables.
    String(const String& other):m_size(other.m_size)
    {
        cout<<"copy"<<endl;
        m_buffer = new char[m_size];
        memcpy(m_buffer,other.m_buffer,m_size);
    }
    //the most exciting
    //String(const String& other){memcpy(this,&other,sizeof(other));}
    ~String(){
        delete[] m_buffer;
    }
    friend ostream& operator<<(ostream& ostream1,const String& string);
};
ostream& operator<<(ostream& ostream1,const String& string){
    ostream1<<string.m_buffer;
    return ostream1;
}
void PrintString(String string1){cout<<string1<<endl;}
int main(){
    const char* name = "xiaoming";
    const char* name1 = name;
    String string1(name);
    String string2 = string1;

    PrintString(string1);
    PrintString(string2);
    cin.get();
}
