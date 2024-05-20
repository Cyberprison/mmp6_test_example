#include <iostream>

//А) Задан класс(двухмерный вектор)
class vect2
{
protected:
	double x;
	double *py;
public:
	//1. Написать конструктор без параметров
	vect2()
	{
		x = 0; //для x не нужен? или сделать равным нулю?
		py = new double;
		*py = NULL; //нужно ли задавать указателю нуль?
	}

	//конструктор без параметров в виде строки инициализации
	/*
	vect2 () :
		x(0),
		py(new double(NULL))
	{}
	*/

	//2. Перегрузить операцию присваивания.
	//каскадная
	vect2& operator=(vect2 &z)
	{
		//x = 0;
		x = z.x;
		py = new double;
		*py = *z.py;
		return *this;
	}

	//конструктор копирования со строкой инициализации
	/*
	vect2(vect2 &z) :
		x(z.x),
		py(new double(*z.py))
	{}
	*/

	//конструктор копирования
	vect2(vect2 &z)
	{
		x = z.x;

		py = new double;
		*py = *z.py;

		//или
		//py = new double(*z.py);
	}

	//3. Перегрузить операцию вывода данных на экран
	friend std::ostream &operator << (std::ostream &out, vect2 &z)
	{
		out << "x = ";
		out << z.x;
		out << "\n";

		out << "*py = ";
		out << *z.py;
		out << "\n";

		return out;
	}
	
	//4. Написать дружественную функцию, выполняющую проверку на равенство двух векторов.
	//методы обычный?
	//или перегрузка операции сравнения???
	friend int operator==(vect2 &v, vect2 &w)
	{
		if (v.x == w.x && *v.py == *w.py) 
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	
	//5. Написать метод, вычисляющий разность двух векторов.
	//предполагаю, что начало вектора в (0; 0), а конец в (x, *py)
	//v-w
	//равно
	//v.x + (-w.x)
	//*v.py + (-*w.py)
	vect2& diff(vect2 &v, vect2 &w)
	{
		x = v.x + (-1.0)*w.x;
		*py = *v.py + *w.py*(-1.0);
		return *this;
	}

	//мы никак не зададим значения для объекта, без конструктора с параметрами
	//ну или можно через геттеры и сеттеры
	//конструктор с параметрами в виде строки инициализации
	//можно еще конструктор не используя строку инициализации
	vect2(double x0, double y0):
		x(x0),
		py(new double(y0))
	{}
	/*
	vect2(double x0, double y0)
	{
		x = x0;
		py = new double;
		*py = y0;
	}
	*/

	//деструктор
	/*
	~vect2() 
	{
		//для x ничего не надо
		delete py;
	}
	*/

	//перегрузка оператора(операции) ввода с клавиатуры
	//геттер
	//сеттер, сразу все значения или по одному
	//вывод и ввод как обычный метод класса, как интерфейс класса
};


//В) Задан класс: (трехмерный вектор)
class dvect3 : public vect2
{
private:
	double *pz;
public:
	//6. Написать конструктор копирования.
	dvect3(dvect3 &z) 
	{
		pz = new double;
		*pz = *z.pz;

		//почему не нужен new для родительских полей???
		x = z.x;
		*py = *z.py;
	}

	//конструктор копирования со строкой инициализации(с ошибкой)
	/*
	dvect3(dvect3 &z) :
		vect2(z),
		pz(new double(*z.pz))
	{}
	*/

	//7. Написать конструктор без параметров.
	dvect3() 
	{
		pz = new double;
		*pz = NULL; //нужно ли нуль задавать???

		//почему нету вызова для родительского класса vect2???
	}

	//конструктор без параметров со строкой инициализации
	/*
	dvect3():
		pz(new double(NULL))
	{}
	*/

	//8. Перегрузить операцию присваивания.
	dvect3& operator=(dvect3 &z)
	{
		pz = new double;
		*pz = *z.pz;

		/*
		x = z.x;
		*py = *z.py;
		*/

		//или????
		//vect2(z.x, *z.py);

		vect2::operator=(z); //зачем так тооо

		return *this;
	}

	//9. Перегрузить операцию вывода данных на экран.
	//почему без friend не работает перегузка операции вывода
	friend std::ostream& operator<<(std::ostream &out, dvect3 &z)
	{
		out << (vect2&)z;

		out << "*pz = ";
		out << *z.pz;
		out << "\n";

		return out;
	}

	//10. Написать метод, вычисляющий разность двух векторов.
	dvect3& diff(dvect3 &v, dvect3 &w)
	{
		x = v.x + (-1.0)*w.x;
		*py = *v.py + *w.py*(-1.0);
		*pz = *v.pz + *w.pz*(-1.0);
		return *this;
	}

	//деструктор
	/*
	~dvect3() 
	{
		//x
		//delete py; //почему не нужно удалять указатель от py
		delete pz;
	}
	*/

	//методы ВВ

	//конструктор в тремя параметрами со строкой инициализации и без
	dvect3 (double x0, double y0, double z0):
		//не работает
		//x(x0),
		//py(new double(y0)),

		vect2(x0, y0),

		pz(new double(z0))
	{}

	//конструктор в классов и параметром со строкой инициализации и без
	/*
	dvect3 (vect2 z, double z0):
		vect2(z),
		pz(new double(z0))
	{}
	*/

	//сеттер в зависимости от сигнатуры
	void set(double x0, double y0, double z0) {
		//т.к нету сеттера у родителя vect2
		x = x0;
		py = new double(y0);
		
		//но если бы был???
		
		pz = new double(z0);
	}

	//геттер
};


int main() 
{
	/*
	//проверка пункта А
	vect2 a0;
	std::cout << a0;
	std::cout << "\n";

	vect2 a(2, 2);
	std::cout << a;
	std::cout << "\n";

	std::cout << (a0 == a);
	std::cout << "\n";
	std::cout << "\n";

	vect2 b;
	std::cout << b.diff(a0, a);
	std::cout << "\n";

	a0 = a;
	std::cout << a0;
	std::cout << "\n";

	std::cout << (a0 == a);
	std::cout << "\n";
	std::cout << "\n";
	*/

	dvect3 aaa;

	std::cout << aaa;
	std::cout << "\n";

	dvect3 aaa1(1, 2, 3);

	std::cout << aaa1;
	std::cout << "\n";

	dvect3 aaa2(aaa1);

	std::cout << aaa2;
	std::cout << "\n";

	aaa2 = aaa1 = aaa;

	std::cout << aaa;
	std::cout << "\n";
	std::cout << aaa1;
	std::cout << "\n";
	std::cout << aaa2;
	std::cout << "\n";

	aaa.set(1, 2, 3);
	aaa1.set(3, 2, 1);

	std::cout << aaa2.diff(aaa, aaa1);
	std::cout << "\n";

	return 0;
}