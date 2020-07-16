# 游戏实现思路
## 游戏构成
- 玩家飞机
- 普通NPC飞机、Boss NPC飞机
- 玩家子弹，NPC子弹
- 飞行界面
- 子弹包、炮弹包、技能包等（选做）

## 主要游戏事件及实现
- 初始化：
        - 普通NPC飞机在飞行界面一端随机位置、随机时间出现——通过随机函数定义出现位置及时间
        - 玩家飞机和Boss NPC飞机——构造函数定义属性
- 发射子弹：
        - 单独定义子弹类，在类中定义飞机属性获取发射子弹的飞机信息，便于获取子弹的初始位置
        - 通过关联键盘事件，决定子弹是否显示（发射）、改变位置
- 子弹击中飞机，NPC飞机与玩家飞机碰撞：
        - 子弹击中飞机，NPC飞机与玩家飞机碰撞都通过碰撞检测算法判断
        - 检测某个飞机对象的碰撞时（例如玩家飞机），在定义该对象的类中声明碰撞检测函数，检测其他子弹、飞机是否与该飞机对象发生碰撞，并相应的改变碰撞主题的属性
- 飞机、子弹的消亡
        - 子弹击中目标，NPC、子弹飞出游戏界面等，都通过改变飞行物的显示属性，创造消亡行为
- 发动大招
        - 在发动大招的同时，直接改变敌方飞机属性，无需检测碰撞行为
- 子弹包、炮弹包（选做）
        - 通过碰撞检测算法进行拾取
        - 改变子弹杀伤力、数量等属性定义技能

## 实现参考
https://blog.csdn.net/hao_zong_yin/article/details/74540652?utm_medium=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-4.nonecase&depth_1-utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-4.nonecase

https://blog.csdn.net/hao_zong_yin/article/details/74560842
