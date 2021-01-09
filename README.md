# Calculator

## About copyright
```
version 0.1.0 :

(code will be deleted)

CC 4.0 BY-SA copyright agreement.Please attach the source link and this statement.
source link: blog.csdn.net/luoluozlb/article/details/78793252

遵循 CC 4.0 BY-SA 版权协议，转载请附上原文出处链接和本声明。
本文链接：blog.csdn.net/luoluozlb/article/details/78793252

other versions :

see LICENSE
```

## Description:

This is a calculator which supports functions(e.g. sin(30))and unit conversion(e.g. 1(g/cm^3)/(kg/m^3)).

这是一个支持函数（例如sin(30)）和单位转化（例如1(g/cm^3)/(kg/m^3)）的计算器

## OS

Mainly for windows,I don't know whether it can run on linus,Mac,etc.

主要用于windows，我不知道是否可在其他操作系统上运行

I'm trying to make it more portable.

我在试图使之更可移植。

## About file system

```
{
    lang:{//language package
        en-uk.txt//English
        zh-CN.txt//Chinese
    },
    save:{//saving
        AboutSave.txt
        setting.data//if you have saved the setting
    },
    src:{//main code
        main.cpp
        |-calcintergrate.h&.cpp
          |-calcexpress.h&.cpp
            |-calchelper.h&.cpp
            |-calcdim.h&.cpp
            |-calcset.h&.cpp
              |-calcreadfile.h&.cpp
        // |- means #include
    },
    KNOWNBUGS.md,
    LICENSE,
    README.md,
}
```

## How to compile

If you use gcc in windows,and put this folder to D:\C++\Math,try

g++ -std=c++11 D:\C++\Math\src\calcdim.cpp D:\C++\Math\src\calchelper.cpp D:\C++\Math\src\calcreadfile.cpp D:\C++\Math\src\calcset.cpp D:\C++\Math\src\calcexpress.cpp D:\C++\Math\src\calcintergrate.cpp  D:\C++\Math\src\main.cpp -o D:\C++\Math\calculator.exe

then you can make a link to the exe file

## Feature

### In Code

- Pure C++

- Using C++11 standard

- Using try-catch-throw

- Using long double

- Using mt19937

### In Programme

- Press "Enter" three times to clear the window

- 连按三次回车清屏

- Colourful words

- 彩色字

## Language

- en-uk

- zh-CN

## Useful Commands(You can try)

- /random,/dice

- /help

- /exit

- /debug,/disdebug

- /information

- /example

- /save

- /mr,/m+,/m-,/ms

- /color

## Helpers before 2.0.0

- www.luogu.com.cn/user/149872 (solved my grammar problem in v0.8.0)

- www.luogu.com.cn/user/320697 (solved my grammar problem in v1.0.2)