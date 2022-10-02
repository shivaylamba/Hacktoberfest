import java.util.ArrayList;
public class StringRotation {
public static void main(String[] args) {

String s1 = "happy";
int iteration = 3;
  int num = 0;

ArrayList<Character> al = new ArrayList<>();
for (int i=0; i< s1.length(); i++)
{ 
 al.add(s1.charAt(1));
}
  
while(num < iteration) 
{
Character lastChar = al.get(al.size()-1); 
al.remove(al.size()-1);
al.add(0, lastChar);
num++;
}

for (Character m : al)
System.out.print(m);

}
}
