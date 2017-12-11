#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define MAXCLIENTES 100
#define MAXPRODUTOS 50

typedef struct _produto{
	int codigo,prod_quantidade;
	char nome[30], data_fab[12], data_val[12], fornecedor[30];
	double val_venda;
}Produto;

typedef struct _compra{
	Produto produtos[20];
	double total;
}Compra;

typedef struct _cartao{
	int numero;
	Compra compras[20];
	double total_compras;
}Cartao;

typedef struct _cliente{
	char nome[30], cpf[16], telefone[17];
	Cartao cartao;
}Cliente;

typedef struct _estoque{
	Produto proqduto;
	int qtd_estoque;
	double val_aquisicao;
}Estoque;

int quantidadeclientes = 0;//varia de acordo com a quantidade de clientes cadastrados
Cliente cliente[MAXCLIENTES]; //Vetor para salvar clientes
int quantidadeproduto=0; 
Produto produto[MAXPRODUTOS];//Vetor para salvar produtos 


void cadastrar_cliente(){
	printf("Digite o nome do cliente: ");
	getchar();
	fgets(cliente[quantidadeclientes].nome, 30, stdin);
	printf("Digite o numero do CPF: ");
	fgets(cliente[quantidadeclientes].cpf, 16, stdin);
	printf("Digite o numero do telefone:");
	fgets(cliente[quantidadeclientes].telefone, 17, stdin);
	printf("Digite o numero do seu cart„o:");
	scanf("%d", &cliente[quantidadeclientes].cartao.numero);
	
	quantidadeclientes++;

 }
void cadastrar_produto(){
	int ler;
	printf("Digite o nome do produto: ");
	
	getchar();//limpa lixo de memoria
	fgets(produto[quantidadeproduto].nome, 30, stdin);
	printf("Digite o nome do Fonecedor: ");
	fgets(produto[quantidadeproduto].fornecedor, 30, stdin);
	printf("Digite a data de fabricacao: ");
	fgets(produto[quantidadeproduto].data_fab, 12, stdin);
	printf("Digite a data de validade:");
	fgets(produto[quantidadeproduto].data_val, 12, stdin);
	printf("Digite o valor da venda: ");
	scanf("%lf",&produto[quantidadeproduto].val_venda);
	printf("Digite o codigo do Produto: ");
	scanf("%d",&produto[quantidadeproduto].codigo);
	printf("Digite a quantidade de produto:");
	scanf("%d", &produto[quantidadeproduto].prod_quantidade);
	quantidadeproduto++;
	
	}

void cadastrar_venda(){
	int i, n, codigo;
	char CPFcomparar[16];
	printf("Digite o numero do CPF:");
	getchar();
	fgets(CPFcomparar,16,stdin);
	for(i=0; i<quantidadeclientes;i++){
		if(strcmp(CPFcomparar,cliente[i].cpf)==0){
		
			printf("Nome do Cliente: %s\n",cliente[i].nome);
			printf("CPF do Cliente: %s\n", cliente[i].cpf);
			printf("Telefone do Cliente: %s\n",cliente[i].telefone);
			printf("Numero do cart„o: %d\n", cliente[i].cartao.numero);
			printf("Digite 1 para confimar ou outro n˙mero para cancelar: ");
			scanf("%d", &n);
		}
			else if(n==1){
				printf("Digite o cÛdigo do produto a comprar: ");
				scanf("%d", codigo);
				for(i=0;i<quantidadeproduto; i++){
				if(codigo == produto[i].codigo){
					printf("Digite como deseja pagar: ");
					printf("1 - Cartao\n");
					printf("2 - Dinheiro\n");
					printf("3 - Cheque\n");
									
				}
			}
			}
			else
			printf("Cliente nao encontrado\n");
		
	 
   }
	
}
void buscar_cliente(){
	int i;
	char CPFcomparar[16];
	printf("Digite o numero do CPF:");
	getchar();
	fgets(CPFcomparar,16,stdin);
	for(i=0; i<quantidadeclientes;i++){
		if(strcmp(CPFcomparar,cliente[i].cpf)==0){
		
			printf("Nome do Cliente: %s\n",cliente[i].nome);
			printf("CPF do Cliente: %s\n", cliente[i].cpf);
			printf("Telefone do Cliente: %s\n",cliente[i].telefone);
			printf("Numero do cart„o: %d\n", cliente[i].cartao.numero);
		}else
			printf("Cliente nao encontrado\n");
	 
   }
}
void buscar_produto(){
	int i;
	char nomecomparar[30];
	printf("Digite o nome do Produto: ");
	getchar();
	fgets(nomecomparar,30,stdin);
	for(i=0; i<quantidadeproduto; i++){
		if(strcmp(nomecomparar,produto[i].nome)==0){
			printf("O nome do Produto: %s\n", produto[i].nome);
			printf("O nome do Fornecedor: %s\n",produto[i].fornecedor);
			printf("Data da Fabricacao:%s\n",produto[i].data_fab);
			printf("Data de Validade:%s\n",produto[i].data_val);
			printf("Valor da venda: %.2lf\n",produto[i].val_venda);
		}else
			printf("Produto nao encontrado\n");
	}
}
void adicionar_prod_estoque(){
	printf("Falta implementar....\n");  
}
void listar_prod_fornecedor(){
	int i;
	for(i=0; i<quantidadeproduto; i++){
		printf("O nome do Produto: %s\n", produto[i].nome);
		printf("O nome do Fornecedor: %s\n",produto[i].fornecedor);
		printf("Data da Fabricacao:%s\n",produto[i].data_fab);
		printf("Data de Validade:%s\n",produto[i].data_val);
		printf("Valor da venda: %.2lf\n",produto[i].val_venda);
		printf("O codigo e: %d\n",produto[i].codigo);
		}

}
void listar_prod_baixa(){
    int i;
		for(i=0; i < quantidadeproduto; i++){//i vai de acordo com a quantidade de cliente
			printf("Nome do Produto: %s\n", produto[i].nome);
			printf("Digite a Data de Fabricacao: %s\n", produto[i].data_fab);
			printf("Digite a Data de validade: %s\n", produto[i].data_val);
	}
}
void listar_clientes(){
	int i;// percorre o for
	for(i=0; i < quantidadeclientes; i++){
		printf("Nome do Cliente: %s\n",cliente[i].nome);
		printf("CPF do Cliente: %s\n", cliente[i].cpf);
		printf("Telefone do Cliente: %s\n",cliente[i].telefone);
		printf("Numero do cart„o: %d\n", cliente[i].cartao.numero);
	}   
}


int main(void){
	int opcao;
	do{
		printf("\tMenu de Op√ß√µes:\n");
		printf("1 - Cadastrar clientes, produtos ou venda:\n");
		printf("2 - Buscar cliente:\n");
		printf("3 - Buscar produto:\n");
		printf("4 - Adicionar produto no estoque:\n");
		printf("5 - Listar produtos:\n");
		printf("6 - Listar clientes:\n");
		printf("0 - Sair do sistema:\n");
		printf("\n--> ");
		scanf("%d", &opcao);
		printf("\n");
		switch(opcao){
			case 1:
				do{
					printf("\tSubmenu de cadastro\n");
					printf("1 - Cadastrar cliente:\n");
					printf("2 - Cadastrar produto:\n");
					printf("3 - Cadastrar venda:\n");
					printf("0 - Voltar ao menu anterior\n");
					printf("\n--> ");
					scanf("%d", &opcao);
					printf("\n");
					switch(opcao){
						case 1:
							cadastrar_cliente();
							opcao = 0;
							break;
						case 2:
							cadastrar_produto();
							opcao = 0;
							break;
						
						case 3:
							cadastrar_venda();
							opcao = 0;
							break;
						case 0:
							break;
						default:
							printf("Opcao inv√°lida\n\n");
							break;
					}
				}while(opcao != 0);
				opcao = 1;
				break;
			case 2:
				buscar_cliente();
				break;
			case 3:
				buscar_produto();
				break;
			case 4:
				adicionar_prod_estoque();
				break;
			case 5:
				do{
					printf("\tSubmenu de produtos\n");
					printf("1 - Listar produtos por fornecedor:\n");
					printf("2 - Listar produtos em baixa no estoque:\n");
					printf("0 - Voltar ao menu anterior\n");
					printf("\n--> ");
					scanf("%d", &opcao);
					printf("\n");
					switch(opcao){
						case 1:
							listar_prod_fornecedor();
							opcao = 0;
							break;
						case 2:
							listar_prod_baixa();
							opcao = 0;
							break;
						case 0:
							break;
						default:
							printf("Opcao inv√°lida\n\n");
							break;
					}

				}while(opcao != 0);
				opcao = 5;
				break;
			case 6:
				listar_clientes();
				break;
			case 0:
				break;
			default:
				printf("Op√ß√£o inv√°lida\n\n");
		}
	}while(opcao != 0);


	return 0;
}
