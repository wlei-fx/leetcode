#include <iostream>
#include <string>
using namespace std;

void Func(char str_arg[100])
{
       cout<<sizeof(str_arg)<<endl;
}
int main(void)
{
     char str[]="Hello";
     cout<<sizeof(str)<<endl;
    cout<<strlen(str)<<endl;
    char*p=str;
    cout<<sizeof(p)<<endl;
    Func(str);
}
