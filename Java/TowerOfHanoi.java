import java.util.*;
class TowerofHanoi
{
  public static void main(String args[])
  {
    Scanner sc= new Scanner(System.in);
    System.out.println("Enter number of discs\n");
    int n= sc.nextInt();
    towerofhanoi(n,'A','C','B');
  }
  public static void towerofhanoi(int n,char rod1,char rod2,char rod3) //recursive
  {
    if(n==1)
    {
      System.out.println("Move disk 1 from "+ rod1 +" to rod "+rod2+"\n");
      return;
    }
    towerofhanoi(n-1,rod1,rod3,rod2);
    System.out.println("Move disk "+ n + " from rod "+rod1+" to rod "+rod2+"\n");
    towerofhanoi(n-1,rod3,rod2,rod1);
  }
}
