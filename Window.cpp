#include "Classes.h"					//объявление классов

extern Func* ActiveFunc;				//объект для построения графика

//инициализация окна
int Func::WinMain(void) {
	HINSTANCE histance;					//дескриптор модуля
	WNDCLASSEX wclass = { 0 };			//класс окна

	//получение дескриптора модуля
	histance = GetModuleHandleW(NULL);

	//ИНИЦИАЛИЗАЦИЯ ПОЛЕЙ КЛАССА ОКНА
	wclass.lpszClassName = L"MYCLASS";	//уникальное имя класса
	wclass.lpfnWndProc = WndProc;		//функция обработки сообщений
	wclass.hInstance = histance;		//дескриптор модуля
	//размер структуры для определения, какая версия API используется
	wclass.cbSize = sizeof(WNDCLASSEX);	
	//включение перерисовки окна при изменении размеров окна
	wclass.style = CS_HREDRAW | CS_VREDRAW;
	//белый фон окна
	wclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);

	//регистрирация класса окна
	RegisterClassEx(&wclass);

	//создание окна
	HWND window = CreateWindowExW(
		0,
		wclass.lpszClassName,			//имя класса
		L"График функции",				//заголовок окна
		WS_POPUPWINDOW | WS_CAPTION,	//тип окна
		550, 0,							//отступы слева и сверху
		600, 725,						//ширина и высота окна
		0,								//ссылка на родительское окно
		0,								//дескриптор меню
		histance,						//дескриптор модуля
		0
	);

	//отображение окна
	ShowWindow(window, SW_SHOW);
	//обновление окна
	UpdateWindow(window);

	//цикл обработки сообщений окна
	MSG msg = { 0 };
	while (GetMessage(&msg, 0, 0, 0)) {
		//преобразование виртуальной клавиши в ASCII-код
		TranslateMessage(&msg);
		//передача сообщения в "главную функцию обработки сообщений"
		DispatchMessage(&msg);
	}//end while

	return 0;                            //завершение работы с окном
}//end Func::WinMain()

//главная функция обработки сообщений
LRESULT WINAPI WndProc(
	HWND hwnd,							//дескриптор окна
	UINT msg,							//сообщение
	WPARAM wParam, 
	LPARAM lParam) {
	PAINTSTRUCT ps; 
	HDC hdc;							//контекст устройства
	
	//обработка сообщения в соответствии с его кодом
	switch (msg) {
	case WM_DESTROY:					//сообщение о удалении окна
		PostQuitMessage(0);				//отправить сообщения WM_QUIT
		break;

	case WM_CREATE:						//сообщение о создании окна
		hdc = GetDC(hwnd);				//получить контекст устройства
		break;

	case WM_PAINT:						//сообщение об обновлении окна
		hdc = BeginPaint(hwnd, &ps);	//начало рисования в окне
		ActiveFunc->Graphic(hdc);		//построить график активной ф-ии
		EndPaint(hwnd, &ps);			//конец рисования в окне
		break;

	case WM_KEYDOWN:					//сообщение о нажатии клавиши
		if (wParam == VK_ESCAPE) {		//нажата кнопка Esc
			ShowWindow(hwnd, SW_HIDE);	//закрыть окно
			PostQuitMessage(0);			//отправить сообщения WM_QUIT
		}
		break;
	}//end switch

	//обработка всеч остальных сообщений обработчиком "по умолчанию"
	return DefWindowProc(hwnd, msg, wParam, lParam);

}//end LRESULT WINAPI WndProc()

/***********************   End of File WINDOW.H   ***********************/