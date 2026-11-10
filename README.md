# PSE EM AÇÃO

## Sistema de Planejamento e Acompanhamento de Ações de Saúde na Escola

Projeto desenvolvido para a Atividade de Estudo Programada (AEP) do 2º semestre de 2026 do curso de Engenharia de Software da Universidade Cesumar - UniCesumar.

O projeto propõe o desenvolvimento de uma aplicação em linguagem C, executada em terminal, destinada ao planejamento e acompanhamento de ações coletivas do Programa Saúde na Escola (PSE).

---

## Integrantes

- Davi Mancini Faustino Da Silva
- Nicolas Alexandre
- Davi Pena Justino

---

## Objetivo do projeto

Planejar e desenvolver uma aplicação em linguagem C capaz de auxiliar equipes escolares e profissionais da saúde no cadastro, consulta e acompanhamento de ações coletivas do Programa Saúde na Escola.

A solução busca organizar as informações das ações realizadas ou planejadas, facilitar a localização dos registros e apresentar dados gerais de participação de maneira simples e compreensível.

---

## Funcionalidades previstas

O sistema deverá permitir:

- Cadastrar ações do Programa Saúde na Escola;
- Listar todas as ações cadastradas;
- Pesquisar ações por código, escola ou tema;
- Atualizar a situação da ação para planejada, realizada ou cancelada;
- Registrar a quantidade efetiva de participantes das ações realizadas;
- Gerar um resumo geral das ações cadastradas;
- Calcular o percentual de participação efetiva em relação à quantidade prevista nas ações realizadas;
- Validar códigos, quantidades, campos obrigatórios e opções do menu;
- Permanecer em execução até que o usuário escolha encerrar o programa.

---

## Tecnologias e recursos

- Linguagem C;
- Aplicação executada em terminal;
- Git e GitHub para organização e versionamento do projeto;
- Estruturas condicionais;
- Estruturas de repetição;
- Vetores;
- Funções;
- Estruturas do tipo `struct`.

---

## Escopo do sistema

O projeto contempla o cadastro e acompanhamento de ações coletivas do PSE utilizando informações administrativas e dados agregados.

Entre as informações previstas estão:

- Código da ação;
- Escola;
- Tema;
- Data prevista;
- Público-alvo;
- Responsável;
- Quantidade prevista de participantes;
- Situação da ação;
- Quantidade efetiva de participantes.

O sistema será desenvolvido de forma compatível com o nível introdutório do segundo semestre do curso.

---

## Privacidade e limites da solução

A aplicação utilizará somente dados fictícios e informações coletivas.

Não serão armazenados nomes de estudantes, diagnósticos, prontuários, condições clínicas ou outros dados pessoais sensíveis.

O sistema possui finalidade acadêmica e administrativa e não realizará diagnóstico, triagem, prescrição ou recomendação de tratamento.

---

## Estrutura do repositório

```text
AEP-PSE-EM-ACAO/
│
├── documentacao/
│   └── Documentos, fluxogramas, pseudocódigos e materiais da AEP
│
├── src/
│   └── Código-fonte da aplicação em linguagem C
│
└── README.md
    └── Informações gerais do projeto
```

---

## Processo de desenvolvimento

O projeto será desenvolvido de forma incremental, utilizando sprints semanais.

O planejamento contempla as seguintes etapas:

1. Levantamento e contextualização;
2. Modelagem da solução;
3. Desenvolvimento da base da aplicação;
4. Implementação das funcionalidades principais;
5. Testes e geração do resumo;
6. Documentação e preparação da apresentação final.

---

## Status do projeto

### 1ª etapa da AEP (Planejamento e Modelagem) — Concluída
Nesta etapa foram desenvolvidos:
- Contextualização do problema;
- Definição dos objetivos;
- Delimitação do escopo;
- Identificação dos usuários;
- Requisitos funcionais e não funcionais;
- Regras de negócio;
- Modelagem dos dados;
- Fluxogramas;
- Pseudocódigos;
- Planejamento das sprints;
- Identificação de riscos;
- Plano preliminar de testes;
- Documentação da primeira etapa.

### 2ª etapa da AEP (Implementação e Validação) — Concluída / Em Fase de Entrega
Nesta etapa foram desenvolvidos e integrados:
- Implementação completa do código-fonte da aplicação em Linguagem C (`src/main.c`);
- Estruturação de registros (`struct Acao`) e manipulação de vetores na memória;
- Menu interativo com validações de entrada e navegação contínua no terminal;
- Funções modulares para cadastro, listagem, pesquisa por critérios, atualização de status e cálculo de percentual de atendimento no resumo;
- Elaboração do Diagrama de Casos de Uso e especificação detalhada dos casos de uso principais;
- Elaboração do Manual do Usuário com instruções detalhadas de compilação, execução e uso;
- Gravação da vídeo-demonstração da aplicação e consolidação do documento final.
---

## Instituição

**Universidade Cesumar - UniCesumar**  
Curso de Engenharia de Software  
2º semestre de 2026
