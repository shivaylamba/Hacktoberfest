public static void main(String[] args) {
    Scanner getIt = new Scanner(System.in);
    System.out.println("Input 1 integer n: ");
    int n = getIt.nextInt();
    if (n > 0){
        final double M[][][] = new double[n][n][n];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                for (int k = 0; k < n; k++)
                    M[i][j][k] = 3.0;
        System.out.println("Input 1 integer p: ");
        int p = getIt.nextInt();
        if(p > 0){
          for(int q = 1; q <= p; q++){
              for (int i = 0; i < n; i++){
                  for (int j = 0; j < n; j++){
                      for (int k = 0; k < n; k++){
                          System.out.printf("%f ", Math.pow(matrixMult(M[i], M[i])[j][k], q));
                      }
                      System.out.println("\n");
                  }

              }
              System.out.println("xxxxxxxxxxxxxxxxxxxxx");
          }
        }
        else{
            System.out.println("Woops, you entered a negative p.");
        }
    }
    else{
        System.out.println("Woops, you entered a negative n.");
    }
}

public static double[][] matrixMult(double a[][], double b[][]) {   
    int aRows = a.length; 
    int aCols = a[0].length; 
    int bCols = b[0].length;
    double[][] result = new double[aRows][bCols];   
    for(int i = 0; i < aRows; i++){ 
        for(int j = 0; j < bCols; j++){ 
            for(int k = 0; k < aCols; k++){ 
                result[i][j] += a[i][k] * b[k][j];      
                }
            }  
        }   
    return result;
}
