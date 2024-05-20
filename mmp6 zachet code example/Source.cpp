#include <iostream>

//ј) «адан класс(двухмерный вектор)
class vect2
{
protected:
	double x;
	double *py;
public:
	//1. Ќаписать конструктор без параметров
	vect2()
	{
		x = 0; //дл€ x не нужен? или равен нулю?
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

	//2. ѕерегрузить операцию присваивани€.
	vect2 operator=(vect2 &z)
	{
		//x = 0;
		x = z.x;
		py = new double;
		*py = *z.py;
		return *this;
	}

	//3. ѕерегрузить операцию вывода данных на экран
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
	
	//4. Ќаписать дружественную функцию, выполн€ющую проверку на равенство двух векторов.
	//методы обычный?
	//или перегрузка операции сравнени€???
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
	
	//5. Ќаписать метод, вычисл€ющий разность двух векторов.
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

	//мы никак не зададим значени€ дл€ объекта, без конструктора с параметрами
	//ну или можно через геттеры и сеттеры
	//конструктор с параметрами в виде строки инициализации
	vect2(double x0, double y0):
		x(x0),
		py(new double(y0))
	{}
};


//¬) «адан класс: (трехмерный вектор)
class dvect3 : public vect2 
{
private:
	double *pz;
public:
	//6. Ќаписать конструктор копировани€.


	//7. Ќаписать конструктор без параметров.


	//8. ѕерегрузить операцию присваивани€.


	//9. ѕерегрузить операцию вывода данных на экран.


	//10. Ќаписать метод, вычисл€ющий разность двух векторов.



};


int main() 
{
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

	return 0;
}