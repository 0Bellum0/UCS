import java.util.Scanner;

public class Cliente {

	private String nome;
	private long celular;
	//private ContaCorrente conta;
	public static final int CONTAS = 10;
	private ContaCorrente[] contas = new ContaCorrente[CONTAS];
	private int iMax = -1;

	public Cliente() {
		String nome;
		long celular;
		
		System.out.println("Digite seu nome: ");
		Scanner sc = new Scanner(System.in);
		nome = sc.nextLine();
		sc.nextLine();
		sc.close();
		
		System.out.println("Digite seu celular: ");
		Scanner sc1 = new Scanner(System.in);
		celular = sc1.nextLong();
		sc1.nextLine();
		sc1.close();
		
		this.nome = nome;
		this.celular = celular;
	}

	public String getNome() {
		return nome;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}

	public long getCelular() {
		return celular;
	}

	public void setCelular(long celular) {
		this.celular = celular;
	}

	public void addConta(ContaCorrente conta) {
		if(iMax < CONTAS) {
			contas[++iMax] = conta;			
		}
		else {
			System.out.println("Número máximo de contas alcançado!");
		}
		
	}
	
	public ContaCorrente getConta(int index) {
		if(index < 0 || index > CONTAS - 1 || iMax == - 1) {
			return null;
		}
	}
	
	public ContaCorrente selecionaConta() {
		System.out.println("As contas disponiveis são: ");
		
		if(iMax > 0) {
			for(int i=0; i< CONTAS; i++) {
				System.out.println(contas[i] + ", ");
			}
		}
		else if(iMax == 0) {
			System.out.println(contas[0]);
		}
		else if(iMax == -1) {
			addConta(new ContaCorrente());
		}
	}

	public double getSaldoTotal() {
		double total = 0;
		for(int i = 0; i<=iMax; i++) {
			total += this.getConta(i).getSaldo();
		}
		return total;
	}
	@Override
	public String toString() {
		StringBuilder sb = new StringBuilder();
		
		sb.append("Nome: " + this.getNome() + "\n");
		sb.append("Celular: " + this.getCelular() + "\n");
		
		for(int i = 0; i<=iMax; i++) {
			sb.append(this.getConta(i) + "\n");
		
			return sb;
	}
	
	/*public ContaCorrente getConta() {
		return conta;
	}
	
	public ContaCorrente setConta() {
		return conta;
	}*/
	}
}