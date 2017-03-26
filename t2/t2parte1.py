#Defina uma função addSuffix(suf,nomes) que retorne a lista de nomes com o sufixo suf adicionado. Exemplos:
'''
>>> addSuffix('@inf.ufsm.br',['fulano','beltrano'])
  ['fulano@inf.ufsm.br', 'beltrano@inf.ufsm.br']
'''
def addSuffix(suf, nomes):
    return [nome+suf for nome in nomes]

#Escreva uma função countShorts(words), que receba uma lista de palavras e retorne a quantidade de palavras dessa lista que possuem menos de 5 caracteres.
'''
>>> t2.countShorts(['lazy','dog','brown','fox'])
3
'''
def countShorts(words):
    return len([palavra for palavra in words if len(palavra) < 5])

#Defina uma função stripVowels(s) que receba uma string e retire suas vogais, conforme os exemplos abaixo:
'''
>>> stripVowels('Andrea')
'ndr'
>>> stripVowels('xyz')
'xyz'
>>> stripVowels('')
''
'''
def stripVowels(s):
    return ''.join([letra for letra in s if letra not in "aeiouAEIOU"])

#Defina uma função hideChars(s) que receba uma string, possivelmente contendo espaços, e que retorne outra string substituindo os demais caracteres por '-', mas mantendo os espaços. Exemplos:
'''
>>> hideChars("Rio Grande do Sul")
'--- ------ -- ---'
>>> hideChars("")
''
'''
def hideChars(s):
    return ''.join([' ' if letra == ' ' else '-' for letra in s])

#Defina uma função que receba um número n e retorne uma tabela de números de 1 a n e seus quadrados, conforme os exemplos abaixo (você vai usar tuplas em Python):
'''
>>> genTable(5)
[(1, 1), (2, 4), (3, 9), (4, 16), (5, 25)]
>>> genTable(0)
[]
>>> genTable(1)
[(1, 1)]
'''
def genTable(n):
    return [(x,x**2) for x in range(1,n+1)]

#Defina uma função que receba uma lista de palavras e retorne uma string contendo o primeiro e o último caracter de cada palavra da lista. Exemplo:
'''
>>> genCode(['abacaxi','mamao','banana'])
'aimoba'
'''
def genCode(l):
   	return ''.join([palavra[0]+palavra[-1] for palavra in l])

#Defina uma função myZip(l1,l2) que reproduza o comportamento da função zip do Python:
'''
>>> myZip([1,2,3],[4,5,6])
[(1, 4), (2, 5), (3, 6)]
>>> myZip([1,2,3],[4,5])
[(1, 4), (2, 5)]
'''
def myZip(l1,l2):
    return [(l1[n],l2[n]) for n in range(min(len(l1),len(l2)))]

#Escreva uma função enumerate(words) que numere cada palavra da lista recebida:
'''
>>> enumerate(['abacaxi','mamao','banana'])
[(1, 'abacaxi'), (2, 'mamao'), (3, 'banana')]
'''
def enumerate(words):
    return [(n+1,words[n]) for n in range(len(words))]
#Escreva uma função isBin(s) que verifique se a string recebida representa um número binário. Exemplo:
'''
>>> isBin('1010')
True
>>> isBin('1012')
False
'''
def isBin(s):
    return len([x for x in s if x not in "10"])==0

#Escreva uma função bin2dec(digits), que receba uma lista de dígitos representando um número binário e retorne seu equivalente em decimal. Exemplo:
'''
>>> bin2dec([1,1,1,1])
15
'''
def bin2dec(digits):
    return sum([digits[-x-1]*2**x for x in range(len(digits))])
