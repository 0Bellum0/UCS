package principal;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;

import estabelecimento.Cinema;

public class Programa {

	private static boolean dataChanged = false;
	
	private static Cinema cinema = null;

	public static void main(String[] args) {
				
		File data = new File("cinema.dat");
		
		Tela tela = new Tela();
		
		if(data.exists()) {
			try {
				FileInputStream fis = new FileInputStream("cinema.dat");
				ObjectInputStream ois = new ObjectInputStream(fis);
				Object o = ois.readObject();
				cinema = (Cinema) o;
				ois.close();
				fis.close();
				}
				catch(IOException e ) {
					e.printStackTrace();
				}
				catch(ClassNotFoundException ce ) {
					ce.printStackTrace();
				}
		}
		else {
			System.out.println("Digite o nome do cinema: ");
			String nome;
			nome = Tela.sc.nextLine();
			
			System.out.println("Digite o endereco do cinema: ");
			String endereco;
			endereco = Tela.sc.nextLine();
			
			Programa.cinema = new Cinema(nome, endereco);
		}
		
		tela.console(cinema);

		if (dataChanged) {
			try {
				FileOutputStream fos = new FileOutputStream("cinema.dat");
				ObjectOutputStream oos = new ObjectOutputStream(fos);
				oos.writeObject(cinema);
				oos.close();
				fos.close();
				
				}
				catch(IOException e ) {
					e.printStackTrace();
				}
		}
	}
	
	public static void setDataChanged() {
		if(Programa.dataChanged == true) {
			System.out.println("Dados serão salvos ao final da execução!");
		}
		else {
			Programa.dataChanged = true;
			System.out.println("Dados serão salvos ao final da execução!");
		}
	}
}