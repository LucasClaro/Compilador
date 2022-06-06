#include "Tipos.h"
#include <map>
#include <cmath>       
#include <iostream>
#include <string>
#include <vector>

struct retornoComNumero {
  bool exito;
  int valor;
};

struct retornoComString {
  bool exito;
  std::string valor;
};

struct retornoComBool {
  bool exito;
  bool valor;
};

std::string boolLabels[] = {
  "false",
  "true"
};

bool pInicio(std::vector <TokenValor> tokens);
bool pFim(std::vector <TokenValor> tokens);
bool pPalavraIf(std::vector <TokenValor> tokens);
bool pPalavraElse(std::vector <TokenValor> tokens);
bool pPalavraPrint(std::vector <TokenValor> tokens);

bool pOperadorAtribuicao(std::vector <TokenValor> tokens);
bool pOperadorSoma(std::vector <TokenValor> tokens);
bool pOperadorSub(std::vector <TokenValor> tokens);
bool pOperadorMult(std::vector <TokenValor> tokens);
bool pOperadorDiv(std::vector <TokenValor> tokens);
bool pOperadorMod(std::vector <TokenValor> tokens);
bool pOperadorPow(std::vector <TokenValor> tokens);
bool pAbreParent(std::vector <TokenValor> tokens);
bool pFechaParent(std::vector <TokenValor> tokens);
bool pAbreChave(std::vector <TokenValor> tokens);
bool pFechaChave(std::vector <TokenValor> tokens);
bool pOperadorE(std::vector <TokenValor> tokens);
bool pOperadorOu(std::vector <TokenValor> tokens);
bool pOperadorMaior(std::vector <TokenValor> tokens);
bool pOperadorMaiorIgual(std::vector <TokenValor> tokens);
bool pOperadorMenor(std::vector <TokenValor> tokens);
bool pOperadorMenorIgual(std::vector <TokenValor> tokens);
bool pOperadorIgual(std::vector <TokenValor> tokens);
bool pOperadorDiferente(std::vector <TokenValor> tokens);

bool pIdentificador(std::vector <TokenValor> tokens);

bool pComando(std::vector <TokenValor> tokens);

bool pDeclaracaoNumero(std::vector <TokenValor> tokens);
bool pDeclaracaoBool(std::vector <TokenValor> tokens);
bool pDeclaracaoString(std::vector <TokenValor> tokens);

bool pAtribuicao(std::vector <TokenValor> tokens);
bool pAtribuicaoNumero(std::vector <TokenValor> tokens, std::string nomeVar);
bool pAtribuicaoString(std::vector <TokenValor> tokens, std::string nomeVar);
bool pAtribuicaoBool(std::vector <TokenValor> tokens, std::string nomeVar);

bool pIf(std::vector <TokenValor> tokens);

bool pWhile(std::vector <TokenValor> tokens);

bool pPrint(std::vector <TokenValor> tokens);

retornoComNumero pOpMatematica(std::vector <TokenValor> tokens);
retornoComNumero pTermo(std::vector <TokenValor> tokens);
retornoComNumero pFator(std::vector <TokenValor> tokens);
retornoComNumero pPotencia(std::vector <TokenValor> tokens);
retornoComNumero pBase(std::vector <TokenValor> tokens);
bool pLiteralNumero(std::vector <TokenValor> tokens);

retornoComString pBaseString(std::vector <TokenValor> tokens);
bool pLiteralString(std::vector <TokenValor> tokens);

retornoComBool pOpLogica(std::vector <TokenValor> tokens);
retornoComBool pTermoLogico(std::vector <TokenValor> tokens);
retornoComBool pComparacao(std::vector <TokenValor> tokens);
retornoComBool pComparacaoMatematica(std::vector <TokenValor> tokens);
bool pLiteralTrue(std::vector <TokenValor> tokens);
bool pLiteralFalse(std::vector <TokenValor> tokens);

bool ignoraBloco(std::vector <TokenValor> tokens);
void printaErro(std::string msg, std::vector <TokenValor> tokens);

std::map<std::string, int> NumVars;
std::map<std::string, std::string> StringVars;
std::map<std::string, bool> BoolVars;
int i = 0;

void Parser(std::vector <TokenValor> tokens) {
  
  if (!pInicio(tokens)) {
    printaErro("Não achou um inicio", tokens);
    return;
  }
  i++;
  
  while(!pFim(tokens)) {
    
    if (!pComando(tokens)) {
      printaErro("Comando desconhecido ou fim não encontrado", tokens);
      std::cout << TokenLabels[tokens[i].token] << std::endl;
      return;
    }
    
  }
}

///////////////

bool pInicio(std::vector <TokenValor> tokens) {
  return tokens[i].token == inicio;
}
bool pFim(std::vector <TokenValor> tokens) {
  return tokens[i].token == fim;
}
bool pPalavraIf(std::vector <TokenValor> tokens) {
  return tokens[i].token == MeuIf;
}
bool pPalavraElse(std::vector <TokenValor> tokens) {
  return tokens[i].token == MeuElse;
}
bool pPalavraPrint(std::vector <TokenValor> tokens) {
  return tokens[i].token == MeuPrint;
}

///////////////

bool pOperadorAtribuicao(std::vector <TokenValor> tokens) {
  return tokens[i].token == OperadorAtribuicao;
}
bool pOperadorSoma(std::vector <TokenValor> tokens) {
  return tokens[i].token == OperadorSoma;
}
bool pOperadorSub(std::vector <TokenValor> tokens) {
  return tokens[i].token == OperadorSub;
}
bool pOperadorMult(std::vector <TokenValor> tokens) {
  return tokens[i].token == OperadorMult;
}
bool pOperadorDiv(std::vector <TokenValor> tokens) {
  return tokens[i].token == OperadorDiv;
}
bool pOperadorMod(std::vector <TokenValor> tokens) {
  return tokens[i].token == OperadorMod;
}
bool pOperadorPow(std::vector <TokenValor> tokens) {
  return tokens[i].token == OperadorPower;
}
bool pAbreParent(std::vector <TokenValor> tokens) {
  return tokens[i].token == AbreParent;
}
bool pFechaParent(std::vector <TokenValor> tokens) {
  return tokens[i].token == FechaParent;
}
bool pAbreChave(std::vector <TokenValor> tokens) {
  return tokens[i].token == AbreChave;
}
bool pFechaChave(std::vector <TokenValor> tokens) {
  return tokens[i].token == FechaChave;
}
bool pOperadorE(std::vector <TokenValor> tokens) {
  return tokens[i].token == OperadorE;  
}
bool pOperadorOu(std::vector <TokenValor> tokens) {
  return tokens[i].token == OperadorOu;
}
bool pOperadorMaior(std::vector <TokenValor> tokens) {
  return tokens[i].token == OperadorMaior;
}
bool pOperadorMaiorIgual(std::vector <TokenValor> tokens) {
  return tokens[i].token == OperadorMaiorIgual;
}
bool pOperadorMenor(std::vector <TokenValor> tokens) {
  return tokens[i].token == OperadorMenor;
}
bool pOperadorMenorIgual(std::vector <TokenValor> tokens) {
  return tokens[i].token == OperadorMenorIgual;
}
bool pOperadorIgual(std::vector <TokenValor> tokens) {
  return tokens[i].token == OperadorIgual;
}
bool pOperadorDiferente(std::vector <TokenValor> tokens) {
  return tokens[i].token == OperadorDiferente;
}

///////////////

bool pIdentificador(std::vector <TokenValor> tokens) {
  return tokens[i].token == Identificador;
}

///////////////

bool pComando(std::vector <TokenValor> tokens) {
  switch(tokens[i].token) {
    case TipoNumero:
      if(!pDeclaracaoNumero(tokens)){
        return false;
      }
      break;
    case TipoBool: 
      if(!pDeclaracaoBool(tokens)){
        return false;
      }
      break;
    case TipoString:
      if(!pDeclaracaoString(tokens)) {
        return false;
      }
      break;
    case Identificador:
      if(!pAtribuicao(tokens)) {
        return false;
      }
      break;
    case MeuIf: 
      if (!pIf(tokens)) {
        return false;
      }
      break;
    case MeuWhile: 
      if (!pWhile(tokens)) {
        return false;
      }
      break;
    case MeuPrint:
      if(!pPrint(tokens)){
        return false;
      };
      break;
    default:       
      return false;
  }
  return true;
}

///////////////

bool pDeclaracaoNumero(std::vector <TokenValor> tokens) {
  i++;
  if (!pIdentificador(tokens)) {
    printaErro("Esperado um identificador", tokens);
    return false;
  }

  std::string nomeVar = tokens[i].valor;
  NumVars[nomeVar] = 0;

  i++;
  
  return true;
}

bool pDeclaracaoBool(std::vector <TokenValor> tokens) {
  i++;
  if (!pIdentificador(tokens)) {
    printaErro("Esperado um identificador", tokens);
    return false;
  }

  std::string nomeVar = tokens[i].valor;
  BoolVars[nomeVar] = false;

  i++;
  
  return true;
}

bool pDeclaracaoString(std::vector <TokenValor> tokens) {
  i++;
  if (!pIdentificador(tokens)) {
    printaErro("Esperado um identificador", tokens);
    return false;
  }

  std::string nomeVar = tokens[i].valor;
  StringVars[nomeVar] = "";

  i++;
  
  return true;
}

///////////////

bool pAtribuicao(std::vector <TokenValor> tokens) {
  if (NumVars.find(tokens[i].valor) != NumVars.end()) {
    if(!pAtribuicaoNumero(tokens, tokens[i].valor)) {
      return false;
    }    
  }
  else {
    if (StringVars.find(tokens[i].valor) != StringVars.end()) {
      if(!pAtribuicaoString(tokens, tokens[i].valor)) {
        return false;
      }
    }
    else {
      if (BoolVars.find(tokens[i].valor) != BoolVars.end()) {
        if(!pAtribuicaoBool(tokens, tokens[i].valor)) {
          return false;
        }
      }
      else {
        printaErro("Variável não declarada", tokens);
        return false;
      }
    }
  }

  return true;
}

bool pAtribuicaoNumero(std::vector <TokenValor> tokens, std::string nomeVar) {
  i++;
  if (!pOperadorAtribuicao(tokens)) {
    printaErro("Esperava uma atribuição", tokens);
    return false;
  }
  i++;

  retornoComNumero r = pOpMatematica(tokens);
  if (!r.exito) {
    printaErro("Esperava um numero", tokens);
    return false;
  }
    
  NumVars[nomeVar] = r.valor;  
  return true;
}

bool pAtribuicaoString(std::vector <TokenValor> tokens, std::string nomeVar) {
  i++;
  if (!pOperadorAtribuicao(tokens)) {
    printaErro("Esperava uma atribuição", tokens);
    return false;
  }
  i++;

  retornoComString r = pBaseString(tokens);
  if (!r.exito) {
    return false;
  }
  
  StringVars[nomeVar] = r.valor;
  return true;
}

bool pAtribuicaoBool(std::vector <TokenValor> tokens, std::string nomeVar) {
  i++;
  if (!pOperadorAtribuicao(tokens)) {
    printaErro("Esperava uma atribuição", tokens);
    return false;
  }
  i++;

  retornoComBool r = pOpLogica(tokens);
  if (!r.exito) {
    return false;
  }
  
  BoolVars[nomeVar] = r.valor;
  return true;
}

///////////////

bool pIf(std::vector <TokenValor> tokens) {
  i++;

  if (!pAbreParent(tokens)) {
    printaErro("Esperava um \"(\"", tokens);
    return false;
  }
  i++;

  retornoComBool r = pOpLogica(tokens);
  if (!r.exito) {
    printaErro("Esperava uma expressão lógica", tokens);
    return false;
  }

  if (!pFechaParent(tokens)) {
    printaErro("Esperava um \")\"", tokens);
    return false;
  }
  i++;

  if (r.valor) {

    if (!pAbreChave(tokens)) {
      printaErro("Esperava um \"{\"", tokens);
      return false;
    }
    i++;
    
    while(!pFechaChave(tokens)) {
    
      if (!pComando(tokens)) {
        printaErro("Comando desconhecido", tokens);
        std::cout << TokenLabels[tokens[i].token] << std::endl;
        return false;
      }
      
    }
    i++;
    
    if (pPalavraElse(tokens)) {
      i++;
      ignoraBloco(tokens);
    }    
  }
  else {
    ignoraBloco(tokens);
    if (pPalavraElse(tokens)) {
      i++;

      if (!pAbreChave(tokens)) {
        printaErro("Esperava um \"{\"", tokens);
        return false;
      }
      i++;
    
      while(!pFechaChave(tokens)) {
    
        if (!pComando(tokens)) {
          printaErro("Comando desconhecido", tokens);
          std::cout << TokenLabels[tokens[i].token] << std::endl;
          return false;
        }
        
      }
      i++;
    }
  }

  return true;
}

///////////////

bool pWhile(std::vector <TokenValor> tokens) {
  int inicioLoop = i;
  i++;
  
  if (!pAbreParent(tokens)) {
    printaErro("Esperava um \"(\"", tokens);
    return false;
  }
  i++;

  retornoComBool r = pOpLogica(tokens);
  if (!r.exito) {
    printaErro("Esperava uma expressão lógica", tokens);
    return false;
  }

  if (!pFechaParent(tokens)) {
    printaErro("Esperava um \")\"", tokens);
    return false;
  }
  i++;

  
  if (r.valor) {

    if (!pAbreChave(tokens)) {
      printaErro("Esperava um \"{\"", tokens);
      return false;
    }
    i++;
    
    while(!pFechaChave(tokens)) {  
    
      if (!pComando(tokens)) {
        printaErro("Comando desconhecido", tokens);
        std::cout << TokenLabels[tokens[i].token] << std::endl;
        return false;
      }
        
    }
    i = inicioLoop;
  }
  else {
    ignoraBloco(tokens);
  }

  return true;
}

///////////////

bool pPrint(std::vector <TokenValor> tokens) {
  if (!pPalavraPrint(tokens)) {
    return false;
  }
  i++;
  
  if (!pAbreParent(tokens)) {
    printaErro("Esperava um \"(\"", tokens);
    return false;
  }
  i++;

  switch (tokens[i].token) {
    case TipoNumero: {
      i++;
      retornoComNumero r = pOpMatematica(tokens);
      if (!r.exito) {
        printaErro("Esperava um numero", tokens);
        return false;
      }
      std::cout << std::to_string(r.valor) << std::endl;
      break;  
    }      
    case TipoString: {
      i++;
      retornoComString r = pBaseString(tokens);
      if (!r.exito) {
        return false;
      }
      std::cout << r.valor << std::endl;
      break;
    }      
    case TipoBool: {
      i++;
      retornoComBool r = pOpLogica(tokens);
      if (!r.exito) {
        return false;
      }
      std::cout << boolLabels[r.valor] << std::endl;
      break;
    }
    default:
      printaErro("Tipo desconhecido", tokens);
      return false;
  }

  if (!pFechaParent(tokens)) {
    printaErro("Esperava um \")\"", tokens);
    return false;
  }
  i++;

  return true;
}

///////////////

retornoComNumero pOpMatematica(std::vector <TokenValor> tokens) {
  retornoComNumero r1 = pTermo(tokens);
  if (!r1.exito) {
    retornoComNumero r;
    r.exito = false;
    return r;
  }

  if (pOperadorSoma(tokens)) {
    i++;
    retornoComNumero r2 = pTermo(tokens);
    if (!r2.exito) {
      retornoComNumero r;
      r.exito = false;
      return r;
    }
    r1.valor += r2.valor;
  }  
  else if (pOperadorSub(tokens)) {
    i++;
    retornoComNumero r2 = pTermo(tokens);
    if (!r2.exito) {
      retornoComNumero r;
      r.exito = false;
      return r;
    }
    r1.valor -= r2.valor;
  }

  return r1;
}

retornoComNumero pTermo(std::vector <TokenValor> tokens) {
  retornoComNumero r1 = pFator(tokens);
  if (!r1.exito) {
    retornoComNumero r;
    r.exito = false;
    return r;
  }

  if (pOperadorMult(tokens)) {
    i++;
    retornoComNumero r2 = pFator(tokens);
    if (!r2.exito) {
      retornoComNumero r;
      r.exito = false;
      return r;
    }
    r1.valor *= r2.valor;
  }
  else if (pOperadorDiv(tokens)) {
    i++;
    retornoComNumero r2 = pFator(tokens);
    if (!r2.exito) {
      retornoComNumero r;
      r.exito = false;
      return r;
    }
    r1.valor /= r2.valor;
  }
  else if (pOperadorMod(tokens)) {
    i++;
    retornoComNumero r2 = pFator(tokens);
    if (!r2.exito) {
      retornoComNumero r;
      r.exito = false;
      return r;
    }
    r1.valor = r1.valor % r2.valor;
  }

  return r1;
}

retornoComNumero pFator(std::vector <TokenValor> tokens) {

  retornoComNumero r1 = pPotencia(tokens);
  
  if (!r1.exito) {
    retornoComNumero r;
    r.exito = false;
    return r;
  }

  if (pOperadorPow(tokens)) {
    i++;
    retornoComNumero r2 = pPotencia(tokens);
    if (!r2.exito) {
      retornoComNumero r;
      r.exito = false;
      return r;
    }

    if (r2.valor == 0) {
      r1.valor = 1;
    }
    else {
      int x = r1.valor;
      for (int i = 1; i < r2.valor; i++) {
        std::cout << i << std::endl;
        x *= r1.valor;
      }
      
      r1.valor = x;
    }
    
  }

  return r1;
}

retornoComNumero pPotencia(std::vector <TokenValor> tokens) {

  int um = 1;
  
  if (pOperadorSoma(tokens)) {
    i++;
  }
  else if  (pOperadorSub(tokens)) {
    i++;
    
    um = -1;
  }

  retornoComNumero r1 = pBase(tokens);
  
  if (!r1.exito) {
    retornoComNumero r;
    r.exito = false;
    return r;
  }

  r1.valor = r1.valor * um;
  return r1;
}

retornoComNumero pBase(std::vector <TokenValor> tokens) {
  if (pLiteralNumero(tokens)) {
    retornoComNumero r;
    r.exito = true;
    r.valor = stoi(tokens[i].valor);
    i++;
    return r;
  }
  if (pIdentificador(tokens)) {
    if (NumVars.find(tokens[i].valor) != NumVars.end()) {
      retornoComNumero r;
      r.exito = true;
      r.valor = NumVars[tokens[i].valor];
      i++;
      return r;
    }
    else {
      printaErro("Variável não é do tipo numero", tokens);
      retornoComNumero r;
      r.exito = false;
      return r;
    }
  }
  if (pAbreParent(tokens)) {
    i++;

    retornoComNumero r1 = pOpMatematica(tokens);
  
    if (!r1.exito) {
      retornoComNumero r;
      r.exito = false;
      return r;
    }
  
    if (!pFechaParent(tokens)) {
      printaErro("Esperava um \")\"", tokens);
      retornoComNumero r;
      r.exito = false;
      return r;
    }
    i++;

    return r1;
    
  }

  retornoComNumero r;
  r.exito = false;
  return r;
}

bool pLiteralNumero(std::vector <TokenValor> tokens) {
  return tokens[i].token == LiteralNumero;
}

///////////////

retornoComString pBaseString(std::vector <TokenValor> tokens) {
  if (pLiteralString(tokens)) {
    retornoComString r;
    r.exito = true;
    r.valor = tokens[i].valor.substr(1, tokens[i].valor.length()-2);
    i++;
    return r;
  }
  if (pIdentificador(tokens)) {
    if (StringVars.find(tokens[i].valor) != StringVars.end()) {
      retornoComString r;
      r.exito = true;
      r.valor = StringVars[tokens[i].valor];
      i++;
      return r;
    }
    else {
      printaErro("Variável não é do tipo string", tokens);
      retornoComString r;
      r.exito = false;
      return r;
    }
  }

  printaErro("Esperava uma string", tokens);
  retornoComString r;
  r.exito = false;
  return r;
}

bool pLiteralString(std::vector <TokenValor> tokens) {
  return tokens[i].token == LiteralString;
}

///////////////

retornoComBool pOpLogica(std::vector <TokenValor> tokens) {
  retornoComBool r1 = pTermoLogico(tokens);
  
  if (!r1.exito) {
    retornoComBool r;
    r.exito = false;
    return r;
  }

  if (pOperadorE(tokens)) {
    i++;
    retornoComBool r2 = pTermoLogico(tokens);
    if (!r2.exito) {
      retornoComBool r;
      r.exito = false;
      return r;
    }
    r1.valor = r1.valor && r2.valor;
  }

  return  r1;
}

retornoComBool pTermoLogico(std::vector <TokenValor> tokens) {
  retornoComBool r1 = pComparacao(tokens);
  
  if (!r1.exito) {
    retornoComBool r;
    r.exito = false;
    return r;
  }

  if (pOperadorOu(tokens)) {
    i++;
    retornoComBool r2 = pComparacao(tokens);
    if (!r2.exito) {
      retornoComBool r;
      r.exito = false;
      return r;
    }
    r1.valor = r1.valor || r2.valor;
  }

  return  r1;  
}

retornoComBool pComparacao(std::vector <TokenValor> tokens) {

  int backupI = i;
  retornoComBool r = pComparacaoMatematica(tokens);
  if (r.exito) {
    return r;
  }
  else {
    i = backupI;

    if (pLiteralTrue(tokens)) {
      retornoComBool r;
      r.exito = true;
      r.valor = true;
      i++;
      return r;
    }
    if (pLiteralFalse(tokens)) {
      retornoComBool r;
      r.exito = true;
      r.valor = false;
      i++;
      return r;
    }
    if (pIdentificador(tokens)) {
        if (BoolVars.find(tokens[i].valor) != BoolVars.end()) {
          retornoComBool r;
          r.exito = true;
          r.valor = BoolVars[tokens[i].valor];
          i++;
          return r;
        }
      else {
  
        printaErro("Variável não é do tipo bool", tokens);
        retornoComBool r;
        r.exito = false;
        return r;
      }
    }
    
    if (!pAbreParent(tokens)) {
      retornoComBool r;
      r.exito = false;
      return r;
    }

    retornoComBool r = pOpLogica(tokens);
    if (!r.exito) {
      return r;
    }

    if (!pFechaParent(tokens)) {
      printaErro("Esperava um \")\"", tokens);
      r.exito = false;
      return r;
    }

    return r;
    
  }

  printaErro("Esperava um bool", tokens);
  r.exito = false;
  return r;
}

retornoComBool pComparacaoMatematica(std::vector <TokenValor> tokens) {
  
  retornoComBool r;
  r.exito = false;
  
  retornoComNumero r1 = pOpMatematica(tokens);
  if (!r1.exito) {
    return r;
  }

  Tokens operacao = tokens[i].token;
  i++;

  retornoComNumero r2 = pOpMatematica(tokens);
  if (!r2.exito) {
    return r;
  }
  
  switch (operacao) {
    case OperadorIgual: {
      r.exito = true;
      r.valor = r1.valor == r2.valor;
      break;
    }
    case OperadorDiferente: {
      r.exito = true;
      r.valor = r1.valor != r2.valor;
      break;
    }
    case OperadorMenorIgual: {
      r.exito = true;
      r.valor = r1.valor <= r2.valor;
      break;
    }
    case OperadorMenor: {
      r.exito = true;
      r.valor = r1.valor < r2.valor;
      break;
    }
    case OperadorMaiorIgual: {
      r.exito = true;
      r.valor = r1.valor >= r2.valor;
      break;
    }
    case OperadorMaior: {
      r.exito = true;
      r.valor = r1.valor > r2.valor;
      break;
    }
    default: {
      return r;
    }
  }
  
  return r;
}

bool pLiteralTrue(std::vector <TokenValor> tokens) {
  return tokens[i].token == LiteralTrue;
}

bool pLiteralFalse(std::vector <TokenValor> tokens) {
  return tokens[i].token == LiteralFalse;
}

//////////////////

bool ignoraBloco(std::vector <TokenValor> tokens) {
  if (!pAbreChave(tokens)) {
    printaErro("Esperava um \"{\"", tokens);
  return false;
  }
  i++;

  int count = 1;
  while (count != 0) {
    if (pAbreChave(tokens))
      count++;
    else if (pFechaChave(tokens))
      count--;
    i++;
  }

  return true;
}

void printaErro(std::string msg, std::vector <TokenValor> tokens) {
  std::cout << "ERRO: " + msg + " na Linha " + std::to_string(tokens[i].linha) + " Coluna " + std::to_string(tokens[i].coluna) << std::endl;
}