#pragma once
#define _USE_MATH_DEFINES
#define _WIN32_WINNT 0x0500
#include <windows.h>
#include <windowsx.h>
#include <iomanip>
#include <math.h>
#include <iostream>
#include <sstream>
using namespace std;

/************************************************************************\
|*                          Т И П Ы    Д А Н Н Ы Х                      *|
\************************************************************************/
/*---------------------------- Структура ЦВЕТ --------------------------*/
struct Color {
	int Red;						//красный
	int Green;						//зеленый
	int Blue;						//синий
};//end struct Color

/*----------------------- Структура МЕСТОПОЛОЖЕНИЕ ---------------------*/
struct Point {
	double X;						//координата X
	double Y;						//координата Y
};//end struct Point

/*-------------------------- Интерфейс ФУНКЦИЯ -------------------------*/
class IFunc {
public:
	IFunc(void) {};						//конструктор
	virtual ~IFunc(void) {};			//деструктор

	/*--------------методы доступа к закрытым полям класса--------------*/
	virtual void SetAB					//установить отрезок
		(double newA, double newB) = 0;
	virtual double GetA(void) = 0;		//получить левую границу отрезка
	virtual double GetB(void) = 0;		//получить правую границу отрезка
	virtual string GetfName(void) = 0;	//получить формулу f(x)
	virtual string GetdfName(void) = 0;	//получить формулу f'(x)
	virtual string GetColName(void) = 0;//получить газвание цвета графика
	/*------------------------------------------------------------------*/

	virtual void Caller					//обработка команд пользователя
		(int mode, double param1, double param2, double param3) = 0;
	virtual void Tabulation(int N) = 0;	//табулирование ф-ии
	virtual void Graphic(HDC hdc) = 0;	//построение графика
	virtual int WINAPI WinMain() = 0;	//инициализация окна
	virtual double dihotom(int mode) = 0;//поиск корня уравнения f(x) = 0
	virtual bool isMax(double x) = 0;	//проверка, есть ли max в точке
	virtual bool isMin(double x) = 0;	//проверка, есть ли min в точке
	virtual double func					//вызов f(x) или f'(x), 
		(int mode, double x) = 0;		//с округлением или без

	/*------------------------виртуальные методы------------------------*/
	virtual double Equation(void) = 0;	//обработка рез-та работы dihotom
	virtual double MAX() = 0;			//поиск локального max на отрезке
	virtual double MIN() = 0;			//поиск локального min на отрезке
	virtual double CountY(double x) = 0;//расчёт f(x)
	virtual double CountdY(double x) = 0;//расчёт f'(x)
	/*------------------------------------------------------------------*/

};//end class IFunc

/*---------------------------- Класс  ФУНКЦИЯ --------------------------*/
class Func : public IFunc {
protected:
	Color GC = { 0, 173, 69 };		//цвет графика
	double A;						//левая граница отрезка
	double B;						//правая граница отрезка
	string fName = "1.2 * x - 3";	//формула f(X) для печати
	string dfName = "1.2";			//формула f'(X) для печати
	string colName = "зеленый";		//название цвета графика

public:
	Func							//конструктор
		(double InitA = -5, double InitB = 5);
	~Func(void) {};					//деструктор

	/*--------------методы доступа к закрытым полям класса--------------*/
	virtual void SetAB				//установить отрезок
		(double newA, double newB);
	virtual double GetA(void);		//получить левую границу отрезка
	virtual double GetB(void);		//получить правую границу отрезка
	virtual string GetfName(void);	//получить формулу f(x)
	virtual string GetdfName(void);	//получить формулу f'(x)
	virtual string GetColName(void);//получить газвание цвета графика
	/*------------------------------------------------------------------*/

	virtual void Caller				
		(int mode, double param1, double param2, double param3);
	virtual void Tabulation(int N);	//табулирование функции
	virtual void Graphic(HDC hdc);	//построение графика функции
	virtual int WINAPI WinMain();	//инициализация окна
	virtual double dihotom(int mode);//поиск корня уравнения f(x) = 0
	virtual bool isMax(double x);	//проверка, есть ли max в точке
	virtual bool isMin(double x);	//проверка, есть ли min в точке
	virtual double func				//вызов f(x) или f'(x), 
		(int mode, double x);		//с округлением или без

	/*------------------------виртуальные методы------------------------*/
	virtual double Equation(void);	//обработка рез-та работы dihotom
	virtual double MAX();			//поиск локального max на отрезке
	virtual double MIN();			//поиск локального min на отрезке
	virtual double CountY(double x);//расчёт f(x)
	virtual double CountdY(double x);//расчёт f'(x)
	/*------------------------------------------------------------------*/

};//end class Func

/*-------------------------- Класс ЭКСПОНЕНТА --------------------------*/
class ExpFunc : public Func {
public:
	ExpFunc							//конструктор
		(double InitA = -5, double InitB = 2);
	~ExpFunc(void) {};				//деструктор

	//перегруженные методы из Func
	double Equation(void);			//обработка рез-та работы dihotom
	double CountY(double x);		//расчёт f(x)
	double CountdY(double x);		//расчёт f'(x)

};//end class ExpFunc

/*---------------------------- Класс СИНУС -----------------------------*/
class SinFunc : public Func {
public:
	SinFunc							//конструктор
	(double InitA = -2 * M_PI, double InitB = 2 * M_PI);
	~SinFunc(void) {};				//деструктор

	//перегруженные методы из Func
	double Equation(void);			//обработка рез-та работы dihotom
	double MAX();					//поиск локального max на отрезке
	double MIN();					//поиск локального min на отрезке
	double CountY(double x);		//расчёт f(x)
	double CountdY(double x);		//расчёт f'(x)

};//end class SinFunc

/*--------------------------- Класс КОСИНУС ----------------------------*/
class CosFunc : public Func {
public:
	CosFunc							//конструктор
	(double InitA = -2 * M_PI, double InitB = 2 * M_PI);
	~CosFunc(void) {};				//деструктор

	//перегруженные методы из Func
	double Equation(void);			//обработка рез-та работы dihotom
	double MAX();					//поиск локального max на отрезке
	double MIN();					//поиск локального min на отрезке
	double CountY(double x);		//расчёт f(x)
	double CountdY(double x);		//расчёт f'(x)

};//end class CosFunc

/*--------------------------- Класс ПАРАБОЛА ---------------------------*/
class ParabFunc : public Func {
public:
	ParabFunc						//конструктор
		(double InitA = -2, double InitB = 2);
	~ParabFunc(void) {};			//деструктор
	
	//перегруженные методы из Func
	double Equation(void);			//обработка рез-та работы dihotom
	double MAX();					//поиск локального max на отрезке
	double MIN();					//поиск локального min на отрезке
	double CountY(double x);		//расчёт f(x)
	double CountdY(double x);		//расчёт f'(x)

};//end class ParabFunc

/*--------------------- Класс НАТУРАЛЬНЫЙ ЛОГАРИФМ ---------------------*/
class LogFunc : public Func {
public:
	LogFunc							//конструктор
		(double InitA = 0.1, double InitB = 6);
	~LogFunc(void) {};				//деструктор

	//перегруженные методы из Func
	double CountY(double x);		//расчёт f(x)
	double CountdY(double x);		//расчёт f'(x)

};//end class LogFunc

/*---------------------- Класс КВАДРАТНЫЙ КОРЕНЬ -----------------------*/
class SqrtFunc : public Func {
public:
	SqrtFunc						//конструктор
	(double InitA = 0, double InitB = 7);
	~SqrtFunc(void) {};				//деструктор

	//перегруженные методы из Func
	double CountY(double x);		//расчёт f(x)
	double CountdY(double x);		//расчёт f'(x)

};//end class SqrtFunc

/************************************************************************\
|*                  П Р О Т О Т И П Ы    Ф У Н К Ц И Й                  *|
\************************************************************************/

void			 Move		(HDC hdc, Point point);
void			 Line		(HDC hdc, Point point);
double			 scale		(int mode, double arg, Point* dots);
string			 eng		(string rus);
double			 EPSround	(double x);
LRESULT CALLBACK WndProc	(HWND hwnd, UINT message, 
							 WPARAM wParam, LPARAM lParam);

/***********************   End of File CLASSES.H   **********************/