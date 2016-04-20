class Array2 {
private:
    int ** array2d;
    int x_size, y_size;
public:
    Array2(){
        array2d = NULL;
    }
    Array2(int d1, int d2){
        x_size = d2;
        y_size = d1;
        array2d = new int*[d1];
        for (int i = 0; i < d1; i++){
            array2d[i] = new int[d2];
        }
    }
    ~Array2(){
        if (array2d != NULL){
            for (int i = 0; i<y_size; i++){
                delete []array2d[i];
            }
            delete []array2d;
        }
    }

    // from stackoverflow
    // for Array2[][]
    class Proxy{
        int * _array;
    public:
        Proxy(int * _array): _array(_array){}
        int & operator[](int index){
            return _array[index];
        }
    };

    Proxy operator[](int index){
        return Proxy(array2d[index]);
    }

    // for operator =
    Array2 & operator=( const Array2 & operand){
        if (array2d == operand.array2d) return *this;
        if (array2d != NULL){
            for (int i = 0; i<y_size; i++){
                delete []array2d[i];
            }
            delete []array2d;
            x_size = 0;
            y_size = 0;
        }
        if (operand.array2d != NULL){
            x_size = operand.x_size;
            y_size = operand.y_size;
            array2d = new int*[y_size];
            for (int i = 0; i < y_size; i++){
                array2d[i] = new int[x_size];
            }
            for (int i = 0; i < y_size; i++){
                for (int j = 0; j < x_size; j++){
                    array2d[i][j] = operand.array2d[i][j];
                }
            }

        } else {
            array2d = NULL;
        }
        return *this;
    }

    // for Array2(i,j)
    int & operator()(const int d1, const int d2){
        return array2d[d1][d2];
    }

};
