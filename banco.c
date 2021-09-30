/*Esse projeto foi desenvolvido pela aluna Lucy Késsila Arquejada Velasco - PC3015581, do curso Engenharia da Computação
do Instituto Federal de São Paulo campus Piracicaba, para a disciplina de Algorítmos e Lógica de Programação 2 (ALPC2),
conforme proposto pela professora Andreia Novelli. Projeto 1 - Opção 1.*/


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdbool.h>

#define MAX 100
typedef struct contas cnts;
struct contas
{
	int num_conta;
	int chave_pix;
	float saldo;
	int agencia;
	int tipo_conta;
	int qtd_titulares;
	char nome_titulares[5][50];
	int RG_titulares[5];
}contas[MAX];

typedef union documentos doc;
union documentos{
	int cpf;
	int cnpj;
};

typedef struct clientes clts;
struct clientes
{
	int num_cliente;
	char nome[50];
	int RG;
	char endereco[70];
	char ddd_telefone[12];
	float renda;
	int tipo_cliente;
	doc cpf_ou_cnpj;
}clientes[MAX];

void menuPrincipal();
int main();

void inserir_nova_conta();
void inserir_novo_cliente();
void imprimir_dados_conta();
void imprimir_dados_cliente();
void imprimir_clientes_agencia();
void imprimir_contas_tipo_agencia();
void atualizar_cliente();
void atualizar_conta();
void depositar();
void sacar();
void pix();
int opcao;
int qtd_cnts_cadastrado = 0;
int qtd_clts_cadastrado = 0;
int qtd_titulares = 0;


void inserir_novo_cliente(){
	int op, num=1;
	bool existe;
	do{
		clientes[qtd_clts_cadastrado].num_cliente=num;
		printf("\n Numeração do cliente: %d", clientes[qtd_clts_cadastrado].num_cliente);
		printf("\nRG: ");
		scanf("%d", &clientes[qtd_clts_cadastrado].RG);
		/*do{
			existe=false;
			printf("\nRG: ");
			scanf("%d", &clientes[qtd_clts_cadastrado].RG);
			if(qtd_clts_cadastrado==0){
				existe=false;
			} else
				for (int i=0;i<qtd_clts_cadastrado;i++){
					if (clientes[qtd_clts_cadastrado].RG==clientes[i].RG)
					{
						printf("Esse cliente já está cadastrado.");
						existe=true;
					}
				}
		
		}
		while (existe=true);*/
		fflush(stdin);
		printf("\nNome: "); gets(clientes[qtd_clts_cadastrado].nome);
		printf("\nEndereço: "); gets(clientes[qtd_clts_cadastrado].endereco);
		printf("\nDDD+Telefone: "); gets(clientes[qtd_clts_cadastrado].ddd_telefone);
		printf("\nRenda: "); scanf("%f", &clientes[qtd_clts_cadastrado].renda);
		
		do {
			printf("\nTipo de cliente: 1) Pessoa física - 2) Pessoa jurídica\n"); scanf("%d", &clientes[qtd_clts_cadastrado].tipo_cliente);
			switch (clientes[qtd_clts_cadastrado].tipo_cliente){
				case 1:
		        	printf("\nDigite o CPF: ");
					scanf("%d",&clientes[qtd_clts_cadastrado].cpf_ou_cnpj.cpf);
	       			break;
	       		case 2:
		       		printf("\nDigite o CNPJ: ");
					scanf("%d",&clientes[qtd_clts_cadastrado].cpf_ou_cnpj.cnpj);
					break;
				default:
					printf("\nOpção invalida! Tente novamente.\n");
			}
		} while(clientes[qtd_clts_cadastrado].tipo_cliente != 1 && clientes[qtd_clts_cadastrado].tipo_cliente != 2);
        fflush(stdin);
        
        printf("\nCLIENTE CADASTRADO COM SUCESSO");
        printf("\nNumero: %d",clientes[qtd_clts_cadastrado].num_cliente);
        printf("\nNome: %s",clientes[qtd_clts_cadastrado].nome);
        printf("\nRG: %d",clientes[qtd_clts_cadastrado].RG);
        printf("\nEndereço: %s",clientes[qtd_clts_cadastrado].endereco);
        printf("\nTelefone: %s",clientes[qtd_clts_cadastrado].ddd_telefone);
		printf("\nRenda: %f",clientes[qtd_clts_cadastrado].renda);
		
		if (clientes[qtd_clts_cadastrado].tipo_cliente==1){
			printf("\nTipo de cliente: 1) Pessoa física");
			printf("\nCPF: %d",clientes[qtd_clts_cadastrado].cpf_ou_cnpj.cpf);
		} else{
			printf("\nTipo de cliente: 2) Pessoa jurídica");
			printf("\nCNPJ: %d",clientes[qtd_clts_cadastrado].cpf_ou_cnpj.cnpj);
		}
		
        
        num++;
        qtd_clts_cadastrado++;
		printf("\nDeseja cadastrar mais um cliente? 1- Sim 0 - Nao ");
        scanf ("%d", &op);

	}while(op != 0);
}


void inserir_nova_conta(){
	int op,num=1,qtd_titulares=0,rg_teste[5],existe=0;
	char nome_teste[5][50];

	//===========VERIFICA TITULARES=================
	do{
		printf("\nQuantos titulares essa conta terá? (Mínimo:1 - Máximo: 5)"); scanf("%d", &qtd_titulares);
		
			contas[qtd_cnts_cadastrado].qtd_titulares=qtd_titulares;
			for (int i=0; i<qtd_titulares; i++){
				
		            printf("\nNome do titular %d\n",i+1); scanf("%s", &nome_teste[i][50]);
		            fflush(stdin);
					printf("\n RG do titular %d\n", i+1); scanf("%d", &rg_teste[i]);
		            if (qtd_clts_cadastrado == 0)
		            {
		                existe = 0;
		                printf("\n Nenhum cliente registrado. Por favor, cadastre o cliente antes de cadastrar uma conta.");
		                break;
		                
		            } else
		                for (int j = 0; j < qtd_clts_cadastrado; j++)
		                {
		                    if (rg_teste[i] == clientes[j].RG)
		                    {
		                        existe++;
		                        contas[qtd_cnts_cadastrado].nome_titulares[i][50]=nome_teste[i][50];
		                        contas[qtd_cnts_cadastrado].RG_titulares[i]=rg_teste[i];
		                    }
		                }
	    	}
	    	if (existe<qtd_titulares){
	    		printf("\n Cliente não registrado. Por favor, cadastre o cliente antes de cadastrar uma conta.");
		        break;
			} else{
	    	//==============CADASTRA CONTA===============
				fflush(stdin);
				contas[qtd_cnts_cadastrado].num_conta= num;
				
				printf("\nNúmero da conta: %d", contas[qtd_cnts_cadastrado].num_conta);
				printf("\nChave PIX: "); scanf("%d",&contas[qtd_cnts_cadastrado].chave_pix);
				printf("\nSaldo: "); scanf("%f", &contas[qtd_cnts_cadastrado].saldo);
				printf("\nAgência: "); scanf("%d", &contas[qtd_cnts_cadastrado].agencia);
				printf("\nTipo de conta: 1) Conta-corrente - 2) Conta poupança - 3) Conta salário - 4) Conta digital - 5) Conta universitária: \n"); 
				scanf("%d", &contas[qtd_cnts_cadastrado].tipo_conta);
				
				fflush(stdin);
			
				num++;
		        qtd_cnts_cadastrado++;
				printf("\nCONTA CADASTRADA COM SUCESSO\n");
				
				/*printf("\nNumero da Conta: %d",contas[qtd_cnts_cadastrado].num_conta);
		        printf("\nSaldo: %f",contas[qtd_cnts_cadastrado].saldo);
		        printf("\nNúmero da Agência: %d",contas[qtd_cnts_cadastrado].agencia);
		        switch(contas[qtd_cnts_cadastrado].tipo_conta){
					case 1:
						printf("\n Tipo de conta: 1) Conta-corrente");
						break;
					case 2:
						printf("2) Conta poupança");
						break;
					case 3:
						printf("3) Conta salário");
						break;
					case 4:
						printf("4) Conta digital");
						break;
					case 5:
						printf("5) Conta universitária");
						break;
				}
		        for (int i=0; i<qtd_titulares; i++){
					
		            printf("\nNome do titular : %s \n", contas[qtd_cnts_cadastrado].nome_titulares[i][50]);
					printf("\n RG do titular %d: \n",contas[qtd_cnts_cadastrado].RG_titulares[i]); 
				}*/
			
				
		        
				
			 
		}
			existe=0;
			printf("\nDeseja cadastrar mais uma conta? 1- Sim 0 - Nao ");
		    scanf ("%d", &op);
		}while(op != 0);
	}
		
			

		
void imprimir_dados_conta(int num){
	int indice, op;
	bool achou=false;
	
		do{
		if (qtd_cnts_cadastrado == 0){
			achou=false;
			printf("\n Não há nenhuma conta cadastrada no momento.");
			break;
		} 
		for (indice=0; indice<qtd_cnts_cadastrado;indice++){
			
			if (contas[indice].num_conta==num){
				achou = true;
				printf("\nNumero da Conta: %d",contas[indice].num_conta);
		        printf("\nSaldo: %f",contas[indice].saldo);
		        printf("\nNúmero da Agência: %d",contas[indice].agencia);
		        for (int i=0; i<qtd_titulares; i++){
				
		            printf("\nNome do titular : %s \n", contas[indice].nome_titulares[i]);
					printf("\n RG do titular : %d \n",contas[indice].RG_titulares[i]); 
				}
		        switch(contas[indice].tipo_conta){
					case 1:
						printf("\n Tipo de conta: 1) Conta-corrente");
						break;
					case 2:
						printf("\n Tipo de conta: 2) Conta poupança");
						break;
					case 3:
						printf("\n Tipo de conta: 3) Conta salário");
						break;
					case 4:
						printf("\n Tipo de conta: 4) Conta digital");
						break;
					case 5:
						printf("\n Tipo de conta: 5) Conta universitária");
						break;
				}
				fflush(stdin);
		        
				
		        
			} 
			
		
		}
		
			if (achou==false){
				printf("\nConta não encontrada.");
			}
			printf("\n");
			fflush(stdin);
			printf("Deseja acessar outra conta? 1- Sim 0 - Nao ");
			scanf ("%d", &op);
			if (op==1){
				printf("\nDigite o número da conta: ");
				scanf("%d", &num);
			}
	
		} while(op != 0);
	
}
        
void imprimir_dados_cliente(){
	int indice, rg, op, achou=0;
	
	
		do{
		if (qtd_clts_cadastrado == 0){
		achou=0;
		printf("\n Não há nenhum cliente cadastrado no momento.");
		break;
		}
		printf("\n RG do cliente que deseja acessar: "); scanf("%d", &rg);
		for (indice=0; indice<qtd_clts_cadastrado;indice++){
			
			if (clientes[indice].RG==rg){
				achou=1;
				printf("\nNumero: %d",clientes[indice].num_cliente);
		        printf("\nNome: %s",clientes[indice].nome);
		        printf("\nRG: %d",clientes[indice].RG);
		        printf("\nEndereço: %s",clientes[indice].endereco);
		        printf("\nTelefone: %s",clientes[indice].ddd_telefone);
				printf("\nRenda: %f",clientes[indice].renda);
				
				if (clientes[indice].tipo_cliente==1){
					printf("\nTipo de cliente: 1) Pessoa física");
					printf("\nCPF: %d",clientes[indice].cpf_ou_cnpj.cpf);
				} else{
					printf("\nTipo de cliente: 2) Pessoa jurídica");
					printf("\nCNPJ: %d",clientes[indice].cpf_ou_cnpj.cnpj);
				}
			        
				} 
			}
			if(achou != 1){
				printf("\nCliente não encontrado.");
			}
			fflush(stdin);
			
		    
		    printf("\n");
			printf("Deseja acessar outro cliente? 1- Sim 0 - Nao ");
			scanf ("%d", &op);
			} while(op != 0);
}

void atualizar_cliente(){
	int rg, op, op1,indice, achou=0;
	
	do{
		if (qtd_clts_cadastrado == 0){
			achou=0;
			printf("\n Não há nenhum cliente cadastrado no sistema no momento.");
			break;
		} else{
			printf("\n RG do cliente a ser atualizado: "); scanf("%d", &rg);
			achou=0;
			for (int i=0; i<qtd_clts_cadastrado;i++){
				if (clientes[i].RG==rg){
					achou = 1;
					indice=i;
					printf(
                "\n============= Atualizar dados do cliente ============= \n\n"
                "Escolha uma das opções abaixo: \n"
                "Tecle '1' para editar o nome do cliente\n"
                "Tecle '2' para editar o RG \n"
                "Tecle '3' para editar o endereço\n"
                "Tecle '4' para editar o telefone\n"
                "Tecle '5' para editar a renda\n"
                "Tecle '0' para sair\n\n"
            );
            scanf("%d", &op1);
            switch(op1){
            	case 1:
            		fflush(stdin);
            		printf("Nome do cliente: ");
                	gets(clientes[indice].nome);
                	break;
                case 2:
                	fflush(stdin);
            		printf("RG do cliente: ");
                	scanf("%d",&clientes[indice].RG);
                	break;
                case 3:
                	fflush(stdin);
                	printf("Novo endereço: ");
                	gets(clientes[indice].endereco);
                	break;
                case 4:
                	fflush(stdin);
                	printf("Telefone com DDD: ");
                	gets(clientes[indice].ddd_telefone);
                	break;
                case 5:
                	fflush(stdin);
                	printf("Renda: ");
                	scanf("%f",&clientes[indice].renda);
                	break;
                case 0:
                	printf("Saindo...");
                	fflush(stdin);
                	break;
                default:
                	printf ("\n\t\t\tOpcao invalida!\n\n");
                	fflush(stdin);
                	break;
			}
				}  
			} 
	}
		fflush(stdin);
		if (achou ==0){
			printf("\nCliente não encontrado.");
		}
		printf("\n");
		printf("Deseja acessar outro cliente? 1- Sim 0 - Nao ");
		scanf ("%d", &op);
	} while (op != 0);
}

void atualizar_conta(){
	int num, op, op1,indice,rg_teste[5];
	char nome_teste[5][50];
	bool achou=false;
	
	do{
		if (qtd_cnts_cadastrado == 0){
		achou=false;
		printf("\n Não há nenhuma conta cadastrada no momento.");
		break;
		
			}
		printf("\n Número da conta que deseja acessar: "); scanf("%d", &num);
		for (int i=0; i<qtd_clts_cadastrado;i++){	
			if (contas[i].num_conta==num){
				achou = true;
				indice=i;
				}  
		}
		
		if (achou){
			printf(
                "\n============= Atualizar dados do cliente ============= \n\n"
                "Escolha uma das opções abaixo: \n"
                "Tecle '1' para atualizar o saldo da conta\n"
                "Tecle '2' para atualizar os titulares da conta \n"
                "Tecle '0' para sair\n\n"
            );
            scanf("%d", &op1);
            switch(op1){
            	case 1:
            		fflush(stdin);
            		printf("Saldo da conta: ");
                	scanf("%f",contas[indice].saldo);
                	break;
                case 2:
                	fflush(stdin);
            		for (int i=0; i<qtd_titulares; i++){
			            printf("\nNome do titular %d\n",i+1); scanf("%s", &nome_teste[i][50]);
						printf("\n RG do titular %d\n", i+1); scanf("%d", &rg_teste[i]);
			            if (qtd_clts_cadastrado == 0)
			            {
			                achou = false;
			                printf("\n Nenhum cliente registrado. Por favor, cadastre o cliente antes de cadastrar uma conta.");
			                break;
			                
			            } else
			                for (int j = 0; j < qtd_clts_cadastrado; j++)
			                {
			                    if (rg_teste[i] == clientes[j].RG)
			                    {
			                        achou = true;
			                        contas[qtd_cnts_cadastrado].nome_titulares[i][50]=nome_teste[i][50];
			                        contas[qtd_cnts_cadastrado].RG_titulares[i]=rg_teste[i];
			                    }
			                }
			    	}
                	break;
                
                case 0:
                	printf("Saindo...");
                	fflush(stdin);
                	break;
                default:
                	printf ("\n\t\t\tOpcao invalida!\n\n");
                	fflush(stdin);
                	break;
			}
		} else printf("\nCliente não encontrado.");
			
		
		fflush(stdin);
		
		printf("\n");
		printf("Deseja acessar outro cliente? 1- Sim 0 - Nao ");
		scanf ("%d", &op);
	} while (op != 0);
}

void imprimir_clientes_agencia(){
	int i, indice, ag, op, tipo, rg[5];
	bool encontroucontas=false, encontrouclientes=false;
		do{
		
		printf("\n Número da agência que deseja acessar: "); scanf("%d", &ag);
		
		for (i=0; i<qtd_cnts_cadastrado;i++){	
			if (qtd_clts_cadastrado == 0){
				encontrouclientes=false;
				printf("\n Não há nenhum cliente cadastrado no momento.");
				break;
			}
			if (contas[i].agencia==ag) {
				encontroucontas=true;
				for (int titular=0; titular<qtd_titulares; titular++){
					rg[titular]=contas[i].RG_titulares[titular];
				}
		
		if (encontroucontas==false) {
			printf("\nNenhuma conta encontrada nesta agência.");
			break;
			}
			
		for (int indice=0; indice<qtd_clts_cadastrado; indice++){
			if (clientes[indice].RG==rg[indice]){
				encontrouclientes=true;
				printf("\nNumero: %d",clientes[indice].num_cliente);
			        printf("\nNome: %s",clientes[indice].nome);
			        printf("\nRG: %d",clientes[indice].RG);
			        printf("\nEndereço: %s",clientes[indice].endereco);
			        printf("\nTelefone: %s",clientes[indice].ddd_telefone);
					printf("\nRenda: %f",clientes[indice].renda);
					
					if (clientes[indice].tipo_cliente==1){
						printf("\nTipo de cliente: 1) Pessoa física");
						printf("\nCPF: %d",clientes[indice].cpf_ou_cnpj.cpf);
					} else{
						printf("\nTipo de cliente: 2) Pessoa jurídica");
						printf("\nCNPJ: %d",clientes[indice].cpf_ou_cnpj.cnpj);
					}
				}
				for (int j=0; j<5;j++){
					if (clientes[j].RG==rg[i]){
					printf("\nNumero: %d",clientes[indice].num_cliente);
			        printf("\nNome: %s",clientes[indice].nome);
			        printf("\nRG: %d",clientes[indice].RG);
			        printf("\nEndereço: %s",clientes[indice].endereco);
			        printf("\nTelefone: %s",clientes[indice].ddd_telefone);
					printf("\nRenda: %f",clientes[indice].renda);
					
					if (clientes[indice].tipo_cliente==1){
						printf("\nTipo de cliente: 1) Pessoa física");
						printf("\nCPF: %d",clientes[indice].cpf_ou_cnpj.cpf);
					} else{
						printf("\nTipo de cliente: 2) Pessoa jurídica");
						printf("\nCNPJ: %d",clientes[indice].cpf_ou_cnpj.cnpj);
					}
					        
					} 
			}
			}

				
		
			fflush(stdin);
			printf("\n");
			printf("Deseja procurar novamente? 1- Sim 0 - Nao ");
			scanf ("%d", &op);
			} 
	
		}
}while(op != 0);
}

void imprimir_contas_tipo_agencia(){
	int i, indice,num, ag, op, tipo;
	bool encontrou=false;
	do{
	
		if (qtd_cnts_cadastrado == 0){
		printf("\n Não há nenhuma conta cadastrada no momento.");
		break;
		} 
			printf("\n Número da agência que deseja acessar: "); scanf("%d", &ag);
			printf("\n Tipo de contas que deseja acessar: "); scanf("%d", &tipo);
			fflush(stdin);
			for (indice=0; indice<qtd_cnts_cadastrado;indice++){
				if ((contas[indice].agencia==ag) && (contas[indice].tipo_conta==tipo)){
					encontrou=true;
					printf("\nNumero da Conta: %d",contas[indice].num_conta);
			        printf("\nSaldo: %f",contas[indice].saldo);
			        printf("\nNúmero da Agência: %d",contas[indice].agencia);
			        switch(contas[indice].tipo_conta){
						case 1:
							printf("\n Tipo de Conta: 1) Conta-corrente");
							break;
						case 2:
							printf("\n Tipo de Conta: 2) Conta poupança");
							break;
						case 3:
							printf("\n Tipo de Conta: 3) Conta salário");
							break;
						case 4:
							printf("\n Tipo de Conta: 4) Conta digital");
							break;
						case 5:
							printf("\n Tipo de Conta: 5) Conta universitária");
							break;
						default:
							break;
					 }
			        
			        
			        for (int i=0; i<contas[indice].qtd_titulares; i++){
					
			            printf("\nNome do titular %d: %s\n",i+1, contas[indice].nome_titulares[i]);
						printf("\n RG do titular %d: %d\n", i+1,contas[indice].RG_titulares[i]); 
					 }
				}		
			} 
				
	fflush(stdin);
	printf("\n");
	if (encontrou==false) {
		printf("\nNenhuma conta encontrada.");
	}
	printf("\nDeseja procurar novamente?"); scanf("%d", &op);	
			
	} while(op!=0);
	} 


void depositar(){
	int ag, num,op;
	float valor;
	char nome[70];
	bool contaencontrada=false;
	do{
		printf("==============DEPÓSITO=====================");
		printf("\nDigite seu nome completo: ");
		scanf("%s",&nome[70]);
		fflush(stdin);
		printf("\nNúmero da conta na qual deseja depositar: ");
		scanf("%d", &num);
		fflush(stdin);
		printf("\nNúmero da Agência: ");
		scanf("%d", &ag);
		fflush(stdin);
		printf("\nDigite o valor que deseja depositar: ");
		scanf("%f", &valor);
		fflush(stdin);
		for (int i=0; i<qtd_cnts_cadastrado; i++){
			if (qtd_cnts_cadastrado == 0){
				contaencontrada=false;
				printf("\n Não há nenhuma conta cadastrada no momento.");
				break;
			}
			if (contas[i].agencia==ag && contas[i].num_conta==num){
				contaencontrada=true;
				contas[i].saldo=(valor + contas[i].saldo);
				printf("\nValor depositado com sucesso");
				printf("\nNúmero da Conta: %d", contas[i].num_conta);
				printf("\nNome do Titular 1: %s", contas[i].nome_titulares[0][50]);
				printf("\nNome da pessoa que efetuou o depósito: %s", nome[50]);
				printf("\nNovo saldo = %f", contas[i].saldo);
				break;
			}
		}
		if (contaencontrada==false){
			printf("\nConta não encontrada.");
			break;
		} 
		
		fflush(stdin);
		printf("\n");
		printf("Deseja realizar outro depósito? 1- Sim 0 - Nao ");
		scanf ("%d", &op);
		} while(op != 0);
	
	} 

void sacar(){
	int num, op, achouconta=0;
	float valor;
	
	do{
		printf("==========SAQUE==============");
		printf("\n Digite o número da conta corrente: ");
		scanf("%d", &num);
		for (int i=0; i<qtd_cnts_cadastrado; i++){
			if (contas[i].num_conta==num && contas[i].tipo_conta==1){
				achouconta=1;
				printf("\nDigite o valor que deseja sacar: ");
				scanf("%f", &valor);
				if (valor>contas[i].saldo){
					printf("\nNão é possível sacar esse valor.");
				} else{
					contas[i].saldo=(contas[i].saldo - valor);
					printf("\n Saque realizado com sucesso.");
					
					
				}
			} 
		}
		if (achouconta==0){
			printf("\nConta corrente não encontrada.");
		}
		fflush(stdin);
		printf("\nDeseja realizar outro saque?");
		scanf("%d", &op);
	} while(op != 0);
}

void pix(){
	int pix,op;
	float valor;
	char nome[70];
	bool contaencontrada=false;
	do{
		printf("==============DEPÓSITO=====================");
		printf("\nDigite seu nome completo: ");
		scanf("%s",&nome[70]);
		printf("\nInsira a chave PIX da operação: ");
		scanf("%d", &pix);
	
		printf("\nDigite o valor que deseja depositar: ");
		scanf("%f", &valor);
		for (int i=0; i<qtd_cnts_cadastrado; i++){
			if (qtd_cnts_cadastrado == 0){
				contaencontrada=false;
				printf("\n Não há nenhuma conta cadastrada no sistema.");
				break;
			}
			if (contas[i].chave_pix==pix){
				contaencontrada=true;
				contas[i].saldo=(valor + contas[i].saldo);
				printf("\nValor depositado com sucesso");
				printf("\nCódigo PIX: %d", contas[i].chave_pix);
				printf("\nNome do Titular 1: %d", contas[i].nome_titulares[0]);
				printf("\nNome da pessoa que efetuou o pagamento: %s", nome[70]);
				printf("\nValor transferido: %f", valor);
				break;
			}
		}
		if (contaencontrada=false){
			printf("\nConta não encontrada. Verifique o código PIX e tente novamente.");
			break;
		} 
		
		fflush(stdin);
		printf("\n");
		printf("Deseja realizar outro depósito? 1- Sim 0 - Nao ");
		scanf ("%d", &op);
		} while(op != 0);
}

void menuPrincipal()
{
	int num;
	do{
		printf("\n\n=================MENU PRINCIPAL====================\n");
		printf("\n1) Inserir novo cliente");
		printf("\n2) Inserir nova conta");
	    printf("\n3) Imprimir dados de uma conta");
	    printf("\n4) Imprimir dados de um cliente");
	    printf("\n5) Imprimir todos os clientes de uma agência");
	    printf("\n6) Imprimir todas as contas de um tipo de uma agência");
	    printf("\n7) Atualizar dados de um cliente");
	    printf("\n8) Atualizar dados de uma conta");
	    printf("\n9) Depósito");
	    printf("\n10) Saque");
	    printf("\n11) Pix");
	    printf("\n0) Sair\n");
	    
	    
		printf("Insira aqui sua resposta: ");
        scanf("%d", &opcao);
        system ("cls");
        switch(opcao){
	        case 1:
	        	inserir_novo_cliente();
	            break;
	        case 2:
	        	inserir_nova_conta();
				break;
	        case 3:
	        	printf("\n Número da conta que deseja acessar: "); scanf("%d", &num);
	            imprimir_dados_conta(num);
	            break;
	        case 4:
	            imprimir_dados_cliente();
	            break;
	        case 5:
	        	imprimir_clientes_agencia();
	        	break;
	        case 6:
	            imprimir_contas_tipo_agencia();
	            break;
	        case 7:
	            atualizar_cliente();
	            break;
	        case 8:
	            atualizar_conta();
	            break;
	        case 9:
	        	depositar();
	            break;
	        case 10:
	            sacar();
	            break;
	        case 11:
	        	pix();
	        	break;
	        case 0:
	            printf("Obrigada por utilizar nosso sistema!");
	        default:
	            printf ("\nOpcao invalida!\n\n");
	            fflush(stdin);
	    }
    }
    while(opcao != 0);
   	system("cls");
}


int main ()
{
    setlocale(LC_ALL, "Portuguese");
    menuPrincipal();
    
	system("pause");
	return 0;
}



