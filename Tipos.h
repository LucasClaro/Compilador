#include <iostream>
#include <string>
#include <vector>

std::string TokenLabels[] =
{
  "Inicio",
  "Fim",
  "TipoNumero",
  "TipoString",
  "TipoBool",
  "Identificador",
  "MeuIf",
  "MeuElse",
  "MeuWhile",
  "MeuPrint",
  "AbreChave",
  "FechaChave",
  "AbreParent",
  "FechaParent",
  "OperadorAtribuicao",
  "OperadorSoma",
  "OperadorSub",
  "OperadorMult",
  "OperadorDiv",
  "OperadorMod",
  "OperadorPower",
  "OperadorE",
  "OperadorOu",
  "OperadorMaior",
  "OperadorMaiorIgual",
  "OperadorMenor",
  "OperadorMenorIgual",
  "OperadorIgual",
  "OperadorDiferente",
  "LiteralString",
  "LiteralNumero",
  "LiteralTrue",
  "LiteralFalse"
};

enum Tokens {
  inicio = 0,
  fim,
  TipoNumero,
  TipoString,
  TipoBool,
  Identificador,
  MeuIf,
  MeuElse,
  MeuWhile,
  MeuPrint,

  AbreChave,
  FechaChave,
  AbreParent,
  FechaParent,
  OperadorAtribuicao,
  OperadorSoma,
  OperadorSub,
  OperadorMult,
  OperadorDiv,
  OperadorMod,
  OperadorPower,

  OperadorE,
  OperadorOu,
  OperadorMaior,
  OperadorMaiorIgual,
  OperadorMenor,
  OperadorMenorIgual,
  OperadorIgual,
  OperadorDiferente,

  LiteralString,
  LiteralNumero,
  LiteralTrue,
  LiteralFalse
};

struct TokenValor {
  Tokens token;
  std::string valor;
  int linha;
  int coluna;
};