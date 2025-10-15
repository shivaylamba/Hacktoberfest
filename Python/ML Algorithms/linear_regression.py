#Linear Regression 
import numpy as np
import matplotlib.pyplot as plt

x = np.array([1, 2, 3, 4, 5])
y = np.array([2, 4, 6, 8, 10])


coef = np.polyfit(x, y, 1) 
a, b = coef  

y_pred = a * x + b
print(f"Equação da reta: y = {a:.2f}x + {b:.2f}")


plt.scatter(x, y, color='blue', label='Pontos reais')  
plt.title('Regressão Linear Simples')
plt.xlabel('x')
plt.ylabel('y')
plt.legend()
plt.grid(True)
plt.show()