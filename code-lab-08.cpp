#include <iostream>

using namespace std;

void initialize(int **a, int rows, int cols){//esta funcion sirve para ingresar los datos de una funcion
    for(int i = 0; i < rows; i++){
      for(int j = 0; j < cols; j++){
          cin >> *(*(a + i) + j);//ingreso el valor de la direccion de la posicion de mi matriz con punteros
      }
    }
}
int mult(int **a,int **b, int **rpt, int n, int h, int l, int i = 0, int j = 0, int k = 0){//funcion recursiva para ñla multiplicación de matrices
    if(i == n){
        return 0;//cuando mi iterador general llegue al numero de filas de la matriz 1 se detiene la función
    }
    if(j == l){//cuando mi segundo iterador llegue al numero de columnas de la matriz 2 este se reinicia junto con el tercer iterador
        return mult(a,b,rpt,n,h,l,++i,0,0);
    }
    if(k == h){//cuando mi tercer iterador tenga el
        return mult(a,b,rpt,n,h,l,i,++j,0);
    }
    *(*(rpt + i) + j) += *(*(a + i) + k) * *(*(b + k) + j);//a mi matriz rpt como al inicializar c++ me pone por defecto NULL el cual es cero se suma
    return mult(a,b,rpt,n,h,l,i,j,++k);//aumento el tercer iterador
}
void print(int **a,int rows, int cols){//funcion para imprimir mi matriz
  for(int i = 0; i < rows; i++){
    for(int j = 0; j < cols; j++){
      cout << *(*(a + i) + j) << " ";//imprimo mi matriz con punteros
    }
    cout << endl;
  }
}
void def_tam(int **rpt, int n,int k, int i = 0){//funcion recursiva que utilizo para definir el tamanio
  if(i == n){
    return;
  }
  rpt[i] = new int[k];
  def_tam(rpt, n , k, ++i);
}
void del_mat(int **rpt, int n, int i = 0){//funcion para eliminar una matriz
  if(i == n){
    delete [] rpt;//elimino el array raiz
    return;
  }
  delete [] rpt[i];//voy eliminando los arrays hijos
  del_mat(rpt,n,++i);
}

int main()
{
    int rows_1,cols_1;
    int rows_2,cols_2;
    cin >> rows_1 >> cols_1;//el usuario ingresa las filas de la primera matriz y sus columnas
    cin >> rows_2 >> cols_2;//el usuario ingresa las filas de la segunda matriz con sus columnas se sobreentiende que el usuario tiene que ingresar el mismo numero de columnas de la matriz 1 que con las filas de la matriz 2
    
    //inicializo todas mis matrices
    int **rpt = new int* [rows_1];
    def_tam(rpt,rows_1,cols_2);

    int **a = new int* [rows_1];
    def_tam(a,rows_1,cols_1);
    
    int **b = new int* [rows_2];
    def_tam(b,rows_2,cols_2);
    
    //initialize es para ingresar los valores que tomaran mis matrices
    initialize(a,rows_1,cols_1);
    initialize(b,rows_2,cols_2);
    mult(a,b,rpt,rows_1,cols_1,cols_2);
    print(rpt,rows_1,cols_2);
    
    //elimio mis matrices
    del_mat(a,rows_1);
    del_mat(b,rows_2);
    del_mat(rpt,rows_1);
    
    return 0;
}
