#Operador Ternário é um método disponibilizado pela própria linguagem para facilitar a visualização e diminuir as linhas do código. Exemplo em Python

#Sintaxe sem Operador Ternário
if a == b
    True
else
    False
end

#Sintaxe com Operador Ternário
if a == b ? True : False

#Exemplo sem Operador Ternário
nome_salvo = "Lucas"
print "Digite seu nome: "
nome = gets.chomp

if nome == nome_salvo
    print"True"
else
    print"False"
end

#Exemplo com Operador Ternário
nome_salvo = "Lucas"
print "Digite seu nome: "
nome = gets.chomp

puts nome.eql?("Lucas") ? "True" : "False"