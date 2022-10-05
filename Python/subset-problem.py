import time
#Programa onde você insere itens em um conjunto e pede pra ele te dar todos os subconjuntos onde  a soma dos itens do subconjunto resulta ao numero que vc pedir
#Inserção dos itens do conjunto
conjunto = []
item = input('Insira um elemento no conjunto ou digite "-" para parar de inserir\n')
conjunto.append(int(item))

while item:
    item = input('Insira um elemento no conjunto ou digite "-" para parar de inserir\n')
    if(item!= '-'):
        conjunto.append(int(item))
    else:
        break
#Inserção do numero que estou buscando nos subconjuntos somados
numero = int(input('Digite o numero que esta buscando na soma do conjunto \n'))
#Ordenando conjunto e criando variaveis auxiliares
conjunto = sorted(conjunto)
conjunto = set(conjunto)
conjunto = list(conjunto)
tamExp = pow(2,len(conjunto))
aux = []

start = time.time()
#Percorrendo o conjunto e achando o conjunto das partes
for i in range(tamExp):
    for j in range(len(conjunto)):
        if i & (1 << j):
                aux.append(conjunto[j])
    resposta = 0
    for k in range(len(aux)):
        resposta = resposta + aux[k]
#Verificando se a soma de cada conjunto das partes resulta no numero buscado
    if(numero == resposta ):
        if(len(aux) != 1):
            print("Achei o numero ",numero, "na soma no subconjunto",aux)
    aux.clear()

print("O tempo utilizado pra executar esse programa foi de:")

end = time.time()

print(end - start)        