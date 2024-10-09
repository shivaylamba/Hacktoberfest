import java.util.Scanner;//transpose of a matrix
public class transpose {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int i,j;
        System.out.println("enter no of rows and columns:");
        int n=input.nextInt();
        int[][] arr=new int[n][n];
        System.out.println("enter the elements of matrix ");
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                arr[i][j]=input.nextInt();
            }
        }
        System.out.println("displaying the matrix:");
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                System.out.print(arr[i][j]+" ");
            }
            System.out.println();
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(i>j)
                {

                    int temp=arr[i][j];
                    arr[i][j]=arr[j][i];
                    arr[j][i]=temp;
                }
            }
        }
        System.out.println("matrix after transposing");
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                System.out.print(arr[i][j]+" ");
            }
            System.out.println();
        }
        input.close();

    }
}
