#include <iostream>
#include<vector>
using namespace std;

class base {
public:
    virtual void show() {};
};

template <class T> class H {
protected:
    T h;
public:
    H(T h) : h(h) {};
};

template <class T> class Z {
protected:
    T z;
public:
    Z(T z) : z(z) {};
};

template <class T> class Point2D {
protected:
    T x, y;
public:
    Point2D(T x, T y) : x(x), y(y) {};
};


template <class T> class Point3Dh : public Point2D<T>, public Z<T>, public H<T>, base{
public:
    Point3Dh(T x, T y, T z, T h) : Point2D <T>(x, y), Z <T>(z), H <T>(h) {};
    void show() {
        if (this->h != 0)
            cout << "X: " << this->x << ", Y: " << this->y << ", Z: " << this->z << ", H: " << this->h << endl;
        else
            cout << "4 координата не должна быть равна 0";
    }
};

int main() {
    setlocale(LC_ALL, "Russian");

    Point3Dh <int> x1(1, 2, 3, 4);
    x1.show();
    Point3Dh <double> x2(1.11, 2.22, 3.33, 4.44);
    x2.show();
    Point3Dh <long> x3(100, 200, 300, 400);
    x3.show();
    Point3Dh <float> x4(1.5, 2.4, 3.3, 4.2);
    x4.show();
    Point3Dh <short> x5(1, 20, 30, 0);
    x5.show();

    vector <base*> K;
    K.push_back((base*)&x1);
    K.push_back((base*)&x2);
    K.push_back((base*)&x3);
    K.push_back((base*)&x4);
    K.push_back((base*)&x5);

    for (int i = 0; i < K.size(); i++) {
        K[i]->show();
    }

	return 0;
}
