# Compilador

```
gcc main.cpp -lstdc++

./a.out <entradaN.txt
```

## Linguagem:

```
<programa> ::= "inicio" <comando>* "fim"
<comando> ::= (<declaracao> | <atribuicao> | <if> | <while> | <print>)
<declaracao> ::= ("numero" | "string" | "bool") <identificador> ";"
<atribuicao> ::= <identificador> "=" (<OpMatematica> | <OpLogica> | <string>) ";"
<if> ::= "if" "(" <OpLogica> ")" "{" <comando>* "}" ("else" "{" <comando>* "}")?
<while> ::= "while" "(" <OpLogica> ")" "{" <comando>* "}"
<print> ::= "print" "(" ("numero" | "string" | "bool") " " (<OpMatematica> | <OpLogica> | <baseString> ) ")" ";"

<identificador> ::= [A-z]+

<OpMatematica> ::= <termo> (("+" | "-") <termo>)?
<termo> ::= <fator> (("*" | "/" | "%") <fator>)?
<fator> ::= <potencia> ("**" <potencia>)?
<potencia> ::= ("+" | "-")? <base>
<base> ::= (<numero> | "(" <OpMatematica> ")" | <identificador>)
<numero> ::= [0-9]

<OpLogica> ::= <termoLogico> ("&&" <termoLogico>)?
<termoLogico> ::= <comparacao> ("||" <comparacao>)?
<comparacao> ::= ("true" | "false" | <comparacaoMat> | "(" <OpLogica> ")" | <identificador>)
<comparacaoMat> ::=  <OpMatematica> (">" | ">=" | "<" | "<=" | "==" | "!=") <OpMatematica>

<baseString> ::= (<string> | <identificador>)
<string> ::= " ... "
```
