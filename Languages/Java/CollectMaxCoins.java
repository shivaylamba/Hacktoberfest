
import java.util.Stack;

public class CollectMaxCoins {
	

	public static void main(String[] args) {
		
		int arr[][] = {
				{ 0 , 3 , 1 , 1 } ,
				{ 2 , 5 , 3 , 4 } ,
				{ 1 , 5 , 3 , 1 } 
		};
		
		int max = collectMaxCoins(arr);
		
		System.out.println("Max is : " + max);
	}
	
	public static int collectMaxCoins(int [][] arr) {
		
		
		return collectMaxCoinsHelper(arr ,  0 , 0 , arr.length , arr[0].length);
		
	}
	
	public static int collectMaxCoinsHelper(int[][] arr , int Crow , int Ccol , int rows , int cols){
		
		int cVal = arr[Crow][Ccol];
		
		if(Crow == rows-1 && Ccol == cols-1)
			return cVal;
		 
		int down = cVal, right = cVal;
		
		if( Crow < rows-1){
			down += collectMaxCoinsHelper(arr , Crow+1 , Ccol , rows , cols);
		}
		
		if( Ccol < cols-1){
			right += collectMaxCoinsHelper(arr , Crow , Ccol+1 , rows , cols);
		}
		
		return Math.max(down, right);
	}

}
