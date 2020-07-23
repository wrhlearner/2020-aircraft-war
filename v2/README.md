# v2增改情况
- 新增Boss
- 玩家飞机发动大招
# 环境配置
- Qt 5.14.2
- compiler MinGW 7.3.0 64bit
- qmake
- 图片库：myimage文件夹
# 编程
1. Qt Creator中新建other project->empty qmake project,选择MinGW 64bit编译器
2. 将rar中.h，.cpp，/myimage/images.qrc文件添加到项目中
3. 在.pro文件中添加以下指令
    QT += widgets
