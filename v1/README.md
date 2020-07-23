# v1.0 release 操作说明
1. 打开exe文件后，双击游戏界面出现菜单
2. 游戏过程中，双击游戏界面出现菜单，可以退出或继续
3. 游戏操作
- 键盘WASD控制玩家飞机上下左右移动
- 键盘J控制玩家飞机发射子弹
- 键盘空格控制玩家飞机发射炸弹（v3实现）
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
