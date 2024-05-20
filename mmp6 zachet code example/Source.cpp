#include <iostream>

//�) ����� �����(���������� ������)
class vect2
{
protected:
	double x;
	double *py;
public:
	//1. �������� ����������� ��� ����������
	vect2()
	{
		x = 0; //��� x �� �����? ��� ����� ����?
		py = new double;
		*py = NULL; //����� �� �������� ��������� ����?
	}

	//����������� ��� ���������� � ���� ������ �������������
	/*
	vect2 () :
		x(0),
		py(new double(NULL))
	{}
	*/

	//2. ����������� �������� ������������.
	vect2 operator=(vect2 &z)
	{
		//x = 0;
		x = z.x;
		py = new double;
		*py = *z.py;
		return *this;
	}

	//3. ����������� �������� ������ ������ �� �����
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
	
	//4. �������� ������������� �������, ����������� �������� �� ��������� ���� ��������.
	//������ �������?
	//��� ���������� �������� ���������???
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
	
	//5. �������� �����, ����������� �������� ���� ��������.
	//�����������, ��� ������ ������� � (0; 0), � ����� � (x, *py)
	//v-w
	//�����
	//v.x + (-w.x)
	//*v.py + (-*w.py)
	vect2& diff(vect2 &v, vect2 &w)
	{
		x = v.x + (-1.0)*w.x;
		*py = *v.py + *w.py*(-1.0);
		return *this;
	}

	//�� ����� �� ������� �������� ��� �������, ��� ������������ � �����������
	//�� ��� ����� ����� ������� � �������
	//����������� � ����������� � ���� ������ �������������
	vect2(double x0, double y0):
		x(x0),
		py(new double(y0))
	{}
};


//�) ����� �����: (���������� ������)
class dvect3 : public vect2 
{
private:
	double *pz;
public:
	//6. �������� ����������� �����������.


	//7. �������� ����������� ��� ����������.


	//8. ����������� �������� ������������.


	//9. ����������� �������� ������ ������ �� �����.


	//10. �������� �����, ����������� �������� ���� ��������.



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