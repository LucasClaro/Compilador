#include <iostream>
#include <string>

struct retornoComValor {
  int i;
  std::string valor;
};

retornoComValor achaFloat(std::string linha, int index, int nLinha) {
  int estado = 0;
  int i = index;

  while (true) {
    switch (estado) {
      case 0:
        switch (linha[i]) {
          case '0': estado = 1; i++; break;
          case '1': estado = 1; i++; break;
          case '2': estado = 1; i++; break;
          case '3': estado = 1; i++; break;
          case '4': estado = 1; i++; break;
          case '5': estado = 1; i++; break;
          case '6': estado = 1; i++; break;
          case '7': estado = 1; i++; break;
          case '8': estado = 1; i++; break;
          case '9': estado = 1; i++; break;          
          case '.': estado = 2; i++; break;
          default: retornoComValor r; r.i = index; return r;
        }
        break;
      case 1:
        switch (linha[i]) {
          case '0': i++; break;
          case '1': i++; break;
          case '2': i++; break;
          case '3': i++; break;
          case '4': i++; break;
          case '5': i++; break;
          case '6': i++; break;
          case '7': i++; break;
          case '8': i++; break;
          case '9': i++; break;
          case '.': estado = 2; i++; break;
          case 'E': estado = 3; i++; break;
          case ' ': estado = 7; i++; break;
          case ')': estado = 6; break;
          case ';': estado = 6; break;
          default: retornoComValor r; r.i = index; return r;
        }
        break;
      case 2:
        switch (linha[i]) {
          case '0': i++; break;
          case '1': i++; break;
          case '2': i++; break;
          case '3': i++; break;
          case '4': i++; break;
          case '5': i++; break;
          case '6': i++; break;
          case '7': i++; break;
          case '8': i++; break;
          case '9': i++; break;
          case 'E': estado = 3; i++; break;
          case ' ': estado = 7; i++; break;
          case ')': estado = 6; break;
          case ';': estado = 6; break;
          default: retornoComValor r; r.i = index; return r;
        }
        break;
      case 3:
        switch (linha[i]) {
          case '0': estado = 4; i++; break;
          case '1': estado = 4; i++; break;
          case '2': estado = 4; i++; break;
          case '3': estado = 4; i++; break;
          case '4': estado = 4; i++; break;
          case '5': estado = 4; i++; break;
          case '6': estado = 4; i++; break;
          case '7': estado = 4; i++; break;
          case '8': estado = 4; i++; break;
          case '9': estado = 4; i++; break;
          case '-': estado = 5; i++; break;
          default: retornoComValor r; r.i = index; return r;
        }
        break;
      case 4:
        switch (linha[i]) {
          case '0': i++; break;
          case '1': i++; break;
          case '2': i++; break;
          case '3': i++; break;
          case '4': i++; break;
          case '5': i++; break;
          case '6': i++; break;
          case '7': i++; break;
          case '8': i++; break;
          case '9': i++; break;
          case ' ': estado = 7; i++; break;
          case ')': estado = 6; break;
          case ';': estado = 6; break;          
          default: retornoComValor r; r.i = index; return r;
        }
        break;
      case 5:
        switch (linha[i]) {
          case '0': estado = 4; i++; break;
          case '1': estado = 4; i++; break;
          case '2': estado = 4; i++; break;
          case '3': estado = 4; i++; break;
          case '4': estado = 4; i++; break;
          case '5': estado = 4; i++; break;
          case '6': estado = 4; i++; break;
          case '7': estado = 4; i++; break;
          case '8': estado = 4; i++; break;
          case '9': estado = 4; i++; break;
          default: retornoComValor r; r.i = index; return r;
        }
        break;
      case 6: {
        retornoComValor r;
        r.i = i;
        r.valor = linha.substr(index, i-index);
        return r;
        break;
      }           
      case 7: {
        retornoComValor r;
        r.i = i;
        r.valor = linha.substr(index, i-index-1);
        return r;
        break;   
      }        
      default:        
        retornoComValor r; r.i = index; return r;
    }
  }
}

retornoComValor achaIdentificador(std::string linha, int index, int nLinha) {
  int estado = 0;
  int i = index;

  while(true) {
    switch(estado) {
      case 0:
        if (std::isalpha(linha[i])) {
          estado = 1; i++; break;
        }
        else {
          retornoComValor r; r.i = index; return r;;
        }
        break;
      case 1:
        if (std::isalpha(linha[i]) || std::isdigit(linha[i])) {
          i++; break;
        }
        switch (linha[i]) {
          case '_': i++; break;
          case ' ': estado = 3; i++; break;
          case ')': estado = 2; break;
          case ';': estado = 2; break; 
          default: retornoComValor r; r.i = index; return r;;
        }
        break;
      case 2: {
        retornoComValor r;
        r.i = i;
        r.valor = linha.substr(index, i-index);
        return r;
        break;
      }  
      case 3: {
        retornoComValor r;
        r.i = i;
        r.valor = linha.substr(index, i-index-1);
        return r;
        break;
      }  
      default:
        retornoComValor r; r.i = index; return r;
    }
  }
}

retornoComValor achaString(std::string linha, int index, int nLinha) {
  int estado = 0;
  int i = index;

  while(true) {
    switch(estado) {
      case 0:
        if (linha[i] == '\"') {
          estado = 1; i++; break;
        }
        else {
          retornoComValor r; r.i = index; return r;
        }
        break;   
      case 1: {
        if (std::isalpha(linha[i]) || std::isdigit(linha[i]) || linha[i] == ' ') {
          i++; break;
        }
        if (linha[i] == '\"') {
          estado = 2; i++; break;
        }
        else {
          retornoComValor r; r.i = index; return r;
        }
        break;
      }  
      case 2: {
        switch (linha[i]) {
          case ' ': estado = 5; i++; break;
          case ')': estado = 4; break;
          case ';': estado = 4; break; 
          default: retornoComValor r; r.i = index; return r;;
        }
        break;
      }
      case 4: {
        retornoComValor r;
        r.i = i;
        r.valor = linha.substr(index, i-index);
        return r;
        break;
      }
      case 5: {
        retornoComValor r;
        r.i = i;
        r.valor = linha.substr(index, i-index-1);
        return r;
        break;
      }
      default:
        retornoComValor r; r.i = index; return r;;
    }
  }
}

int achaOperadorAtribuicao(std::string linha, int index, int nLinha) {
  int estado = 0;
  int i = index;

  while(true) {
    switch (estado) {
      case 0:
        if (linha[i] == '=') {
          estado = 1; i++; break;
        }
        else {
          return index;
        }
        break;
      case 1:
        if (linha[i] == ' ') {
          estado = 2; i++; break;
        }
        else {          
          return index;
        }
        break;
      case 2:
        // std::cout << "Operador " + linha.substr(index, i-index-1) + ", l: " + std::to_string(nLinha) + " c: " + std::to_string(index) << std::endl;
        return i;
        break;
      default:
        return index;
    }
  }
}

int achaOperadorSoma(std::string linha, int index, int nLinha) {
  int estado = 0;
  int i = index;

  while(true) {
    switch (estado) {
      case 0:
        if (linha[i] == '+') {
          estado = 1; i++; break;
        }
        else {
          return index;
        }
        break;
      case 1:
        if (linha[i] == ' ') {
          estado = 2; i++; break;
        }
        else {          
          return index;
        }
        break;
      case 2:
        // std::cout << "Operador " + linha.substr(index, i-index-1) + ", l: " + std::to_string(nLinha) + " c: " + std::to_string(index) << std::endl;
        return i;
        break;
      default:
        return index;
    }
  }
}

int achaOperadorSubtracao(std::string linha, int index, int nLinha) {
  int estado = 0;
  int i = index;

  while(true) {
    switch (estado) {
      case 0:
        if (linha[i] == '-') {
          estado = 1; i++; break;
        }
        else {
          return index;
        }
        break;
      case 1:
        if (linha[i] == ' ') {
          estado = 2; i++; break;
        }
        if (std::isalpha(linha[i]) || std::isdigit(linha[i]) || linha[i] == '(') {
          estado = 3; break;
        }
        else {          
          return index;
        }
        break;
      case 2:
        // std::cout << "Operador " + linha.substr(index, i-index-1) + ", l: " + std::to_string(nLinha) + " c: " + std::to_string(index) << std::endl;
        return i;
        break;
      case 3:
        // std::cout << "Operador " + linha.substr(index, i-index) + ", l: " + std::to_string(nLinha) + " c: " + std::to_string(index) << std::endl;
        return i;
        break;
      default:
        return index;
    }
  }
}

int achaOperadorMultiplicacao(std::string linha, int index, int nLinha) {
  int estado = 0;
  int i = index;

  while(true) {
    switch (estado) {
      case 0:
        if (linha[i] == '*') {
          estado = 1; i++; break;
        }
        else {
          return index;
        }
        break;
      case 1:
        if (linha[i] == ' ') {
          estado = 2; i++; break;
        }
        else {          
          return index;
        }
        break;
      case 2:
        // std::cout << "Operador " + linha.substr(index, i-index-1) + ", l: " + std::to_string(nLinha) + " c: " + std::to_string(index) << std::endl;
        return i;
        break;
      default:
        return index;
    }
  }
}

int achaOperadorDivisao(std::string linha, int index, int nLinha) {
  int estado = 0;
  int i = index;

  while(true) {
    switch (estado) {
      case 0:
        if (linha[i] == '/') {
          estado = 1; i++; break;
        }
        else {
          return index;
        }
        break;
      case 1:
        if (linha[i] == ' ') {
          estado = 2; i++; break;
        }
        else {          
          return index;
        }
        break;
      case 2:
        // std::cout << "Operador " + linha.substr(index, i-index-1) + ", l: " + std::to_string(nLinha) + " c: " + std::to_string(index) << std::endl;
        return i;
        break;
      default:
        return index;
    }
  }
}

int achaOperadorModulo(std::string linha, int index, int nLinha) {
  int estado = 0;
  int i = index;

  while(true) {
    switch (estado) {
      case 0:
        if (linha[i] == '%') {
          estado = 1; i++; break;
        }
        else {
          return index;
        }
        break;
      case 1:
        if (linha[i] == ' ') {
          estado = 2; i++; break;
        }
        else {          
          return index;
        }
        break;
      case 2:
        // std::cout << "Operador " + linha.substr(index, i-index-1) + ", l: " + std::to_string(nLinha) + " c: " + std::to_string(index) << std::endl;
        return i;
        break;
      default:
        return index;
    }
  }
}

int achaOperadorPotencia(std::string linha, int index, int nLinha) {
  int estado = 0;
  int i = index;

  while(true) {
    switch (estado) {
      case 0:
        if (linha[i] == '*') {
          estado = 1; i++; break;
        }
        else {
          return index;
        }
        break;
      case 1:
        if (linha[i] == '*') {
          estado = 2; i++; break;
        }
        else {          
          return index;
        }
        break;
      case 2:
        if (linha[i] == ' ') {
          estado = 3; i++; break;
        }
        else {          
          return index;
        }
        break;
      case 3:
        // std::cout << "Operador " + linha.substr(index, i-index-1) + ", l: " + std::to_string(nLinha) + " c: " + std::to_string(index) << std::endl;
        return i;
        break;
      default:
        return index;
    }
  }
}

int achaAgrupadorAbre(std::string linha, int index, int nLinha) {
  int estado = 0;
  int i = index;

  while(true) {
    switch (estado) {
      case 0:
        if (linha[i] == '(') {
          estado = 1; i++; break;
        }
        else {
          return index;
        }
        break;
      case 1:
        if (std::isalpha(linha[i]) || std::isdigit(linha[i])) {
          estado = 2; break;
        }
        switch (linha[i]) {
          case '(': estado = 2; break;
          case ' ': estado = 3; i++; break;
          case ')': estado = 2; break;
          case ';': estado = 2; break; 
          default: return index;
        }
        break;
      case 2:
        // std::cout << "Agrupador " + linha.substr(index, i-index) + ", l: " + std::to_string(nLinha) + " c: " + std::to_string(index) << std::endl;
        return i;
        break;
      case 3:
        // std::cout << "Agrupador " + linha.substr(index, i-index-1) + ", l: " + std::to_string(nLinha) + " c: " + std::to_string(index) << std::endl;
        return i;
        break;
      default:
        return index;
    }
  }
}

int achaAgrupadorFecha(std::string linha, int index, int nLinha) {
  int estado = 0;
  int i = index;

  while(true) {
    switch (estado) {
      case 0:
        if (linha[i] == ')') {
          estado = 1; i++; break;
        }
        else {
          return index;
        }
        break;
      case 1:
        switch (linha[i]) {
          case ' ': estado = 3; i++; break;
          case ')': estado = 2; break;
          case ';': estado = 2; break; 
          default: return index;
        }
        break;
      case 2:
        // std::cout << "Agrupador " + linha.substr(index, i-index) + ", l: " + std::to_string(nLinha) + " c: " + std::to_string(index) << std::endl;
        return i;
        break;
      case 3:
        // std::cout << "Agrupador " + linha.substr(index, i-index-1) + ", l: " + std::to_string(nLinha) + " c: " + std::to_string(index) << std::endl;
        return i;
        break;
      default:
        return index;
    }
  }
}

int achaInicio(std::string linha, int index, int nLinha) {
  int estado = 0;
  int i = index;

  while(true) {
    switch (estado) {
      case 0:
        if (linha[i] == 'i') {
          estado = 1; i++; break;
        }
        else {
          return index;
        }
        break;
      case 1:
        if (linha[i] == 'n') {
          estado = 2; i++; break;
        }
        else {
          return index;
        }
        break;
      case 2:
        if (linha[i] == 'i') {
          estado = 3; i++; break;
        }
        else {
          return index;
        }
        break;
      case 3:
        if (linha[i] == 'c') {
          estado = 4; i++; break;
        }
        else {
          return index;
        }
        break;
      case 4:
        if (linha[i] == 'i') {
          estado = 5; i++; break;
        }
        else {
          return index;
        }
        break;
      case 5:
        if (linha[i] == 'o') {
          estado = 6; i++; break;
        }
        else {
          return index;
        }
        break;
      case 6:
        if (linha[i] == '\0') {
          estado = 7; i++; break;
        }
        else {          
          return index;
        }
        break;
      case 7:
        return i;
        break;
      default:
        return index;
    }
  }
}

int achaFim(std::string linha, int index, int nLinha) {
  int estado = 0;
  int i = index;

  while(true) {
    switch (estado) {
      case 0:
        if (linha[i] == 'f') {
          estado = 1; i++; break;
        }
        else {
          return index;
        }
        break;
      case 1:
        if (linha[i] == 'i') {
          estado = 2; i++; break;
        }
        else {
          return index;
        }
        break;
      case 2:
        if (linha[i] == 'm') {
          estado = 3; i++; break;
        }
        else {
          return index;
        }
        break;
      case 3:
        if (linha[i] == '\0') {
          estado = 4; break;
        }
        else {
          return index;
        }
        break;
      case 4:
        return i;
        break;
      default:
        return index;
    }
  }
}

int achaTipoNumero(std::string linha, int index, int nLinha) {
  int estado = 0;
  int i = index;

  while(true) {
    switch (estado) {
      case 0:
        if (linha[i] == 'n') {
          estado = 1; i++; break;
        }
        else {
          return index;
        }
        break;
      case 1:
        if (linha[i] == 'u') {
          estado = 2; i++; break;
        }
        else {
          return index;
        }
        break;
      case 2:
        if (linha[i] == 'm') {
          estado = 3; i++; break;
        }
        else {
          return index;
        }
        break;
      case 3:
        if (linha[i] == 'e') {
          estado = 4; i++; break;
        }
        else {
          return index;
        }
        break;
      case 4:
        if (linha[i] == 'r') {
          estado = 5; i++; break;
        }
        else {
          return index;
        }
        break;
      case 5:
        if (linha[i] == 'o') {
          estado = 6; i++; break;
        }
        else {
          return index;
        }
        break;
      case 6:
        if (linha[i] == ' ') {
          estado = 7; i++; break;
        }
        else {
          return index;
        }
        break;
      case 7:
        return i;
        break;
      default:
        return index;
    }
  }
}

int achaTipoString(std::string linha, int index, int nLinha) {
  int estado = 0;
  int i = index;

  while(true) {
    switch (estado) {
      case 0:
        if (linha[i] == 's') {
          estado = 1; i++; break;
        }
        else {
          return index;
        }
        break;
      case 1:
        if (linha[i] == 't') {
          estado = 2; i++; break;
        }
        else {
          return index;
        }
        break;
      case 2:
        if (linha[i] == 'r') {
          estado = 3; i++; break;
        }
        else {
          return index;
        }
        break;
      case 3:
        if (linha[i] == 'i') {
          estado = 4; i++; break;
        }
        else {
          return index;
        }
        break;
      case 4:
        if (linha[i] == 'n') {
          estado = 5; i++; break;
        }
        else {
          return index;
        }
        break;
      case 5:
        if (linha[i] == 'g') {
          estado = 6; i++; break;
        }
        else {
          return index;
        }
        break;
      case 6:
        if (linha[i] == ' ') {
          estado = 7; i++; break;
        }
        else {
          return index;
        }
        break;
      case 7:
        return i;
        break;
      default:
        return index;
    }
  }
}

int achaTipoBool(std::string linha, int index, int nLinha) {
  int estado = 0;
  int i = index;

  while(true) {
    switch (estado) {
      case 0:
        if (linha[i] == 'b') {
          estado = 1; i++; break;
        }
        else {
          return index;
        }
        break;
      case 1:
        if (linha[i] == 'o') {
          estado = 2; i++; break;
        }
        else {
          return index;
        }
        break;
      case 2:
        if (linha[i] == 'o') {
          estado = 3; i++; break;
        }
        else {
          return index;
        }
        break;
      case 3:
        if (linha[i] == 'l') {
          estado = 4; i++; break;
        }
        else {
          return index;
        }
        break;
      case 4:
        if (linha[i] == ' ') {
          estado = 5; i++; break;
        }
        else {
          return index;
        }
        break;
      case 5:
        return i;
        break;
      default:
        return index;
    }
  }
}

int achaIf(std::string linha, int index, int nLinha) {
  int estado = 0;
  int i = index;

  while(true) {
    switch (estado) {
      case 0:
        if (linha[i] == 'i') {
          estado = 1; i++; break;
        }
        else {
          return index;
        }
        break;
      case 1:
        if (linha[i] == 'f') {
          estado = 2; i++; break;
        }
        else {
          return index;
        }
        break;
      case 2:
        if (linha[i] == ' ') {
          estado = 3; i++; break;
        }
        else {
          return index;
        }
        break;
      case 3:
        return i;
        break;
      default:
        return index;
    }
  }
}

int achaElse(std::string linha, int index, int nLinha) {
  int estado = 0;
  int i = index;

  while(true) {
    switch (estado) {
      case 0:
        if (linha[i] == 'e') {
          estado = 1; i++; break;
        }
        else {
          return index;
        }
        break;
      case 1:
        if (linha[i] == 'l') {
          estado = 2; i++; break;
        }
        else {
          return index;
        }
        break;
      case 2:
        if (linha[i] == 's') {
          estado = 3; i++; break;
        }
        else {
          return index;
        }
        break;
      case 3:
        if (linha[i] == 'e') {
          estado = 4; i++; break;
        }
        else {
          return index;
        }
        break;
      case 4:
        if (linha[i] == ' ') {
          estado = 5; i++; break;
        }
        else {
          return index;
        }
        break;
      case 5:
        return i;
        break;
      default:
        return index;
    }
  }
}

int achaWhile(std::string linha, int index, int nLinha) {
  int estado = 0;
  int i = index;

  while(true) {
    switch (estado) {
      case 0:
        if (linha[i] == 'w') {
          estado = 1; i++; break;
        }
        else {
          return index;
        }
        break;
      case 1:
        if (linha[i] == 'h') {
          estado = 2; i++; break;
        }
        else {
          return index;
        }
        break;
      case 2:
        if (linha[i] == 'i') {
          estado = 3; i++; break;
        }
        else {
          return index;
        }
        break;
      case 3:
        if (linha[i] == 'l') {
          estado = 4; i++; break;
        }
        else {
          return index;
        }
        break;
      case 4:
        if (linha[i] == 'e') {
          estado = 5; i++; break;
        }
        else {
          return index;
        }
        break;
      case 5:
        if (linha[i] == ' ') {
          estado = 6; i++; break;
        }
        else {
          return index;
        }
        break;
      case 6:
        return i;
        break;
      default:
        return index;
    }
  }
}

int achaPrint(std::string linha, int index, int nLinha) {
  int estado = 0;
  int i = index;

  while(true) {
    switch (estado) {
      case 0:
        if (linha[i] == 'p') {
          estado = 1; i++; break;
        }
        else {
          return index;
        }
        break;
      case 1:
        if (linha[i] == 'r') {
          estado = 2; i++; break;
        }
        else {
          return index;
        }
        break;
      case 2:
        if (linha[i] == 'i') {
          estado = 3; i++; break;
        }
        else {
          return index;
        }
        break;
      case 3:
        if (linha[i] == 'n') {
          estado = 4; i++; break;
        }
        else {
          return index;
        }
        break;
      case 4:
        if (linha[i] == 't') {
          estado = 5; i++; break;
        }
        else {
          return index;
        }
        break;
      case 5:
        if (linha[i] == ' ') {
          estado = 6; i++; break;
        }
        else {
          return index;
        }
        break;
      case 6:
        return i;
        break;
      default:
        return index;
    }
  }
}

int achaAbreChave(std::string linha, int index, int nLinha) {
  int estado = 0;
  int i = index;

  while(true) {
    switch (estado) {
      case 0:
        if (linha[i] == '{') {
          estado = 1; i++; break;
        }
        else {
          return index;
        }
        break;
      case 1:
        if (linha[i] == '\0') {
          estado = 2; break;
        }
        else {
          return index;
        }
        break;
      case 2:
        return i;
        break;
      default:
        return index;
    }
  }
}

int achaFechaChave(std::string linha, int index, int nLinha) {
  int estado = 0;
  int i = index;

  while(true) {
    switch (estado) {
      case 0:
        if (linha[i] == '}') {
          estado = 1; i++; break;
        }
        else {
          return index;
        }
        break;
      case 1:
        if (linha[i] == '\0') {
          estado = 2; break;
        }
        else {
          return index;
        }
        break;
      case 2:
        return i;
        break;
      default:
        return index;
    }
  }
}

int achaOperadorE(std::string linha, int index, int nLinha) {
  int estado = 0;
  int i = index;

  while(true) {
    switch (estado) {
      case 0:
        if (linha[i] == '&') {
          estado = 1; i++; break;
        }
        else {
          return index;
        }
        break;
      case 1:
        if (linha[i] == '&') {
          estado = 2; i++; break;
        }
        else {          
          return index;
        }
        break;
      case 2:
        if (linha[i] == ' ') {
          estado = 3; i++; break;
        }
        else {          
          return index;
        }
        break;
      case 3:
        // std::cout << "Operador " + linha.substr(index, i-index-1) + ", l: " + std::to_string(nLinha) + " c: " + std::to_string(index) << std::endl;
        return i;
        break;
      default:
        return index;
    }
  }
}

int achaOperadorOu(std::string linha, int index, int nLinha) {
  int estado = 0;
  int i = index;

  while(true) {
    switch (estado) {
      case 0:
        if (linha[i] == '|') {
          estado = 1; i++; break;
        }
        else {
          return index;
        }
        break;
      case 1:
        if (linha[i] == '|') {
          estado = 2; i++; break;
        }
        else {          
          return index;
        }
        break;
      case 2:
        if (linha[i] == ' ') {
          estado = 3; i++; break;
        }
        else {          
          return index;
        }
        break;
      case 3:
        // std::cout << "Operador " + linha.substr(index, i-index-1) + ", l: " + std::to_string(nLinha) + " c: " + std::to_string(index) << std::endl;
        return i;
        break;
      default:
        return index;
    }
  }
}

int achaOperadorMaiorIg(std::string linha, int index, int nLinha) {
  int estado = 0;
  int i = index;

  while(true) {
    switch (estado) {
      case 0:
        if (linha[i] == '>') {
          estado = 1; i++; break;
        }
        else {
          return index;
        }
        break;
      case 1:
        if (linha[i] == '=') {
          estado = 2; i++; break;
        }
        else {          
          return index;
        }
        break;
      case 2:
        if (linha[i] == ' ') {
          estado = 3; i++; break;
        }
        else {          
          return index;
        }
        break;
      case 3:
        // std::cout << "Operador " + linha.substr(index, i-index-1) + ", l: " + std::to_string(nLinha) + " c: " + std::to_string(index) << std::endl;
        return i;
        break;
      default:
        return index;
    }
  }
}

int achaOperadorMaior(std::string linha, int index, int nLinha) {
  int estado = 0;
  int i = index;

  while(true) {
    switch (estado) {
      case 0:
        if (linha[i] == '>') {
          estado = 1; i++; break;
        }
        else {
          return index;
        }
        break;
      case 1:
        if (linha[i] == ' ') {
          estado = 2; i++; break;
        }
        else {          
          return index;
        }
        break;
      case 2:
        // std::cout << "Operador " + linha.substr(index, i-index-1) + ", l: " + std::to_string(nLinha) + " c: " + std::to_string(index) << std::endl;
        return i;
        break;
      default:
        return index;
    }
  }
}

int achaOperadorMenorIg(std::string linha, int index, int nLinha) {
  int estado = 0;
  int i = index;

  while(true) {
    switch (estado) {
      case 0:
        if (linha[i] == '<') {
          estado = 1; i++; break;
        }
        else {
          return index;
        }
        break;
      case 1:
        if (linha[i] == '=') {
          estado = 2; i++; break;
        }
        else {          
          return index;
        }
        break;
      case 2:
        if (linha[i] == ' ') {
          estado = 3; i++; break;
        }
        else {          
          return index;
        }
        break;
      case 3:
        // std::cout << "Operador " + linha.substr(index, i-index-1) + ", l: " + std::to_string(nLinha) + " c: " + std::to_string(index) << std::endl;
        return i;
        break;
      default:
        return index;
    }
  }
}

int achaOperadorMenor(std::string linha, int index, int nLinha) {
  int estado = 0;
  int i = index;

  while(true) {
    switch (estado) {
      case 0:
        if (linha[i] == '<') {
          estado = 1; i++; break;
        }
        else {
          return index;
        }
        break;
      case 1:
        if (linha[i] == ' ') {
          estado = 2; i++; break;
        }
        else {          
          return index;
        }
        break;
      case 2:
        // std::cout << "Operador " + linha.substr(index, i-index-1) + ", l: " + std::to_string(nLinha) + " c: " + std::to_string(index) << std::endl;
        return i;
        break;
      default:
        return index;
    }
  }
}

int achaOperadorIgual(std::string linha, int index, int nLinha) {
  int estado = 0;
  int i = index;

  while(true) {
    switch (estado) {
      case 0:
        if (linha[i] == '=') {
          estado = 1; i++; break;
        }
        else {
          return index;
        }
        break;
      case 1:
        if (linha[i] == '=') {
          estado = 2; i++; break;
        }
        else {          
          return index;
        }
        break;
      case 2:
        if (linha[i] == ' ') {
          estado = 3; i++; break;
        }
        else {          
          return index;
        }
        break;
      case 3:
        // std::cout << "Operador " + linha.substr(index, i-index-1) + ", l: " + std::to_string(nLinha) + " c: " + std::to_string(index) << std::endl;
        return i;
        break;
      default:
        return index;
    }
  }
}

int achaOperadorDiferente(std::string linha, int index, int nLinha) {
  int estado = 0;
  int i = index;

  while(true) {
    switch (estado) {
      case 0:
        if (linha[i] == '!') {
          estado = 1; i++; break;
        }
        else {
          return index;
        }
        break;
      case 1:
        if (linha[i] == '=') {
          estado = 2; i++; break;
        }
        else {          
          return index;
        }
        break;
      case 2:
        if (linha[i] == ' ') {
          estado = 3; i++; break;
        }
        else {          
          return index;
        }
        break;
      case 3:
        // std::cout << "Operador " + linha.substr(index, i-index-1) + ", l: " + std::to_string(nLinha) + " c: " + std::to_string(index) << std::endl;
        return i;
        break;
      default:
        return index;
    }
  }
}

int achaTrue(std::string linha, int index, int nLinha) {
  int estado = 0;
  int i = index;

  while(true) {
    switch (estado) {
      case 0:
        if (linha[i] == 't') {
          estado = 1; i++; break;
        }
        else {
          return index;
        }
        break;
      case 1:
        if (linha[i] == 'r') {
          estado = 2; i++; break;
        }
        else {
          return index;
        }
        break;
      case 2:
        if (linha[i] == 'u') {
          estado = 3; i++; break;
        }
        else {
          return index;
        }
        break;
      case 3:
        if (linha[i] == 'e') {
          estado = 4; i++; break;
        }
        else {
          return index;
        }
        break;
      case 4:
        if (linha[i] == ' ') {
          estado = 5; i++; break;
        }
        if (linha[i] == ')' || linha[i] == ';') {
          estado = 5; break;
        }
        else {          
          return index;
        }
        break;
      case 5:
        return i;
        break;
      default:
        return index;
    }
  }
}

int achaFalse(std::string linha, int index, int nLinha) {
  int estado = 0;
  int i = index;

  while(true) {
    switch (estado) {
      case 0:
        if (linha[i] == 'f') {
          estado = 1; i++; break;
        }
        else {
          return index;
        }
        break;
      case 1:
        if (linha[i] == 'a') {
          estado = 2; i++; break;
        }
        else {
          return index;
        }
        break;
      case 2:
        if (linha[i] == 'l') {
          estado = 3; i++; break;
        }
        else {
          return index;
        }
        break;
      case 3:
        if (linha[i] == 's') {
          estado = 4; i++; break;
        }
        else {
          return index;
        }
        break;
      case 4:
        if (linha[i] == 'e') {
          estado = 5; i++; break;
        }
        else {
          return index;
        }
        break;
      case 5:
        if (linha[i] == ' ') {
          estado = 6; i++; break;
        }
        if (linha[i] == ')' || linha[i] == ';') {
          estado = 6; break;
        }
        else {          
          return index;
        }
        break;
      case 6:
        return i;
        break;
      default:
        return index;
    }
  }
}