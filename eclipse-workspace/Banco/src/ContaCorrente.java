import java.util.Scanner;

public class ContaCorrente {

	private int numero = 0;
	private double saldo;
	
	public ContaCorrente() {
		this.saldo = 0.0;
		this.numero += 1;
	}
	
	public int getNumero() {
		return numero;
	}
	
	public void setNumero(int numero) {
		this.numero = numero;
	}
	
	public double getSaldo() {
		return saldo;
	}
	
	public void deposita(double valor) {
		
		mostraSaldo();
		
		System.out.println("Digite um valor para depósito: ");
		Scanner sc = new Scanner(System.in);
		valor = sc.nextInt();
		sc.nextLine();
		sc.close();
		
		if(valor >= 1) {
			this.saldo += valor;
		}
		else {
			System.out.println("Deposito mínimo é R$1.00");
		}
	}
	public void saque(double valor) {
		
		mostraSaldo();
		
		System.out.println("Digite um valor para Saque: ");
		Scanner sc = new Scanner(System.in);
		valor = sc.nextInt();
		sc.nextLine();
		sc.close();
		
		if(valor <= this.saldo) {
			this.saldo -= valor;
		}
		else {
			System.out.println("Saque máximo de R$" + this.getSaldo());
		}
	}
	
	public void mostraSaldo() {
		System.out.println("Conta: " + this.getNumero());
		System.out.println("Saldo: " + this.getSaldo());
	}
}