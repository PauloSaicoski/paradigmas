#Escreva uma função que receba uma lista de nomes e retorne uma lista com a string "Sr. " adicionada ao início de cada nome.
def addsr (l):
    return list(map(lambda x:"Sr. "+x, l))
#Escreva uma função que, dada uma lista de números, calcule 3n*2 + 2/n + 1 para cada número n da lista.
def calc (l):
    return list(map(lambda n: 3*n*2+2/n+1, l))
#Crie uma função que receba uma lista de nomes e retorne outra lista com somente aqueles nomes que terminarem com a letra 'a'.
def ultima(l):
    return list(filter(lambda x:x[-1]=='a', l))
#Escreva uma função que, dada uma lista de idades de pessoas no ano atual, retorne uma lista somente com as idades de quem nasceu depois de 1970. Para testar a condição, sua função deverá subtrair a idade do ano atual. Exemplo de uso:
'''
>>> idades([20,30,51,57])
[20, 30]
'''
def mil970 (l):
    return list(filter(lambda x:2017-x>=1970, l))
#O código abaixo é escrito em Python imperativo. Escreva um código equivalente usando programação funcional.
'''
numbers = [1, 2, 3, 4]
new_numbers = []
for number in numbers:
 new_numbers.append(number * 2)
print(new_numbers)
'''
def pimp(ns):
    return list(map(lambda x:x*2, ns))

