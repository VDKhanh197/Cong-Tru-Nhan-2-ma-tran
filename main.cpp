#include <iostream>
#include "matrix.h"

using namespace std;

int main()
{
    Matrix A, B;
    float k;
    //A.Show("Matrix A:");

    A.Init("Nhap MT A:");
    A.Show("Matrix A:");

    B.Init("Nhap MT B:");
    B.Show("Matrix B:");

    Matrix C = A;
    C.Show("Matrix C:");

    Matrix D = A.Add(C);
    D.Show("D = A + C=");

    Matrix M = A.Sub(B);
    M.Show("M = A - B=");

    Matrix N = A.Multi(k);
    N.Show("N = k * A=");

    Matrix E = A.Multi(B);
    E.Show("E = A * B =");

    Matrix F = B.Multi(A);
    F.Show("F = B * A = ");

   // Matrix P = A.Trans

    if (F.isMT0()==true)
        cout << "F = 0\n";
    else cout << "F != 0\n";
    return 0;
}
