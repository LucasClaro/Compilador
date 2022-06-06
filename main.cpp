#include <iostream>
#include <string>
#include <vector>
#include "Automatos.h"
#include "Parser.h"

int main() {

  std::vector <TokenValor> tokens;
  
  std::string linha = "";
  int contadorLinha = 1;
  bool devoChamarParser = true;

  while (std::getline(std::cin, linha)) {

    retornoComValor ret;
    ret.i = 0;

    // if (linha[6] == '\0') {
    //   std::cout << linha[5];      
    // }
    // return 0;
    
    while (!(linha[ret.i] == ';' || linha[ret.i] == '\0')) {

      while(linha[ret.i] == ' ' || linha[ret.i] == '\t') {
        ret.i++;
      }
      
      int indexControle = ret.i;

      ret = achaFloat(linha, ret.i, contadorLinha);
      if (ret.i != indexControle) {
        TokenValor t;
        t.token = LiteralNumero;
        t.valor = ret.valor;
        t.linha = contadorLinha;
        t.coluna = ret.i;
        tokens.push_back(t); 
      }        

      if (ret.i == indexControle) {
        ret = achaString(linha, ret.i, contadorLinha);
        if (ret.i != indexControle) {
          TokenValor t;
          t.token = LiteralString;
          t.valor = ret.valor;
          t.linha = contadorLinha;
          t.coluna = ret.i;
          tokens.push_back(t); 
        }
      }

      if (ret.i == indexControle) {
        ret.i = achaOperadorAtribuicao(linha, ret.i, contadorLinha);
        if (ret.i != indexControle) {
          TokenValor t;
          t.token = OperadorAtribuicao;
          t.valor = "";                    
          t.linha = contadorLinha;
          t.coluna = ret.i;
          tokens.push_back(t); 
        }
      }                
            
      if (ret.i == indexControle) {
        ret.i = achaOperadorSoma(linha, ret.i, contadorLinha);
        if (ret.i != indexControle) {
          TokenValor t;
          t.token = OperadorSoma;
          t.valor = "";          
          t.linha = contadorLinha;
          t.coluna = ret.i;
          tokens.push_back(t); 
        }
      }
      
      if (ret.i == indexControle) {
        ret.i = achaOperadorSubtracao(linha, ret.i, contadorLinha);
        if (ret.i != indexControle) {
          TokenValor t;
          t.token = OperadorSub;
          t.valor = "";          
          t.linha = contadorLinha;
          t.coluna = ret.i;
          tokens.push_back(t); 
        }
      }
      
      if (ret.i == indexControle) {
        ret.i = achaOperadorMultiplicacao(linha, ret.i, contadorLinha);
        if (ret.i != indexControle) {
          TokenValor t;
          t.token = OperadorMult;
          t.valor = "";          
          t.linha = contadorLinha;
          t.coluna = ret.i;
          tokens.push_back(t); 
        }  
      }
      
      if (ret.i == indexControle) {
        ret.i = achaOperadorDivisao(linha, ret.i, contadorLinha);
        if (ret.i != indexControle) {
          TokenValor t;
          t.token = OperadorDiv;
          t.valor = "";          
          t.linha = contadorLinha;
          t.coluna = ret.i;
          tokens.push_back(t); 
        }
      }

      if (ret.i == indexControle) {
        ret.i = achaOperadorModulo(linha, ret.i, contadorLinha);
        if (ret.i != indexControle) {
          TokenValor t;
          t.token = OperadorMod;
          t.valor = "";          
          t.linha = contadorLinha;
          t.coluna = ret.i;
          tokens.push_back(t); 
        }
      }
      
      if (ret.i == indexControle) {
        ret.i = achaOperadorPotencia(linha, ret.i, contadorLinha);
        if (ret.i != indexControle) {
          TokenValor t;
          t.token = OperadorPower;
          t.valor = "";          
          t.linha = contadorLinha;
          t.coluna = ret.i;
          tokens.push_back(t); 
        }  
      }
      
      if (ret.i == indexControle) {
        ret.i = achaAgrupadorAbre(linha, ret.i, contadorLinha);
        if (ret.i != indexControle) {
          TokenValor t;
          t.token = AbreParent;
          t.valor = "";          
          t.linha = contadorLinha;
          t.coluna = ret.i;
          tokens.push_back(t); 
        }  
      }
      
      if (ret.i == indexControle) {
        ret.i = achaAgrupadorFecha(linha, ret.i, contadorLinha);
        if (ret.i != indexControle) {
          TokenValor t;
          t.token = FechaParent;
          t.valor = "";          
          t.linha = contadorLinha;
          t.coluna = ret.i;
          tokens.push_back(t); 
        }  
      }

      if (ret.i == indexControle) {
        ret.i = achaInicio(linha, ret.i, contadorLinha);
        if (ret.i != indexControle) {
          TokenValor t;
          t.token = inicio;
          t.valor = "";          
          t.linha = contadorLinha;
          t.coluna = ret.i;
          tokens.push_back(t); 
        }  
      }

      if (ret.i == indexControle) {
        ret.i = achaFim(linha, ret.i, contadorLinha);
        if (ret.i != indexControle) {
          TokenValor t;
          t.token = fim;
          t.valor = "";          
          t.linha = contadorLinha;
          t.coluna = ret.i;
          tokens.push_back(t); 
        }  
      }

      if (ret.i == indexControle) {
        ret.i = achaTipoNumero(linha, ret.i, contadorLinha);
        if (ret.i != indexControle) {
          TokenValor t;
          t.token = TipoNumero;
          t.valor = "";          
          t.linha = contadorLinha;
          t.coluna = ret.i;
          tokens.push_back(t); 
        }  
      }

      if (ret.i == indexControle) {
        ret.i = achaTipoString(linha, ret.i, contadorLinha);
        if (ret.i != indexControle) {
          TokenValor t;
          t.token = TipoString;
          t.valor = "";          
          t.linha = contadorLinha;
          t.coluna = ret.i;
          tokens.push_back(t); 
        }  
      }

      if (ret.i == indexControle) {
        ret.i = achaTipoBool(linha, ret.i, contadorLinha);
        if (ret.i != indexControle) {
          TokenValor t;
          t.token = TipoBool;
          t.valor = "";          
          t.linha = contadorLinha;
          t.coluna = ret.i;
          tokens.push_back(t); 
        }  
      }

      if (ret.i == indexControle) {
        ret.i = achaIf(linha, ret.i, contadorLinha);
        if (ret.i != indexControle) {
          TokenValor t;
          t.token = MeuIf;
          t.valor = "";          
          t.linha = contadorLinha;
          t.coluna = ret.i;
          tokens.push_back(t); 
        }  
      }

      if (ret.i == indexControle) {
        ret.i = achaElse(linha, ret.i, contadorLinha);
        if (ret.i != indexControle) {
          TokenValor t;
          t.token = MeuElse;
          t.valor = "";          
          t.linha = contadorLinha;
          t.coluna = ret.i;
          tokens.push_back(t); 
        }  
      }

      if (ret.i == indexControle) {
        ret.i = achaWhile(linha, ret.i, contadorLinha);
        if (ret.i != indexControle) {
          TokenValor t;
          t.token = MeuWhile;
          t.valor = "";          
          t.linha = contadorLinha;
          t.coluna = ret.i;
          tokens.push_back(t); 
        }  
      }

      if (ret.i == indexControle) {
        ret.i = achaPrint(linha, ret.i, contadorLinha);
        if (ret.i != indexControle) {
          TokenValor t;
          t.token = MeuPrint;
          t.valor = "";          
          t.linha = contadorLinha;
          t.coluna = ret.i;
          tokens.push_back(t); 
        }  
      }

      if (ret.i == indexControle) {
        ret.i = achaAbreChave(linha, ret.i, contadorLinha);
        if (ret.i != indexControle) {
          TokenValor t;
          t.token = AbreChave;
          t.valor = "";          
          t.linha = contadorLinha;
          t.coluna = ret.i;
          tokens.push_back(t); 
        }  
      }

      if (ret.i == indexControle) {
        ret.i = achaFechaChave(linha, ret.i, contadorLinha);
        if (ret.i != indexControle) {
          TokenValor t;
          t.token = FechaChave;
          t.valor = "";          
          t.linha = contadorLinha;
          t.coluna = ret.i;
          tokens.push_back(t); 
        }  
      }

      if (ret.i == indexControle) {
        ret.i = achaOperadorE(linha, ret.i, contadorLinha);
        if (ret.i != indexControle) {
          TokenValor t;
          t.token = OperadorE;
          t.valor = "";          
          t.linha = contadorLinha;
          t.coluna = ret.i;
          tokens.push_back(t); 
        }  
      }

      if (ret.i == indexControle) {
        ret.i = achaOperadorOu(linha, ret.i, contadorLinha);
        if (ret.i != indexControle) {
          TokenValor t;
          t.token = OperadorOu;
          t.valor = "";          
          t.linha = contadorLinha;
          t.coluna = ret.i;
          tokens.push_back(t); 
        }  
      }

      if (ret.i == indexControle) {
        ret.i = achaOperadorMaior(linha, ret.i, contadorLinha);
        if (ret.i != indexControle) {
          TokenValor t;
          t.token = OperadorMaior;
          t.valor = "";          
          t.linha = contadorLinha;
          t.coluna = ret.i;
          tokens.push_back(t); 
        }  
      }

      if (ret.i == indexControle) {
        ret.i = achaOperadorMaiorIg(linha, ret.i, contadorLinha);
        if (ret.i != indexControle) {
          TokenValor t;
          t.token = OperadorMaiorIgual;
          t.valor = "";          
          t.linha = contadorLinha;
          t.coluna = ret.i;
          tokens.push_back(t); 
        }  
      }

      if (ret.i == indexControle) {
        ret.i = achaOperadorMenor(linha, ret.i, contadorLinha);
        if (ret.i != indexControle) {
          TokenValor t;
          t.token = OperadorMenor;
          t.valor = "";          
          t.linha = contadorLinha;
          t.coluna = ret.i;
          tokens.push_back(t); 
        }  
      }

      if (ret.i == indexControle) {
        ret.i = achaOperadorMenorIg(linha, ret.i, contadorLinha);
        if (ret.i != indexControle) {
          TokenValor t;
          t.token = OperadorMenorIgual;
          t.valor = "";          
          t.linha = contadorLinha;
          t.coluna = ret.i;
          tokens.push_back(t); 
        }  
      }

      if (ret.i == indexControle) {
        ret.i = achaOperadorIgual(linha, ret.i, contadorLinha);
        if (ret.i != indexControle) {
          TokenValor t;
          t.token = OperadorIgual;
          t.valor = "";          
          t.linha = contadorLinha;
          t.coluna = ret.i;
          tokens.push_back(t); 
        }  
      }

      if (ret.i == indexControle) {
        ret.i = achaOperadorDiferente(linha, ret.i, contadorLinha);
        if (ret.i != indexControle) {
          TokenValor t;
          t.token = OperadorDiferente;
          t.valor = "";          
          t.linha = contadorLinha;
          t.coluna = ret.i;
          tokens.push_back(t); 
        }  
      }

      if (ret.i == indexControle) {
        ret.i = achaFalse(linha, ret.i, contadorLinha);
        if (ret.i != indexControle) {
          TokenValor t;
          t.token = LiteralFalse;
          t.valor = "";          
          t.linha = contadorLinha;
          t.coluna = ret.i;
          tokens.push_back(t); 
        }  
      }

      if (ret.i == indexControle) {
        ret.i = achaTrue(linha, ret.i, contadorLinha);
        if (ret.i != indexControle) {
          TokenValor t;
          t.token = LiteralTrue;
          t.valor = "";          
          t.linha = contadorLinha;
          t.coluna = ret.i;
          tokens.push_back(t); 
        }  
      }

      if (ret.i == indexControle) {
        ret = achaIdentificador(linha, ret.i, contadorLinha);
        if (ret.i != indexControle) {
          TokenValor t;
          t.token = Identificador;
          t.valor = ret.valor;          
          t.linha = contadorLinha;
          t.coluna = ret.i;
          tokens.push_back(t); 
        }
      }

      if (ret.i == indexControle) {
        std::cout << ("Erro na linha: " + std::to_string(contadorLinha) +
                      " coluna: " + std::to_string(ret.i))
                  << std::endl;
        devoChamarParser = false;
        break;
      }
    }

    contadorLinha++;
  }

  // std::vector<TokenValor>::iterator it;
  // for(it = tokens.begin(); it != tokens.end(); it++)    {
  //   std::cout << TokenLabels[it->token] << std::endl;
  // }

  if (devoChamarParser) {
   Parser(tokens);   
  }
  
}