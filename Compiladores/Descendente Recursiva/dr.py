class Parser:
    def __init__(self, tokens):
        self.tokens = tokens
        self.index = 0
        self.current = self.tokens[self.index] if self.tokens else None

    def eat(self, expected_token):
        print(f"[eat] Esperando: {expected_token}, atual: {self.current}")
        if self.current == expected_token:
            self.index += 1
            self.current = self.tokens[self.index] if self.index < len(self.tokens) else None
            print(f"[eat] Token consumido. Próximo token: {self.current}")
        else:
            raise SyntaxError(f"Esperado {expected_token}, encontrado {self.current}")

    def parse(self):
        self.programa()
        if self.current is not None:
            raise SyntaxError(f"Entrada malformada. Sobrou: {self.current}")

    def programa(self):
        while self.current is not None:
            self.declaracao()

    def declaracao(self):
        print(f"[declaracao] token atual: {self.current}")
        if self.current in {'int', 'float', 'double', 'char', 'boolean'}:
            tipo = self.current
            print(f"[declaracao] tipo detectado: {tipo}")
            self.eat(tipo)
            print(f"[declaracao] token após consumir tipo: {self.current}")
            if self.current == 'ID':
                self.eat('ID')
                if self.current == '(':
                    self.declaracao_funcao()
                elif self.current == ';' or (self.current and self.current[0] == '='):
                    self.declaracao_variavel()
                elif self.current == '[':
                    self.eat('[')
                    if self.current == ']':
                        self.eat(']')
                        self.declaracao_variavel()
                    else:
                        self.expressao()
                        self.eat(']')
                        self.declaracao_variavel()
                else:
                    raise SyntaxError("Declaração inválida")
        elif self.current == 'struct':
            self.declaracao_estrutura()
        elif self.current == '//':
            self.eat('//')
            while self.current and self.current != 'NEWLINE':
                self.eat(self.current)
            self.eat('NEWLINE')
        elif self.current == '/*':
            self.eat('/*')
            while self.current and self.current != '*/':
                self.eat(self.current)
            self.eat('*/')
        elif self.current in {'if', 'while', 'for', 'switch', 'break', 'continue', 'return'}:
            self.estrutura_controle()
        else:
            raise SyntaxError("Declaração inválida")
    
    def lista_inicializacao(self):
        self.expressao()
        while self.current == ',':
            self.eat(',')
            self.expressao()


    def declaracao_variavel(self):
        print(f"[declaracao_variavel] token atual: {self.current}")
        if self.current == '=':
            self.eat('=')
            print(f"[declaracao_variavel] token após consumir '=': {self.current}")
            if self.current == '{':
                self.eat('{')
                if self.current != '}':
                    self.lista_inicializacao()
                self.eat('}')
            else:
                self.expressao()
            print(f"[declaracao_variavel] token após inicialização: {self.current}")
        self.eat(';')
        print(f"[declaracao_variavel] token após consumir ';': {self.current}")


    def declaracao_funcao(self):
        self.eat('(')
        if self.current != ')':
            self.parametros()
        self.eat(')')
        self.bloco()

    def parametros(self):
        self.parametro()
        while self.current == ',':
            self.eat(',')
            self.parametro()

    def parametro(self):
        if self.current in {'int', 'float', 'double', 'char', 'boolean'}:
            self.eat(self.current)
            if self.current == '...':
                self.eat('...')
            self.eat('ID')
            if self.current == '[':
                self.eat('[')
                self.eat(']')
        else:
            raise SyntaxError("Parâmetro inválido")

    def bloco(self):
        self.eat('{')
        while self.current and self.current != '}':
            self.declaracao()
        self.eat('}')

    def estrutura_controle(self):
        if self.current == 'if':
            self.eat('if')
            self.eat('(')
            self.expressao()
            self.eat(')')
            self.bloco()
            if self.current and self.current == 'else':
                self.eat('else')
                self.bloco()
        elif self.current == 'while':
            self.eat('while')
            self.eat('(')
            self.expressao()
            self.eat(')')
            self.bloco()
        elif self.current == 'for':
            self.eat('for')
            self.eat('(')
            self.expressao()
            self.eat(';')
            self.expressao()
            self.eat(';')
            self.expressao()
            self.eat(')')
            self.bloco()
        elif self.current == 'switch':
            self.eat('switch')
            self.eat('(')
            self.expressao()
            self.eat(')')
            self.case_lista()
        elif self.current == 'break':
            self.eat('break')
            self.eat(';')
        elif self.current == 'continue':
            self.eat('continue')
            self.eat(';')
        elif self.current == 'return':
            self.eat('return')
            self.expressao()
            self.eat(';')

    def case_lista(self):
        while self.current in {'case', 'default'}:
            self.case_decl()

    def case_decl(self):
        if self.current == 'case':
            self.eat('case')
            self.expressao()
            self.eat(':')
            self.bloco()
        elif self.current == 'default':
            self.eat('default')
            self.eat(':')
            self.bloco()

    def declaracao_estrutura(self):
        self.eat('struct')
        self.eat('ID')
        self.eat('{')
        while self.current and self.current in {'int', 'float', 'double', 'char', 'boolean'}:
            self.declaracao_variavel()
        self.eat('}')
        self.eat(';')

    def expressao(self):
        print(f"[expressao] token atual: {self.current}")
        self.atribuicao()
        print(f"[expressao] token após atribuicao: {self.current}")

    def atribuicao(self):
        print(f"[atribuicao] token atual: {self.current}")
        if self.current == 'ID':
            self.eat('ID')
            print(f"[atribuicao] token após consumir 'ID': {self.current}")
            if self.current in {'=', '+=', '-=', '*=', '/=', '%=', '&&=', '||='}:
                self.eat(self.current)
                print(f"[atribuicao] token após consumir operador atribuicao: {self.current}")
                self.expressao()
                print(f"[atribuicao] token após expressao: {self.current}")
        else:
            self.expressao_logica()

    def expressao_logica(self):
        self.expressao_relacional()
        while self.current and self.current in {'&&', '||'}:
            self.eat(self.current)
            self.expressao_relacional()

    def expressao_relacional(self):
        self.expressao_aritmetica()
        while self.current and self.current in {'>', '>=', '<', '<=', '!=', '=='}:
            self.eat(self.current)
            self.expressao_aritmetica()

    def expressao_aritmetica(self):
        self.expressao_multiplicativa()
        while self.current and self.current in {'+', '-'}:
            self.eat(self.current)
            self.expressao_multiplicativa()

    def expressao_multiplicativa(self):
        self.expressao_unaria()
        while self.current and self.current in {'*', '/', '%'}:
            self.eat(self.current)
            self.expressao_unaria()

    def expressao_unaria(self):
        if self.current in {'-', '++', '--', '!'}:
            self.eat(self.current)
        self.expressao_postfix()

    def expressao_postfix(self):
        self.primaria()
        while self.current and self.current in {'[', '(', '.', '->'}:
            if self.current == '[':
                self.eat('[')
                self.expressao()
                self.eat(']')
            elif self.current == '(':
                self.eat('(')
                if self.current != ')':
                    self.argumentos()
                self.eat(')')
            elif self.current == '.':
                self.eat('.')
                self.eat('ID')
            elif self.current == '->':
                self.eat('->')
                self.eat('ID')

    def argumentos(self):
        self.expressao()
        while self.current and self.current == ',':
            self.eat(',')
            self.expressao()

    def primaria(self):
        if self.current in {'ID', 'NUM_INT', 'NUM_DEC', 'TEXTO'}:
            self.eat(self.current)
        elif self.current == '(':
            self.eat('(')
            self.expressao()
            self.eat(')')
        else:
            raise SyntaxError("Expressão primária inválida")