#pragma once
class fecha
{
public:
	fecha(int d=0,int m=0,int a=0);
	~fecha();

private:
	int dia;
	int mes;
	int anio;
	bool biciesto;

};

