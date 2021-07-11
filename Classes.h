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
|*                          � � � �    � � � � � �                      *|
\************************************************************************/
/*---------------------------- ��������� ���� --------------------------*/
struct Color {
	int Red;						//�������
	int Green;						//�������
	int Blue;						//�����
};//end struct Color

/*----------------------- ��������� �������������� ---------------------*/
struct Point {
	double X;						//���������� X
	double Y;						//���������� Y
};//end struct Point

/*-------------------------- ��������� ������� -------------------------*/
class IFunc {
public:
	IFunc(void) {};						//�����������
	virtual ~IFunc(void) {};			//����������

	/*--------------������ ������� � �������� ����� ������--------------*/
	virtual void SetAB					//���������� �������
		(double newA, double newB) = 0;
	virtual double GetA(void) = 0;		//�������� ����� ������� �������
	virtual double GetB(void) = 0;		//�������� ������ ������� �������
	virtual string GetfName(void) = 0;	//�������� ������� f(x)
	virtual string GetdfName(void) = 0;	//�������� ������� f'(x)
	virtual string GetColName(void) = 0;//�������� �������� ����� �������
	/*------------------------------------------------------------------*/

	virtual void Caller					//��������� ������ ������������
		(int mode, double param1, double param2, double param3) = 0;
	virtual void Tabulation(int N) = 0;	//������������� �-��
	virtual void Graphic(HDC hdc) = 0;	//���������� �������
	virtual int WINAPI WinMain() = 0;	//������������� ����
	virtual double dihotom(int mode) = 0;//����� ����� ��������� f(x) = 0
	virtual bool isMax(double x) = 0;	//��������, ���� �� max � �����
	virtual bool isMin(double x) = 0;	//��������, ���� �� min � �����
	virtual double func					//����� f(x) ��� f'(x), 
		(int mode, double x) = 0;		//� ����������� ��� ���

	/*------------------------����������� ������------------------------*/
	virtual double Equation(void) = 0;	//��������� ���-�� ������ dihotom
	virtual double MAX() = 0;			//����� ���������� max �� �������
	virtual double MIN() = 0;			//����� ���������� min �� �������
	virtual double CountY(double x) = 0;//������ f(x)
	virtual double CountdY(double x) = 0;//������ f'(x)
	/*------------------------------------------------------------------*/

};//end class IFunc

/*---------------------------- �����  ������� --------------------------*/
class Func : public IFunc {
protected:
	Color GC = { 0, 173, 69 };		//���� �������
	double A;						//����� ������� �������
	double B;						//������ ������� �������
	string fName = "1.2 * x - 3";	//������� f(X) ��� ������
	string dfName = "1.2";			//������� f'(X) ��� ������
	string colName = "�������";		//�������� ����� �������

public:
	Func							//�����������
		(double InitA = -5, double InitB = 5);
	~Func(void) {};					//����������

	/*--------------������ ������� � �������� ����� ������--------------*/
	virtual void SetAB				//���������� �������
		(double newA, double newB);
	virtual double GetA(void);		//�������� ����� ������� �������
	virtual double GetB(void);		//�������� ������ ������� �������
	virtual string GetfName(void);	//�������� ������� f(x)
	virtual string GetdfName(void);	//�������� ������� f'(x)
	virtual string GetColName(void);//�������� �������� ����� �������
	/*------------------------------------------------------------------*/

	virtual void Caller				
		(int mode, double param1, double param2, double param3);
	virtual void Tabulation(int N);	//������������� �������
	virtual void Graphic(HDC hdc);	//���������� ������� �������
	virtual int WINAPI WinMain();	//������������� ����
	virtual double dihotom(int mode);//����� ����� ��������� f(x) = 0
	virtual bool isMax(double x);	//��������, ���� �� max � �����
	virtual bool isMin(double x);	//��������, ���� �� min � �����
	virtual double func				//����� f(x) ��� f'(x), 
		(int mode, double x);		//� ����������� ��� ���

	/*------------------------����������� ������------------------------*/
	virtual double Equation(void);	//��������� ���-�� ������ dihotom
	virtual double MAX();			//����� ���������� max �� �������
	virtual double MIN();			//����� ���������� min �� �������
	virtual double CountY(double x);//������ f(x)
	virtual double CountdY(double x);//������ f'(x)
	/*------------------------------------------------------------------*/

};//end class Func

/*-------------------------- ����� ���������� --------------------------*/
class ExpFunc : public Func {
public:
	ExpFunc							//�����������
		(double InitA = -5, double InitB = 2);
	~ExpFunc(void) {};				//����������

	//������������� ������ �� Func
	double Equation(void);			//��������� ���-�� ������ dihotom
	double CountY(double x);		//������ f(x)
	double CountdY(double x);		//������ f'(x)

};//end class ExpFunc

/*---------------------------- ����� ����� -----------------------------*/
class SinFunc : public Func {
public:
	SinFunc							//�����������
	(double InitA = -2 * M_PI, double InitB = 2 * M_PI);
	~SinFunc(void) {};				//����������

	//������������� ������ �� Func
	double Equation(void);			//��������� ���-�� ������ dihotom
	double MAX();					//����� ���������� max �� �������
	double MIN();					//����� ���������� min �� �������
	double CountY(double x);		//������ f(x)
	double CountdY(double x);		//������ f'(x)

};//end class SinFunc

/*--------------------------- ����� ������� ----------------------------*/
class CosFunc : public Func {
public:
	CosFunc							//�����������
	(double InitA = -2 * M_PI, double InitB = 2 * M_PI);
	~CosFunc(void) {};				//����������

	//������������� ������ �� Func
	double Equation(void);			//��������� ���-�� ������ dihotom
	double MAX();					//����� ���������� max �� �������
	double MIN();					//����� ���������� min �� �������
	double CountY(double x);		//������ f(x)
	double CountdY(double x);		//������ f'(x)

};//end class CosFunc

/*--------------------------- ����� �������� ---------------------------*/
class ParabFunc : public Func {
public:
	ParabFunc						//�����������
		(double InitA = -2, double InitB = 2);
	~ParabFunc(void) {};			//����������
	
	//������������� ������ �� Func
	double Equation(void);			//��������� ���-�� ������ dihotom
	double MAX();					//����� ���������� max �� �������
	double MIN();					//����� ���������� min �� �������
	double CountY(double x);		//������ f(x)
	double CountdY(double x);		//������ f'(x)

};//end class ParabFunc

/*--------------------- ����� ����������� �������� ---------------------*/
class LogFunc : public Func {
public:
	LogFunc							//�����������
		(double InitA = 0.1, double InitB = 6);
	~LogFunc(void) {};				//����������

	//������������� ������ �� Func
	double CountY(double x);		//������ f(x)
	double CountdY(double x);		//������ f'(x)

};//end class LogFunc

/*---------------------- ����� ���������� ������ -----------------------*/
class SqrtFunc : public Func {
public:
	SqrtFunc						//�����������
	(double InitA = 0, double InitB = 7);
	~SqrtFunc(void) {};				//����������

	//������������� ������ �� Func
	double CountY(double x);		//������ f(x)
	double CountdY(double x);		//������ f'(x)

};//end class SqrtFunc

/************************************************************************\
|*                  � � � � � � � � �    � � � � � � �                  *|
\************************************************************************/

void			 Move		(HDC hdc, Point point);
void			 Line		(HDC hdc, Point point);
double			 scale		(int mode, double arg, Point* dots);
string			 eng		(string rus);
double			 EPSround	(double x);
LRESULT CALLBACK WndProc	(HWND hwnd, UINT message, 
							 WPARAM wParam, LPARAM lParam);

/***********************   End of File CLASSES.H   **********************/