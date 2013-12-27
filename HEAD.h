#include "stdafx.h"
#include <vector>
#include <string.h>
#include <fstream>
#include <iostream>
using namespace std;
class Range
{
	char* range;//суть ошибки
public:
	Range(char* s);//конструктор
	~Range();//деструктор
	void sendMessage();//функция распечатки информации об ошибке
};
class Table
{
protected:
	char* colour;//цвет
	char* material;//материал
	double table_price;//цена стола
	double material_price;//цена материала
	static int count;//счетчик объектов класса
	virtual void CountPrice() = 0;//чисто виртуальная функция,устанавливающая цену стола
public:
	Table();//конструктор по умолчанию
	Table(char* colour,char* material,double material_price);//инициализирующий конструктор
	virtual ~Table();//деструктор
	char* getColour()const;//возвращает цвет
	char* getMaterial()const;//возвращает материал
	double getTablePrice()const;//возвращает цену стола
	double getMaterialPrice()const;//возвращает цену материала
	void setColour(char* color);//устанавливает цвет
	void setMaterial(char* material);//устанавливает материал
	void setMaterialPrice(double material_price);//устанавливает цену материала
	virtual ostream & output(ostream & os)const;//чисто виртуальная функция распечатки данных объекта класса
	virtual istream & input(istream & is);//виртуальная функция ввода данных объекта класса
	static void displayCount();//функция распечатки кол-ва объектов класса
	static void resetCount();//функция сброса счетчика кол-ва объектов класса
};
class SquareTable:public Table
{
private:
	double width;//ширина столешницы
	double length;//длина столешницы
	double high;//высота стола
	void CountPrice();//функция,устанавливающая цену стола
public:
	SquareTable();//конструктор по умолчанию
	SquareTable(char* colour,char* material,double material_price,double width,double length,double high);//инициализирующий конструктор
	//~SquareTable();//деструктор
	double getWidth()const;//возвращает ширину столешницы
	double getLength()const;//возвращает длину столешницы
	double getHigh()const;//возвращает высоту стола
	void setWidth(double width);//устанавливает ширину столешницы
	void setLength(double length);//устанавливает длину столешницы
	void setHigh(double high);//устанавливает высоту стола
	ostream & output(ostream & os)const;//виртуальная функция распечатки данных объекта класса
	istream & input(istream & is);//виртуальная функция ввода данных объекта класса
};
class CircleTable:public Table
{
private:
	double r;//радиус столешницы
	int leg_amount;//количество ножек стола
	void CountPrice();//функция,устанавливающая цену стола
public:
	CircleTable();//конструктор по умолчанию
	CircleTable(char* colour,char* material,double material_price,double r,int leg_amount);//инициализирующий конструктор
	//~CircleTable();//деструктор
	double getR()const;//возвращает радиус столешницы
	int getLegAmount()const;//возвращает количество ножек стола
	void setR(double r);//устанавливает радиус столешницы
	void setLegAmount(int leg_amount);//устанавливает количество ножек стола
	ostream & output(ostream & os)const;//виртуальная функция распечатки данных объекта класса
	istream & input(istream & is);//виртуальная функция ввода данных объекта класса
};
ostream & operator<<(ostream & os,const Table & T);//перегрузка оператора вывода из потока
istream & operator>>(istream & is,Table & T);//перегрузка оператора ввода в поток
double TotalPrice(vector <Table *> & v);//функция подсчета общей цены набора изданий
