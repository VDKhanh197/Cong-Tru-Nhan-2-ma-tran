#ifndef MATRIX_H
#define MATRIX_H
class Matrix{
private:
    int m, n;
    float **a;
public:
    Matrix(int h=2, int c=2);
    Matrix(const Matrix &M);
    ~Matrix();
    void Init(char *s);
    void Show(char *s);
    Matrix Add(const Matrix &M);//Cộng hai ma trận
    Matrix Sub(const Matrix &M);//Trừ hai ma trận
    Matrix Multi(float k);//Nhân ma trận với số thực k
    Matrix Multi(const Matrix &M); //Nhân 2 ma trận với nhau
    bool isMTDV(); //Kiểm tra ma trận đơn vị
    bool isMT0(); //Kiểm tra có là ma trận 0
    Matrix Trans(); //Tìm ma trận chuyển vị
    bool isTrans(const Matrix &M); //Kiểm tra M có là ma trận chuyển vị
    float DTMT();//Tính định thức ma trận
    Matrix Inversion();//Tìm ma trận nghịch đảo
};
#endif // MATRIX_H
