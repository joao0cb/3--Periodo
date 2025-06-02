from dr import Parser

tokens = ['float', 'ID', '(', 'int', 'ID', ',', 'float', 'ID', ')', '{', '}']
parser = Parser(tokens)
parser.parse()
print("Análise sintática concluída com sucesso!")