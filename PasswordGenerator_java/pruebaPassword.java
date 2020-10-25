package exercises;

import java.util.Scanner;
import exercises.Password;

public class pruebaPassword {

	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		System.out.print("Numero de contraseñas a generar: ");
		int n = s.nextInt();
		System.out.print("Introduce la longitud de las contraseñas: ");
		int longi = s.nextInt();
		Password passwd = new Password(longi);
		int cont = 0;
		while (cont < n) {
			passwd.setPass(Password.generarPassword(longi));
			System.out.print(passwd.getPass() + "\t Es fuerte: " + passwd.esFuerte(passwd.getPass()) + "\n");
			cont++;
		}
	}
}

