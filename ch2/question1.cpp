#include <iostream>
#include <cstring>

using namespace std;

class CMyString
{
private:
    char* m_pdata;
public:
    CMyString(char * pdata = nullptr);
    CMyString(const CMyString& str);
    char *get_char(void) { return m_pdata; }
    CMyString& operator= (const CMyString &str);
    ~CMyString(void);
};


//构造函数
CMyString::CMyString(char * pdata)
{
    m_pdata = new char[strlen(pdata) + 1];
    strcpy(m_pdata, pdata);
}

//析构函数
CMyString::~CMyString(void)
{
    if(m_pdata)
    {
        delete []m_pdata;
        m_pdata = nullptr;
    }    
}

//拷贝构造函数
CMyString::CMyString(const CMyString& str)
{
    cout << "拷贝构造函数!" << endl;
    m_pdata = new char[strlen(str.m_pdata)+1];
    strcpy(m_pdata, str.m_pdata);
}

//赋值运算符
CMyString& CMyString::operator= (const CMyString &str)
{
    if(&str == this)
        return *this;
    
    if(m_pdata)
    {
        delete []m_pdata;
        m_pdata = nullptr;
    }

    m_pdata = new char[strlen(str.m_pdata) + 1];
    strcpy(m_pdata, str.m_pdata);

    return *this;
}

//赋值运算符（考虑new分配空间是否足够）
CMyString& CMyString::operator= (const CMyString &str)
{
    if(&str != this)
    {
        CMyString strtemp;//使用临时实例，在构造函数中分配内存，如果失败会跑出异常
        char * pTemp = strtemp.m_pdata;
        strtemp.m_pdata = m_pdata;
        m_pdata = pTemp;
    }
    return *this;
}


int main(int argc, char const *argv[])
{
    
    char *tmp = "hello world";
    CMyString myStr(tmp);

    cout << "myStr: " << myStr.get_char() << endl;

    CMyString otherOne = myStr;

    cout << "otherOne: " << otherOne.get_char() << endl;

    char *tmp2 = "show the difference.";
    CMyString myStr2(tmp2);
    cout << "myStr2: " << myStr2.get_char() << endl;

    myStr2 = otherOne;
    cout << "myStr2 after operator \"=\": " << myStr2.get_char() << endl;

    return 0;
}
