#View与Window部分
这一个部分因为个人原因进度较慢，尚在调试之中，所以可能要到下一次迭代才能放出较为完整的成品。
View部分定义了一个VisualObject类，继承了QGraphicsPixmapitem类，其已经比较完善。
Window部分定义了VisualObjects类、GraphicsScene类与GraphicsView类，分别继承了stl::list、QGraphicsScene与QGraphicsView类。
Window通过set_keyCommand、set_confCommand、NotificationSink与PropertySink与Viewmodel层进行交互。
set_keyCommand(const int& kv)直接传递键值，set_confCommand(const int& cv)直接传递设置值。
PropertySink(const std::list<FlyingObject>& Prop, const std::string& Type)调用VisualObjects::Update修改需刷新的对象的属性。
状态机还在做。。。