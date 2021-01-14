# NOTICE公告
## 计算器停止更新
我以前没有仔细读过[微软的代码](https://github.com/microsoft/calculator)

有一天，我点开一个[文件](https://github.com/microsoft/calculator/blob/master/src/CalcManager/Ratpack/exp.cpp)

我读出2点

1. 我太菜了
2. 我来晚了

不必造轮子了
- 提供计算器的目的已经破碎
- 学习的目的已经达到了
---
[追忆](https://github.com/Rratic/Calculator)

## 致谢
- blog.csdn.net/luoluozlb
- www.luogu.com.cn/user/149872
- www.luogu.com.cn/user/320697
- 张子辰
# Calculator

## About copyright
```
(file calcexpress)
CC 4.0 BY-SA copyright agreement.Please attach the source link and this statement.
source link: blog.csdn.net/luoluozlb/article/details/78793252

遵循 CC 4.0 BY-SA 版权协议，转载请附上原文出处链接和本声明。
本文链接：blog.csdn.net/luoluozlb/article/details/78793252
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
