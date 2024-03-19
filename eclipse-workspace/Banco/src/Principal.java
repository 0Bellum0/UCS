import java.util.Scanner;

public class Principal {

	public static void main(String[] args) {
		
		ContaCorrente conta;
		Cliente cliente;
		
		boolean operacao = false;
		
		System.out.println("Digite '0' para criar sua conta ou '1' para acessar sua conta: ");
		Scanner sc = new Scanner(System.in);
		operacao = sc.nextInt() == 1;
		sc.nextLine();
		sc.close();
		
		if(operacao == true) {
			
			conta = cliente.selecionaConta();
			
			System.out.println("Digite '0' para saque ou '1' para deposito: ");
			Scanner sc1 = new Scanner(System.in);
			operacao = sc1.nextInt() == 1;
			sc1.nextLine();
			sc1.close();
			
			if(operacao == true) {
				int valor = 0;
				conta.deposita(valor);
			}
			else if(operacao == false) {
				int valor = 0;
				conta.saque(valor);
			}
			
			conta.mostraSaldo();
		}
		
		else if(operacao == false) {
			conta = new ContaCorrente();
			cliente = new Cliente();
		}
		
		//cli.addConta(c1);
		//cli.addConta(c2);
	}
}