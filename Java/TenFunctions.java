// this program have ten function(patterns,fibonacci,basic calculator,etc)
import java.util.Scanner;
public class all {
    public static void prime( ) {
           Scanner scanner = new Scanner(System.in);

            System.out.print("Enter a positive integer: ");
            int number = scanner.nextInt();
            scanner.close();

            if (isPrime(number)) {
                System.out.println(number + " is a prime number.");
            } else {
                System.out.println(number + " is not a prime number.");
            }
    }
    public static boolean isPrime(int num) {
        if (num <= 1) {
            return false;
        }
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }

//           pattern

public static void pattern(){
    int choice;
    System.out.println("which pattern do you want to print:");
    System.out.println("star or number");
    Scanner sc = new Scanner(System.in);
    String userpat = sc.next();
    if ( userpat.endsWith("ber") || userpat.endsWith("BER")){
        System.out.println("number pattern availaible here are : ");
        do{
            System.out.println(" 1. square numbers");
            System.out.println(" 2. square increment numbers");
            System.out.println(" 3. right number  pyramid");
            System.out.println(" 4. Floyd's triangle pattern");
            System.out.println(" 5. exit!!!");
            System.out.println("enter your choice :::");
            choice = sc.nextByte();
            switch (choice){
                case 3:
                    System.out.println(":::right number  pyramid:::");
                    System.out.println("enter number of rows::");
                    int row3= sc.nextByte();
                    for(int i = 0; i< row3; i++){
                        for(int j = 0;j<i+1;j++){
                            System.out.print(i+1);

                        }
                        System.out.println();
                    }
                    break;



                case 2:
                    System.out.println(" :::square number ::: ");
                    System.out.println("enter number of rows:::");
                    int row2 = sc.nextByte();
                    int num = 1;
                    for (int i = 1; i <= row2; i++) {
                        for (int j = 1; j <=row2; j++) {
                            System.out.print(num);
                            num++;
                        }
                        System.out.println();


                    }
                    break;



                case 1:
                    System.out.println(" :::square number ::: ");
                    System.out.println("enter number of rows:::");
                    int row1 = sc.nextByte();
                    for (int i = 1; i <= row1; i++) {
                        for (int j = 1; j <= row1; j++) {
                            System.out.print(i);
                        }
                        System.out.println();


                    }
                    break;


               case 4:
                    System.out.println("::: Floyd's pattern :::");
                    System.out.print("Enter the rows of the pyramid: ");
                    int row4 = sc.nextInt();
                    int num1 = 1;
                    for (int i = 1; i <= row4 ; i++) {
                        for (int j = 0; j < i+1 ; j++) {
                            System.out.print(num1);
                            num1++;
                        }
                        System.out.println();
                        
                    }
                    break;

                case 5:
                    System.out.println("exitinggggggg");
                    break;
                default:
                    System.out.println("enter a valid choice");

            }


        }while(choice!=5);
    }
    if ( userpat.endsWith("tar") || userpat.endsWith("TAR")){
        System.out.println("star");
        int choice1;
        do{
            System.out.println("menu:");
            System.out.println("half pyramid star pattern (1)");
            System.out.println("pyramid pattern (2)");
            System.out.println("right angled triangle pattern (3)");
            System.out.println(" exit (4)");
            System.out.println("enter tour choice:::");
            choice1 = sc.nextByte();
            switch (choice1){
                case 1:
                    System.out.println("half pyramid");
                    System.out.println("enter number of rows");
                    int r = sc.nextInt();
                    for (int i = 0; i <= r; i++) {
                        for (int j = 0; j <= i ; j++) {
                            System.out.print(" * ");

                        }
                        System.out.println();

                    }
                    break;
                case 2:
                    System.out.println("pattern:");
                    System.out.println("enter number of rows");
                    int row = sc.nextByte();
                    for (int i = 1; i <= row; i++) {
                        // first inner loop for space
                        for (int j = 1; j <= row - i; j++) {
                            System.out.print(" ");
                        }
                        // for stars
                        for (int k = 1; k <= 2*i -1; k++) {
                            System.out.print("*");
                        }
                        System.out.println();
                    }
                    break;
                case 3:
                    System.out.println("enter number of rows");
                    int row6 = sc.nextByte();
                    for (int i = 1; i <= row6; i++) {
                        // Inner loop to print '*' i times
                        for (int j = 1; j <= i; j++) {
                            System.out.print("*");
                        }
                        System.out.println();
                    }

                    break;
                case 4:
                    System.out.println("exiting...");
                    break;
                default:
                    System.out.println("enter valid chioce 3");






            }



        }while(choice1!=4) ;

    }
}

//           table

public static void table(){
    System.out.println("enter the number whose table you want to see:");
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    for (int i = 1; i <= 10; i++) {
        System.out.println(n + " X " + i + " = "+ n*i);

    }

}

//           airthmetic

public static void airthmetic() {
    Scanner sc = new Scanner(System.in);
    int choice;
    System.out.println("enter a:::");
    int a= sc.nextInt();
    System.out.println("enter b:::");
    int b= sc.nextInt();
    do{
        System.out.println(" 1. ADDITION ");
        System.out.println(" 2. SUBTRACTION");
        System.out.println(" 3. MULTIPLICATION");
        System.out.println(" 4. DIVISION");
        System.out.println(" 5. exit!!!");
        System.out.println("enter your choice :::");
        choice = sc.nextByte();
        switch (choice){
            case 1:
                System.out.println("the sum is:::"+ (a+b));
                break;
            case 2:
                System.out.println("the subtraction is:::"+ (a-b));
                break;
            case 3:
                System.out.println(" multiplication is :::"+ (a*b));
                break;
            case 4:
                System.out.println("divison is :::"+ (a/b));
                break;
            case 5:
                System.out.println("exiting...");
                break;
        }


    }while (choice!=5);

}

//             temprature

public static void temprature(){
    System.out.println("this fuction will only work in celcius to feranheit ");
    System.out.println("so just enter the tempratire in celcius");
    Scanner sc = new Scanner(System.in);
    int celicus = sc.nextInt();
    System.out.println("temprature in feranheit is::"+ ((celicus*1.8)+ 32));
}

//               factorial

public static void factoo(){
            int i,fact=1;
            Scanner scan = new Scanner(System.in);
            System.out.println("enter the number::");
            int number= scan.nextInt();
            for(i=1;i<=number;i++){
                fact=fact*i;
            }
            System.out.println("Factorial of "+number+" is: "+fact);
    }

//         even- odd

public static void evenodd(){
    Scanner sc = new Scanner(System.in);
    System.out.println("enter number to check is it even or odd:::");
    int numb = sc.nextInt();
    if(numb%2==0){
        System.out.println("even");
    }else {
        System.out.println("odd");
    }
}

//              palindrome

public static void palindrome(){
    Scanner sc = new Scanner(System.in);
    System.out.println("enter number to check is it palindrome or not :::");
    int numb= sc.nextInt();
    int sum = 0,r;
    int temp = numb;
    while(numb>0){
        r=numb%10;
        sum=(sum*10)+r;
        numb=numb/10;
    }
    if (temp== sum){
        System.out.println("palindrome");
    }else{
        System.out.println("not palindrome");
    }

}

//       fibonacci

public static void fibonnaci(){
    int n1=0,n2=1,n3,i,count=10;
    System.out.print(n1+" "+n2);//printing 0 and 1

    for(i=2;i<count;++i)//loop starts from 2 because 0 and 1 are already printed
    {
        n3=n1+n2;
        System.out.print(" "+n3);
        n1=n2;
        n2=n3;

    }
//change the value of n1 and n2 and also increment the value of i
//change the value of count so that you can take as many elements in the series as you want
//here count =10 so,the elements are 10
}

//                                            main function
  
    public static void main(String[] args){
        System.out.println( "  MENU ::: ");
        int choice;
        Scanner sc= new Scanner(System.in);
        do{
            System.out.println(" 1. TO CHECK PRIME OR NOT ");
            System.out.println(" 2. TO SEE PATTERNS");
            System.out.println(" 3. TO PRINT TABLE");
            System.out.println(" 4. TO DO AIRTHMETIC FUNCT.");
            System.out.println(" 5. TO CHECK TEMPRATURE");
            System.out.println(" 6. TO FIND FACTORIAL OF A NUMBER");
            System.out.println(" 7. TO CHECK EVEN OR ODD");
            System.out.println(" 8. TO CHECK PALINDROME");
            System.out.println(" 9. TO SEE FIBONACCI ");
            System.out.println(" 10.           !!!EXIT!!!       ");

            System.out.println("enter your choice :::");
            choice = sc.nextByte();
            switch (choice){
                case 1:
                     prime();
                     break;
                case 2:
                   pattern();
                    break;
                case 3:
                    table();
                    break;
                case 4:
                    airthmetic();
                    break;
                case 5:
                    temprature();
                    break;
                case 6:
                    factoo();
                    break;
                case 7:
                    evenodd();
                    break;
                case 8:
                    palindrome();
                    break;
                case 9:
                    fibonnaci();
                    break;
                case 10:
                    System.out.println("exiting....");
                    break;
                default:
                    System.out.println("Invalid choice! Please choose again.");
            }


        }while(choice!=10);

    }


}
