#include<cstring>
#include <stdio.h>
#include <iostream>
#include<string.h>

using namespace std;
unsigned int MAX_LEN = 11;

int main() {

    char strHelloworld[] = {"hello"};
    char const *pStr1 = "helloworld";          //存储空间内容不可变
    char * const pStr2 = "helloworld";          //指针不可变
    char const *const pStr3 = "helloworld";    //存储空间内容和指针都不可变
    pStr1 = strHelloworld;
    //pStr2 = strHelloworld;	//pStr2不可改
    //pStr3 = strHelloworld;	//pStr3不可改
    unsigned int len = strnlen_s(pStr2, MAX_LEN);

}



