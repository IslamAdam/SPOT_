#include "stdafx.h"
#include "util.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip> // necessary for setprecision
using namespace std;
#include "..\Rules.h"
#include "Import.h"
#include "..\Registrar.h"
#include "../Courses/UnivCourse.h"
#include <sstream>


Import::Import(Registrar* p) :Action(p)
{
}

bool Import::Execute()
{
	GUI* pGUI = pReg->getGUI();
	Rules Rules;
	string line;
	vector<string> lines;
	string item;
	vector<string> items;

	ActionData actData = pGUI->GetUserAction("Importing");

	if ((actData.actType == LOAD))
	{
		int xs = 80;
		int ys = 30;

		pGUI->PrintMsg("Importing Study Plan");
		ifstream inFile;
		inFile.open("E:\\CIE-StudyPlan.txt");

		cout << " line " << endl;      /////////////
		while (getline(inFile, line, '\n'))
		{
			lines.push_back(line);
			lines.push_back("end");
			cout << line << endl;  //////////////
		}
		cout << " end line " << endl;  //////////////


		for (const auto& in : lines)
		{
			auto it = std::begin(in);
			while (true)
			{
				auto commaPosition = std::find(it, std::end(in), ',');
				items.emplace_back(it, commaPosition);
				if (commaPosition == std::end(in))
				{
					break;
				}
				it = std::next(commaPosition);
			}
		}
		cout << " items " << endl;      /////////////
		for (const auto& out : items)
		{
			std::cout << out << std::endl;
		}
		cout << " end items " << endl;      /////////////

		vector<int> boundary;
		for (int i = 0; i < items.size(); i++)
		{
			if ((items[i] == "Year 1") || (items[i] == "Year 2") || (items[i] == "Year 3") || (items[i] == "Year 4") || (items[i] == "Year 5") || (items[i] == "Fall") || (items[i] == "Spring") || (items[i] == "Summer") || (items[i] == "end")) {
				boundary.push_back(i);
				cout << items[i] << endl;   ////////////////////
				cout << " boundary " << i << endl; ////////////
			}

		}
		/////////////////////////////
		int crd = 0;
		string Title = "DUMMY";
		int x = 40;
		/// //////////////////////////////////////////////////////////////
		for (int j = 0; j < boundary.size(); j = j + 3)
		{
			if ((items[boundary[j]] == "Year 1") && (items[boundary[j + 1]] == "Fall"))
			{

				x = 40;
				for (int i = boundary[j + 1] + 1; i < boundary[j + 2]; i++) {
					Course_Code code = items[i];
					CourseInfo mycourse = pReg->getCourseInfo(code);
					if (mycourse.Code != "000") {
						Course* pC = new Course(code, mycourse.Title, mycourse.Credits);
						//Course* pC = new Course(code, Title, crd);
						x = x + xs;
						int y = 600 - 60 - 1 * ys;
						graphicsInfo gInfo{ x, y };
						pC->setGfxInfo(gInfo);
						pC->setY(y);
						StudyPlan* pS = pReg->getStudyPlay();
						pS->AddCourse(pC, 1, FALL);
						pReg->setCourseType(pC);
					}
				}

			}

			else if ((items[boundary[j]] == "Year 1") && (items[boundary[j + 1]] == "Spring"))
			{
				x = 40;
				for (int i = boundary[j + 1] + 1; i < boundary[j + 2]; i++) {
					Course_Code code = items[i];
					CourseInfo mycourse = pReg->getCourseInfo(code);
					if (mycourse.Code != "000") {
						Course* pC = new Course(code, mycourse.Title, mycourse.Credits);
						x = x + xs;
						int y = 600 - 60 - 2 * ys;
						graphicsInfo gInfo{ x, y };
						pC->setGfxInfo(gInfo);
						pC->setY(y);
						StudyPlan* pS = pReg->getStudyPlay();
						pS->AddCourse(pC, 1, SPRING);
						pReg->setCourseType(pC);
					}
				}
			}
			else if ((items[boundary[j]] == "Year 1") && (items[boundary[j + 1]] == "Summer"))
			{
				x = 40;
				for (int i = boundary[j + 1] + 1; i < boundary[j + 2]; i++) {
					Course_Code code = items[i];
					CourseInfo mycourse = pReg->getCourseInfo(code);
					if (mycourse.Code != "000") {
						Course* pC = new Course(code, mycourse.Title, mycourse.Credits);
						x = x + xs;
						int y = 600 - 60 - 3 * ys;
						graphicsInfo gInfo{ x, y };
						pC->setGfxInfo(gInfo);
						pC->setY(y);
						StudyPlan* pS = pReg->getStudyPlay();
						pS->AddCourse(pC, 1, SUMMER);
						pReg->setCourseType(pC);
					}
				}
			}
			else if ((items[boundary[j]] == "Year 2") && (items[boundary[j + 1]] == "Fall"))
			{
				x = 40;
				for (int i = boundary[j + 1] + 1; i < boundary[j + 2]; i++) {
					Course_Code code = items[i];
					CourseInfo mycourse = pReg->getCourseInfo(code);
					if (mycourse.Code != "000") {
						Course* pC = new Course(code, mycourse.Title, mycourse.Credits);
						x = x + xs;
						int y = 600 - 60 - 4 * ys;
						graphicsInfo gInfo{ x, y };
						pC->setGfxInfo(gInfo);
						pC->setY(y);
						StudyPlan* pS = pReg->getStudyPlay();
						pS->AddCourse(pC, 2, FALL);
						pReg->setCourseType(pC);
					}
				}
			}
			else if ((items[boundary[j]] == "Year 2") && (items[boundary[j + 1]] == "Spring"))
			{
				x = 40;
				for (int i = boundary[j + 1] + 1; i < boundary[j + 2]; i++) {
					Course_Code code = items[i];
					CourseInfo mycourse = pReg->getCourseInfo(code);
					if (mycourse.Code != "000") {
						Course* pC = new Course(code, mycourse.Title, mycourse.Credits);
						x = x + xs;
						int y = 600 - 60 - 5 * ys;
						graphicsInfo gInfo{ x, y };
						pC->setGfxInfo(gInfo);
						pC->setY(y);
						StudyPlan* pS = pReg->getStudyPlay();
						pS->AddCourse(pC, 2, SPRING);
						pReg->setCourseType(pC);
					}
				}
			}
			else if ((items[boundary[j]] == "Year 2") && (items[boundary[j + 1]] == "Summer"))
			{
				x = 40;
				for (int i = boundary[j + 1] + 1; i < boundary[j + 2]; i++) {
					Course_Code code = items[i];
					CourseInfo mycourse = pReg->getCourseInfo(code);
					if (mycourse.Code != "000") {
						Course* pC = new Course(code, mycourse.Title, mycourse.Credits);
						x = x + xs;
						int y = 600 - 60 - 6 * ys;
						graphicsInfo gInfo{ x, y };
						pC->setGfxInfo(gInfo);
						pC->setY(y);
						StudyPlan* pS = pReg->getStudyPlay();
						pS->AddCourse(pC, 2, SUMMER);
						pReg->setCourseType(pC);
					}
				}
			}
			else if ((items[boundary[j]] == "Year 3") && (items[boundary[j + 1]] == "Fall"))
			{
				x = 40;
				for (int i = boundary[j + 1] + 1; i < boundary[j + 2]; i++) {
					Course_Code code = items[i];
					CourseInfo mycourse = pReg->getCourseInfo(code);
					if (mycourse.Code != "000") {
						Course* pC = new Course(code, mycourse.Title, mycourse.Credits);
						x = x + xs;
						int y = 600 - 60 - 7 * ys;
						graphicsInfo gInfo{ x, y };
						pC->setGfxInfo(gInfo);
						pC->setY(y);
						StudyPlan* pS = pReg->getStudyPlay();
						pS->AddCourse(pC, 3, FALL);
						pReg->setCourseType(pC);
					}
				}
			}
			else if ((items[boundary[j]] == "Year 3") && (items[boundary[j + 1]] == "Spring"))
			{
				x = 40;
				for (int i = boundary[j + 1] + 1; i < boundary[j + 2]; i++) {
					Course_Code code = items[i];
					CourseInfo mycourse = pReg->getCourseInfo(code);
					if (mycourse.Code != "000") {
						Course* pC = new Course(code, mycourse.Title, mycourse.Credits);
						x = x + xs;
						int y = 600 - 60 - 8 * ys;
						graphicsInfo gInfo{ x, y };
						pC->setGfxInfo(gInfo);
						pC->setY(y);
						StudyPlan* pS = pReg->getStudyPlay();
						pS->AddCourse(pC, 3, SPRING);
						pReg->setCourseType(pC);
					}
				}
			}
			else if ((items[boundary[j]] == "Year 3") && (items[boundary[j + 1]] == "Summer"))
			{
				x = 40;
				for (int i = boundary[j + 1] + 1; i < boundary[j + 2]; i++) {
					Course_Code code = items[i];
					CourseInfo mycourse = pReg->getCourseInfo(code);
					if (mycourse.Code != "000") {
						Course* pC = new Course(code, mycourse.Title, mycourse.Credits);
						x = x + xs;
						int y = 600 - 60 - 9 * ys;
						graphicsInfo gInfo{ x, y };
						pC->setGfxInfo(gInfo);
						pC->setY(y);
						StudyPlan* pS = pReg->getStudyPlay();
						pS->AddCourse(pC, 3, SUMMER);
						pReg->setCourseType(pC);
					}
				}
			}
			else if ((items[boundary[j]] == "Year 4") && (items[boundary[j + 1]] == "Fall"))
			{
				x = 40;
				for (int i = boundary[j + 1] + 1; i < boundary[j + 2]; i++) {
					Course_Code code = items[i];
					CourseInfo mycourse = pReg->getCourseInfo(code);
					if (mycourse.Code != "000") {
						Course* pC = new Course(code, mycourse.Title, mycourse.Credits);
						x = x + xs;
						int y = 600 - 60 - 10 * ys;
						graphicsInfo gInfo{ x, y };
						pC->setGfxInfo(gInfo);
						pC->setY(y);
						StudyPlan* pS = pReg->getStudyPlay();
						pS->AddCourse(pC, 4, FALL);
						pReg->setCourseType(pC);
					}
				}
			}
			else if ((items[boundary[j]] == "Year 4") && (items[boundary[j + 1]] == "Spring"))
			{
				x = 40;
				for (int i = boundary[j + 1] + 1; i < boundary[j + 2]; i++) {
					Course_Code code = items[i];
					CourseInfo mycourse = pReg->getCourseInfo(code);
					if (mycourse.Code != "000") {
						Course* pC = new Course(code, mycourse.Title, mycourse.Credits);
						x = x + xs;
						int y = 600 - 60 - 11 * ys;
						graphicsInfo gInfo{ x, y };
						pC->setGfxInfo(gInfo);
						pC->setY(y);
						StudyPlan* pS = pReg->getStudyPlay();
						pS->AddCourse(pC, 4, SPRING);
						pReg->setCourseType(pC);
					}
				}
			}
			else if ((items[boundary[j]] == "Year 4") && (items[boundary[j + 1]] == "Summer"))
			{
				x = 40;
				for (int i = boundary[j + 1] + 1; i < boundary[j + 2]; i++) {
					Course_Code code = items[i];
					CourseInfo mycourse = pReg->getCourseInfo(code);
					if (mycourse.Code != "000") {
						Course* pC = new Course(code, mycourse.Title, mycourse.Credits);
						x = x + xs;
						int y = 600 - 60 - 12 * ys;
						graphicsInfo gInfo{ x, y };
						pC->setGfxInfo(gInfo);
						pC->setY(y);
						StudyPlan* pS = pReg->getStudyPlay();
						pS->AddCourse(pC, 4, SUMMER);
						pReg->setCourseType(pC);
					}
				}
			}
			else if ((items[boundary[j]] == "Year 5") && (items[boundary[j + 1]] == "Fall"))
			{
				x = 40;
				for (int i = boundary[j + 1] + 1; i < boundary[j + 2]; i++) {
					Course_Code code = items[i];
					CourseInfo mycourse = pReg->getCourseInfo(code);
					if (mycourse.Code != "000") {
						Course* pC = new Course(code, mycourse.Title, mycourse.Credits);
						x = x + xs;
						int y = 600 - 60 - 13 * ys;
						graphicsInfo gInfo{ x, y };
						pC->setGfxInfo(gInfo);
						pC->setY(y);
						StudyPlan* pS = pReg->getStudyPlay();
						pS->AddCourse(pC, 5, FALL);
						pReg->setCourseType(pC);
					}
				}
			}
			else if ((items[boundary[j]] == "Year 5") && (items[boundary[j + 1]] == "Spring"))
			{
				x = 40;
				for (int i = boundary[j + 1] + 1; i < boundary[j + 2]; i++) {
					Course_Code code = items[i];
					CourseInfo mycourse = pReg->getCourseInfo(code);
					if (mycourse.Code != "000") {
						Course* pC = new Course(code, mycourse.Title, mycourse.Credits);
						x = x + xs;
						int y = 600 - 60 - 14 * ys;
						graphicsInfo gInfo{ x, y };
						pC->setGfxInfo(gInfo);
						pC->setY(y);
						StudyPlan* pS = pReg->getStudyPlay();
						pS->AddCourse(pC, 5, SPRING);
						pReg->setCourseType(pC);
					}
				}
			}

		}

		pGUI->PrintMsg("Importing Study Plan Done Successfully");
		inFile.close();
		return true;
	}

	///////////////////////////////////
	else if (actData.actType == ADD_MINOR)
	{
		pGUI->PrintMsg("Declaring Minor");
		ifstream inFile;
		inFile.open("E:\\CIE-Requirements.txt");
		while (getline(inFile, line, '\n'))
		{
			lines.push_back(line);
		}
		inFile.close();

		pGUI->PrintMsg("Enter the total MINOR Credites");
		int Minor_Credites = stoi(pGUI->GetSrting());
		int Total_Credites = stoi(lines[0]);
		int new_Total_Credites = Minor_Credites + Total_Credites;
		lines[0] = to_string(new_Total_Credites);

		pGUI->PrintMsg("Enter the number of Minor Courses");
		int number = stoi(pGUI->GetSrting());
		string minor_courses = "";
		for (int i = 0; i < number; i++)
		{
			pGUI->PrintMsg("Enter course number " + to_string(i + 1));
			string course = pGUI->GetSrting();
			Rules.Minor_Courses.push_back(course);

			if (i == (number - 1))
				minor_courses = minor_courses + course;
			else
				minor_courses = minor_courses + course + ",";
		}
		//lines[18] = minor_courses;
		lines.push_back(minor_courses);
		ofstream outFile;
		outFile.open("E:\\NANENG-Requirements.txt");
		for (int i = 0; i < lines.size(); i++)
		{
			if (i == (lines.size() - 1))
				outFile << lines[i];
			else
				outFile << lines[i] << "\n";
		}
		outFile.close();
	}
}
Import::~Import()
{
}
