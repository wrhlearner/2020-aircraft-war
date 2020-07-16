#pragma once

#include "etlbase.h"

class planeviewmodel;
class bulletviewmodel;
class command:public ICommandBase{
	Command(planeviewmodel* pm) throw();
	Command(bulletviewmodel* bm) throw();
	
	virtual void SetParameter(const std::any& param);
	virtual void Exec();
private:
	planeviewmodel* m_pm;
	bulletviewmodel* m_bm;

	TwoStrings m_param;
};
