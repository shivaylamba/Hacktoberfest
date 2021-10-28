import java.util.*;

public class Scramble
{
public static void main(String[] args)
{

Scanner sc=new Scanner(System.in);
System.out.println("          WELCOME SCRAMBLE GAME          ");
System.out.println("1.Football");
System.out.println("2.Basketball");
System.out.println("3.Tennis");
System.out.println("4.Baseball");
System.out.println("5.Exit");
System.out.println("Enter your choice ");
int c=sc.nextInt();
System.out.println("You must guess the word based on the sport you have selected above ");
switch(c)
{
case 1:
int k=1;int score=0;
String f[]={"LKEACT","KSIIPNG","OLLGECE","SFEDNEE","EFSNFEO","BRNEUOTAWRCQSDAK","ERCMAMGIS","KOFKFCI","RPENNTCTEIOI"};
String a[]={"TACKLE","PIGSKIN","COLLEGE","DEFENSE","OFFENSE","DOWNSQUARTERBACK","SCRIMMAGE","KICKOFF","INTERCEPTION"};
for(int i=0;i<f.length;i++)
{
System.out.println(k+"."+f[i]);
String s=sc.next();
if(s.equalsIgnoreCase(a[i]))
++score;
++k;
}//closing of for loop
System.out.println("CONGRATULATIONS");
System.out.println("Your Score ="+score);
break;
case 2:
int k1=1;int score1=0;
String b[]={"KATEASLLBB","OCACH","OHOP","HYEATPL","RBEILBD","ULOF","TMREEOVI","NTSPOI"};
String a1[]={"BASKETBALL","COACH","HOOP","PENALTY","DRIBBLE","FOUL","OVERTIME","POINTS"};
for(int i=0;i<b.length;i++)
{
System.out.println(k1+"."+b[i]);
String s=sc.next();
if(s.equalsIgnoreCase(a1[i]))
++score1;
++k1;
}//closing of for loop
System.out.println("CONGRATULATIONS");
System.out.println("Your Score ="+score1);
break; 
case 3:
int k2=1;int score2=0;
String t[]={"LGSISEN","OEDLBUS","ANTAVGAED","OTURC","ECUDE","ASMHS","SEVER","OVLE","TAULF"};
String a2[]={"SINGLES","DOUBLES","ADVANTAGE","COURT","DEVCE","SMASH","SERVE","LOVE","FAULT"};
for(int i=0;i<t.length;i++)
{
System.out.println(k2+"."+t[i]);
String s=sc.next();
if(s.equalsIgnoreCase(a2[i]))
++score2;
++k2;
}//closing of for loop
System.out.println("CONGRATULATIONS");
System.out.println("Your Score ="+score2);
break;
case 4:
int k3=1;int score3=0;
String ba[]={"TCPHI","TIRSEK","NUR","BEDULO","HEMO","FDEIL","RVDEI","UODUGHT","IWDL"};
String a3[]={"PITCH","STRIKE","RUN","DOUBLE","HOME","FIELD","DRIVE","DUGOUT","WILD"};
for(int i=0;i<ba.length;i++)
{
System.out.println(k3+"."+ba[i]);
String s=sc.next();
if(s.equalsIgnoreCase(a3[i]))
++score3;
++k3;
}//closing of for loop
System.out.println("CONGRATULATIONS");
System.out.println("Your Score ="+score3);
break; 
default:
System.out.println("Invalid option");
}//closing of switch case
 }//closing of void main
}//closing of class 
