/*

   Programa criado por Bruno Ribeiro de Almeida.
   Data: Setembro de 2020.

   Descrição: Software que classifica matrizes entre simétrica, anti-simétrica, identidade, nula ou desconhecida.

   Código compilado em c++17.

*/


#include <iostream>
#include <string>


namespace ALinear{

   double **createMatrix(int &rows, int &columns){

      double **array = new double*[rows];
      for(int count{0}; count < rows; ++count){
         array[count] = new double[columns];
      }

      return array;

   }

   bool isSquare(const int &rows, const int &columns){

      return (rows == columns) ? true : false;

   }

   
   bool isSymmetrical(double **matrix, const int &rows, const int columns){

      if(!isSquare(rows, columns)){
         return false;
      }else{
         for(int valueL{0}; valueL < rows; ++valueL){
            for(int valueC{0}; valueC < columns; ++valueC){
               if(matrix[valueL][valueC] != matrix[valueC][valueL]){
                  return false;
               }
            }
         }
      }

      return true;

   }

   bool isAntiSimmetrical(double **matrix, const int &rows, const int &columns){

      if(!isSquare(rows, columns)){
         return false;
      }else{

         for(int valueL{0}; valueL < rows; ++valueL){
            for(int valueC{0}; valueC < columns; ++valueC){
               if(matrix[valueL][valueC] != (-matrix[valueC][valueL])){
                  return false;
               }
            }
         }
         
      }

      return true;
      

   }

   bool isNull(double **matrix, const int &rows, const int &columns){

      for(int valueL{0}; valueL < rows; ++valueL){

         for(int valueC{0}; valueC < columns; ++valueC){
            if(matrix[valueL][valueC] != 0){
               return false;
            }
         }

      }

      return true;

   }

   bool isIdentity(double **matrix, const int &rows, const int &columns){

      if(!isSquare(rows, columns)){

         return false;
         
      }else{

         for(int valueL{0}; valueL < rows; ++valueL){

            if(matrix[valueL][valueL] != 1){
                  return false;
            }

            for(int valueC{0}; valueC < columns; ++valueC){
               
               if(valueL != valueC && matrix[valueL][valueC] != 0){
                  return false;
               }
            
            }
         }
      }

      return true;
      

   }


}

void getRowsAndColumns(int &rows, int &columns){

   std::cout << "Digite o numero de linhas da matriz: ";
   std::cin >> rows;
   std::cout << "Digite o numero de colunas da matriz: ";
   std::cin >> columns;


}

void numbersOfMatrix(double **matrix, const int &rows, const int &columns){


   for(int valueL{0}; valueL < rows; ++valueL){
      for(int valueC{0}; valueC < columns; ++valueC){
         std::cout << "Digite o valor do elemento: [" << valueL+1 << "]" << "[" << valueC+1 << "]: ";
         std::cin >> matrix[valueL][valueC];
      }
   }


}


int main(){


   
   int rows{0};
   int columns {0};

   std::string classe{};

   getRowsAndColumns(rows, columns);

   double **matrix{ALinear::createMatrix(rows, columns)};

   numbersOfMatrix(matrix, rows, columns);

   std::cout << "Sua matriz é: ";

   if(ALinear::isAntiSimmetrical(matrix, rows, columns))
      classe += "Anti-simetrica; ";
   if(ALinear::isNull(matrix, rows, columns))
      classe += "Nula; ";
   if(ALinear::isIdentity(matrix, rows, columns))
      classe += "Identidade; ";
   if(ALinear::isSymmetrical(matrix, rows, columns))
      classe += "Simetrica; ";
   if(std::size(classe) == 0)
      classe += "Indefinida; ";
   

   std::cout << classe << '\n';
   

   return 0;
}