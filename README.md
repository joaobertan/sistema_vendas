# Sistema de Vendas (Projeto de Laboratório de Programação)

Este projeto foi desenvolvido durante as aulas de **Laboratório de Programação** na universidade. Trata-se de um sistema simples de vendas escrito em **linguagem C**, com gerenciamento de **Produtos**, **Clientes** e **Vendas**, utilizando **vetores fixos**, **structs** e **menus interativos no terminal**.

---

## 📋 Funcionalidades Principais

### 🛒 Produtos
- Cadastro de novos produtos
- Listagem de produtos cadastrados
- Atualização de informações dos produtos
- Exclusão de produtos

### 👤 Clientes
- Cadastro de novos clientes
- Listagem de clientes cadastrados
- Atualização de informações dos clientes
- Exclusão de clientes

### 💰 Vendas
- Realização de vendas (associando clientes e produtos)
- Listagem de vendas realizadas

---

## 🗂️ Estrutura de Arquivos

|── main.c # Função principal e controle dos menus

|── actions.c # Funções para criar, listar, atualizar e excluir produtos e clientes, além de realizar vendas

|── utils.c # Funções utilitárias como validações e formatação de CPF

|── structs.h # Definição das structs (Product, Client, Sale, SaledProducts)

|── actions.h # Header das funções de ações

|── utils.h # Header das funções utilitárias

## 🛠️ Tecnologias Utilizadas

- Linguagem: **C**
- Compilador: **GCC**
- IDE: **CLion** (JetBrains)

## 📌 Limitações do Sistema

### Limites de cadastro:

- Máximo de **10 produtos**
- Máximo de **10 clientes**
- Máximo de **10 vendas**
- Máximo de **100 produtos vendidos** (itens em vendas)

---

### Sem persistência de dados:

Todos os dados são mantidos apenas **em memória** enquanto o programa estiver em execução.  
Ao **fechar o programa**, todas as informações cadastradas serão **perdidas**.

## ✅ Melhorias Futuras (sugestões)

- Implementar **gravação em arquivos** (salvar e carregar dados)
- **Alocação** de clientes, produtos e vendas
- Implementar **filtros e relatórios** (exemplo: listar vendas por cliente)
