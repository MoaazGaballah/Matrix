#include <iostream>

class matrix
{
private:
    int row, col;
    int **mat;

public:
    matrix(); // done
    matrix(int,int); // bu yapici metod ile belirlenen row col boyutunda bir matrix
                    // heap te new keywordu ile oluşturulacaktır. done
    void printMatrix();// done
    void setRow(int); // done
    void setCol(int); // done
    int getRow()const; // done
    int getCol()const; // done
    matrix operator+(const matrix&); // iki matrisi birbiri ile toplayan // done
    matrix operator-(const matrix&); // iki matrisi birbiri ile çıkaran  // done
    int** operator<(int); // matris tüm elemanlarını verilen int ile karşılaştırıp
                        // matris elemanı küçükse 0 değilse 1 yazan ve geri matrisi döndüren metod   // done
    void operator--(); // matris tüm elemanlarını 1 azaltan // done 
    void operator++(); // matris tüm elemanlarını 1 artıran // done
    friend std::ostream& operator<<(std::ostream&, const matrix &); // matrisi ekrana yazdıran
                                        // ^ operatörünü şu şekilde overload etmeniz gerekmektedir
                                        // matrix^3 şeklinde kullanıldıysa eğer tüm matris elemanlarının küpünü alıp geri
                                        // geri döndüren overload metod.
                                        // ~ operatörünü şu şekilde overload etmeniz gerekmektedir
                                        // ~matrix şeklinde kullanıldıysa eğer matrisin transpozunu alıp geri döndüren
                                        // overload metod. // done
    ~matrix();// heapte bulunan matrisi iade eden yıkıcı // done
};
