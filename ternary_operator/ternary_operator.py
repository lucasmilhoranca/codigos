#Operador Ternário é um método disponibilizado pela própria linguagem para facilitar a visualização e diminuir as linhas do código. Exemplo em Python

#Sintaxe sem Operador Ternário
if a ==b:
    True
else:
    False

#Sintaxe com Operador Ternário
True if a == b else False

#Exemplo sem Operador Ternário
idade = int(input("Digite a sua idade: "))
if idade > 0:
    print(True)
else:
    print(False)

#Exemplo com Operador Ternário
idade = int(input("Digite a sua idade: "))
print(True if idade > 0 else False)