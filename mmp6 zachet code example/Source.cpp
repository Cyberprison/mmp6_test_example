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
		x = 0; //��� x �� �����? ��� ������� ������ ����?
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
	//���������
	vect2& operator=(vect2 &z)
	{
		//x = 0;
		x = z.x;
		py = new double;
		*py = *z.py;
		return *this;
	}

	//����������� ����������� �� ������� �������������
	/*
	vect2(vect2 &z) :
		x(z.x),
		py(new double(*z.py))
	{}
	*/

	//����������� �����������
	vect2(vect2 &z)
	{
		x = z.x;

		py = new double;
		*py = *z.py;

		//���
		//py = new double(*z.py);
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
	//����� ��� ����������� �� ��������� ������ �������������
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

	//����������
	/*
	~vect2() 
	{
		//��� x ������ �� ����
		delete py;
	}
	*/

	//���������� ���������(��������) ����� � ����������
	//������
	//������, ����� ��� �������� ��� �� ������
	//����� � ���� ��� ������� ����� ������, ��� ��������� ������
};


//�) ����� �����: (���������� ������)
class dvect3 : public vect2
{
private:
	double *pz;
public:
	//6. �������� ����������� �����������.
	dvect3(dvect3 &z) 
	{
		pz = new double;
		*pz = *z.pz;

		//������ �� ����� new ��� ������������ �����???
		x = z.x;
		*py = *z.py;
	}

	//����������� ����������� �� ������� �������������(� �������)
	/*
	dvect3(dvect3 &z) :
		vect2(z),
		pz(new double(*z.pz))
	{}
	*/

	//7. �������� ����������� ��� ����������.
	dvect3() 
	{
		pz = new double;
		*pz = NULL; //����� �� ���� ��������???

		//������ ���� ������ ��� ������������� ������ vect2???
	}

	//����������� ��� ���������� �� ������� �������������
	/*
	dvect3():
		pz(new double(NULL))
	{}
	*/

	//8. ����������� �������� ������������.
	dvect3& operator=(dvect3 &z)
	{
		pz = new double;
		*pz = *z.pz;

		/*
		x = z.x;
		*py = *z.py;
		*/

		//���????
		//vect2(z.x, *z.py);

		vect2::operator=(z); //����� ��� ����

		return *this;
	}

	//9. ����������� �������� ������ ������ �� �����.
	//������ ��� friend �� �������� ��������� �������� ������
	friend std::ostream& operator<<(std::ostream &out, dvect3 &z)
	{
		out << (vect2&)z;

		out << "*pz = ";
		out << *z.pz;
		out << "\n";

		return out;
	}

	//10. �������� �����, ����������� �������� ���� ��������.
	dvect3& diff(dvect3 &v, dvect3 &w)
	{
		x = v.x + (-1.0)*w.x;
		*py = *v.py + *w.py*(-1.0);
		*pz = *v.pz + *w.pz*(-1.0);
		return *this;
	}

	//����������
	/*
	~dvect3() 
	{
		//x
		//delete py; //������ �� ����� ������� ��������� �� py
		delete pz;
	}
	*/

	//������ ��

	//����������� � ����� ����������� �� ������� ������������� � ���
	dvect3 (double x0, double y0, double z0):
		//�� ��������
		//x(x0),
		//py(new double(y0)),

		vect2(x0, y0),

		pz(new double(z0))
	{}

	//����������� � ������� � ���������� �� ������� ������������� � ���
	/*
	dvect3 (vect2 z, double z0):
		vect2(z),
		pz(new double(z0))
	{}
	*/

	//������ � ����������� �� ���������
	void set(double x0, double y0, double z0) {
		//�.� ���� ������� � �������� vect2
		x = x0;
		py = new double(y0);
		
		//�� ���� �� ���???
		
		pz = new double(z0);
	}

	//������
};


int main() 
{
	/*
	//�������� ������ �
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