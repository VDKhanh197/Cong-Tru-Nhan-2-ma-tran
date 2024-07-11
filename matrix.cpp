#include<iostream>
#include"matrix.h"
using namespace std;
Matrix::Matrix(int h, int c)
{
    int i, j;
    m = h;
    n = c;
    a = new float *[m];
    for (i=0; i<m; i++)
        a[i] = new float [n];

    for (i=0; i<m; i++)
        for (j=0; j<n; j++)
            a[i][j] = 0;

}
Matrix::Matrix(const Matrix &M)
{
    int i, j;
    m = M.m;
    n = M.n;
    a = new float *[m];
    for (i=0; i<m; i++)
        a[i] = new float [n];

    for (i=0; i<m; i++)
        for (j=0; j<n; j++)
            a[i][j] = M.a[i][j];
}
Matrix::~Matrix()
{
    for (int i=0; i<m; i++)
        delete a[i];
    delete a;
}
void Matrix::Init(char *s)
{
    cout << s << endl;
    int i, j;
    for (i=0; i<m; i++)
    for (j=0; j<n; j++)
        cin >> a[i][j];
}
void Matrix::Show(char *s)
{
    int i, j;
    cout << s << endl;
    for (i=0; i<m; i++)
    {
        for (j=0; j<n; j++)
            cout << a[i][j] << "\t";
        cout << endl;
    }
    cout << endl;
}

Matrix Matrix::Add(const Matrix &M)
{
    int i, j;
    if ((m==M.m)&&(n==M.n))
    {
        Matrix kq(m,n);
        for (i=0; i<m; i++)
        for (j=0; j<n; j++)
            kq.a[i][j] = a[i][j]+M.a[i][j];
        return kq;
    }
    else
    {
        cout << "Khong cong duoc\n";
        return Matrix(0,0);
    }
}
Matrix Matrix::Sub(const Matrix &M)
{
    int i, j;
    if ((m==M.m)&&(n==M.n))
    {
        Matrix kq(m,n);
        for (i=0; i<m; i++)
        for (j=0; j<n; j++)
            kq.a[i][j] = a[i][j]-M.a[i][j];
        return kq;
    }
    else
    {
        cout << "Khong tru duoc\n";
        return Matrix(0,0);
    }
}
Matrix Matrix::Multi(float k = 3)
{
Matrix kq(m,n);
for(int i=0; i<m; i++)
    for(int j=0; j<n; j++ )
        kq.a[i][j] = k* a[i][j];
    return kq;

}

Matrix Matrix::Multi(const Matrix &M)
{
    int i, j, k;
    if (n==M.m)
    {
        Matrix kq(m,M.n);
        for (i=0; i<m; i++)
        for (j=0; j<M.n; j++)
        for (k=0; k<n; k++)
            kq.a[i][j] += a[i][k]*M.a[k][j];
        return kq;
    }
    else
    {
        cout << "Khong nhan duoc\n";
        return Matrix(0,0);
    }
}
bool Matrix::isMTDV()
{
    if (m==n)
    {
        for(int i=0; i<m; i++)
    for(int j=0; j<n; j++ )
    {
        if (i==j && a[i][j]!=1)
            return false;
        else if(i!=j && a[i][j] != 0)
            return false;
    }
    return true;
    }
    else return false;
}
bool Matrix::isMT0()
{
    int i, j;
    for (i=0; i<m; i++)
    for (j=0; j<n; j++)
    {
        if (a[i][j]!=0)
            return false;
    }
    return true;
}

Matrix Matrix::Trans()
{
    Matrix CV(n, m);
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
        CV.a[i][j] = a[i][j];
    return CV;
}
bool Matrix::isTrans(const Matrix &M)
{
    if (m==M.n && n==M.m)
    {
        for(int i=0; i<m; i++)
    for(int j=0; j<n; j++ )
    {
        if (a[i][j] != M.a[i][j])
            return false;
    }
    return true;
    }
    else return false;
}
/*
float Matrix::DTMT();
Matrix Matrix::Inversion();
*/

