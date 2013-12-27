#include "stdafx.h"
#include "HEAD.h"
Range::Range(char* s)
{
	range = new char[50];
	strcpy(range,s);
}
Range::~Range(){delete [] range;}
void Range::sendMessage(){cout << "ERROR: " << range << endl;}
int Table::count = 0;
Table::Table()
{
	colour = new char[20];
	strcpy(colour,"white");
	material = new char[20];
	strcpy(material,"acril");
	table_price = 0;
	material_price = 300;
	count++;
}
Table::Table(char* colour,char* material,double material_price)
{
	if(strlen(colour) > 20)
	{
		Range * r = new Range("too big colour name!");
		throw r;
	}
	colour = new char[20];
	strcpy(this->colour,colour);
	if(strlen(material) > 20)
	{
		Range * r = new Range("too big material name!");
		throw r;
	}
	material = new char[20];
	strcpy(this->material,material);
	if(material_price<10 || material_price>2000)
	{
		Range * r = new Range("invalid material price!");
		throw r;
	}
	this->material_price = material_price;
	count++;
}
Table::~Table()
{
	delete [] colour;
	delete [] material;
	count --;
}
char* Table::getColour()const{return colour;}
char* Table::getMaterial()const{return material;}
double Table::getTablePrice()const{return table_price;}
double Table::getMaterialPrice()const{return material_price;}
void Table::setColour(char* color)
{
	if(strlen(color) > 20)
	{
		Range * r = new Range("too big colour name!");
		throw r;
	}
	strcpy(this->colour,color);
}
void Table::setMaterial(char* material)
{
	if(strlen(material) > 20)
	{
		Range * r = new Range("too big material name!");
		throw r;
	}
	strcpy(this->material,material);
}
void Table::setMaterialPrice(double material_price)
{
	if(material_price<10 || material_price>2000)
	{
		Range * r = new Range("invalid material price!");
		throw r;
	}
	this->material_price = material_price;
	CountPrice();
}
ostream & Table::output(ostream & os)const{return os<<"material: "<<material<<", colour: "<<colour<< ", price: "<<table_price<<'$'<<endl;}
istream & Table::input(istream & is)
{
	char str[50];
	double temp;
	is >> str;
	if(strlen(str) > 20)
	{
		Range * r = new Range("too big colour name!");
		throw r;
	}
	strcpy(colour,str);
	is >> str;
	if(strlen(str) > 20)
	{
		Range * r = new Range("too big material name!");
		throw r;
	}
	strcpy(material,str);
	is >> temp;
	if(temp<10 || temp>2000)
	{
		Range * r = new Range("invalid material price!");
		throw r;
	}
	material_price = temp;
	CountPrice();
	return is;
}
void Table::displayCount(){cout << "There are " << count << " table(s)" << endl;}
void Table::resetCount(){count = 0;}
void SquareTable::CountPrice(){table_price = (width*length + 2*high*width)*material_price*1.2;}
SquareTable::SquareTable():Table()
{
	width = 1;
	length = 2;
	high = 1;
	CountPrice();
}
SquareTable::SquareTable(char* colour,char* material,double material_price,double width,double length,double high):Table(colour,material,material_price)
{
	if(width<0 || width>8)
	{
		Range * r = new Range("invalid table width!");
		throw r;
	}
	this->width = width;
	if(length<0 || length>8)
	{
		Range * r = new Range("invalid table length!");
		throw r;
	}
	this->length = length;
	if(high<0 || high>1.5)
	{
		Range * r = new Range("invalid table high!");
		throw r;
	}
	this->high = high;
	CountPrice();
}
/*SquareTable::~SquareTable()
{
	count--;
}*/
double SquareTable::getWidth()const{return width;}
double SquareTable::getLength()const{return length;}
double SquareTable::getHigh()const{return high;}
void SquareTable::setWidth(double width)
{
	if(width<0 || width>8)
	{
		Range * r = new Range("invalid table width!");
		throw r;
	}
	this->width = width;
	CountPrice();
}
void SquareTable::setLength(double length)
{
	if(length<0 || length>8)
	{
		Range * r = new Range("invalid table length!");
		throw r;
	}
	this->length = length;
	CountPrice();
}
void SquareTable::setHigh(double high)
{
	if(high<0 || high>1.5)
	{
		Range * r = new Range("invalid table high!");
		throw r;
	}
	this->high = high;
	CountPrice();
}
ostream & SquareTable::output(ostream & os)const
{
	os << "square table, ";
	return Table::output(os);
}
istream & SquareTable::input(istream & is)
{
	//cout<<"Please,enter information about table(colour,material,price of material,width,length,high): "<<endl;
	Table::input(is);
	double temp;
	is >> temp;
	if(temp<0 || temp>8)
	{
		Range * r = new Range("invalid table width!");
		throw r;
	}
	width = temp;
	is >> temp;
	if(temp<0 || temp>8)
	{
		Range * r = new Range("invalid table length!");
		throw r;
	}
	length = temp;
	is >> temp;
	if(temp<0 || temp>1.5)
	{
		Range * r = new Range("invalid table high!");
		throw r;
	}
	high = temp;
	CountPrice();
	return is;
}
void CircleTable::CountPrice(){table_price = (3,14*r*r*material_price + leg_amount*20)*1.2;}
CircleTable::CircleTable():Table()
{
	r = 1;
	leg_amount = 4;
	CountPrice();
}
CircleTable::CircleTable(char* colour,char* material,double material_price,double r,int leg_amount):Table(colour,material,material_price)
{
	if(r<0 || r>2)
	{
		Range * rn = new Range("invalid table radius!");
		throw rn;
	}
	this->r = r ;
	if(leg_amount<0 || leg_amount>7)
	{
		Range * rn = new Range("invalid leg's amount!");
		throw rn;
	}
	this->leg_amount = leg_amount;
	CountPrice();
}
/*CircleTable::~CircleTable()
{
	count--;
}*/
double CircleTable::getR()const{return r;}
int CircleTable::getLegAmount()const{return leg_amount;}
void CircleTable::setR(double r)
{
	if(r<0 || r>2)
	{
		Range * r = new Range("invalid table radius!");
		throw r;
	}
	this->r = r;
	CountPrice();
}
void CircleTable::setLegAmount(int leg_amount)
{
	if(leg_amount<0 || leg_amount>7)
	{
		Range * r = new Range("invalid leg's amount!");
		throw r;
	}
	this->leg_amount = leg_amount;
	CountPrice();
}
ostream & CircleTable::output(ostream & os)const
{
	os << "circle table, ";
	return Table::output(os);
}
istream & CircleTable::input(istream & is)
{
	//cout<<"Please,enter information about table(colour,material,price of material,table radius,leg's amount): "<<endl;
	Table::input(is);
	double temp;
	is >> temp;
	if(temp<0 || temp>2)
	{
		Range * r = new Range("invalid table radius!");
		throw r;
	}
	r = temp;
	is >> temp;
	if(temp<0 || temp>7)
	{
		Range * r = new Range("invalid leg's amount!");
		throw r;
	}
	leg_amount = temp;
	CountPrice();
	return is;
}
ostream & operator<<(ostream & os,const Table & T){return T.output(os);}
istream & operator>>(istream & is,Table & T){return T.input(is);}
double TotalPrice(vector <Table *> & v)
{
	double total_price = 0;
	vector <Table *>::iterator i;
	for(i = v.begin();i != v.end();i++)
		total_price+= (*i)->getTablePrice();
	return total_price;
}
