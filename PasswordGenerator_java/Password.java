package exercises;

import java.util.Random;

public class Password {
	private int longitud = 8;
	private String pass;
	
	public Password(String pass, int longitud) {
		this.longitud = longitud;
		this.pass = pass;
	}
	public Password(int longitud) {
		this.longitud = longitud;
	}
	
	public String getPass() {
		return pass;
	}
	public void setPass(String pass) {
		this.pass = pass;
	}
	public void setLongitud(int longitud) {
		this.longitud = longitud;
	}
	
	public boolean esFuerte(String pass) {
		int upper = 0;
		int lower = 0;
		int number = 0;
		for (int i = 0; i < pass.length(); i++) {
			if (Character.isDigit(pass.charAt(i))) number++;
			if (Character.isUpperCase(pass.charAt(i))) upper++;
			if (Character.isLowerCase(pass.charAt(i))) lower++;
		}
		if (upper >= 2 && lower >= 1 && number >= 2) {
			return true;
		} else {
			return false;
		}
	}
	
	public static String generarPassword(int longitud) {
		String caracteres = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789~`!@#$%^&*()-_=+[{]}\\|;:\'\",<.>/?";
		Random rand = new Random();
		char[] pwd = new char[longitud];
		for (int i = 0; i < longitud; i++) {
			pwd[i] = caracteres.charAt(rand.nextInt(caracteres.length()));
		}
		return String.valueOf(pwd);
	}
}
