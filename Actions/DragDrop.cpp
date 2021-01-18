#include "DragDrop.h"
#include "..\Registrar.h"
#include "../Courses/UnivCourse.h"
#include "../Courses/Course.h"
#include <iostream>

//class Course;
//class AcademicYear;

DragDrop::DragDrop(Registrar* p) :Action(p)
{
}

bool DragDrop::Execute()
{
	GUI* pGUI = pReg->getGUI();
	ActionData actData = pGUI->GetUserAction("Drage and Drop any Course");
	int x, y;
	if (actData.actType == DRAW_AREA)	//user clicked inside drawing area
	{
		x = actData.x;
		y = actData.y;

		StudyPlan* pS = pReg->getStudyPlay();

		for (int i = 1; i <= 5; i++)
		{
			for (int sem = FALL; sem < SEM_CNT; sem++)
			{
				SEMESTER sem2 = static_cast<SEMESTER>(sem);
				list<Course*> courses = pS->getCourses(i, sem2);
				for (auto it = courses.begin(); it != courses.end(); ++it)
				{
					graphicsInfo gInfo = (*it)->getGfxInfo();
					if (((x > gInfo.x) && (x < (gInfo.x + CRS_WIDTH))) && ((y > gInfo.y) && (y < (gInfo.y + CRS_HEIGHT))))
					{
						graphicsInfo gInfo2 = pGUI->DragCourse(*it);
						x_y_year_semester st;
						st = pS->co_ordinates(gInfo2.x, gInfo2.y);
						if ((i == st.year) && (sem2 == st.semester))
						{
							break;
						}
						else
						{
							Course_Code code = (*it)->getCode();
							string Title = (*it)->getTitle();
							int crd = (*it)->getCredits();
							pS->DeleteCourseFromPlan((*it), i, sem2);
							Course* pC = new Course(code, Title, crd);
							pC->setGfxInfo({ st.x_co,st.y_co });
							pC->setY(st.y_co);
							pS->AddCourse(pC, st.year, st.semester);
							pReg->setCourseType(pC);

							for (auto itt = courses.begin(); itt != courses.end(); ++itt)
							{
								graphicsInfo gInfo3 = (*itt)->getGfxInfo();
								if (gInfo3.x > gInfo.x)
								{
									(*itt)->setGfxInfo({ gInfo3.x - 120 , gInfo3.y });
									(*itt)->setY(gInfo3.y);
								}
									
							}

							break;
						}
					}
				}
			}
		}
	}
	return true;
}


DragDrop::~DragDrop()
{
}
