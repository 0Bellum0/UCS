package programa;
import java.util.Scanner;
import instituicao.InstituicaoTI;

public class Tela {
	
	private static int codTurma;
	public static Scanner sc = new Scanner(System.in);
	
	public Tela() {
		
	}
		
	public void console(InstituicaoTI iti) {
		
		int option;
		
		do {
			System.out.println("--------------------------------------");
			System.out.println("|          Instituição TI            |");
			System.out.println("|------------------------------------|");
			System.out.println("| Escolha uma das opções a seguir:   |");
			System.out.println("|                                    |");
			System.out.println("| 1) Listar todas as turmas          |");
			System.out.println("| 2) Informar dados de uma turma     |");
			System.out.println("| 3) Consultar os dados de uma turma |");
			System.out.println("| 4) Consultar estatísticas gerais   |");
			System.out.println("| 5) Sair do sistema                 |");
			System.out.println("--------------------------------------");
			
			//Scanner sc = new Scanner(System.in);
			option = sc.nextInt();
			sc.nextLine();
			//sc.close();
			
			switch (option) {
			
			case 1: iti.listarTurmas();
				System.out.println("Digite enter para prosseguir!");
				sc.nextLine();
				break;
				
			case 2: iti.cadastrarTurma();
				System.out.println("Digite enter para prosseguir!");
				sc.nextLine();
				break;
				
			case 3: 
				System.out.println("Digite o código da turma desejada: ");
				//Scanner sca = new Scanner(System.in);
				codTurma = (sc.nextInt() - 1);
				sc.nextLine();
				iti.infoTurma(codTurma);
				//sc.close();
				System.out.println("Digite enter para prosseguir!");
				sc.nextLine();
				break;
			
			case 4: iti.listarContingente();
				System.out.println("Digite enter para prosseguir!");
				sc.nextLine();
				break;
				
			case 5:
				System.out.println("Deseja realmente sair?");
				System.out.println("5 - Sim | 0 - Não");
				//Scanner scan = new Scanner(System.in);
				option = sc.nextInt();
				sc.nextLine();
				//sc.close();
				break;
				
			default : System.out.println("Digite uma opção novamente!");
				System.out.println("Digite enter para prosseguir!");
				sc.nextLine();
				break;
			}
			
		}
		while(option!=5);
		sc.close();
	}
}