package principal;

import java.util.Scanner;
import estabelecimento.Cinema;

public class Tela {

	public static Scanner sc = new Scanner(System.in);

	public Tela() {

	}

	public void console(Cinema cinema) {

		int option;

		do {
			System.out.println("-----------------------------------");
			System.out.println("|            " + cinema.getNome() + "              |");
			System.out.println("|---------------------------------|");
			System.out.println("|Escolha uma das opções a seguir: |");
			System.out.println("| 1) Cadastro                     |");
			System.out.println("| 2) Consulta                     |");
			System.out.println("| 3) venda                        |");
			System.out.println("| 4) Sair do sistema              |");
			System.out.println("-----------------------------------");

			option = sc.nextInt();
			sc.nextLine();

			switch (option) {

			case 1:
				cinema.cadastro();
				break;

			case 2:
				cinema.consulta();
				break;
				
			case 3:
				cinema.venda();
				break;

			case 4:
				System.out.println("Deseja realmente sair?");
				System.out.println("4 - Sim | 0 - Não");
				option = sc.nextInt();
				sc.nextLine();
				break;

			default:
				System.out.println("Digite uma opção novamente!");
				System.out.println("Digite enter para prosseguir!");
				sc.nextLine();
				break;
			}

		} while (option != 4);
		sc.close();
	}
}