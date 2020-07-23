# 新增功能
- 血包：玩家飞机初始hp值为3，每接收一个血包hp+1，hp上限为3
- 炸弹包：玩家飞机初始炸弹包数量为3，每接收一个炸弹包炸弹数量+1，上限为3
- 按空格发射炸弹
# 环境配置
- Qt 5.14.2
- compiler MinGW 7.3.0 64bit
- qmake
- 图片库：myimage文件夹
# 编程
1. Qt Creator中新建other project->empty qmake project,选择MinGW 64bit编译器
2. 将rar中.h，.cpp，/myimage/images.qrc，icon.ico文件添加到项目中
3. 在.pro文件中添加以下指令
- QT += widgets
- RC_ICONS = icon.ico
