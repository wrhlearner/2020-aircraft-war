#include <VisualObjects.h>

void VisualObjects::createVO(VisualObject *VOptr)
{
    VO.push_back(VOptr);
    GS->additem(VOptr);
}

void VisualObjects::deleteVO(VisualObject *VOptr)
{
    GS->removeitem(VOptr);
    VO.remove(VOptr); //按值删除
    it = VO.begin();
    while (it != VO.end())
    {
        cout << *it << " ";
        ++it;
    }
}

void get_GS(std::shared_ptr<GraphicsScene> m_GS)
{
    GS = m_GS;
}