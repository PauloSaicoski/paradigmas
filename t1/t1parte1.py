#Defina uma função somaQuad(x,y) que calcule a soma dos quadrados de dois números x e y.
def somaQuad(x,y):
    return pow(x,2)+pow(y,2)

#Crie uma função hasEqHeads(l1,l2) que verifique se as listas l1 e l2 possuem o mesmo primeiro elemento.
def hasEqHeads(l1,l2):
    return l1[0] == l2[0]
#Escreva uma função que receba uma lista de nomes e retorne uma lista com a string "Sr. " adicionada ao início de cada nome. Defina uma função auxiliar para ajudar neste exercício.
def sraux (nome):
    return "Sr. "+nome
def addsr (lista):
    return list(map(sraux, lista))
#Crie uma função que receba uma string e retorne o número de espaços nela contidos. Defina uma função auxiliar para ajudar neste exercício.
def espaco (letra):
    return letra == ' '
def numesp (texto):
    return len(list(filter(espaco, texto)))
#Escreva uma função que, dada uma lista de números, calcule 3n*2 + 2/n + 1 para cada número n da lista. Defina uma função auxiliar para ajudar neste exercício.
def calc (n):
    return 3*n*2+2/n+1
def calcula (l):
    return list(map(calc, l))
#Escreva uma função que, dada uma lista de números, retorne uma lista com apenas os que forem negativos. Defina uma função auxiliar para ajudar neste exercício.
def negativos(n):
    return n<0
def neg(l):
    return list(filter(negativos, l))
#Escreva uma função que receba uma lista de números e retorne somente os que estiverem entre 1 e 100, inclusive. Defina uma função auxiliar para ajudar neste exercício.
def de1a100 (n):
    return (n>=1 and n<=100)
def n1a100 (l):
    return list(filter(de1a100, l))
#Escreva uma função que receba uma lista de números e retorne somente aqueles que forem pares. Defina uma função auxiliar para ajudar neste exercício.
def par(n):
    return n%2==0
def pares(l):
    return list(filter(par, l))
#Crie uma função charFound(c,s) que verifique se o caracter c está contido na string. O resultado deve ser True ou False. Você não deve usar o operador in. Defina uma função auxiliar para ajudar neste exercício.
'primeira solução'
'''
def caracter(c,x):
    return x==c
def charFound(c, s):
    return len(list(filter(None, list(map(caracter, c*len(s), s)))))>0
'''
'segunda solução'
def charFound (c,s):
	def caracter (x):
		return c == x
	return len(list(filter(caracter, s)))>0
#Escreva uma função que receba uma lista de strings e retorne uma nova lista com adição de marcações HTML (p.ex.: <B> e </B>) antes e depois de cada string.
def addmarcAux(s):
    return "<B>"+s+"</B>"
def addmarc(l):
    return list(map(addmarcAux, l))
    