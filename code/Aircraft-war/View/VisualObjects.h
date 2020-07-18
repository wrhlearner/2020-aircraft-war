#include <list>
#include <VisualObject.h>

class VisualObject 
{
public:
    void get_GS(std::shared_ptr<GraphicsScene> m_GS); 

    void createVO(VisualObject *VOptr);

    void deleteVO(VisualObject *VOptr);

    std::list<VisualObject*> VO;

private:
    std::shared_ptr<GraphicsScene> GS;
}