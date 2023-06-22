# sistemaBanco
Projeto desenvolvido para a disciplina Algoritmos e Lógica de Programação 2, utilizando conceito de Estruturas. 

Um banco armazena dados de seus clientes, suas contas correntes e a movimentação de cada conta. Pensando na movimentação que os clientes fazem em suas contas vamos controlar nesse sistema os depósitos e saques nas contas correntes, para isso vamos implementar algumas funcionalidades.
## Organização do Programa:
Os dados das contas e seus clientes devem estar armazenados em estrutura e uniões como indicado a seguir:
* Conta: deve conter o número da conta (deve ser único e gerado pelo próprio programa), saldo, número da agência, tipo da conta e os titulares da conta (deve estar vinculado aos clientes cadastrados).
* Cliente: deve conter nome do cliente, RG, endereço, telefone, renda, tipo de cliente e numa união o cpf ou cnpj do cliente que pode ser uma pessoa física ou jurídica.
* Defina também um typedef para as estruturas criadas.
O programa deve ter uma organização que permita a execução das funcionalidades propostas. Pode ser na forma de menu de opções. Os dados gerados no programa devem ser armazenados em vetores de tamanho fixo.
As funcionalidades devem ser desenvolvidas em funções.
## Funcionalidades propostas:
* Inserção:
▪ Novas contas
▪ Novos Clientes
* Impressão
▪ Imprimir dados de uma conta
▪ Imprimir dados de um Cliente
▪ Todos os clientes de uma agência
▪ Todas as contas de um tipo de uma agência.
* Atualização
▪ Dados dos clientes
▪ Não é permitido mudar CPF do cliente.
▪ Dados das contas
▪ Não é permitido mudar número da conta, agência e tipo de
conta.
* Deposito
▪ Dado um valor e uma conta e uma agência, fazer uma função que faça o deposito do valor na conta. Quando o deposito for feito faça a impressão do número da conta, do nome do cliente e do novo saldo. (Lembre-se que o deposito aumenta o saldo da conta).
* Saque 
▪ Faça uma função que execute o saque de um determinado valor da conta corrente fornecida. Se o saque foi possível imprima todos os dados da conta e se não for possível imprima uma mensagem para o usuário.
* Pix
▪ Dado o valor do código PIX da operação, faça uma função que efetue o pagamento ou crédito do valor fornecido.
