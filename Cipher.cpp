#include <iostream>
#include <string>
 
 using namespace std;
 
 int main(){
	 cout << "Welcome to the substituion cypher!" << endl;
	 
	 cout << "\nEnter any message, we will help you encrypt it!\n" << endl;
	 
	 string alphabet {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
	 
	 string key {"QWERTYUIOPLKJHGFDSAZXCVBNMmnbvcxzasdfghjklpoiuytrewq"};
	 
	 string message, encryptingMessage; 
	 
	 encryptingMessage = message;
	 
	 unsigned int finder{};
	  
	 getline(cin, message);
	 
	 for(unsigned int i=0; i<message.length(); i++){
		 finder=alphabet.find(message[i]);
		 
		 if(finder!=string::npos)
			 encryptingMessage[i]=key.at(finder);
		 
	 }
	 
	 cout << "\n Encrypting message ...." << endl;
	 cout << encryptingMessage << endl;
	 cout << "\n Decrypting message ...." << endl;
	 cout << message << endl;
	 
	 
	 return 0;
 }
