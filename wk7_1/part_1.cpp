#include <iostream>
using namespace std;
// 在此处补充你的代码
template <class T>
class CArray3D {
public:
    int x_size, y_size, z_size;
    T*** array3d;
    CArray3D(int a, int b, int c): x_size(a), y_size(b), z_size(c){
        array3d = new T **[a];
        for (int i = 0; i<a; i++){
            array3d[i] = new T *[b];
            for (int j = 0; j<b; j++){
                array3d[i][j] = new T [c];
            }
        }
    }
    ~CArray3D(){
        if (array3d != NULL){
            for (int i = 0; i<x_size; i++){
                for (int j = 0; j<y_size; j++){
                    delete [] array3d[i][j];
                }
                delete [] array3d[i];
            }
            delete [] array3d;
        }
    }

    // from stackoverflow
    // for Array2[][]


    class Proxy2D{
        T **_array2d;
    public:
        Proxy2D(T ** _array2d): _array2d(_array2d){}
        T * operator[](int index){
            return _array2d[index];
        }

        class Proxy{
            T * _array;
        public:
            Proxy(T * _array): _array(_array){}
            T & operator[](int index){
                return _array[index];
            }
        };
        /*
        Proxy operator[](int index){
            return Proxy2D(array3d[index]));
        }
        */
    };

    Proxy2D operator[](int index){
        return Proxy2D(array3d[index]);
    }



    // for operator =
    CArray3D & operator=( const CArray3D & operand){
        if (array3d == operand.array3d) return *this;
        if (array3d != NULL){
            for (int i = 0; i<x_size; i++){
                for (int j = 0; j<y_size; j++){
                    delete [] array3d[i][j];
                }
                delete [] array3d[i];
            }
            delete [] array3d;
            x_size = 0;
            y_size = 0;
            z_size = 0;
        }
        if (operand.array3d != NULL){
            x_size = operand.x_size;
            y_size = operand.y_size;
            z_size = operand.z_size;
            array3d = new T **[x_size];
            for (int i = 0; i<x_size; i++){
                array3d[i] = new T *[y_size];
                for (int j = 0; j<y_size; j++){
                    array3d[i][j] = new T [z_size];
                }
            }

            /////
            for (int i = 0; i < x_size; i++){
                for (int j = 0; j < y_size; j++){
                    for (int k = 0; k < z_size; k++)
                    array3d[i][j][k] = operand.array3d[i][j][k];
                }
            }

        } else {
            array3d = NULL;
        }
        return *this;
    }
};


int main()
{
    CArray3D<int> a(3,4,5);
    int No = 0;
    for( int i = 0; i < 3; ++ i )
        for( int j = 0; j < 4; ++j )
            for( int k = 0; k < 5; ++k )
                a[i][j][k] = No ++;
    for( int i = 0; i < 3; ++ i )
        for( int j = 0; j < 4; ++j )
            for( int k = 0; k < 5; ++k )
                cout << a[i][j][k] << ",";
    return 0;
}
