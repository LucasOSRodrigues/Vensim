# MyVensim

Projeto da disciplina Engenharia de Software I.

## Sprint 5 - Arquitetura em camadas, componentização e fábricas

Esta versão organiza o projeto em camadas, sem exigir que o usuário da API conheça as classes concretas de implementação.

- **Camada de interface/API:** `System.h`, `Flow.h`, `Model.h` e `MySim.h`.
- **Camada de implementação:** `SystemImpl`, `FlowImpl` e `ModelImpl`.
- **Camada de aplicação/testes:** arquivos dentro de `test/`.

A componentização foi feita por separação de responsabilidades em arquivos/classes de interface e implementação. Nesta versão, o projeto é compilado diretamente pelo `Makefile`, sem gerar DLL/SO.

## Fábricas

O usuário deve preferir criar objetos pela API pública:

```cpp
#include "src/MySim.h"

Model* model = Model::createModel();
System* s1 = model->createSystem("S1", 100.0);
System* s2 = model->createSystem("S2", 0.0);
Flow* f = model->createFlow<MyFlow>(s1, s2);
```

Também existe a fábrica direta de `System`:

```cpp
System* s = System::createSystem("S", 10.0);
```

## Compilar

```bash
make
```

## Executar todos os testes

```bash
make tests
```

## Executar separadamente

```bash
make funcional_test
make unit_test
```

## Limpar

```bash
make clean
```
