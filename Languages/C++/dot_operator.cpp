#include <stdio.h> 

struct Point { 
	int x, y; 
}; 

int main() 
{ 
	struct Point p1 = { 0, 1 }; 

	// Accesing members of point p1 
	// using the dot operator 
	p1.x = 20; 

	printf("x = %d, y = %d", p1.x, p1.y); 

	return 0; 
} 
